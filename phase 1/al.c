#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rules.h"

extern int alpha_yylex(void *yylval);
extern FILE *yyin, *yyout;
extern int yylineno;
extern int no_of_tokens;
extern char *yytext;

extern alpha_token_t *head_ptr;

void print_list(alpha_token_t *head, FILE *stream)
{
    alpha_token_t *tmp = head;
    while (tmp != NULL)
    {
        fprintf(stream, "%d: #%d    \"%s\"    %s\n", tmp->line_no, tmp->token_no, tmp->value, tmp->category);
        tmp = tmp->next;
    }
}

int main(int argc, char const *argv[])
{
    yyin = fopen(argv[1], "r");
    if (argv[2] != NULL)
    {
        yyout = fopen(argv[2], "w+");
    }
    else
    {
        yyout = stdout;
    }
    alpha_token_t token;
    char *category;
    int result;
    result = alpha_yylex(&token);

    while (result)
    {
        switch (result)
        {
        case -1:
            return -1;

        case END_OF_FILE:
            return 1;

        default:
            break;
        }
        result = alpha_yylex(&token);
    }
    print_list(head_ptr, yyout);
    fclose(yyin);
    return 0;
}
