#include<stdio.h>
#include<math.h>
int main()
{
    long long  num, remainder;
    while(scanf("%lld", &num))
    {
        if(num==0)
        {
            break;
        }
        while(num>9)
        {
            remainder = (num%10);
            num = (num/10);
            num = num+remainder;
        }
        printf("%lld\n", num);
    }
    return 0;
}
