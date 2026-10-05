%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i;
%}

%%
[a-zA-Z]+ {
    for(i = 0; i + 2 < yyleng; i++) {
        if (yytext[i] == 'a' && yytext[i+1] == 'b' && yytext[i+2] == 'c') {
            yytext[i] = 'A';
            yytext[i+1] = 'B';
            yytext[i+2] = 'C';
        }
    }
    printf("%s", yytext);
}

.|\n { ECHO; }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}



sdx@pop-os:~/Desktop/CD-lab-main$ lex 8.l
sdx@pop-os:~/Desktop/CD-lab-main$ gcc lex.yy.c
sdx@pop-os:~/Desktop/CD-lab-main$ ./a.out
abc
ABC


