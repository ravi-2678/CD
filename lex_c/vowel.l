%{
   #include <stdio.h>
   int a=0,b=0;
%}

%%
[aeiouAEIOU] {a++;}
[a-zA-Z] {b++;}
%%

int yywrap() {}
int main()
{
     printf("enter a input string: ");
     yylex();
     printf("vowel count : %d \nconsonant count : %d",a,b);
}
