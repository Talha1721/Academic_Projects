#include <gl/glut.h>
#include <math.h>
#include<stdio.h>
#include<conio.h>
#include <iostream>
#include<vector>
#include <bits/stdc++.h>
#define PI 3.141592654

using namespace std;

float m,c;

struct Point {
	int x;
	int y;
};
/*
struct Shape{
    vector<float> x;
    vector<float> y;
};*/
//struct Shape Sh;

Point p1, p2;
//int decision;
void draw_dda() {





    p1.x=100,p1.y=200,p2.x=400,p2.y=400;

    //Sh.x.clear();
    //Sh.y.clear();


	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	//GLfloat dx = p2.x - p1.x;
	//GLfloat dy = p2.y - p1.y;

	GLfloat x1 = p1.x;
	GLfloat y1 = p1.y;
/*
	GLfloat step = 0;

	if (abs(dx) > abs(dy)) {
		step = abs(dx);
	}
	else {
		step = abs(dy);
	}

	GLfloat xInc = dx / step;
	GLfloat yInc = dy / step;
*/
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (float i = 1; i <= 300; i++) {
        //Sh.x.push_back(x1);
        //Sh.y.push_back(y1);

		glVertex2i(x1, y1);

		x1 ++;
		y1 =m*x1+c;
	}
glEnd();

glBegin(GL_LINES);
    glVertex2i(0, 100);
    glVertex2i(900, 100);

	glEnd();

	glBegin(GL_LINES);
    glVertex2i(100, 0);
    glVertex2i(100, 900);

	glEnd();
	glFlush();
}


/*
void myMouseFunc(int button, int state, int x, int y)
{
	int d;
	bool b = 1;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		p1.x = x;
		p1.y = 680 - y;

		cout << x << " " << y << "\n";
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		p2.x = x;
		p2.y = 680 - y;

		cout << x << " " << y << "\n";
		b = 0;
		//draw_dda(p1, p2);
	}
	if (b == 0)
	{


		//draw_dda(p1, p2);
		if (decision == 1)
			draw_dda(p1, p2);
		else if (decision == 2)
		{
			Bresenham_line(p1, p2);
		}
		else if(decision == 3)
		{
			Bresenham_circle(p1, p2);
		}
		else if(decision == 4)
		{
			Midpoint_circle(p1, p2);
		}
		else if(decision == 5)
        {
            //printf("root point before translate func :%d %d AND %d %d\n",p1.x,p1.y,p2.x,p2.y);
            Translate(p1,p2);
        }
        else if(decision == 6)
        {
            Rotate();
        }
        else if(decision == 7)
        {
            Scale();
        }
        else if(decision == 8)
        {
            Box(p1,p2);
        }
        else if(decision == 9)
        {
            Triangle(p1,p2);

        }
        else
        {
            Reflection();
        }
	}

}
*/
void init() {

    glClearColor(0.0, 0.0, 0.0, 0.0);
	//glClearColor(0.0, 0.1, 1.0, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, 740.0f, 0.0f, 680.0f);
}


void display()
{

	glFlush();
}
/*
void mainMenuHandler(int c)
{
	glClear(GL_COLOR_BUFFER_BIT);
	decision = c;
	glutMouseFunc(myMouseFunc);
}
*/
int main(int argc, char** argv) {


	//cout << "What do you want to draw: \n1.Bresenham Line\n2.Bresenham Circle\n3.Midpoint Circle\n4.DDA Line\n";
	//cin >> decision;
    printf("Enter the value of m : ");
    scanf("%f",&m);
    printf("Enter the value of c : ");
    scanf("%f",&c);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(600, 15);
	glutInitWindowSize(740, 680);
	glutCreateWindow("Mouse Func");


	glutDisplayFunc(draw_dda);
	//glutMouseFunc(myMouseFunc);
	init();

	/*glutCreateMenu(mainMenuHandler);
	glutAddMenuEntry("1.DDA Line", 1);
	glutAddMenuEntry("2.Bresenham Line", 2);
	glutAddMenuEntry("3.Bresenham Circle", 3);
	glutAddMenuEntry("4.Midpoint Circle", 4);
	glutAddMenuEntry("5.Translation", 5);
	glutAddMenuEntry("6.Rotation", 6);
	glutAddMenuEntry("7.Scaling", 7);
	glutAddMenuEntry("8.Box", 8);
	glutAddMenuEntry("9.Triangle", 9);
	glutAddMenuEntry("10.Reflection", 10);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	*/
	glutMainLoop();

	//cout << "\n";
	_getch();
	return 0;
}
