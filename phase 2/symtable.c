#include "symtable.h"

#define INIT_TABLE_SIZE 50
#define HASH_MULT 15711

unsigned int variable_hash(Variable *entry, int buckets) {
    size_t ui;
    unsigned int uiHash = 0;
    for (ui = 0; entry->name[ui] != '\0'; ui++)
        uiHash = uiHash * HASH_MULT + entry->name[ui] * entry->line;
    return uiHash % buckets;
}

unsigned int function_hash(Function *entry, int buckets) {
    size_t ui;
    unsigned int uiHash = 0;
    for (ui = 0; entry->name[ui] != '\0'; ui++)
        uiHash = uiHash * HASH_MULT + entry->name[ui] * entry->line;
    return uiHash % buckets;
}

SymTable *create_table() {
    SymTable *table = (SymTable *)malloc(sizeof(SymTable));
    table->HashTable = (SymbolTableEntry **)malloc(INIT_TABLE_SIZE * sizeof(SymbolTableEntry));
    table->curr_size = 0;
    table->buckets = INIT_TABLE_SIZE;

    function_insert(table, create_function("print", 0, 0), LIBFUNC);
    function_insert(table, create_function("input", 0, 0), LIBFUNC);
    function_insert(table, create_function("objectmemberkeys", 0, 0), LIBFUNC);
    function_insert(table, create_function("objecttotalmembers", 0, 0), LIBFUNC);
    function_insert(table, create_function("objectcopy", 0, 0), LIBFUNC);
    function_insert(table, create_function("totalarguments", 0, 0), LIBFUNC);
    function_insert(table, create_function("argument", 0, 0), LIBFUNC);
    function_insert(table, create_function("typeof", 0, 0), LIBFUNC);
    function_insert(table, create_function("strtonum", 0, 0), LIBFUNC);
    function_insert(table, create_function("sqrt", 0, 0), LIBFUNC);
    function_insert(table, create_function("cos", 0, 0), LIBFUNC);
    function_insert(table, create_function("sin", 0, 0), LIBFUNC);

    return table;
}

int variable_insert(SymTable *table, Variable *var, enum SymbolType type) {
    SymbolTableEntry *tmp;
    SymbolTableEntry *new = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    unsigned int spot = -1;
    spot = variable_hash(var, table->buckets);

    if (!new || spot == -1)
        return 0;

    new->isActive = true;
    new->value.varVal = var;
    new->type = type;

    if (!table->HashTable[spot]) {
        table->HashTable[spot] = new;
        table->curr_size++;
    } else {
        tmp = table->HashTable[spot];
        while (tmp->table_next != NULL) {
            tmp = tmp->table_next;
        }
        tmp->table_next = new;
        table->curr_size++;
    }

    /*keep track of scope list*/
    if (!scope_list_head) {
        scope_list_head = (scoped_entries_list *)malloc(sizeof(scoped_entries_list));
        scope_list_head->scope_head = new;
        scope_list_head->scope_tail = new;
        scope_list_head->scope = var->scope;
    } else {
        scoped_entries_list *tmp = scope_list_head;
        while (tmp->next != NULL) {
            if (tmp->scope == var->scope) {
                break;
            }
            tmp = tmp->next;
        }
        if (tmp->scope == var->scope) {
            tmp->scope_tail->scope_next = new;
            new->scope_prev = tmp->scope_tail;
            tmp->scope_tail = new;
        } else if (tmp->next == NULL) {
            scoped_entries_list *new_obj = (scoped_entries_list *)malloc(sizeof(scoped_entries_list));
            tmp->next = new_obj;
            new_obj->scope_head = new;
            new_obj->scope_tail = new;
            new_obj->scope = var->scope;
        }
    }
}

int function_insert(SymTable *table, Function *func, enum SymbolType type) {
    SymbolTableEntry *tmp;
    SymbolTableEntry *new = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    unsigned int spot = -1;
    spot = function_hash(func, table->buckets);

    if (!new || spot == -1)
        return 0;

    new->isActive = true;
    new->value.funcVal = func;
    new->type = type;

    if (!table->HashTable[spot]) {
        table->HashTable[spot] = new;
        table->curr_size++;
    } else {
        tmp = table->HashTable[spot];
        while (tmp->table_next != NULL) {
            tmp = tmp->table_next;
        }
        tmp->table_next = new;
        table->curr_size++;
    }

    /*keep track of scope list*/
    if (!scope_list_head) {
        scope_list_head = (scoped_entries_list *)malloc(sizeof(scoped_entries_list));
        scope_list_head->scope_head = new;
        scope_list_head->scope_tail = new;
        scope_list_head->scope = func->scope;
    } else {
        scoped_entries_list *tmp = scope_list_head;
        while (tmp->next != NULL) {
            if (tmp->scope == func->scope) {
                break;
            }
            tmp = tmp->next;
        }
        if (tmp->scope == func->scope) {
            tmp->scope_tail->scope_next = new;
            new->scope_prev = tmp->scope_tail;
            tmp->scope_tail = new;
        } else if (tmp->next == NULL) {
            scoped_entries_list *new_obj = (scoped_entries_list *)malloc(sizeof(scoped_entries_list));
            tmp->next = new_obj;
            new_obj->scope_head = new;
            new_obj->scope_tail = new;
            new_obj->scope = func->scope;
        }
    }
}

enum SymbolType distinguish_lookup(SymTable *table, const char *name, unsigned int curr_scope) {
    scoped_entries_list *tmp = scope_list_head;
    SymbolTableEntry *tmp_entry = tmp->scope_tail;
    int tmp_scope = curr_scope;

    // fprintf(stderr, "Distinguish called for %s\n", name);

    while (tmp_scope >= 0) {
        tmp = scope_list_head;
        while (tmp != NULL) {
            if (tmp->scope != tmp_scope) {
                tmp = tmp->next;
                continue;
            } else {
                // fprintf(stderr, "scope: %d\n", tmp_scope);
                tmp_entry = tmp->scope_tail;
                while (tmp_entry != NULL) {
                    // fprintf(stderr, "looking at: %s\n", tmp_entry->value.varVal->name);
                    if (tmp_entry->isActive == false) {
                        tmp_entry = tmp_entry->scope_prev;
                        continue;
                    }
                    if (strcmp(name, tmp_entry->value.varVal->name) == 0) {
                        if (tmp_entry->type == USERFUNC || tmp_entry->type == LIBFUNC) {
                            // fprintf(stderr, "matched with \"%s\" -- <%d>\n", tmp_entry->value.varVal->name, tmp_entry->value.varVal->line);
                            return tmp_entry->type;
                        }
                        // fprintf(stderr, "matched with \"%s\" -- <%d>\n", tmp_entry->value.varVal->name, tmp_entry->value.varVal->line);
                        return GENERAL;
                    }
                    tmp_entry = tmp_entry->scope_prev;
                }
            }
            tmp = tmp->next;
        }
        tmp_scope--;
    }

    return GENERAL;
}

/* Lookup for a Variable */
void variable_lookup(SymTable *table, Variable *var, enum SymbolType type, unsigned int curr_scope) {
    scoped_entries_list *tmp = scope_list_head;
    SymbolTableEntry *tmp_entry = tmp->scope_head;
    int tmp_scope = curr_scope;

    /*lookup for local variables*/
    if (type == LOCAL_t) {
        while (tmp != NULL) {
            if (tmp->scope != curr_scope) {
                tmp = tmp->next;
                continue;
            } else {
                tmp_entry = tmp->scope_head;
                while (tmp_entry != NULL) {
                    if (tmp_entry->isActive == false) {
                        tmp_entry = tmp_entry->scope_next;
                        continue;
                    }
                    if (strcmp(var->name, tmp_entry->value.varVal->name) == 0) {
                        if (nameAllowed(var->name) == false) {
                            fprintf(stderr, "Error, \"%s\", line <%d>, shadows library function.\n", var->name, var->line);
                            return;
                        }
                        return;
                    }
                    tmp_entry = tmp_entry->scope_next;
                }
            }
            tmp = tmp->next;
        }

        if (nameAllowed(var->name) == false) {
            fprintf(stderr, "Error, \"%s\", line <%d>, shadows library function.\n", var->name, var->line);
            return;
        } else {
            if (var->scope == 0) {
                variable_insert(table, var, GLOBAL);
            } else {
                variable_insert(table, var, type);
            }
        }
    }

    /*lookup for global variables*/
    if (type == GLOBAL) {
        while (tmp != NULL) {
            if (tmp->scope != 0) {
                tmp = tmp->next;
                continue;
            } else {
                tmp_entry = tmp->scope_head;
                while (tmp_entry != NULL) {
                    if (tmp_entry->isActive == false) {
                        tmp_entry = tmp_entry->scope_next;
                        continue;
                    }
                    if (strcmp(var->name, tmp_entry->value.varVal->name) == 0) {
                        return;
                    }
                    tmp_entry = tmp_entry->scope_next;
                }
            }
            tmp = tmp->next;
        }

        fprintf(stderr, "Error, \"%s\" at line <%d> undeclared, first used here.\n", var->name, var->line);
    }

    /*general variable lookup*/
    if (type == GENERAL) {
        // fprintf(stderr, "Lookup called for %s\n", var->name);
        while (tmp_scope >= 0) {
            // fprintf(stderr, "scope: %d\n", tmp_scope);
            tmp = scope_list_head;
            while (tmp != NULL) {
                if (tmp->scope != tmp_scope) {
                    tmp = tmp->next;
                    continue;
                } else {
                    tmp_entry = tmp->scope_tail;
                    while (tmp_entry != NULL) {
                        // fprintf(stderr, "looking at: %s\n", tmp_entry->value.varVal->name);
                        if (tmp_entry->isActive == false) {
                            tmp_entry = tmp_entry->scope_prev;
                            continue;
                        }
                        if (strcmp(var->name, tmp_entry->value.varVal->name) == 0) {
                            if (tmp_entry->type != GLOBAL) {
                                if (active_function_between_scopes(tmp_entry->value.varVal->scope, var->scope) == 1) {
                                    fprintf(stderr, "Error, cannot access \"%s\" previous decleration was here <%d>\n", var->name, tmp_entry->value.varVal->line);
                                    return;
                                }
                            }

                            // fprintf(stderr, "matched with \"%s\" -- <%d>\n", tmp_entry->value.varVal->name, tmp_entry->value.varVal->line);
                            return;
                        }
                        tmp_entry = tmp_entry->scope_prev;
                    }
                }
                tmp = tmp->next;
            }
            tmp_scope--;
        }

        /*nothing found, insert var in symbol table*/
        // fprintf(stderr, "Nothn found, inserting\n--------\n");

        if (var->scope == 0) {
            variable_insert(table, var, GLOBAL);
        } else {
            variable_insert(table, var, type);
        }
    }
}

/* Lookup for a Function */
void function_lookup(SymTable *table, Function *func, enum SymbolType type, unsigned int curr_scope, bool isCall) {
    scoped_entries_list *tmp = scope_list_head;
    SymbolTableEntry *tmp_entry = tmp->scope_head;

    if (nameAllowed(func->name) == false) {
        fprintf(stderr, "Error, \"%s\" at line <%d> shadows library function\n", func->name, func->line);
        return;
    }

    /* search the list to find the scope of the func that we want to lookup */
    while (tmp != NULL) {
        if (tmp->scope != curr_scope) {
            tmp = tmp->next;
            continue;
        } else {
            tmp_entry = tmp->scope_head;
            while (tmp_entry != NULL) {
                if (tmp_entry->isActive == false) {
                    tmp_entry = tmp_entry->scope_next;
                    continue;
                }
                if (strcmp(func->name, tmp_entry->value.funcVal->name) == 0) {
                    if (tmp_entry->type == USERFUNC)
                        fprintf(stderr, "Error, redefinition of \"%s\" at line <%d>, previous definition was at line <%d>\n", func->name, func->line, tmp_entry->value.funcVal->line);
                    else
                        fprintf(stderr, "Error, \"%s\" redeclared as different kind of symbol, previous definition was here <%d>\n", func->name, tmp_entry->value.funcVal->line);
                    return;
                }
                tmp_entry = tmp_entry->scope_next;
            }
        }
        tmp = tmp->next;
    }

    if (isCall == false)
        function_insert(table, func, USERFUNC);
}

void formal_lookup(SymTable *table, Variable *var, enum SymbolType type, unsigned int curr_scope) {
    scoped_entries_list *tmp = scope_list_head;
    SymbolTableEntry *tmp_entry = tmp->scope_head;

    while (tmp != NULL) {
        if (tmp->scope != curr_scope) {
            tmp = tmp->next;
            continue;
        } else {
            tmp_entry = tmp->scope_head;
            while (tmp_entry != NULL) {
                if (tmp_entry->isActive == false) {
                    tmp_entry = tmp_entry->scope_next;
                    continue;
                }
                if (strcmp(var->name, tmp_entry->value.varVal->name) == 0) {
                    fprintf(stderr, "Error, redeclaration of formal argument \"%s\"\n", var->name);
                    return;
                }

                tmp_entry = tmp_entry->scope_next;
            }
        }
        tmp = tmp->next;
    }

    if (nameAllowed(var->name) == true) {
        variable_insert(table, var, type);
    } else {
        fprintf(stderr, "Error, redefinition of library function \"%s\" at line <%d>\n", var->name, var->line);
    }
}

int active_function_between_scopes(unsigned int scope_low, unsigned int scope_high) {
    scoped_entries_list *tmp = scope_list_head;
    SymbolTableEntry *tmp_entry = tmp->scope_head;

    // fprintf(stderr, "scopes %d -- %d\n", scope_low, scope_high);

    while (tmp != NULL) {
        tmp_entry = tmp->scope_head;
        if (tmp->scope >= scope_low && tmp->scope <= scope_high) {
            while (tmp_entry != NULL) {
                if (tmp_entry->type == USERFUNC && tmp_entry->isActive == true) {
                    // fprintf(stderr, "active func: %s -- line %d\n", tmp_entry->value.varVal->name, tmp_entry->value.varVal->line);
                    return 1;
                }
                tmp_entry = tmp_entry->scope_next;
            }
        }
        tmp = tmp->next;
    }

    return 0;
}

bool nameAllowed(const char *name) {
    if (strcmp(name, "print") == 0 || strcmp(name, "input") == 0 || strcmp(name, "objectmemberkeys") == 0 || strcmp(name, "objecttotalmembers") == 0 ||
        strcmp(name, "objectcopy") == 0 || strcmp(name, "totalarguments") == 0 || strcmp(name, "argument") == 0 || strcmp(name, "typeof") == 0 ||
        strcmp(name, "strtonum") == 0 || strcmp(name, "sqrt") == 0 || strcmp(name, "cos") == 0 || strcmp(name, "sin") == 0) {
        return false;
    }

    return true;
}

int hide(SymTable *table, unsigned int scope) {
    scoped_entries_list *tmp = scope_list_head;
    bool scope_found = false;
    while (tmp->next != NULL) {
        if (tmp->scope != scope) {
            tmp = tmp->next;
            continue;
        }
        scope_found = true;
        break;
    }

    if (tmp->scope == scope) {
        SymbolTableEntry *entry = tmp->scope_head;
        while (entry != NULL) {
            entry->isActive = false;
            entry = entry->scope_next;
        }
    }
    return scope_found;
}

void print_table_scopes(SymTable *table) {
    scoped_entries_list *head = scope_list_head;
    SymbolTableEntry *st_entry = head->scope_head;
    while (head != NULL) {
        fprintf(stderr, "----------     scope #%d      ----------\n", head->scope);
        st_entry = head->scope_head;
        while (st_entry != NULL) {
            fprintf(stderr, "\"%s\" [%s] (line %d) (scope %d)\n", st_entry->value.funcVal->name, toString(st_entry->type), st_entry->value.funcVal->line, st_entry->value.funcVal->scope);
            st_entry = st_entry->scope_next;
        }

        fprintf(stderr, "\n");
        head = head->next;
    }
}

void print_table_buckets(SymTable *table) {
    SymbolTableEntry *st_entry;
    int i;
    for (i = 0; i < table->buckets; i++) {
        fprintf(stderr, "-------    Bucket#%d    -------\n", i);
        st_entry = table->HashTable[i];
        while (st_entry != NULL) {
            fprintf(stderr, "\"%s\" [%s] (line %d) (scope %d)\n", st_entry->value.funcVal->name, toString(st_entry->type), st_entry->value.funcVal->line, st_entry->value.funcVal->scope);
            st_entry = st_entry->table_next;
        }
    }
}