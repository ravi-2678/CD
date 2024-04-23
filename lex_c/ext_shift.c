#include <stdio.h>
#include <string.h>
#define null '\0'
struct p 
{
    char left[10];
    char right[10];
};

int main()
{
      char input[20],stack[20],temp[50],ch[2],*token1,*token2,*substring;
      int n,substring_length, stack_length,stack_top;
      struct p rules[10];
      stack[0] = null;
      
      scanf("%d",&n);
      for(int i=0;i<n;i++)
      {
           scanf("%s",&temp);
           token1 = strtok(temp,"->");
           token2 = strtok(NULL, "->");
           strcpy(rules[i].left , token1);
           strcpy(rules[i].right, token2);
      }
      printf("enter input string: ");
      scanf("%s",&input);
      
      int k = 0;
      while(1)
      {
            if(k<strlen(input))
            {
                  ch[0] = input[k];
                  ch[1] = null;
                  k++;
                  strcat(stack,ch);
                  
                  printf("%s \t",stack);
                  for(int i=k; i < strlen(input);i++)
                  printf("%c",input[i]);
                  printf("\t shift %s\n",ch);
                  
                  for(int j=0;j<n;j++)
                  {
                       substring = strstr( stack , rules[j].right);
                       if( substring != NULL )
                       {
                           substring_length = strlen(substring);
                           stack_length = strlen(stack);
                           stack_top = stack_length - substring_length;
                           stack[ stack_top ] = null;
                           
                           strcat( stack , rules[j].left );
                           printf( "%s \t", stack);
                           for(int i=k; i<strlen(input) ; i++)
                           {
                                printf( "%c", input[i] );
                            }
                            printf("\t reduces %s -> %s \n", rules[j].left , rules[j].right );
                            j = -1;
                        }
                   }
               }
               
               if( strcmp( stack, rules[0].left ) == 0 && k == strlen( input ) )
               {
                    printf(" Accepted " );
                    break;
                }
               if( k == strlen( input ) )
               {
                   printf (" not accepted ");
                   break;
                }
        }
 }
                  
                    
         
