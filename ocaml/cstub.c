#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <caml/mlvalues.h>
#include <caml/callback.h>
#include <caml/alloc.h>

char* hello(char* name) {
    static const value* closure = NULL;
    if (closure == NULL)
        closure = caml_named_value("hello");

    return (char*) caml_callback_exn(*closure, caml_copy_string(name));
}

void compile() {
    static const value* closure = NULL;
    if (closure == NULL)
        closure = caml_named_value("compile");

    caml_callback_exn(*closure, Val_unit);
}

char* prove(char* input) {
    static const value* closure = NULL;
    if (closure == NULL)
        closure = caml_named_value("prove");

    return (char*) caml_callback_exn(*closure, caml_copy_string(input));
}

void init() {
    char** argv = malloc(sizeof(char*) * 2);
    *argv = "argv";

    caml_startup(argv);
}
