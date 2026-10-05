%{
#include<stdio.h>
int flag=0;
%}

%token NUMBER

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

ArithmeticExpression: E
{
    printf("Res=%d\n",$$);
    return 0;
}
;

E : E '+' E
    {$$=$1+$3;} | E '-' E  {$$=$1-$3;}| E '*' E  {$$=$1*$3;}  | E '/' E   {$$=$1/$3;}| E '%' E {$$=$1%$3;}| '(' E ')' {$$=$2;}| NUMBER {$$=$1;}
  ;

%%

void main()
{
    printf("\nEnter expression:");
    yyparse();
}

void yyerror()
{
printf("Invalid");
    flag=1;
}
