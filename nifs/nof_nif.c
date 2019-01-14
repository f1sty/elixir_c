#include <erl_nif.h>
#include <string.h>
#include "nof.h"

static ERL_NIF_TERM nof_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
    char* data = nof();
    ErlNifBinary ret = {
        strlen(data),
        data
    };

    return enif_make_binary(env, &ret);
}

static ErlNifFunc nif_funcs[] = {
    {"nof", 0, nof_nif}
};

ERL_NIF_INIT(Elixir.Nof, nif_funcs, NULL, NULL, NULL, NULL)
