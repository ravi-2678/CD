%{
#include<stdio.h>
int er = 0;
%}
%token NUM '+' '-' '*'
%left '+' '-'
%left '*' 
%%
S : E '\n' 
| E {}
;
E : E '+' T {}
E : E '-' T {}
E :T{}
T : T '*' F{}
T  : F {}
F : NUM { }
;
%%
void main()
{
yyparse();
if(er==0){printf("\n valid syntax\n");
return;}
printf("\n Invalid syntax\n");
}
void yyerror(char *s) {
    er = 1;
}
