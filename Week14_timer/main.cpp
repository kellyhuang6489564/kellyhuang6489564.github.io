#include <GL/glut.h>
int angle=0;
void drawArm1(){
    glPushMatrix();
        glScalef(1,0.5,0.5);
        glColor3f(1,0,0);glutSolidCube(0.3); ///�����
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);glutSolidCube(0.4); ///�����
        glPushMatrix();
            glTranslatef(-0.2,+0.2,0); ///(3)����k�W��
            glRotatef(angle,0,0,1); ///(2)���
            glTranslatef(-0.15,0,0); ///(1)����त�ߪ����`�b��b����
            drawArm1();
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers(); ///�h�B
}
int diff=2;
void timer(int t) ///�x���T�F�Atimer�s�F
{
    glutTimerFunc(20,timer,t+1); ///���W�]�w�U�@�Ӿx���A���n�T�Ӥ[
               ///���t
    angle+=diff; ///�W�ӴZ��
    if(angle>180 || angle<0 ) diff=-diff;
    display(); ///�ܭӤ�
}///�ΤF
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);
    glutCreateWindow("Week14 timer");

    glutDisplayFunc(display);
    glutTimerFunc(0  ,  timer  ,0);
                ///�n���h�[ �s�� �Ѽ�
    glutMainLoop();

}
