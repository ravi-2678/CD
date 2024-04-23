#include <stdio.h>
#include <ctype.h>
#define null '\0'
int n;
char p[10][10];

void add(char res[],char c)
{
    int k;
    for(k=0;res[k]!=null;k++)
    {
        if(res[k]==c) return;
    }
    res[k]=c;
    res[k+1] = null;
}

void FIRST(char *res,char c)
{
    char s[20];
    s[0]=null;
    res[0]=null;
    if( !(isupper(c)))
    {
        add(res,c);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(p[i][0]==c)
        {
            if(p[i][2]=='$') add(res,'$');
            else 
            {
               int j=2;
               while(p[i][j]!=null)
               {
                   FIRST(s,p[i][j]);
                   int f = 0;
                   for(int k=0;s[k]!=null;k++)
                   add(res,s[k]);
                   
                   for(int k=0;s[k]!=null;k++)
                   {
                      if(s[k]=='$')
                      {
                          f=1;
                          break;
                      }
                   }

                   if(f==0) break;
                   else j++;
               }
            }
        }
    }
}

int main()
{
    char res[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",p[i]);
    }

    int ans = 1;
    while(ans)
    {
        char c;
        printf("enter character: ");
        scanf(" %c",&c);
        FIRST(res,c);
        printf("First of %c : {",c);
        for(int i=0;res[i]!=null;i++)
        {
            printf("%c ,",res[i]);
        }
        printf(" }\n");
        printf("press 1-continue, 0-exit: ");
        scanf("%d",&ans);
    }
}