%{
#include<stdio.h>
void yyerror(char *s);
%}

%token digit

%%
S : L    {$$=$1;printf("decimal value:%d \n",$$);}
L : L B  {$$=2*$1 + $2;}
| B      {$$=$1;}
B : digit{$$=$1;}
;
%%

void main()
{
  printf("\nEnter binary number to be converted\n");
   yyparse();
}

void yyerror(char *s)
{ 
}

