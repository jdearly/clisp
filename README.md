A basic Lisp implementation written in C. WIP.

# Usage 
```
cc --std=c99 -Wall -g functions.c mpc.c -ledit -lm -o lispy 
```
```
./variables
```
# Examples
```
lispy> +
<function>
lispy> eval (head {5 10 11 15})
5
lispy> eval (head {+ - + - * /})
<function>
lispy> (eval (head {+ - + - * /})) 10 20
30
lispy> hello
Error: unbound symbol!
lispy>
```

