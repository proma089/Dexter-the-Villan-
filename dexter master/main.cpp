#include<windows.h>
#include <glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include<vector>
#include <string>
#include <stdio.h>
#define PI 3.1416
using namespace std;
static float	pa[6];
static float	pb[6];
static float	dx	=  -15.0;
static float	dy	=  -15.0;
static float  moveEnemyX[6];
static float  moveEnemyY[6];
static int countPower = 0;
static int score = 0;
static bool specialPower = false;
static float extraPower = 35.0f;
static float extraPowerUp = 35.0f;

static int r = rand();
static float s = 0.01;

//text display
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_HELVETICA_18 ;
const int font3=(int)GLUT_BITMAP_8_BY_13;

/* GLUT callback Handlers */
void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);{
    glVertex3f( a, 0,2);
    glVertex3f( a,-a,2);
    glVertex3f(-a,-a,2);
    glVertex3f(-a, 0,2);
    }glEnd();
}
void circle(float radius_x, float radius_y,int circleSize)
{
	int i = 0;
	float angle = 30.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < circleSize; i++)
		{

			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();
}
void drawCircle(float radius_x, float radius_y)
{
    int i = 0;
    float angle = 0.0;

        glBegin(GL_POLYGON);
            {
                for(i = 0; i < 100; i++)
                {
                angle = 2 * 3.1416 * i / 100;
                glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
                }

            }

    glEnd();
}
void  circleMaker(float ra,float ta, float tb, float ca, float cb, float cc, float cra, float crb ,float angle)
{
    glPushMatrix();
    glRotatef(ra,0.0f,0.0f,1.0f);
    glTranslatef(ta,tb,0.0f);
    glColor3f(ca,cb,cc);
    circle(cra, crb, angle);
    glPopMatrix();
}



void gun()
{

    glPushMatrix();
        glColor3d(1,1,1);
        drawCircle(30,14);
    glPopMatrix();

    glPushMatrix();
        glColor3d(0.7f,0.2f,0.4f);
        glTranslated(27,0,0);
        drawCircle(8,13);
    glPopMatrix();

     glPushMatrix();
        glColor3d(0,0.5,1);
        glTranslated(21,0,0);
        drawCircle(8,15);
    glPopMatrix();

    glPushMatrix();
        glColor3d(1,1,1);
        glTranslated(10,0,0);
        drawCircle(8,13);
    glPopMatrix();



    glPushMatrix();
        glColor3d(0,0,0);
        glTranslated(-2,6,0);
        glScaled(8,1.5,1);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();
        glColor3d(0,0,0);
        glTranslated(-2,0,0);
        glScaled(6,1.4,1);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();
        glColor3d(0,0,0);
        glTranslated(-2,-6,0);
        glScaled(4,1.3,1);
        drawSquare(2);
    glPopMatrix();




    glPushMatrix();
        glColor3d(0, 0, 0.4);
        glTranslated(40,3.5,0);
        glScaled(3,2,1);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(48,1,0);
        drawCircle(3.2,3.2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-15,-37,0);
        glRotated(90,0,0,1);
        glScaled(5,2,1);
        glColor3f(0.52f,0.12f,0.484f);
        glBegin(GL_POLYGON);
             glVertex2f(0.0f, 0.0f);
             glVertex2f(5.0f, 0.0f);
             glVertex2f(2.5f, -5.0f);

        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3d(1,1,1);
        glTranslated(-6,-13,0);
        glScaled(2,12,1);
        drawSquare(2);
    glPopMatrix();

        glPushMatrix();
            glTranslated(-4,-18,0);
            glScaled(4,3,1);
            glColor3f(0.52f,0.12f,0.484f);
            drawCircle(1,1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-4,-24,0);
            glScaled(4,3,1);
            glColor3f(0.52f,0.12f,0.484f);
            drawCircle(1,1);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-4,-30.5,0);
            glScaled(4,3,1);
            glColor3f(0.52f,0.12f,0.484f);
            drawCircle(1,1);
        glPopMatrix();
}

void eye()
{

    circleMaker(180.0f, -4.5f, -4.5f, 0.0f, 0.0f, 0.0f, 3.0f, 4.0f, 50.0f);     //Outer Right Black eye
    circleMaker(180.0f, 0.5f, -4.5f, 0.0f, 0.0f, 0.0f, 3.0f, 4.0f, 50.0f);    //Outer Left Black eye
    circleMaker(180.0f, 0.6f, -4.0f, 0.484f, 0.781f, 0.914f, 2.5f, 3.0f, 50.0f);   //Inner Right Light Sky eye
    circleMaker(180.0f, -4.6f, -4.0f, 0.484f, 0.781f, 0.914f, 2.5f, 3.0f, 50.0f);  //Inner Left Light Sky eye
    circleMaker(180.0f, 0.5f, -4.5f, 0.0f, 0.0f, 0.0f, 1.5f, 1.5f, 50.0f);       //Inner Right Black eye
    circleMaker(180.0f, -4.5f, -4.5f, 0.0f, 0.0f, 0.0f, 1.5f, 1.5f, 50.0f);      //Inner Left Black eye

}

void quadMaker(float ta, float tb, float ca, float cb, float cc, float ba, float bb )
{
     glPushMatrix();
        glTranslatef(ta,tb,0.0f);
        glBegin(GL_QUADS);
             glColor3f(ca,cb,cc);
            glVertex2f(ba, bb);
            glVertex2f(ba, -bb);
            glVertex2f(-ba, -bb);
            glVertex2f(-ba, bb);
        glEnd();
    glPopMatrix();
}

void bullet(){
  glPushMatrix();{
    glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(-6,8,0);
        glBegin(GL_POLYGON);
                glVertex2f(0, 0);
                glVertex2f(12, 0);
                glVertex2f(6, 5);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3d(1,0,0);
        drawCircle(10,10);
    glPopMatrix();

    glPushMatrix();
        glColor3d(1,0,0);
        glScaled(2,7,1);
        drawSquare(5);
    glPopMatrix();

    glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(-18,-30.0,0);
        glBegin(GL_POLYGON);
                glVertex2f(0, 0);
                glVertex2f(8, 0);
                glVertex2f(8, 15);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glColor3d(1,0,0);
        glTranslated(-14,-30,0);
        glRotated(25,0,1,0);
        glScaled(1.3,2.5,1);
        drawSquare(4);
    glPopMatrix();


    glPushMatrix();
            glColor3d(1,0,0);
            glTranslated(18,-30.0,0);
            glRotated(180,0,1,0);
            glBegin(GL_POLYGON);
                    glVertex2f(0, 0);
                    glVertex2f(8, 0);
                    glVertex2f(8, 15);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glColor3d(1,0,0);
            glTranslated(12.5,-29.0,0);
            glRotated(160,0,1,0);
            glScaled(2,4,1);
            drawSquare(2.5);
    glPopMatrix();



    glPushMatrix();
            glColor3d(1,0,0);
            glTranslated(2,-32,0);
            glRotated(-50,0,1,0);
            glScaled(2.2,3,1);
            drawSquare(2.5);
    glPopMatrix();

  }
  glPopMatrix();
}

void dexter()
{
    //shirt
    quadMaker(0.0f, -4.0f, 0.0f, 0.0f, 0.0f, 4.5f, 3.5f);  //black
    quadMaker(0.0f, -4.0f, 1.0f, 1.0f, 1.0f, 4.0f, 3.0f);   //white
    quadMaker(2.5f, -4.0f, 0.0f, 0.0f, 0.0f, 0.1f, 3.0f);   //line
    circleMaker(0.0f, 2.0f, -5.0f, 0.0f, 0.0f, 0.0f, 0.25f, 0.8f, 100.0f);  //circle

    //hand

    //left arm
    glPushMatrix();
        glTranslatef(-2.55f,-2.5f,0.0f);
        glScaled(.3,1.2,1);
        glColor3f(0.0f, 0.0f, 0.0f);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2.55f,-2.5f,0.0f);
        glScaled(.2,1.15,1);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawSquare(2);
    glPopMatrix();
//Black hand
    glPushMatrix();
        glTranslatef(-2.3f,-5.5f,0.0f);
        glRotated(100,0,1,1);
        glScaled(.83,0.53,1);
        glColor3f(0.0f,0.0f,0.0f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.0f,-5.5f,0.0f);
        glRotated(-100,0,1,1);
        glScaled(.83,0.53,1);
        glColor3f(0.0f,0.0f,0.0f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2.6f,-5.9f,0.0f);
        glScaled(.33,0.83,1);
        glColor3f(0.0f,0.0f,0.0f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.4f,-4.2f,0.0f);
        glScaled(0.38,0.36,1);
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_POLYGON);
             glVertex2f(0.0f, 0.0f);
             glVertex2f(5.0f, 0.0f);
             glVertex2f(2.5f, -5.0f);

        glEnd();
    glPopMatrix();
//purple hand
    glPushMatrix();
        glTranslatef(-2.0f,-5.5f,0.0f);
        glRotated(100,0,1,1);
        glScaled(.82,0.52,1);
        glColor3f(0.52f,0.12f,0.484f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.0f,-5.5f,0.0f);
        glRotated(-100,0,1,1);
        glScaled(.80,0.49,1);
        glColor3f(0.52f,0.12f,0.484f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2.5f,-5.9f,0.0f);
        glScaled(.29,0.80,1);
        glColor3f(0.52f,0.12f,0.484f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.4f,-4.2f,0.0f);
        glScaled(0.34,0.32,1);
        glColor3f(0.52f,0.12f,0.484f);
        glBegin(GL_POLYGON);
             glVertex2f(0.0f, 0.0f);
             glVertex2f(5.0f, 0.0f);
             glVertex2f(2.5f, -5.0f);

        glEnd();
    glPopMatrix();

    //********BULLET**********
  /*  glPushMatrix();
        glTranslatef(20.4f,7.2f,0.0f);
        glRotated(-90,0,0,1);
        glScaled(0.09,0.09,1);
        bullet();
    glPopMatrix();*/

//Right arm
    glPushMatrix();
        glTranslatef(5.3f,-1.8f,0.0f);
        glScaled(0.6,0.75,1);
        glColor3f(0.0f, 0.0f, 0.0f);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(5.4f,-2.0f,0.0f);
        glScaled(0.45, 0.55,1);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawSquare(2);
    glPopMatrix();
//Black hand
    glPushMatrix();
        glTranslatef(-2.3f,-5.5f,0.0f);
        glRotated(100,0,1,1);
        glScaled(.83,0.53,1);
        glColor3f(0.0f,0.0f,0.0f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.0f,-5.5f,0.0f);
        glRotated(-100,0,1,1);
        glScaled(.83,0.53,1);
        glColor3f(0.0f,0.0f,0.0f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2.6f,-5.9f,0.0f);
        glScaled(.33,0.83,1);
        glColor3f(0.0f,0.0f,0.0f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.4f,-4.2f,0.0f);
        glScaled(0.38,0.36,1);
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_POLYGON);
             glVertex2f(0.0f, 0.0f);
             glVertex2f(5.0f, 0.0f);
             glVertex2f(2.5f, -5.0f);

        glEnd();
    glPopMatrix();
//purple hand
    glPushMatrix();
        glTranslatef(-2.0f,-5.5f,0.0f);
        glRotated(100,0,1,1);
        glScaled(.82,0.52,1);
        glColor3f(0.52f,0.12f,0.484f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.0f,-5.5f,0.0f);
        glRotated(-100,0,1,1);
        glScaled(.80,0.49,1);
        glColor3f(0.52f,0.12f,0.484f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-2.5f,-5.9f,0.0f);
        glScaled(.29,0.80,1);
        glColor3f(0.52f,0.12f,0.484f);
        drawCircle(1,1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-3.4f,-4.2f,0.0f);
        glScaled(0.34,0.32,1);
        glColor3f(0.52f,0.12f,0.484f);
        glBegin(GL_POLYGON);
             glVertex2f(0.0f, 0.0f);
             glVertex2f(5.0f, 0.0f);
             glVertex2f(2.5f, -5.0f);

        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(7.8f,0.3f,0.0f);
        glScaled(0.12,0.12,1);
        glColor3f(0.52f,0.12f,0.484f);
        gun();

        glPushMatrix();
            glColor3d(0,0,0);
            glTranslated(-2,6,0);
            glScaled(8,1.5,1);
            drawSquare(2);
        glPopMatrix();

        glPushMatrix();
            glColor3d(0,0,0);
            glTranslated(-2,0,0);
            glScaled(6,1.4,1);
            drawSquare(2);
        glPopMatrix();

        glPushMatrix();
            glColor3d(0,0,0);
            glTranslated(-2,-6,0);
            glScaled(4,1.3,1);
            drawSquare(2);
        glPopMatrix();

    glPopMatrix();

    //face
    quadMaker(0.5f, 4.0f, 0.992f, 0.886f, 0.852f, 5.0f, 3.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-4.85f,0.0f);
    glVertex2f(-4.85f,1.0f);
    glVertex2f(5.5f,1.5f);
    glVertex2f(0.5f,-3.9f);
    glEnd();

    circleMaker(15.0f, .6f, 0.0f, 0.992f, 0.886f, 0.852f, 5.0f, -4.0f, 30.0f);
    //head
    circleMaker(0.0f, 1.0f, 8.0f, 0.0f, 0.0f, 0.0f, -6.0f, 3.0f, 100);
    circleMaker(0.0f, 1.0f, 8.0f, 0.91f, 0.453f, 0.0898f, -5.5f, 2.5f, 100);

    //eye
    eye();

    //sunglass handle
    glBegin(GL_POLYGON);

    glVertex2f(-3.0f,3.0f);
    glVertex2f(-3.0f,4.0f);
    glVertex2f(-5.5f,1.0f);
    glVertex2f(-5.5f,1.5f);
    glEnd();


//ear
  //  circleMaker(0.0f, 5.0f, 1.0f, 0.992f, 0.886f, 0.852f, .5f, 1.0f, 100);
    circleMaker(0.0f, -4.8f, 1.0f, 0.992f, 0.886f, 0.852f, .5f, 1.0f, 100);



//nose

//outer black
       glPushMatrix();
        glTranslatef(0.5f,0.0f,0.0f);
        glBegin(GL_POLYGON);

            //glColor3f(1.0f, 1.0f, 1.0f);
            glColor3f(0.0f, 0.0f, 0.0f);

            glVertex2f(1.0f, -.2f);
            glVertex2f(0.9f, -1.0f);
            glVertex2f(0.1f, -0.1f);
            glVertex2f(0.1f, 0.6f);
            glVertex2f(1.8f, 1.3f);

        glEnd();
    glPopMatrix();

//inner skin color
    glPushMatrix();
        glTranslatef(0.5f,0.0f,0.0f);
        glBegin(GL_POLYGON);
           glColor3f(0.992f,0.886f,0.852f);
           // glColor3f(1.0f, 0.0f, 0.0f);

            glVertex2f(0.8f, 0.0f);
            glVertex2f(0.8f, -0.8f);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(0.2f, 0.5f);
            glVertex2f(1.5f, 1.0f);

        glEnd();
    glPopMatrix();

//leg
     glPushMatrix();
        glTranslatef(0.0f,-7.0f,0.0f);
        glBegin(GL_POLYGON);
           glColor3f(0.0f,0.0f,0.0f);
           // glColor3f(1.0f, 0.0f, 0.0f);

            glVertex2f(-3.0f, 0.0f);
            glVertex2f(-5.0f, -5.0f);
            glVertex2f(-1.0f, -3.0f);
            glVertex2f(-2.2f, -5.0f);
            glVertex2f(0.0f, -4.0f);
            glVertex2f(0.0f, 0.0f);

             glVertex2f(3.0f, 0.0f);
            glVertex2f(5.0f, -5.0f);
            glVertex2f(2.0f, -3.0f);
            glVertex2f(2.2f, -5.0f);
            glVertex2f(0.0f, -4.0f);
            glVertex2f(0.0f, 0.0f);

        glEnd();
    glPopMatrix();


}
void enemy(){

   //hand
   //left side sholder
    glPushMatrix();
    glTranslatef(-3.8f, -3.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(1.0f, 1.0f, 0.8f);
            glVertex2f(2.0f,-4.0f);
            glVertex2f(0.0f,-4.0f);
            glVertex2f(0.0f,-0.0f);
            glVertex2f(2.0f,-0.0f);
        glEnd();
    glPopMatrix();
  //left hand
      glPushMatrix();
    glTranslatef(-3.8f, -9.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(1.0f, 0.8f, 0.6f);
            glVertex2f(0.0f, 2.0f);
            glVertex2f(0.0f, -4.0f);
            glVertex2f(0.3f, -3.0f);
            glVertex2f(0.5f, -4.0f);
            glVertex2f(0.8f, -3.0f);
            glVertex2f(1.1f, -4.0f);
            glVertex2f(1.4f, -3.0f);
            glVertex2f(1.7f, -4.0f);
            glVertex2f(1.7f, 2.0f);
        glEnd();
    glPopMatrix();
//right sholder
     glPushMatrix();
    glTranslatef(2.8f, -3.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(1.0f, 1.0f, 0.8f);
            glVertex2f(2.0f,-4.0f);
            glVertex2f(0.0f,-4.0f);
            glVertex2f(0.0f,-0.0f);
            glVertex2f(2.0f,-0.0f);
        glEnd();
    glPopMatrix();
//right hand
     glPushMatrix();
    glTranslatef(3.1f, -9.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(1.0f, 0.8f, 0.6f);
            glVertex2f(0.0f, 2.0f);
            glVertex2f(0.0f, -4.0f);
            glVertex2f(0.3f, -3.0f);
            glVertex2f(0.5f, -4.0f);
            glVertex2f(0.8f, -3.0f);
            glVertex2f(1.1f, -4.0f);
            glVertex2f(1.4f, -3.0f);
            glVertex2f(1.7f, -4.0f);
            glVertex2f(1.7f, 2.0f);
        glEnd();
    glPopMatrix();
 //neck
    quadMaker(0.5f, -3.0f, 0.0f, 0.0f, 0.0f, 0.3f, 0.3f);
    quadMaker(0.5f, -3.0f, 0.691f, 0.546f, 0.05f, 0.2f, 0.2f);
//face
    glPushMatrix();
        glBegin(GL_POLYGON);
            glColor3f(0.3f, 0.3f, 0.3f);

            glVertex2f(2.8f, -1.5f);
            glVertex2f(2.8f, -0.5f);
            glVertex2f(2.8f, -0.5f);
            glVertex2f(-1.8f, 0.0f);
            glVertex2f(0.0f, -2.8f);


        glEnd();
    glPopMatrix();
    quadMaker(0.5f, 1.0f, 1.0f, 0.8f, 0.6f, 2.3f, 1.5f);
    circleMaker(180.0f, 0.0f, 0.0f, 0.3f, 0.3f, 0.3f, 1.8f, 2.8f, 30.0f);
    circleMaker(-100.0f, 1.0f, 0.2f, 0.3f, 0.3f, 0.3f, 1.8f, 2.8f, 30.0f);
//head
    glPushMatrix();
    glTranslatef(-1.8f, 2.5f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.0f, 0.0f, 0.0f);

            glVertex2f(-0.1f, 0.0f);
            glVertex2f(0.5f, 1.5f);
            glVertex2f(1.0f, 0.0f);
            glVertex2f(1.5f, 1.5f);
            glVertex2f(2.0f, 0.0f);
            glVertex2f(2.5f, 1.5f);
            glVertex2f(3.0f, 0.0f);
            glVertex2f(3.5f, 1.5f);
            glVertex2f(4.0f, 0.0f);
            glVertex2f(4.5f, 1.5f);
            glVertex2f(4.7f, 0.0f);
        glEnd();
    glPopMatrix();

//eye
     circleMaker(0.0f, -0.8f, 1.0f, 1.0f, 1.0f, 1.0f, 0.4f, 0.3f, 100.0f);
     circleMaker(0.0f, 0.8f, 1.0f, 1.0f, 1.0f, 1.0f, 0.4f, 0.3f, 100.0f);
     circleMaker(0.0f,-0.8f, 1.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 100.0f);
     circleMaker(0.0f, 0.8f, 1.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.2f, 100.0f);
//mouth
     circleMaker(180.0f, -.2f, 1.0f, 0.0f, 0.0f, 0.0f, 1.5f, 1.5f, 50.0f);
     circleMaker(0.0f, .2f, -2.1f, 1.0f, 0.31f, 0.31f, 1.0f, 0.2f, 100.0f);

 //body
    glPushMatrix();
    glTranslatef(-2.0f, -3.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(1.0f, 1.0f, 0.8f);

            glVertex2f(0.0f, 0.0f);
            glVertex2f(5.0f, 0.0f);
            glVertex2f(5.0f, -10.0f);
            glVertex2f(0.0f, -10.0f);

        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.2f, 0.4f);
        glVertex2d(1.6,0.0);
        glVertex2d(3.4,0.0);
        glVertex2d(2.5,-2.0);

        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.2f, 0.4f);
        glVertex2d(2.5,-1.5);
        glVertex2d(1.4,-7.0);
        glVertex2d(3.6,-7.0);

        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.2f, 0.4f);
        glVertex2d(1.4,-7.0);
        glVertex2d(3.6,-7.0);
        glVertex2d(2.5,-9.0);

        glEnd();
    glPopMatrix();
//leg
//left leg
    glPushMatrix();
    glTranslatef(-2.0f, -13.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.0f, 0.2f, 0.4f);
            glVertex2f(0.0f, -8.0f);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(3.0f, 0.0f);
            glVertex2f(1.0f, -10.0f);
            glVertex2f(-2.0f, -10.0f);
            glVertex2f(-1.0f, -8.0f);
        glEnd();
    glPopMatrix();
// right leg
    glPushMatrix();
    glTranslatef(2.0f, -13.0f, 0.0f);
        glBegin(GL_POLYGON);
            glColor3f(0.0f, 0.2f, 0.4f);
            glVertex2f(0.0f, -8.0f);
            glVertex2f(-2.0f, 0.0f);
            glVertex2f(1.0f, 0.0f);
            glVertex2f(1.0f, -10.0f);
            glVertex2f(-2.0f, -10.0f);
            glVertex2f(-1.0f, -8.0f);
        glEnd();
    glPopMatrix();


}
void building(float ca, float cb, float cc)
{
    //full building
    quadMaker(0.0f, 0.0f, ca, cb, cc, 2.0, 6.0f);
    //window
    quadMaker(1.0f, 5.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, 5.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, 3.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(1.0f, 3.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(1.0f, -3.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, -3.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(1.0f, -5.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
    quadMaker(-1.0f, -5.0f, 1.0f, 1.0f, 0.0f, 0.5f, 0.5f);
}
void buildingBuild(float angle, float ra, float rb, float ta, float tb, float sa, float sb)
{
    float ca1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float cb1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float cc1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    glPushMatrix();

    glTranslatef(ta, tb, 0.0f);
    glRotatef(angle, ra, rb, 0.0f);
    glScalef(sa, sb, 0.0f);
    building(ca1, cb1, cc1);
    glPopMatrix();
}

void viewBuilding()
{
    buildingBuild(0.0f, 0.0f, 0.0f, -18.0f, 10.0f, 1.0f, 1.0f);
    buildingBuild(0.0f, 0.0f, 0.0f, -13.8f, 13.0f, 0.8f, 1.5f);
    buildingBuild(40.0f, 0.0f, 1.0f, -10.0f, 10.0f, 1.0f, 1.0f);
    buildingBuild(40.0f, 1.0f, 0.0f, -6.0f, 8.55f, 1.0f, 1.0f);
    buildingBuild(0.0f, 0.0f, 0.0f, -1.5f, 11.2f, 1.0f, 1.2f);
    buildingBuild(0.0f, 0.0f, 0.0f, 3.0f, 10.0f, 1.0f, 1.0f);
    buildingBuild(40.0f, 1.0f, 0.0f, 7.5f, 8.55f, 1.0f, 1.0f);
    buildingBuild(40.0f, 0.0f, 1.0f, 11.5f, 10.0f, 1.0f, 1.0f);
    buildingBuild(40.0f, 0.0f, 1.0f, 15.0f, 10.0f, 1.0f, 1.0f);
    buildingBuild(0.0f, 0.0f, 0.0f, 18.5f, 11.8f, 0.7f, 1.3f);
}

void road(){
    //gray color road
    quadMaker(0.0f, 1.5f, 0.41f, 0.41f, 0.41f, 20.0f, 5.0f);
    //white strap
    quadMaker(-19.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-16.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-13.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-10.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-7.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-4.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(-1.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(2.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(5.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(8.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(11.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(14.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(17.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
    quadMaker(20.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.2f);
}
void superPower()
{
    for(int i = 0; i < 6; i++)
    {
        pa[i] = 25.0f;
        pb[i] = 0.0f;
        moveEnemyX[i] = ((float)rand() / RAND_MAX) * 50 ;
        moveEnemyY[i] =  ((float)rand() / RAND_MAX) * 25 -10;
        //cout << moveEnemyY[i] << endl;
    }
    extraPower = 35.0f;
    extraPowerUp = 35.0f;
    specialPower = false;
    glutPostRedisplay();
}

void pointsMany(int num)
{
    //white color
    glPointSize(2);

    glBegin(GL_POINTS);
        for(int i = 0;i<num;i++)
        {
            glVertex2f((i*13)%31,(i*31)%39);//Random position

        }
    glEnd();
}

void endGame()
{

    float c1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float c2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float c3 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

glPushMatrix(); {
    for(int i=0; i<=5000; i+=1){
     glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(50,20,0);
        glScaled(2,100,0);
        drawSquare(500);
     glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0,0);
     glPushMatrix();                     //G
        glTranslatef(-10,15,0);
        glScaled(1,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-11.6,14,0);
        glScaled(.2,2.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-10,10,0);
        glScaled(1,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-8.4,12,0);
        glScaled(.2,1,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-9,12,0);
        glScaled(.5,.3,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();                     //A
        glTranslatef(-6,12.5,0);
        glScaled(.68,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-7,15,0);
        glScaled(.2,3,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-4.2,15,0);
        glScaled(.2,3,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-6,15,0);
        glScaled(.68,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();                 //M
        glTranslatef(-3,15,0);
        glScaled(.2,3,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(.6,15,0);
        glScaled(.2,3,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.6,14,0);
        glRotatef(-45,0,0,1);
        glScaled(.68,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-.8,14,0);
        glRotatef(45,0,0,1);
        glScaled(.68,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();                     //E
        glTranslatef(3.8,15,0);
        glScaled(1,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(2.2,14,0);
        glScaled(.2,2.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(3.9,12.5,0);
        glScaled(.6,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(3.8,10,0);
        glScaled(1,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(2,-1,0);
    glScaled(1.1,1.1,0);
    glPushMatrix();                 //O
        glTranslatef(-12,-1,0);
        glScaled(.2,2.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-11,-1,0);
        glScaled(.7,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-9.5,-1,0);
        glScaled(.2,2.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-10.78,-5.5,0);
        glScaled(.82,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();                 //V
        glTranslatef(-8,-1,0);
        glRotatef(16,0,0,1);
        glScaled(.2,2.8,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-4.6,-1,0);
        glRotatef(-16,0,0,1);
        glScaled(.2,2.8,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();                     //E
        glTranslatef(-1.8,-1,0);
        glScaled(1,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-3.4,-1.4,0);
        glScaled(.2,2.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.8,-3.5,0);
        glScaled(.6,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.8,-5.7,0);
        glScaled(1,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();                     //R
        glTranslatef(1.3,-1,0);
        glScaled(.2,2.8,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(2.3,-1,0);
        glScaled(.7,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(3.3,-1.9,0);
        glScaled(.2,1,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(2.3,-3.5,0);
        glScaled(.7,.5,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2.75,-4.3,0);
        glRotatef(20,0,0,1);
        glScaled(.2,1.3,0);
        glColor3f(c1,c2,c3);
        drawSquare(2);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    }
}
glPopMatrix();
}

void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

static void display(void)
{

    for(int i = 0; i < 5; i++)
    {
        if(pa[i] <=25.0f && pa[i] >= -20.0f)
    {
        for(int j = 0; j < 6; j++)
        {
            if((pa[i]+4.5) >= moveEnemyX[j] && (pb[i]) <= moveEnemyY[j] && pb[i] >= (moveEnemyY[j]-7))
            {
                moveEnemyX[j] = 22.0f;
                pa[i] = 25.0f;
                countPower++;
                score++;
                cout <<"Score: ";
                cout << score <<  endl;
                cout << countPower <<  endl;

                break;
            }
        }
        glutPostRedisplay();
        pa[i]+=0.06f;

    }
    }
    for(int i = 0; i < 6; i++){

        if(moveEnemyX[i] <= -20.00f){
            glClear(GL_COLOR_BUFFER_BIT);
            endGame();
            //glFlush();
            break;
        }
        else{
            moveEnemyX[i]-=s;
            if(countPower == 5){
                    countPower=0;
                    s = s*1.5;
                }
            glutPostRedisplay();
            glClear(GL_COLOR_BUFFER_BIT);
        }

    //night sky
    quadMaker(0.0f, 0.0f,0.0f, 0.0f, 0.0f,20.0f, 20.0f);
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);//white color
    glTranslatef(-20.0f, 10.0f, 0.0f);
    glScalef(0.9f, .35f, 0.0f);
    pointsMany(150);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);//white color
    glTranslatef(8.0f, 10.0f, 0.0f);
    glScalef(0.9f, .35f, 0.0f);  //small dexter
    pointsMany(200);
    glPopMatrix();
    //moon
    circleMaker(0.0f, 14.5f, 18.0f, 1.0f, 1.0f,1.0f, 0.8f, 1.0f, 100.0f);

    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glScalef(1.0f, 0.5f, 0.0f);
    viewBuilding();
    glPopMatrix();
    road();
    //Ground
    quadMaker(0.0f, -11.8f,0.4f, 0.5f, 0.2f, 20.0f, 8.3f);

    glPushMatrix();
    glColor3f(0.4f, 0.4f, 0.2f);
    glTranslatef(-20.0f, -19.0f, 0.0f);
    glScalef(0.6f, 0.42f, 0.0f);  //small dexter
    pointsMany(350);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4f, 0.4f, 0.2f);
    glTranslatef(-2.1, -19, 0.0f);
    glScalef(0.5f, .42f, 0.0f);  //small dexter
    pointsMany(300);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4f, 0.4f, 0.2f);
    glTranslatef(13.5, -19, 0.0f);
    glScalef(0.5f, .42f, 0.0f);  //small dexter
    pointsMany(250);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(dx, dy, 0.0f);
    glScalef(0.3f, .3f, 0.0f);  //small dexter
    dexter();
    glPopMatrix();

    for(int i = 0; i < 6; i++)
    {
        glPushMatrix();
        glTranslatef(moveEnemyX[i], moveEnemyY[i], 0.0f);
        glScalef(0.3f, .3f, 0.0f);
        enemy();
        glPopMatrix();
    }

    for(int i = 0; i < 5; i++){
        glPushMatrix();
            glTranslatef(pa[i]+4.5,pb[i]+.1,0.0f);
            glRotated(-90,0,0,1);
            glScaled(0.02,0.02,1);
            bullet();
        glPopMatrix();
    }
    }
    //score
    char buffer [50];
    sprintf(buffer, "SCORE: %d", score);
    glColor3f(1.0f, 0.0f, 0.0f);
    renderBitmapString(-19.0,18.5,(void *)font3, buffer);

    glFlush();
}



void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
                if(dx >= -18.0f)
				{dx -=2.0f;
				glutPostRedisplay();
				}
				break;

		case GLUT_KEY_RIGHT:
                if(dx <= 18.0f)
				{dx +=2.0f;
				glutPostRedisplay();}
				break;

        case GLUT_KEY_DOWN:
                if(dy >= -15.0f)
				{dy -=2.0f;
				glutPostRedisplay();
				}
				//cout << dy << endl;
				break;

		case GLUT_KEY_UP:
                if(dy <= 8.0f)
				{dy +=2.0f;
				glutPostRedisplay();}
				break;
	  default:
			break;
	}
}

void my_keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'x':
        for(int i = 0; i < 5 ; i++)
        {
            if(pa[i] > 20.0f)
            {    pa[i] = dx;
                 pb[i] = dy;
                 break;
            }
        }
        break;

    default:
        break;
    }
}

void init(void)
{
	glClearColor (1.0f, 1.0f, 1.0f, 1.0f);
	glOrtho(-20.0, 20.0, -20.0, 20.0, -10.0, 10.0);
	superPower();
}

int main(int argc, char *argv[])
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1200, 1000);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Dexter the Villan");
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(spe_key);//up,down,left,right
	glutKeyboardFunc(my_keyboard);
	glutMainLoop();
	return 0;
}
