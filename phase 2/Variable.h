#ifndef VARIABLE_H
#define VARIABLE_H

#include <string.h>
#include <stdlib.h>

#include "symboltype.h"

typedef struct Variable {
    const char *name;
    unsigned int scope;
    unsigned int line;

} Variable;

Variable* create_variable(const char* name, unsigned int scope, unsigned int line);

#endif