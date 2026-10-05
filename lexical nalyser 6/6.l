%{
#include <stdio.h>
#include <stdlib.h>

int COMMENT = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%

"#".* {
    printf("\n%s is a preprocessor directive", yytext);
}

"int"|"float"|"char"|"double"|"while"|"for"|"struct"|"typedef"|"do"|"if"|"break"|"continue"|"void"|"switch"|"return"|"goto" {
    printf("\n%s is a keyword", yytext);
}

"/*" {
    COMMENT = 1;
    printf("\n%s is a COMMENT", yytext);
}

"*/" {
    COMMENT = 0;
}

"{" {
    if (!COMMENT) printf("\nBLOCK BEGINS");
}

"}" {
    if (!COMMENT) printf("\nBLOCK ENDS");
}

{identifier} {
    if (!COMMENT) printf("\n%s is an IDENTIFIER", yytext);
}

\"[^\"]*\" {
    if (!COMMENT) printf("\n%s is a STRING", yytext);
}

[0-9]+ {
    if (!COMMENT) printf("\n%s is a NUMBER", yytext);
}

"=" {
    if (!COMMENT) printf("\n%s is an ASSIGNMENT OPERATOR", yytext);
}

"(" {
    if (!COMMENT) printf("\n%s is an OPENING BRACKET", yytext);
}

")" {
    if (!COMMENT) printf("\n%s is a CLOSING BRACKET", yytext);
}

"<="|">="|"=="|"<"|">" {
    if (!COMMENT) printf("\n%s is a RELATIONAL OPERATOR", yytext);
}

"+"|"-"|"*"|"/"|"%" {
    if (!COMMENT) printf("\n%s is an OPERATOR", yytext);
}

[ \t\n]+ ;

. ;

%%

int main(void)
{
    FILE *file = fopen("prg2.c", "r");

    if (file == NULL) {
        printf("Could not open the file\n");
        return 1;
    }

    yyin = file;
    yylex();
    fclose(file);

    return 0;
}

int yywrap(void)
{
    return 1;
}
