#include <erl_nif.h>
#include "sem.h"


int go(ErlNifMutex* mtx) {
    static int c = 0;
    enif_mutex_lock(mtx);
    c+=1;
    enif_mutex_unlock(mtx);
    return(c);
}
