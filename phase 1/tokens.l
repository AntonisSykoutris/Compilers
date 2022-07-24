%{
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "rules.h"
#define YY_DECL int alpha_yylex(void* yylval)

int embedded_comments = 0;
int no_of_tokens = 1;

int comment_starting_line = 0;
int comment_finish_line = 0;

alpha_token_t* store_token(alpha_token_t *head, char *cat);

extern alpha_token_t *head_ptr;

%}

%option yylineno
%option noyywrap

NEWLINE         \n

IF              if
ELSE            else
WHILE           while 
FOR             for 
FUNCTION        function 
RETURN          return 
BREAK           break 
CONTINUE        continue 
AND             and 
OR              or 
NOT             not 
LOCAL           local 
TRUE            true 
FALSE           false 
NIL             nil 

ASSIGN          "="
PLUS            "+"
MINUS           "-"
MULTIPLY        "*"
SLASH           "/"
PERCENTAGE      "%"
EQUAL           "=="
NOT_EQUAL       "!="
INCREMENT       "++"
DECREMENT       "--"
LOWER           "<"
GREATER         ">"
GREATER_EQUAL   ">="
LOWER_EQUAL     "<="

INTEGER         [0-9][0-9]*
REAL            [0-9]*\.[0-9][0-9]*

OPEN_BRACKET    "{"
CLOSE_BRACKET   "}"
OPEN_SUBSCRIPT  "["
CLOSE_SUBSCRIPT "]"
OPEN_PAR        "("
CLOSE_PAR       ")"
SEMICOLON       ";"
COMMA           ","
COLON           ":"
DOUBLE_COLON    "::"
DOUBLE_DOT      ".." 
DOT             "."

ID              [a-zA-Z][a-zA-Z_0-9]*

STRING          \"(\\.|[^"\\])*\"
STERR           (\"[^\n\"]?+)

COMMENT2        "//"*


%x  BLOCK_COMMENT
%x  LINE_COMMENT


%%


"/*"                {comment_starting_line = yylineno; BEGIN(BLOCK_COMMENT);}
<BLOCK_COMMENT>{
.                   {;}
<<EOF>>             {fprintf(stderr, "Error, non-terminated comment block\n"); return -1;}
{NEWLINE}           {}
"/*"                {embedded_comments++;}
"*"+"/"             {
                        if(embedded_comments != 0) 
                            embedded_comments--; 
                        else {
                            comment_finish_line = yylineno;
                            head_ptr = store_token(head_ptr, "BLOCK_COMMENT");
                            BEGIN(INITIAL);
                        }
                    }
}

<LINE_COMMENT>{
.                   {;}
{NEWLINE}           {BEGIN(INITIAL);}
}



{NEWLINE}           {}

{COMMENT2}          {head_ptr = store_token(head_ptr, "LINE_COMMENT"); BEGIN(LINE_COMMENT);}
{IF}                {head_ptr = store_token(head_ptr, "KEYWORD");}
{ELSE}              {head_ptr = store_token(head_ptr, "KEYWORD");}
{WHILE}             {head_ptr = store_token(head_ptr, "KEYWORD");}
{FOR}               {head_ptr = store_token(head_ptr, "KEYWORD");}
{FUNCTION}          {head_ptr = store_token(head_ptr, "KEYWORD");}
{RETURN}            {head_ptr = store_token(head_ptr, "KEYWORD");}
{BREAK}             {head_ptr = store_token(head_ptr, "KEYWORD");}
{CONTINUE}          {head_ptr = store_token(head_ptr, "KEYWORD");}
{AND}               {head_ptr = store_token(head_ptr, "KEYWORD");}
{OR}                {head_ptr = store_token(head_ptr, "KEYWORD");}
{NOT}               {head_ptr = store_token(head_ptr, "KEYWORD");}
{LOCAL}             {head_ptr = store_token(head_ptr, "KEYWORD");}
{TRUE}              {head_ptr = store_token(head_ptr, "KEYWORD");}
{FALSE}             {head_ptr = store_token(head_ptr, "KEYWORD");}
{NIL}               {head_ptr = store_token(head_ptr, "KEYWORD");}

{ASSIGN}            {head_ptr = store_token(head_ptr, "OPERATOR");}
{PLUS}              {head_ptr = store_token(head_ptr, "OPERATOR");}
{MINUS}             {head_ptr = store_token(head_ptr, "OPERATOR");}
{MULTIPLY}          {head_ptr = store_token(head_ptr, "OPERATOR");}
{SLASH}             {head_ptr = store_token(head_ptr, "OPERATOR");}
{PERCENTAGE}        {head_ptr = store_token(head_ptr, "OPERATOR");}
{EQUAL}             {head_ptr = store_token(head_ptr, "OPERATOR");}
{NOT_EQUAL}         {head_ptr = store_token(head_ptr, "OPERATOR");}
{INCREMENT}         {head_ptr = store_token(head_ptr, "OPERATOR");}
{DECREMENT}         {head_ptr = store_token(head_ptr, "OPERATOR");}
{LOWER}             {head_ptr = store_token(head_ptr, "OPERATOR");}
{GREATER}           {head_ptr = store_token(head_ptr, "OPERATOR");}
{GREATER_EQUAL}     {head_ptr = store_token(head_ptr, "OPERATOR");}
{LOWER_EQUAL}       {head_ptr = store_token(head_ptr, "OPERATOR");}

{INTEGER}           {head_ptr = store_token(head_ptr, "INT_CONST");}
{REAL}              {head_ptr = store_token(head_ptr, "REAL_CONST");}

{OPEN_BRACKET}      {head_ptr = store_token(head_ptr, "PUNCTUATION");}
{CLOSE_BRACKET}     {head_ptr = store_token(head_ptr, "PUNCTUATION");}
{OPEN_SUBSCRIPT}    {head_ptr = store_token(head_ptr, "PUNCTUATION");}
{CLOSE_SUBSCRIPT}   {head_ptr = store_token(head_ptr, "PUNCTUATION");}
{OPEN_PAR}          {head_ptr = store_token(head_ptr, "PUNCTUATION");}
{CLOSE_PAR}         {head_ptr = store_token(head_ptr, "PUNCTUATION");}
{SEMICOLON}         {head_ptr = store_token(head_ptr, "PUNCTUATION");}
{COMMA}             {head_ptr = store_token(head_ptr, "PUNCTUATION");}
{COLON}             {head_ptr = store_token(head_ptr, "PUNCTUATION");}
{DOUBLE_COLON}      {head_ptr = store_token(head_ptr, "PUNCTUATION");}
{DOUBLE_DOT}        {head_ptr = store_token(head_ptr, "PUNCTUATION");}
{DOT}               {head_ptr = store_token(head_ptr, "PUNCTUATION");}

{ID}                {head_ptr = store_token(head_ptr, "ID");}

<<EOF>>             {return END_OF_FILE;}

[ \t]               {;}
[^ \t]              {fprintf(stderr, "Warning, line %d: Undefined input <%s>\n", yylineno, yytext);}

{STRING}            {head_ptr = store_token(head_ptr, "STRING");}
{STERR}             {fprintf(stderr, "ERROR, line %d: Non terminated String\n", yylineno); return 1000;}


%%


void remove_quotes(char* ptr){
    char *tmp = ptr;
    char *next = ptr + 1;
    char *last = ptr + strlen(ptr) - 1;

    *last = '\0';

    while(*tmp != '\0'){
        *tmp = *next;
        tmp++;
        next++;
    }

}

void fix_esc_char(char* ptr){
    char *tmp;
    char *next_char;
    while(*ptr != '\0'){
        if(*ptr == '\\'){
            tmp = ptr;
            next_char = ptr + 1;
            if(*next_char == 'n')
                *ptr = '\n';

            else if(*next_char == 't')
                *ptr = '\t';
            
            else if(*next_char == '\\')
                *ptr = '\\';
            
            else if(*next_char == '\"')
                *ptr = '\"';
            
            else{
                fprintf(stderr, "Warning, string at line %d contains invalid escaped character %c\n", yylineno, *next_char);
                *ptr = 'k';
            }

            tmp++;
            next_char++;
            while(*tmp != '\0'){
                *tmp = *next_char;
                tmp++;
                next_char++;
            }
            
        }
        
        ptr++;
    }
}

alpha_token_t* store_token(alpha_token_t *head, char *cat){

    char from[3];
    char to[3];
    char whole[10];

    alpha_token_t *new = (alpha_token_t *)malloc(sizeof(alpha_token_t));
    alpha_token_t *tmp = head;

    new->line_no = yylineno;
    new->token_no = no_of_tokens;
    
    if(strcmp(cat, "STRING") == 0){
        remove_quotes(yytext);
        fix_esc_char(yytext);
        new->value = strdup(yytext);
    }

    else if(strcmp(cat, "BLOCK_COMMENT") == 0){
        memset(from,0,strlen(from));
        memset(to,0,strlen(to));
        memset(whole,0,strlen(whole));

        sprintf(from, "%d", comment_starting_line);
        sprintf(to, "%d", comment_finish_line);

        strcat(whole, from);
        strcat(whole, " - ");
        strcat(whole, to);


        new->value = strdup(whole);
    }
        
    
    else if(strcmp(cat, "LINE_COMMENT") == 0)
        new->value = strdup("");
    
    else
        new->value = strdup(yytext);
    
    
    new->category = strdup(cat);

    if(head == NULL){
        head = new;
    }
    else{
        while(tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = new;
    }

    no_of_tokens++;

    return head;
}