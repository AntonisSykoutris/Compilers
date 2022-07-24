#include "alpha_exec_env.h"

#include <assert.h>
#include <stdlib.h>

unsigned ins_total = 0;
unsigned int currInst = 0;

static void avm_initstack(void) {
    int i;
    for (i = 0; i < AVM_STACKSIZE; ++i) {
        AVM_WIPEOUT(program_stack[i]);
        program_stack[i].type = undef_m;
    }
}


void avm_tableincrefCounter(avm_table* t) {
    ++t->refCounter;
}

void avm_tabledecrefCounter(avm_table* t) {
    assert(t->refCounter > 0);
    if (!--t->refCounter)
        avm_tabledestroy(t);
}

void avm_tablebucketsinit(avm_table_bucket** p) {
    for (unsigned i = 0; i < AVM_TABLE_HASHSIZE; ++i)
        p[i] = (avm_table_bucket*)0;
}

avm_table* avm_tablenew(void) {
    avm_table* t = (avm_table*)malloc(sizeof(avm_table));

    AVM_WIPEOUT(*t);

    t->refCounter = t->total = 0;
    avm_tablebucketsinit(t->numIndexed);
    avm_tablebucketsinit(t->strIndexed);

    return t;
}
/* check back after vm construction */
void avm_memcellclear(avm_memcell* m){
    if(m->type != undef_m)
        m->type = undef_m;
}

void avm_tablebucketsdestroy(avm_table_bucket** p) {
    unsigned i;
    for (i = 0; i < AVM_TABLE_HASHSIZE; ++i, ++p) {
        for (avm_table_bucket* b = *p; b;) {
            avm_table_bucket* del = b;
            b = b->next;
            avm_memcellclear(&del->key);
            avm_memcellclear(&del->value);
            free(del);
        }
        p[i] = (avm_table_bucket*)0;
    }
}

void avm_tabledestroy(avm_table* t) {
    avm_tablebucketsdestroy(t->strIndexed);
    avm_tablebucketsdestroy(t->numIndexed);
    free(t);
}