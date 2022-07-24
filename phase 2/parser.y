%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symtable.h"
#include "symboltype.h"
#include "Variable.h"
#include "Function.h"

#define RULES_STREAM yyout

void yyerror (char *s);
void print_rules(char* rule1, char* rule2);
int yylex();

extern int yylineno;
extern char *yytext;

extern FILE *yyin;
extern FILE *yyout;

int curr_scope = 0;
bool isLocal = false;

SymTable *table;

%}

%union{
    int integ;
    float fl;
    char *str;
}

%start program

%token <integ> INT_CONST
%token <fl> REAL_CONST
%token <str> ID 
%token KEYWORD OPERATOR PUNCTATION
%token <str> STRING 

%type <str> lvalue


%token  AND OR NOT
%token  ASSIGN PLUS MINUS MULTIPLY DIVIDE MOD GREATER GREATER_EQ LESS LESS_EQ EQ NOT_EQ NEGATIVE
%token  INCREMENT DECREMENT
%token  OPEN_BRACKET CLOSE_BRACKET OPEN_SUBSCRIPT CLOSE_SUBSCRIPT OPEN_PAR CLOSE_PAR SEMICOLON COMMA COLON DOUBLE_COLON DOUBLE_DOT DOT            
%token  WHILE FOR BREAK CONTINUE RETURN
%token  IF ELSE
%token  LOCAL FALSE TRUE NIL FUNCTION
%token  END_OF_FILE 

%token INF_COMMENT INF_STRING

%expect 1

%right      ASSIGN
%left       OR
%left       AND
%nonassoc   EQ NOT_EQ
%nonassoc   GREATER GREATER_EQ LESS LESS_EQ 
%left       PLUS MINUS
%left       MULTIPLY DIVIDE MOD
%right      NOT INCREMENT DECREMENT
%left       DOT DOUBLE_DOT
%left       OPEN_SUBSCRIPT CLOSE_SUBSCRIPT
%left       OPEN_PAR CLOSE_PAR
%left       OPEN_BRACKET CLOSE_BRACKET

%%

program     :   stmts                   {print_rules("program","stmts");}
            ;

stmt        :   expr SEMICOLON          {print_rules("stmt","expr;");}
            |   ifstmt                  {print_rules("stmt","ifstmt");}
            |   whilestmt               {print_rules("stmt","whilestmt");}
            |   forstmt                 {print_rules("stmt","forstmt");}
            |   returnstmt              {print_rules("stmt","returnstmt;");}
            |   BREAK SEMICOLON         {print_rules("stmt","break;");}
            |   CONTINUE SEMICOLON      {print_rules("stmt","continue;");}
            |   block                   {print_rules("stmt","block");}
            |   funcdef                 {print_rules("stmt","funcdef;");}
            |   SEMICOLON               {print_rules("stmt",";");}
            ;
            
stmts       :   stmts stmt              {print_rules("stmt","stmts stmt");}
            |   /*empty*/
            ;

expr        :   assignexpr              {print_rules("expr","assignexpr");}
            |   expr OR expr            {print_rules("expr","expr or expr");}    
            |   expr AND expr           {print_rules("expr","expr and expr");}
            |   expr EQ expr            {print_rules("expr","expr == expr");}
            |   expr NOT_EQ expr        {print_rules("expr","expr != expr");}
            |   expr GREATER expr       {print_rules("expr","expr > expr");}
            |   expr GREATER_EQ expr    {print_rules("expr","expr >= expr");}
            |   expr LESS expr          {print_rules("expr","expr < expr");}
            |   expr LESS_EQ expr       {print_rules("expr","expr <= expr");}
            |   expr PLUS expr          {print_rules("expr","expr + expr");}
            |   expr MINUS expr         {print_rules("expr","expr - expr");}
            |   expr MULTIPLY expr      {print_rules("expr","expr * expr");}
            |   expr DIVIDE expr        {print_rules("expr","expr / expr");}
            |   expr MOD expr           {print_rules("expr","expr % expr");}
            |   term                    {print_rules("expr","term");}
            ;

term        :   OPEN_PAR expr CLOSE_PAR  {print_rules("term","( expr )");}
            |   MINUS expr               {print_rules("term","- expr");}
            |   NOT expr                 {print_rules("term","not expr");}
            |   INCREMENT lvalue         {print_rules("term","++lvalue");}
            |   lvalue INCREMENT         {print_rules("term","lvalue++");}
            |   DECREMENT lvalue         {print_rules("term","--lvalue");}
            |   lvalue DECREMENT         {print_rules("term","lvalue--");}
            |   primary                  {print_rules("term","primary");}
            ;

assignexpr  :   lvalue  
                ASSIGN  {
                            if(isLocal == false && $1 != NULL){
                                if(distinguish_lookup(table, $1, curr_scope) != GENERAL){
                                    fprintf(stderr, "Error, cannot change value of \"%s\", functions are constant\n", $1);
                                }
                               
                            }
                            
                        }
                expr                    {print_rules("assignexpr","lvalue = expr");}
            ;

primary     :   lvalue                          {print_rules("primary","lvalue");}
            |   call                            {print_rules("primary","call");}
            |   objectdef                       {print_rules("primary","objectdef");}
            |   OPEN_PAR funcdef CLOSE_PAR      {print_rules("primary","( funcdef )");}
            |   const                           {print_rules("primary","const");}
            ;

lvalue      :   ID              {
                                    isLocal = false;
                                    $$ = $1;
                                    if(distinguish_lookup(table, yytext, curr_scope) == GENERAL){
                                        /*fprintf(stderr, "variable ID: %s\n", yytext);*/
                                        variable_lookup(table, create_variable(yytext, curr_scope, yylineno), GENERAL, curr_scope);
                                    }
                                    else{
                                        /*fprintf(stderr, "func call ID: %s\n", yytext);*/
                                        
                                    }
                                    print_rules("lvalue","ID");
                                }

            |   LOCAL ID        {
                                    isLocal = true;
                                    $$ = $2;
                                    /*fprintf(stderr, "local ID: %s\n", yytext);*/
                                    variable_lookup(table, create_variable(yytext, curr_scope, yylineno), LOCAL_t, curr_scope);
                                    print_rules("lvalue","local ID");
                                }        
            
            |   DOUBLE_COLON ID {
                                    isLocal = false;
                                    $$ = $2;
                                    if(distinguish_lookup(table, yytext, curr_scope) == GENERAL){
                                        /*fprintf(stderr, "global ID: %s\n", yytext);*/
                                        variable_lookup(table, create_variable(yytext, curr_scope, yylineno), GLOBAL, curr_scope);
                                    }
                                    else{
                                        /*fprintf(stderr, "func call ID: %s\n", yytext);*/
                                    }
                                    print_rules("lvalue","::ID");
                                }

            |   member          {
                                    $$ = NULL;
                                    print_rules("lvalue","member");
                                }
            ;

member      :   lvalue DOT ID                                        {print_rules("member",".ID");}
            |   lvalue OPEN_SUBSCRIPT expr CLOSE_SUBSCRIPT           {print_rules("member","lvalue [ expr ]");}
            |   call DOT ID                                          {print_rules("member","call.ID");}
            |   call OPEN_SUBSCRIPT expr CLOSE_SUBSCRIPT             {print_rules("member","call[ expr ]");}
            ;

call        :   call OPEN_PAR elist CLOSE_PAR                        {print_rules("call","call ( elist )");}
            |   lvalue callsuffix                                    {print_rules("call","lvalue callsuffix");}
            |   OPEN_PAR funcdef CLOSE_PAR OPEN_PAR elist CLOSE_PAR  {print_rules("call","( funcdef ) ( elist )");}
            ;

callsuffix  :   normalcall                                           {print_rules("callsuffix","normalcall");}
            |   methodcall                                           {print_rules("callsuffix","methodcall");}
            ;

normalcall  :   OPEN_PAR elist CLOSE_PAR                             {print_rules("normalcall","( elist )");}
            ;

methodcall  :   DOUBLE_DOT ID OPEN_PAR elist CLOSE_PAR               {print_rules("methodcall","..ID ( elist )");}
            ;

elist       :   expr exprs                                           {print_rules("elist","expr exprs");}
            |   /* empty */                                          {print_rules("elist"," ");}
            ;

exprs       :   COMMA expr exprs                                     {print_rules("exprs",", expr exprs");}
            |   /* empty */                                          {print_rules("exprs"," ");}
            ;

objectdef   :   OPEN_SUBSCRIPT elist CLOSE_SUBSCRIPT                 {print_rules("objectdef","[ elist ]");}
            |   OPEN_SUBSCRIPT indexed CLOSE_SUBSCRIPT               {print_rules("objectdef","[ indexed ]");}
            ;

indexed     :   indexedelem indexedelems                             {print_rules("indexed","indexedelem indexedelems");}
            ;

indexedelem :   OPEN_BRACKET expr COLON expr CLOSE_BRACKET           {print_rules("indexedelem","{ expr; expr }");}
            ;
            
indexedelems:   COMMA indexedelem indexedelems                      {print_rules("indexedelems",", indexedelem indexedelems");}
            |   /* empty */
            ;

block       :   OPEN_BRACKET {curr_scope++;} stmts CLOSE_BRACKET {hide(table, curr_scope); curr_scope--;}  {print_rules("block","{ stmts }");}
            ;

funcdef     :   FUNCTION ID {
                                /*fprintf(stderr, "funcdef ID: %s\n", yytext);*/
                                function_lookup(table, create_function(yytext, curr_scope, yylineno), USERFUNC, curr_scope, false);
                            }
                OPEN_PAR {curr_scope++;}
                idlist 
                CLOSE_PAR {curr_scope--;}
                block                           {print_rules("funcdef","function ID(idlist) block");}

            |   FUNCTION OPEN_PAR {curr_scope++;} idlist CLOSE_PAR {curr_scope--;} block {print_rules("funcdef","function (idlist) block");}
            ;
            
const       :   REAL_CONST                      {print_rules("const","REAL_CONST");}
            |   INT_CONST                       {print_rules("const","INT_CONST");}
            |   STRING                          {print_rules("const","STRING");}
            |   NIL                             {print_rules("const","NIL");}
            |   TRUE                            {print_rules("const","TRUE");}
            |   FALSE                           {print_rules("const","FALSE");}
            ;

idlist      :   ID  {
                        /*fprintf(stderr, "parameter ID: %s\n", yytext);*/
                        formal_lookup(table, create_variable(yytext, curr_scope, yylineno), FORMAL, curr_scope);
                        
                    } 
                ids                             {print_rules("idlist","ID ids");}
            |   /* empty */                     {print_rules("idlist"," ");}
            ;

ids         :   COMMA 
                ID  {
                        /*fprintf(stderr, "parameter ID: %s\n", yytext);*/
                        formal_lookup(table, create_variable(yytext, curr_scope, yylineno), FORMAL, curr_scope);
                    } 
                ids                             {print_rules("ids",", ID ids");}
            |   /* empty */                     {print_rules("ids"," ");}
            ;

ifstmt      :   IF OPEN_PAR expr CLOSE_PAR stmt elsestmt {print_rules("ifstmt","if(expr) stmt elsestmt");}
            ;

elsestmt    :   ELSE stmt                                 {print_rules("elsestmt","else stmt");}
            |   /*empty*/                                 {print_rules("elsestmt"," ");}
            ;

whilestmt   :   WHILE OPEN_PAR expr CLOSE_PAR stmt        {print_rules("whilestmt","while(expr) stmt");}
            ;

forstmt     :   FOR OPEN_PAR elist SEMICOLON expr SEMICOLON elist CLOSE_PAR stmt {print_rules("forstmt","for(elist; expr; elist) stmt");}
            ;

returnstmt  :   RETURN expr SEMICOLON           {print_rules("returnstmt","return expr;");}
            |   RETURN SEMICOLON                {print_rules("returnstmt","return;");}
            ;

%%

void print_rules(char* rule1, char* rule2){
    char* final_rule = (char *)malloc(250*sizeof(char));
    memset (final_rule,'0',250);

    strcpy(final_rule, rule1);
    strcat(final_rule, " -> ");
    strcat(final_rule, rule2);
    strcat(final_rule, "\n");

    fputs(final_rule, RULES_STREAM);
}

int main(int argc, char *argv[]){

    table = create_table();

    if(argv[1] != NULL)
        yyin = fopen(argv[1], "r");

    if(argv[2] != NULL){
        yyout = fopen(argv[2], "w+");
    }else{
        yyout = stdout;
    }
        

    yyparse();
    print_table_scopes(table);
    /*print_table_buckets(table);*/


    return 1;
}