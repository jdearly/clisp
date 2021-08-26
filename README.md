A basic Lisp implementation written in C. WIP.

# Usage 

Requires package libedit-dev

```
cc --std=c99 -Wall -g clispy.c mpc.c -ledit -lm -o clispy 
```
```
./clispy
```
# Examples
```
clispy> +
<function>
clispy> eval (head {5 10 11 15})
5
clispy> eval (head {+ - + - * /})
<function>
clispy> (eval (head {+ - + - * /})) 10 20
30
clispy> print "hello world!"
"hello world!"
()
clispy> load "hello.lspy"
"Hello, World!"
()
```

# Basic Features
- [x] Error handling
- [x] S-Expressions
- [x] Q-Expressions
- [x] Functions
- [x] Variables
- [x] Conditionals
- [x] Strings
- [ ] Standard library

# Future Features
- [ ] Native types
- [ ] User defined types
- [ ] List literals
- [ ] OS interation
- [ ] Macros
- [ ] Variable hashtable
- [ ] Pool allocation
- [ ] Garbage collection
- [ ] Tail call optimization
- [ ] Lexical scoping
- [ ] Static typing
- [ ] Builtin parser (remove MPC)

# Credits

* [Build Your Own Lisp](http://www.buildyourownlisp.com/)
* [MPC](https://github.com/orangeduck/mpc)
