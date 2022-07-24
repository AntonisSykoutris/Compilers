#ifndef SYMBOL_TYPE__H
#define SYMBOL_TYPE__H


enum SymbolType {
    GENERAL,
    GLOBAL,
    LOCAL_t,
    FORMAL,
    USERFUNC,
    LIBFUNC
};

static inline char *toString(enum SymbolType t){
    static char* string[] = {"local variable", "global variable", "local variable", "formal argument", "user function", "library function"};

    return string[t];
}

#endif