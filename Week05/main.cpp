#include <GL/glut.h>
#include <stdio.h>
float vx[2000],vy[2000];  ///�ǳƤ@�ﳻ�I�A���@�U�n�e!!! �y�Ф���-1 ~1����
int N=0; //��N�ӳ��I
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP); //�e�u
    for(int i=0;i<N;i++){
        glVertex2f(vx[i],vy[i]);
    }
    glEnd();
    glutSwapBuffers();
}
void motion(int x,int y)   ///mouse
{
    printf("%d %d\n",x,y); //�⳻�I�O�_��...���@�U�n�e
    vx[N]= (x-150)/150.0;
    vy[N]=-(y-150)/150.0;
    N++;
    display(); //��s�e��
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);
    glutCreateWindow("Week05 drawing");
    glutDisplayFunc(display);
    glutMotionFunc(motion); //�b��(�즲)/�b�e
    glutMainLoop();
}
