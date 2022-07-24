#include "Variable.h"

Variable* create_variable(const char* name, unsigned int scope, unsigned int line){
    Variable *new = (Variable *)malloc(sizeof(Variable));

    if(!new)
        return NULL;

    new->name = strdup(name);
    new->scope = scope;
    new->line = line;

    return new;
}