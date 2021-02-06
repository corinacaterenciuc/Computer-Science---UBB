#include <stdlib.h>
#include <stdio.h>
#include "tokens.h"
#include "lex.yy.c"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {};

int main(int argc, char **argv)
{
    ++argv;
    --argc; /* skip over program name */
    if ( argc > 0 )
    yyin = fopen( argv[0], "r" );
    else
     yyin = stdin;
    int ntoken, vtoken;

    ntoken = yylex();
    while(ntoken)
    {
        printf("%d\n", ntoken);
        if(ntoken == -1)
            return 0;
        ntoken = yylex();
    }
    return 0;
}