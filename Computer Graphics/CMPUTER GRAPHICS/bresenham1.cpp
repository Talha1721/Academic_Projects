

/*

#include<stdio.h>
#include<graphics.h>

void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;

	dx=x1-x0;
	dy=y1-y0;

	x=x0;
	y=y0;

	p=2*dy-dx;

	while(x<x1)
	{
		if(p>=0)
		{
			putpixel(x,y,10);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			putpixel(x,y,10);
			p=p+2*dy;
		}
		x=x+1;
	}
}

int main()
{
	int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

	printf("Enter co-ordinates of first point: ");
	scanf("%d%d", &x0, &y0);

	printf("Enter co-ordinates of second point: ");
	scanf("%d%d", &x1, &y1);
	drawline(x0, y0, x1, y1);


	getch();
	closegraph();
	return 0;

	return 0;
}


*/














#include<graphics.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int gd,gm,x,y,end,p,x1,x2,y1,y2,dx,dy;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"C://TurboC3//BGI");

    printf("Enter the value of x1 : ");
    scanf("%d",&x1);
    printf("Enter the value of y1 : ");
    scanf("%d",&y1);
    printf("Enter the value of x2 : ");
    scanf("%d",&x2);
    printf("Enter the value of y2 : ");
    scanf("%d",&y2);

    //line(x1,y1,x2,y2);
    line(200,0,200,400);
    line(0,200,400,200);

    dx=abs(x1-x2);
    dy=abs(y1-y2);

    if(dx>dy)
    {
        p = 2*dy-dx;

        if(x1>x2)
        {
            x=x2;
            y=y2;
            end=x1;
        }
        else
        {
            x=x1;
            y=y1;
            end=x2;
        }
        putpixel(200+x,200-y,WHITE);

        while(x<=end)
        {
            if(p<0)
            {
                //x++;
                x=x+2;
                p=p+2*dy;
            }
            else
            {
                //x++;
                x=x+2;
                //y++;
                y=y+2;
                p=p+2*(dy-dx);
            }
            putpixel(200+x,200-y,WHITE);
            delay(100);
        }
        getch();
        closegraph();
        return 0;
    }
    else
    {
        p = 2*dx-dy;

        if(x1>x2)
        {
            x=x2;
            y=y2;
            end=x1;
        }
        else
        {
            x=x1;
            y=y1;
            end=x2;
        }
        putpixel(200+x,200-y,WHITE);

        while(x<=end)
        {
            if(p<0)
            {
                //y++;
                y=y+2;
                p=p+2*dx;
            }
            else
            {
                //x++;
                //y++;
                x=x+2;
                y=y+2;

                p=p+2*(dx-dy);
            }
            putpixel(200+x,200-y,WHITE);
            delay(100);
        }
        getch();
        closegraph();
        return 0;
    }
}




