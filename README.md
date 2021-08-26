A basic Lisp implementation written in C. WIP.

# Usage 

Requires package libedit-dev

```
cc --std=c99 -Wall -g lispy.c mpc.c -ledit -lm -o lispy 
```
```
./lispy
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
lispy> print "hello world!"
"hello world!"
()
lispy> load "hello.lspy"
"Hello, World!"
()
```
# Credits

* Build Your Own Lisp [Book](https://www.amazon.com/Build-Your-Own-Lisp-Programming/dp/1501006622) and [Website](http://www.buildyourownlisp.com/);
* MPC library [Github Page](https://github.com/orangeduck/mpc);
