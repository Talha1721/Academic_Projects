#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    double xo,xi,xi_1,ea;
    double fxi,f_xi;
    scanf("%lf \n",&xo);
    xi=xo;
    scanf("%lf \n",&a);
    scanf("%lf \n",&b);
    scanf("%lf \n",&c);
    int i;
    for(i=0 ; i<10 ; i++)
    {
        fxi=a*xi*xi+b*xi+c;
        f_xi=2*a*xi+b;
        xi_1=(xi-(fxi/f_xi));
        ea=fabs(((xi_1-xi)/xi_1)*100);

        xi=xi_1;
        if(ea<0.01)
        {
            break;
        }
        printf("Xi : %lf  Ea : %lf\n",xi,ea);


    }

      printf("the root  Xi = %lf ",xi);
}
