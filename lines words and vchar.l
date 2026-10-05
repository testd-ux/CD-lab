%{
#include <stdio.h>
int lc=0, sc=0, tc=0, ch=0;
%}

%%
\n lc++;    { lc++; }
([ ])+ sc++;    { sc++; }
\t tc++;     { tc++; }
. ch++;       { ch++; }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    printf("no: of lines: %d\n", lc);
    printf("no: of spaces: %d\n", sc);
    printf("no: of tabs: %d\n", tc);
    printf("no: of characters: %d\n", ch);
    return 0;
}



sdx@pop-os:~/Desktop/CD-lab-main$ lex 7.l
sdx@pop-os:~/Desktop/CD-lab-main$ gcc lex.yy.c
sdx@pop-os:~/Desktop/CD-lab-main$ ./a.out
geeks for geeks
no: of lines: 2
no: of spaces: 4
no: of tabs: 0
no: of characters: 26


control + d
