# kellyhuang6489564.github.io
Week03-1 茶壺
------
```C
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///清空
    glutSolidTeapot(0.3);   ///實心茶壺
    glutSwapBuffers();  ///交換兩倍的Buffers
}
int main(int argc,char **argv)  /// 以前是int main()
{
    glutInit(&argc,argv);   ///1.初始設定
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);   ///2.顯示模式
    glutCreateWindow("08160971 奶最大的妹子");   ///3.開視窗

    glutDisplayFunc(display);   ///4.等一下要顯示的函式
    glutMainLoop();  ///5.主要迴圈
}
```
------
Week04 茶壺移動
------
```C
#include <GL/glut.h>
#include <stdio.h>
float teapotX=0,teapotY=0; ///茶壺座標
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();  ///矩陣備份
        glTranslatef(teapotX,teapotY,0);  ///照著座標移動
        glutSolidTeapot(0.3);
    glPopMatrix();   ///矩陣還原
    glEnd();
    glutSwapBuffers();
}

void motion(int x,int y)   ///mouse 移動的函式
{
    teapotX= (x-150)/150.0;  ///把茶壺的位置換算成座標
    teapotY=-(y-150)/150.0;
    display();   ///畫面更新
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
```
-----
