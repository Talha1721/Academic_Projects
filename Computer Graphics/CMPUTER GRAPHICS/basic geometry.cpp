#include<graphics.h>
#include<conio.h>
#include<dos.h>
main ()
{
    int gd,gm;
    gd=DETECT;

    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setcolor(BLUE);
    for(int i=0 ;i<500 ; i++)
    {
        circle(20+i,20,70);
        cleardevice();
        delay(0);

    }


   // bar(400,300,700,600);

    getch();
    closegraph();
    return 0;
}
