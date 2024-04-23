%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%%
\/\/(.*) {};
\/\*(.*\n)*.*\*\/ {};
%%

int yywrap() { }
int main()
{
     yyin = fopen("file1.c","r");
     yyout = fopen("file2.c","w");
     yylex();
}
