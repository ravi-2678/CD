%{
    #include <stdio.h>
    #include <stdlib.h>
    int c= 0,a=0;
%}

%%
[a-zA-Z0-9]+ { if(yytext[0] == 'p' && yyleng==6) 
                          {
                              c++;
                          }
                   }
%%

int yywrap() { }

int main()
{
     yyin = fopen("file1.c","r");
  //  printf("enter a string: ");
     yylex();
     printf("no of print statements : %d" , c);
}
