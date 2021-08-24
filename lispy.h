#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"

struct lval;
struct lenv;

typedef struct lval lval;
typedef struct lenv lenv;

typedef lval*(*lbuiltin)(lenv*, lval*);

enum { LVAL_ERR, LVAL_NUM, LVAL_SYM, LVAL_SEXPR, LVAL_QEXPR, LVAL_FUN };

struct lenv {
    lenv* par;
    int count;
    char** syms;
    lval** vals;
};


typedef struct lval {
    int type;

    // basic
    long num;
    char* err;
    char* sym;

    // function
    lbuiltin builtin;
    lenv* env;
    lval* formals;
    lval* body;

    // expression
    int count;
    struct lval** cell; 
} lval;

lval* lval_lambda(lval* formals, lval* body);
lval* lval_join(lval* x, lval* y);
lval* lval_eval_sexpr(lenv* e, lval* v);
lval* lval_eval(lenv* e, lval* v);
lval* lval_read_num(mpc_ast_t* t);
lval* lval_read(mpc_ast_t* t);
lval* lval_copy(lval* v);
lval* lval_err(char* fmt, ...);
lval* lval_fun(lbuiltin func);
lval* lval_num(long x);
lval* lval_sym(char* s);
lval* lval_sexpr(void); 
lval* lval_qexpr(void);
lval* lval_add(lval* v, lval* x); 
lval* lval_pop(lval* v, int i);             
lval* lval_take(lval* v, int i);
lval* lval_copy(lval* v);
lval* lval_eval(lenv* e, lval* v);
lval* lenv_get(lenv* e, lval* k);
lval* lval_call(lenv* e, lval* f, lval* a); 

lenv* lenv_new(void);
lenv* lenv_copy(lenv* e);

void lval_del(lval* v);
void lval_print(lval* v);
void lval_println(lval* v);
void lval_expr_print(lval* v, char open, char close);
void lenv_del(lenv* e);
void lenv_put(lenv* e, lval* k, lval* v);
void lenv_def(lenv* e, lval* k, lval* v);

char* ltype_name(int t);

// Builtins
lval* builtin_var(lenv* e, lval* a, char* func);
lval* builtin(lenv* e, lval* a, char* func);
lval* builtin_def(lenv* e, lval* a);
lval* builtin_op(lenv* e, lval* a, char* op);
lval* builtin_add(lenv* e, lval* a);
lval* builtin_sub(lenv* e, lval* a);
lval* builtin_mul(lenv* e, lval* a);
lval* builtin_div(lenv* e, lval* a);
lval* builtin_head(lenv* e, lval* a); 
lval* builtin_tail(lenv* e, lval* a);
lval* builtin_list(lenv* e, lval* a);
lval* builtin_eval(lenv* e, lval* a);
lval* builtin_join(lenv* e, lval* a);
lval* builtin_lambda(lenv* e, lval* a);
void lenv_add_builtin(lenv* e, char* name, lbuiltin func);
void lenv_add_builtins(lenv* e);

lval* builtin_gt(lenv* e, lval* a);
lval* builtin_lt(lenv* e, lval* a);
lval* builtin_ge(lenv* e, lval* a);
lval* builtin_le(lenv* e, lval* a); 
lval* builtin_ord(lenv* e, lval* a, char* op);



