#include<stdio.h>

int main()
{
    char input[20];
    int t=1;
    
    while(scanf("%s",input))                        
    {
        if (input[0] == '*')
		break;	
        if (input[0] == 'H')
            printf("Case %d: Hajj-e-Akbar\n", t);
        else
            printf("Case %d: Hajj-e-Asghar\n", t);
        t++;
    }
  return (0);
}
