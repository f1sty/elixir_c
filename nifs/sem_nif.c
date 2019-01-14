#include <erl_nif.h>
#include "sem.h"

static ERL_NIF_TERM go_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
    void* priv;
    priv = enif_priv_data(env);
    int ret = go((ErlNifMutex*)priv);

    return(enif_make_int(env, ret));
}

ErlNifFunc nif_funcs[] = {
    {"go", 0, go_nif}
};

int load(ErlNifEnv* caller_env, void** priv_data, ERL_NIF_TERM load_info) {
    priv_data[0] = enif_mutex_create("test_lock");

    return 0;
}

ERL_NIF_INIT(Elixir.Sem, nif_funcs, load, NULL, NULL, NULL)
