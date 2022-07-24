#define KEYWORD 1
#define OPERATOR 2
#define INT 3
#define REAL 4
#define STR 5
#define P_MARK 6
#define ID 7
#define END_OF_FILE 0

typedef struct alpha_token{
    unsigned int line_no;
    unsigned int token_no;
    char *value;
    char *category;

    struct alpha_token *next;

}alpha_token_t; 

alpha_token_t *head_ptr;