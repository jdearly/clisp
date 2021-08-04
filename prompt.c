#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

void add_history(char* unused) {}

#else
#include <editline/readline.h>
#endif

int main(int argc, char** argv) {

    // Version and Exit information 
    puts("clisp Version 0");
    puts("Press Ctrl+c to Exit\n");

    // infinite loop
    while(1) {
        // the prompt
        char* input = readline("clisp> "); 

        // Add input to history
        add_history(input);

        // Echo back
        printf("No you're a %s\n", input);

        // Free retrieved input
        free(input);
    }

    return 0;
}
