#include <GL/glut.h>
#include <stdio.h>
float angle=0;
void hand()
{
    glPushMatrix();
        glScalef(0.5,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix(); ///���b��
        glTranslatef(-0.25,0,0);///(3)�⥿�T�����u���b�����`
        glRotatef(angle,0,0,1); ///(2)���
        glTranslatef(-0.25,0,0); ///(1)���त��
        hand();///�W���u
        glPushMatrix();
            glTranslatef(-0.25,0,0);///(3)�⥿�T�����u���b�ӤW
            glRotatef(angle,0,0,1); ///(2)���
            glTranslatef(-0.25,0,0); ///(1)���त��
            hand();///�U��y
        glPopMatrix();
    glPopMatrix();

     glPushMatrix(); ///�k�b��
        glTranslatef(+0.25,0,0);///(3)�⥿�T�����u���b�����`
        glRotatef(-angle,0,0,1); ///(2)���
        glTranslatef(+0.25,0,0); ///(1)���त��
        hand();///�W���u
        glPushMatrix();
            glTranslatef(+0.25,0,0);///(3)�⥿�T�����u���b�ӤW
            glRotatef(-angle,0,0,1); ///(2)���
            glTranslatef(+0.25,0,0); ///(1)���त��
            hand();///�U��y
        glPopMatrix();
    glPopMatrix();


    glutSwapBuffers();
    angle++;
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);
    glutCreateWindow("Week06 08160971");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
