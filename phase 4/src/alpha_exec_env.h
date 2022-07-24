#ifndef ALPHA_EXEC_ENV_H
#define ALPHA_EXEC_ENV_H

#include <string.h>

#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m))

typedef enum avm_memcell_t {
    number_m = 0,
    string_m = 1,
    bool_m = 2,
    table_m = 3,
    userfunc_m = 4,
    libfunc_m = 5,
    nil_m = 6,
    undef_m = 7
} avm_memcell_t;

struct avm_table;

typedef struct avm_memcell {
    avm_memcell_t type;
    union {
        double numVal;
        char* strVal;
        unsigned char boolVal;
        struct avm_table* tableVal;
        unsigned funcVal;
        char* libfuncVal;
    } data;
} avm_memcell;

avm_memcell program_stack[AVM_STACKSIZE];

static void avm_initstack(void);

#define AVM_TABLE_HASHSIZE 211

typedef struct avm_table_bucket {
    avm_memcell key;
    avm_memcell value;
    struct avm_table_bucket* next;
} avm_table_bucket;

typedef struct avm_table {
    unsigned refCounter;
    avm_table_bucket* strIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket* numIndexed[AVM_TABLE_HASHSIZE];
    unsigned total;
} avm_table;

void avm_tableincrefCounter(avm_table* t);
void avm_tabledecrefCounter(avm_table* t);
void avm_tablebucketsinit(avm_table_bucket** p);

avm_table* avm_tablenew(void);

void avm_memcellclear(avm_memcell* m);
void avm_tablebucketsdestroy(avm_table_bucket** p);
void avm_tabledestroy(avm_table* t);

#endif