%{
     int lc=0,sc=0,tc=0,ch=0,c=0,wc=0;
%}

%%
\n { lc++;}
([ ]) {sc++;}
. {ch++,c++;}
[a-zA-Z0-9]+ { wc++; c += yyleng;}
%%

int yywrap() {}
int main() {
     printf("enter a string : ");
     yylex();
     
     printf(" lines count : %d, spaces count : %d, characters count : %d, words count : %d " , lc,sc,c,(wc+ch));
 }
