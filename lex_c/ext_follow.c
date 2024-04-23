#include <stdio.h>
#include <string.h>
#define null '\0'
int n,m;
char p[10][10],f[10];

void add(char c)
{
	for(int i=0;i<=m;i++)
	{
		if(f[i]==c) return;
	}
	f[m++] = c;
}

void first(char c)
{
	if(!(isupper(c))) add(c);
	for(int i=0;i<n;i++)
	{
		if(p[i][0] == c)
		{
			if(p[i][2] == '$') FOLLOW(p[i][0]);
			else if ( islower(p[i][2])) add(p[i][2]);
			else first(p[i][2]);
		}
	}
}
void FOLLOW(char c)
{
	if(p[0][0]==c) add('$');
	for(int i=0;i<n;i++)
	{
		for(int j=2;j<strlen(p[i]);j++)
		{
			if(p[i][j]==c)
			{
				if(p[i][j+1] !=null) first(p[i][j+1]);
				else if(p[i][j+1] == null) FOLLOW(p[i][0]);
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%s",&p[i]);
    
    int ans = 1;
    while(ans)
    {
        m = 0;
        printf("enter char: ");
        char c;
        scanf(" %c",&c);
        FOLLOW(c);
        printf("follow of %c --> ",c);

        for(int i=0;i<m;i++)
        {
        	printf("%c ",f[i]);
        }
        printf("\ncontinue (0/1): ");
        scanf("%d",&ans);
    }
}