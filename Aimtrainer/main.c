#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <string.h>

#define pi 3.1415

float p=50*(pi/180);
int move=340,size=0;
int movex1=330,movex2=330,movex3=330,movex4=330,movex5=330;
int movey1=-300,movey2=-300,movey3=-300,movey4=-300,movey5=-300;
int hit1=0,hit2=0,hit3=0,hit4=0,hit5=0,hit6=0;
int CX=250;
int CY=250;
int respawn = 2000;
int score = 0;
int window, returnmenu;
int value=0, counter=0, j=60;
int hitcounter=1;
int start=0;
int flyx=100,flyy=0,rot1=45*(pi/180),rot2=45*(pi/180);
int fly_speed=10;
char scr[100];
char score_is[200]="Score: ";
char time_c[100];
char time_is[200]="Time: ";
//float angle = 45;


//randomly generate music by selecting random frequencies
//this thread will execute until the program terminates
void *myThreadFun(void *vargp)
{
    while(1)
    {
        Beep(660,100);
        Sleep(100);
        Beep(660,100);
        Sleep(200);
        Beep(660,100);
        Sleep(200);
        Beep(510,100);
        Sleep(70);
        Beep(660,100);
        Sleep(200);
        Beep(770,100);
        Sleep(300);
        Beep(380,100);
        Sleep(325);


        Beep(510,100);
        Sleep(250);
        Beep(380,100);
        Sleep(150);
        Beep(320,100);
        Sleep(200);
        Beep(440,100);
        Sleep(100);
        Beep(480,80);
        Sleep(130);
        Beep(450,100);
        Sleep(70);
        Beep(430,100);
        Sleep(150);
        Beep(380,100);
        Sleep(100);
        Beep(660,80);
        Sleep(100);
        Beep(760,50);
        Sleep(75);
        Beep(860,100);
        Sleep(200);
        Beep(700,80);
        Sleep(70);
        Beep(760,50);
        Sleep(150);
        Beep(660,80);
        Sleep(100);
        Beep(520,80);
        Sleep(75);
        Beep(580,80);
        Sleep(75);
        Beep(480,80);
        Sleep(300);


        Beep(500,100);
        Sleep(100);

        Beep(760,100);
        Sleep(50);
        Beep(720,100);
        Sleep(75);
        Beep(680,100);
        Sleep(75);
        Beep(620,150);
        Sleep(150);


        Beep(650,150);
        Sleep(150);
        Beep(380,100);
        Sleep(75);
        Beep(430,100);
        Sleep(75);


        Beep(500,100);
        Sleep(150);
        Beep(430,100);
        Sleep(75);
        Beep(500,100);
        Sleep(50);
        Beep(570,100);
        Sleep(100);


        Beep(500,100);
        Sleep(150);

        Beep(760,100);
        Sleep(50);
        Beep(720,100);
        Sleep(75);
        Beep(680,100);
        Sleep(75);
        Beep(620,150);
        Sleep(150);


        Beep(650,200);
        Sleep(150);


        Beep(1020,80);
        Sleep(150);
        Beep(1020,80);
        Sleep(75);
        Beep(1020,80);
        Sleep(150);

        Beep(380,100);
        Sleep(150);
        Beep(500,100);
        Sleep(150);

        Beep(760,100);
        Sleep(50);
        Beep(720,100);
        Sleep(75);
        Beep(680,100);
        Sleep(75);
        Beep(620,150);
        Sleep(150);

        Beep(650,150);
        Sleep(150);
        Beep(380,100);
        Sleep(75);
        Beep(430,100);
        Sleep(75);


        Beep(500,100);
        Sleep(150);
        Beep(430,100);
        Sleep(75);
        Beep(500,100);
        Sleep(50);
        Beep(570,100);
        Sleep(210);

        Beep(585,100);
        Sleep(220);

        Beep(550,100);
        Sleep(210);

        Beep(500,100);
        Sleep(130);

        Beep(380,100);
        Sleep(150);
        Beep(500,100);
        Sleep(150);
        Beep(500,100);
        Sleep(75);
        Beep(500,100);
        Sleep(150);

        Beep(500,100);
        Sleep(150);


       /* Beep(760,100);
        Sleep(100);
        Beep(720,100);
        Sleep(150);
        Beep(680,100);
        Sleep(150);
        Beep(620,100);
        Sleep(300);*/
    }
}



void myinit() //set attributes
{
    glClearColor(0.80f,0.80f,0.80f,0.80f); //  setting background color
    glColor3f(1.0f,0.0f,0.0f); // drawing color

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_NORMALIZE);

    // Set world coordinates
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,1366,-768,0,100,-100);
    //glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

//        Adding Ambient Light
        GLfloat ambientCLR[]={1.0,1.0,1.0,1.0};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientCLR);

        //Adding Light 0
        GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        GLfloat mat_shininess[] = { 50.0 };
        GLfloat light0diff[]={1.0,1.0,1.0,1.0};
        GLfloat light0spec[]={1.0,1.0,1.0,1.0};
        GLfloat light0CLR[]={1,1.05,1.05,1.0};
        GLfloat light0POS[]={0,0,1,0.0};
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);
        glShadeModel(GL_SMOOTH);
       // glLightfv(GL_LIGHT0,GL_DIFFUSE,light0diff);
        glLightfv(GL_LIGHT0,GL_SPECULAR,light0spec);
       // glLightfv(GL_LIGHT0,GL_DIFFUSE,light0CLR);
        glLightfv(GL_LIGHT0,GL_SPECULAR,light0CLR);
        glLightfv(GL_LIGHT0,GL_POSITION,light0POS);

        //Adding Light 1
        glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);
        glShadeModel(GL_SMOOTH);
        GLfloat light1diff[]={1.0,1.0,1.0,1.0};
        GLfloat light1spec[]={10.0,10.0,10.0,1.0};
        GLfloat light1CLR[]={01.05,1.05,1,0};
        GLfloat light1POS[]={1366,0,1,0};
        //glLightfv(GL_LIGHT1,GL_DIFFUSE,light1diff);
        glLightfv(GL_LIGHT1,GL_SPECULAR,light1spec);
       // glLightfv(GL_LIGHT1,GL_DIFFUSE,light1CLR);
        glLightfv(GL_LIGHT1,GL_SPECULAR,light1CLR);
        glLightfv(GL_LIGHT1,GL_POSITION,light1POS);
        //Game Starts
        if(value==10 && j>0)
        {
            start=1;
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            glutSetCursor(GLUT_CURSOR_NONE);
            background();
            square();
            room();
            targets();
            glColor3f(0,1,0);
            square();
            square1();
            Score();
            time();
            crosshair();
            glutSwapBuffers();
        }
        //End Screen
        if(j==0)
        {
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            rect();
            print();
            fscore();
            glutSwapBuffers();
        }
}
//End Screen Background
void rect()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0.547059,0.164706,0.164706);
    glBegin(GL_QUADS);
    glVertex3f(500,-368,-90);
    glVertex3f(756,-368,-90);
    glVertex3f(756,-270,-90);
    glVertex3f(500,-270,-90);
    glEnd();
    glPopMatrix();
    glFlush();

}
//Crosshair
void crosshair()
{
    glDisable(GL_LIGHTING);
 //   glClear(GL_COLOR_BUFFER_BIT); // clear the background
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);              // up line
        glVertex2f( CX , CY );
        glVertex2f( CX , CY+15 );
    glEnd();
    glBegin(GL_LINES);              // right
        glVertex2f( CX , CY );
        glVertex2f( CX-15 , CY );
    glEnd();
    glBegin(GL_LINES);              //left line
        glVertex2f( CX , CY );
        glVertex2f( CX+15 , CY );
    glEnd();
    glBegin(GL_LINES);              // down line
        glVertex2f( CX , CY );
        glVertex2f( CX , CY-15 );
    glEnd();

   // glutSwapBuffers();
    glEnable(GL_LIGHTING);
}
//Background for Score Display
void square()
{
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0.60,0.40,0.70);
    glBegin(GL_QUADS);
    glVertex2f(1100,-110);
    glVertex2f(1320,-110);
    glVertex2f(1320,-50);
    glVertex2f(1100,-50);
    glEnd();
    glPopMatrix();
    glFlush();
}
//Background for Time Display
void square1()
{
   glPushMatrix();
    glLoadIdentity();
    glColor3f(0.60,0.40,0.70);
    glBegin(GL_QUADS);
    glVertex2f(50,-110);
    glVertex2f(320,-110);
    glVertex2f(320,-50);
    glVertex2f(50,-50);
    glEnd();
    glPopMatrix();
    glFlush();
}
//Final Score Display
void fscore()
{
    glLoadIdentity();
    glColor3f(1,1,1);
    drawStrokeText(score_is,510,-360,-90);
}
//Time Display
void time(){
        glLoadIdentity();
        glColor3f(1,1,1);
        drawStrokeText1(time_is,70,-100,-90);
}
//Invisible Background behind Room
void background()
{
    //glClear(GL_COLOR_BUFFER_BIT); // clear the background
    int x=50,y=-768;
    for(int i=0;i<50;i++)
    {
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINES);
        glVertex2f(x,-768);
        glVertex2f(x,0);
        glEnd();
        x+=50;
    }
    for(int i=0;i<30;i++)
    {
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINES);
        glVertex2f(0,y);
        glVertex2f(1366,y);
        glEnd();
        y+=50;
    }
    glFlush();
}
//Room Design
void room()
{
    //FRONT WALL FACE
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0.547059,0.164706,0.164706);
    glBegin(GL_QUADS);
    glNormal3f(666,218,0);
    glVertex3f(350,-518,-90);
    glVertex3f(1016,-518,-90);
    glVertex3f(1016,-300,-90);
    glVertex3f(350,-300,-90);
    glEnd();
    glPopMatrix();
    //LEFT WALL FACE
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0.647059,0.264706,0.264706);
    glBegin(GL_QUADS);
    glNormal3f(175,218,0);
    glVertex3f(350,-518,-90);
    glVertex3f(0,-768,-90);
    glVertex3f(0,0,-90);
    glVertex3f(350,-300,-90);
    glEnd();
//1366 X 768
    //window
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0.5,0.8,0.9);
    glBegin(GL_QUADS);
    glNormal3f(175,218,0);
    glVertex2f(100,-510);
    glVertex2f(175,-460);
    glVertex2f(175,-350);
    glVertex2f(100,-300);
    glEnd();
    glPopMatrix();
//Window Lines
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(100,-510);
    glVertex2f(175,-460);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(175,-460);
    glVertex2f(175,-350);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(175,-350);
    glVertex2f(100,-300);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(100,-300);
    glVertex2f(100,-510);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(100,-405);
    glVertex2f(175,-405);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(137.5,-325);
    glVertex2f(137.5,-485);
    glEnd();

    glPopMatrix();

    //RIGHT WALL FACE
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0.647059,0.264706,0.264706);
    glBegin(GL_QUADS);
    glNormal3f(350,218,0);
    glVertex3f(1016,-518,-90);
    glVertex3f(1366,-768,-90);
    glVertex3f(1366,0,-90);
    glVertex3f(1016,-300,-90);
    glEnd();
    glPopMatrix();
    //FLOOR FACE
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0.747059,0.764706,0.764706);
    glBegin(GL_QUADS);
    glNormal3f(666,250,0);
    glVertex3f(350,-518,-90);
    glVertex3f(0,-768,-90);
    glVertex3f(1366,-768,-90);
    glVertex3f(1016,-518,-90);
    glEnd();
    glPopMatrix();
    //CEILING FACE
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0.347059,0.364706,0.364706);
    glBegin(GL_QUADS);
    glNormal3f(350,300,0);
    glVertex3f(350,-300,-90);
    glVertex3f(1016,-300,-90);
    glVertex3f(1366,0,-90);
    glVertex3f(0,0,-90);
    glEnd();
    glPopMatrix();
    glFlush();
}
//Sphere target
void sphere(int x,int y,int s)
{
    glColorMaterial(GL_FRONT_AND_BACK|GL_COLOR,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
   // glColor3b(rand()%255,rand()%255,rand()%255);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x,y,-100);
    glRotatef(p,1,1,1);
    glutSolidSphere(s,100,10);
    glPopMatrix();
    glFlush();
}
//Cube Target
void cube(int x,int y,int s)
{
    glColorMaterial(GL_FRONT_AND_BACK|GL_COLOR,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.25,0.25,0.55555);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x,y,-1);
    glRotatef(p,1,1,1);
    glutSolidCube(s);
    glPopMatrix();
    glFlush();
}
//Ring (torus) Target
void torus(int x,int y, int s)
{
    glColorMaterial(GL_FRONT_AND_BACK|GL_COLOR,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.25555,0.25555,0);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x,y,-1);
    glRotatef(p,0,1,0);
    if(size!=0)
    {
        glutSolidTorus(3,10,25,25);
    }
    glPopMatrix();
    glFlush();
}

//Bonus Paper Plane Target
void plane(int x, int y, int s)
{
    glColorMaterial(GL_FRONT_AND_BACK|GL_COLOR,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    float vertices[42]= {
                            0,25,25,          //A
                            30,25,0.5,        //B
                            0,25,7.5,        //C
                            0,12,0,          //D
                            0,25,-7.5,       //E
                            0,25,-25,         //F
                            30,25,-0.5,       //G
                            30,20,0           //H
                        };
        GLubyte indices[16]= {
                                0,1,2,0,
                                2,3,7,1,
                                3,7,6,4,
                                4,6,5,4
                             };
        float color[12]=    {
                             0.0,0.5,0.5,
                             0.0,0.5,0.5,
                             0.0,0.5,0.5,
                             0.0,0.5,0.5
                            };
        float normal[12]={
                            12.5,25,12.5,
                            12.5,12.5,7.5,
                            12.5,12.5,-7.5,
                            12.5,25,-12.5
                         };

        glPushMatrix();
        glLoadIdentity();
        glColor3ub(rand(),rand(),rand());
        //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); //For WireFrame Mode
        glRotatef(rot1,1,0,0);
        glRotatef(rot2,0,0,1);
        glTranslatef(x,y,-90);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glNormalPointer(GL_FLOAT,0, normal);
        glVertexPointer(3,GL_FLOAT,0,vertices);
        glColorPointer(3,GL_FLOAT,0,color);
        glDrawElements(GL_QUADS,16,GL_UNSIGNED_BYTE,indices);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glPopMatrix();
}

//Target Hit n Destroy Method
void targets()
{
    if(hit1==1)
    {
        glColorMask(GL_FALSE,GL_FALSE,GL_FALSE,GL_FALSE);
        glutPostRedisplay();
    }
    glColor3f(0.3,0.5,0);
    sphere(movex1,movey1,size);
    glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);
    glColor3f(0,0.0,1.0);
    if(hit2==1)
    {
        glColorMask(GL_FALSE,GL_FALSE,GL_FALSE,GL_FALSE);
        glutPostRedisplay();
    }
    if(hitcounter%4==0)
    cube(movex2,movey2,size);
    glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);
    glColor3f(0.0,0.0,0.0);

    if(hit3==1)
    {
        glColorMask(GL_FALSE,GL_FALSE,GL_FALSE,GL_FALSE);
        glutPostRedisplay();
    }
    if(hitcounter%6==0)
    torus(movex3,movey3,size);
    glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);

    if(hit4==1)
    {
        glColorMask(GL_FALSE,GL_FALSE,GL_FALSE,GL_FALSE);
        glutPostRedisplay();
    }
    glColor3f(0.1,0.3,0.5);
    sphere(movex4,movey4,size);
    glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);
    if(hit5==1)
    {
        glColorMask(GL_FALSE,GL_FALSE,GL_FALSE,GL_FALSE);
        glutPostRedisplay();
    }
    glColor3f(0.32,0,0.7);
    sphere(movex5,movey5,size);
    glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);
    if(hit6==1)
    {
        glColorMask(GL_FALSE,GL_FALSE,GL_FALSE,GL_FALSE);
        glutPostRedisplay();
    }
    if(score%10==0)
    {
        plane(flyx,flyy,0);
    }
    glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);
}
//Target Hit State Method
void hit(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
    {
        if(CX>=(movex1-size)&&CX<=(movex1+size)&&CY>=(movey1-size)&&CY<=(movey1+size))
            {
                hit1=1;
                score++;
                hitcounter++;
            }
        if(CX>=(movex2-(size))&&CX<=(movex2+(size))&&CY>=(movey2-(size))&&CY<=(movey2+(size)))
            {
                hit2=1;
                if(j>=5)
                    j=j-5;
                else
                    j=j-j;
                hitcounter++;
            }
        if(CX>=(movex3-(8))&&CX<=(movex3+(8))&&CY>=(movey3-(8))&&CY<=(movey3+(8)))
            {
                hit3=1;
                j=j+5;
                hitcounter++;
            }
        if(CX>=(movex4-size)&&CX<=(movex4+size)&&CY>=(movey4-size)&&CY<=(movey4+size))
            {
                hit4=1;
                score++;
                hitcounter++;
            }

        if(CX>=((movex5)-size)&&CX<=((movex5)+size)&&CY>=((movey5)-size)&&CY<=((movey5)+size))
            {
                hit5=1;
                score++;
                hitcounter++;
            }
        if(CX>=((flyx)-15)&&CX<=((flyx)+25)&&CY>=((flyy)-15)&&CY<=((flyy)+30))
            {
                hit6=1;
                flyx=100;
                score+=5;
                j+=5;
                hitcounter++;
            }
    }
    //Changing Target Respawn Time
    if(score>15)
        {
            respawn=1500;
            fly_speed=12;
        }
    if(score>25)
        {
            respawn=1250;
            fly_speed=16;
        }
    if(score>40)
        {
            respawn=1000;
            fly_speed=20;
        }
    if(score>50)
        {
            respawn=900;
            fly_speed=23;
        }
    if(score>60)
        respawn=850;
    if(score>75)
        respawn=800;
    //Converting Score to string
    itoa(score,scr,10);
    strcpy(score_is,"Score: ");
    strcat(score_is,scr);
}
//End Screen
void print()
{
            glLoadIdentity();
            glColor3f(1,1,1);
            drawStrokeText("Game End",510,-310,-90);

}
//Score Display
void Score()
{
            //glClear(GL_COLOR_BUFFER_BIT);
            glLoadIdentity();
            glColor3f(1,1,1);
            drawStrokeText(score_is,1120,-100,-90);
}
//Random Target Spawn Values Generation
void random()
{
    movex1 = ((rand()%(1036-330))+330);
    movex2 = ((rand()%(1036-330))+330);
    movex3 = ((rand()%(1036-330))+330);
    movex4 = ((rand()%(1036-330))+330);
    movex5 = ((rand()%(1036-330))+330);
    movey1 = (rand()%(-300-(-508)))+(-508);
    movey2 = ((rand()%(-300-(-508)))+(-508));
    movey3 = ((rand()%(-300-(-508)))+(-508));
    movey4 = ((rand()%(-300-(-508)))+(-508));
    movey5 = ((rand()%(-300-(-508)))+(-508));
    size   = (rand()%(25-15))+15;
    if(movex1<=(movex2+size)&&movex1>=(movex2-size))
        random();
    else if(movey1<=(movey2+size)&&movey1>=(movey2-size))
        random();
    else if(movex1<=(movex3+size)&&movex1>=(movex3-size))
        random();
    else if(movey1<=(movey3+size)&&movey1>=(movey3-size))
        random();
    else if(movex2<=(movex3+size)&&movex2>=(movex3-size))
        random();
    else if(movey2<=(movey3+size)&&movey2>=(movey3-size))
        random();
    else if(movex1<=(movex4+size)&&movex1>=(movex4-size))
        random();
    else if(movex1<=(movex5+size)&&movex1>=(movex5-size))
        random();
    else if(movey1<=(movey4+size)&&movey1>=(movey4-size))
        random();
    else if(movey1<=(movey5+size)&&movey1>=(movey5-size))
        random();
    else if(movex2<=(movex4+size)&&movex2>=(movex4-size))
        random();
    else if(movex2<=(movex5+size)&&movex2>=(movex5-size))
        random();
    else if(movey2<=(movey4+size)&&movey2>=(movey4-size))
        random();
    else if(movey2<=(movey5+size)&&movey2>=(movey5-size))
        random();
    else
    {
        hit1=0; hit2=0; hit3=0; hit4=0; hit5=0,hit6=0;
        glutTimerFunc(respawn,random,0);
    }
}
//Roatation of Targets
void rot(int val)
{
    p=p+500*(pi/180);
    glutPostRedisplay();
    if(move>=1036)
        move=330;
    move+=10;
    glutTimerFunc(50,rot,0);
}
//Plane Movement
void fly()
{
    if(flyx>=1366)
    {
        flyy=((rand()%(-300-(-508)))+(-508));
        flyx=100;
    }
    if(score%10==0)
        flyx+=fly_speed;
    if(rot1<=(30*(pi/180)))
        rot1++;
    else rot1=0;
    if(rot2>(0*(pi/180)))
        rot2--;
    else rot2=0;
    glutTimerFunc(35,fly,1);
}
//Crosshair Handler
void mypassive (int x,int y)
{

	CX = x;
	CY = -1*y;
    glutPostRedisplay();

}

//creating menu
void menu(int n)
{
    if(n==0)
    {
        glutDestroyWindow(window);
        exit(0);
    }
    else{
        value=n;
    }
    glutPostRedisplay();
}

void createMenu(void)
{
    //returnsubmenu1=glutCreateMenu(menu);
    returnmenu=glutCreateMenu(menu);
    glutAddMenuEntry("Play",10);
    //glutAddSubMenu("Play",returnsubmenu1);
    glutAddMenuEntry("Exit",0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
//Stopwatch Timer Method
void stopwatch(int val)
{
    if(j>0&&start==1)
    {
        j=j-1;
    }
    //converting time (j) to string
    itoa(j,time_c,10);
    strcpy(time_is,"Time: ");
    strcat(time_is,time_c);
    glutPostRedisplay();
    glutTimerFunc(1000, stopwatch, 0);
}

//for Score
void drawStrokeText(char*string,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y,z);
    glScalef(0.25f,+0.28f,-z);

	  for (c=string; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}

//for time
void drawStrokeText1(char*string,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y,z);
    glScalef(0.23f,+0.25f,-z);

	  for (c=string; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}

//for final score
void drawStrokeText2(char*string,int x,int y,int z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y,z);
    glScalef(0.43f,+0.45f,-z);

	  for (c=string; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}
//Main Method
int main (int argc , char ** argv)
{
    pthread_t thread_id;
    glutInit(&argc,argv); // initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); //setting display mode

    glutInitWindowSize(1366,768); // window size
    glutInitWindowPosition(0,0);  // window position

    glutCreateWindow("AIM Trainer");

    //glutDisplayFunc(background);
    glutDisplayFunc(display); // Register callback func
    glutPassiveMotionFunc(mypassive);
    glutMotionFunc(mypassive);
    createMenu();
    myinit(); // Set attributes
    glutTimerFunc(50,rot,0);
    glutTimerFunc(35,fly,1);
    glutTimerFunc(respawn,random,0);
    //start thread execution
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    if(start==1);//Game Start Timer for Respawning
        glutTimerFunc(3000,stopwatch,0);
    glutMouseFunc(hit);
    glutMainLoop(); // enter event Loop
    pthread_join(thread_id, NULL);
    return 0;
}
