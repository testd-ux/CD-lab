%{
#include <stdio.h>
int vow = 0; 
int con = 0;
%}

%%
[aeiouAEIOU] { vow++; }
[a-zA-Z]     { con++; }
.|\n         ; 
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter string: \n");
    yylex();
    printf("Total vowels: %d\n", vow);
    printf("Total consonants: %d\n", con);
    return 0;
}



sdx@pop-os:~/Desktop/CD-lab-main$ lex 9.l
sdx@pop-os:~/Desktop/CD-lab-main$ gcc lex.yy.c
sdx@pop-os:~/Desktop/CD-lab-main$ ./a.out
Enter string: 
VTU dhbhfb ydfwjygvfs
Total vowels: 1
Total consonants: 18


control + d
