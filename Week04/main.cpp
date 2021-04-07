#include <GL/glut.h>
#include <stdio.h>
float teapotX=0,teapotY=0; ///�����y��
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();  ///�x�}�ƥ�
        glTranslatef(teapotX,teapotY,0);  ///�ӵۮy�в���
        glutSolidTeapot(0.3);
    glPopMatrix();   ///�x�}�٭�
    glEnd();
    glutSwapBuffers();
}

void motion(int x,int y)   ///mouse ���ʪ��禡
{
    teapotX= (x-150)/150.0;  ///���������m���⦨�y��
    teapotY=-(y-150)/150.0;
    display();   ///�e����s
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);
    glutCreateWindow("Week04 mouse");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
}
