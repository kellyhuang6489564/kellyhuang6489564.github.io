#include <stdio.h>
#include <GL/glut.h>
float angle=0;
float diff=2;
///float angle=[20];
void timer (int t)
{
    glutTimerFunc(30,timer,t+1); ///設定新的timer(等多久，timer ，參數)
    angle+=diff;
    if(angle>90) diff=-2;
    if(angle<0) diff=+2;
    glutPostRedisplay();
}
void display()
{
     glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glPushMatrix();
        glutSolidTeapot( 0.3 );///身體
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotatef(angle, 0,0,1);
            glTranslatef(-0.3,0,0);
            glutSolidTeapot( 0.3 );///左手臂, 但是,要用 T-R-T移位置
            glPushMatrix();
                glTranslatef(-0.3, 0,0);
                glRotatef(angle, 0,0,1);
                glTranslatef(-0.3, 0,0);
                glutSolidTeapot( 0.3 );///左手肘
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(+0.3,0,0);
            glRotatef(-angle, 0,0,1);
            glTranslatef(+0.3,0,0);
            glutSolidTeapot( 0.3 );///右手臂
            glPushMatrix();
                glTranslatef(+0.3,0,0);
                glRotatef(-angle, 0,0,1);
                glTranslatef(+0.3,0,0);
                glutSolidTeapot( 0.3 );///右手肘
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);
    glutCreateWindow("Week15 many angles");

    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
}
