# kellyhuang6489564.github.io
Week03 茶壺
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
Week05 畫封閉線
-----
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
-----
Week06 機器人手臂
-----
```C
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

    glPushMatrix(); ///左半邊
        glTranslatef(-0.25,0,0);///(3)把正確的手臂掛在肩關節
        glRotatef(angle,0,0,1); ///(2)轉動
        glTranslatef(-0.25,0,0); ///(1)旋轉中心
        hand();///上手臂
        glPushMatrix();
            glTranslatef(-0.25,0,0);///(3)把正確的手臂掛在肩上
            glRotatef(angle,0,0,1); ///(2)轉動
            glTranslatef(-0.25,0,0); ///(1)旋轉中心
            hand();///下手肘
        glPopMatrix();
    glPopMatrix();

     glPushMatrix(); ///右半邊
        glTranslatef(+0.25,0,0);///(3)把正確的手臂掛在肩關節
        glRotatef(-angle,0,0,1); ///(2)轉動
        glTranslatef(+0.25,0,0); ///(1)旋轉中心
        hand();///上手臂
        glPushMatrix();
            glTranslatef(+0.25,0,0);///(3)把正確的手臂掛在肩上
            glRotatef(-angle,0,0,1); ///(2)轉動
            glTranslatef(+0.25,0,0); ///(1)旋轉中心
            hand();///下手肘
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
```
-----
Week06 回家作業 機器人 
-----
```C
#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -2.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
float angle=0;

void body()
{
    glPushMatrix();
        glColor3f(1.0,0.0,0.0);
        glTranslatef(0,-0.27,0);
        glScalef(0.5,0.75,0.1);
        glutSolidCube(1);
    glPopMatrix();
}
void head()
{
    glPushMatrix();///頭
        glTranslatef(0,0.3,0);
        glScalef(0.5,0.5,0.1);
        glColor3ub(200,191,231);
        glutSolidSphere(0.5,100,100);
    glPopMatrix();
}
void hand()
{
    glPushMatrix();
        glColor3ub(255,201,14);
        glScalef(0.5,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
}
void hand1()
{
    glPushMatrix();
        glColor3ub(255,201,14);
        glScalef(0.3,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///右手

        glTranslatef(+0.23,0,0);
        glRotatef(-angle,0,0,1);
        glTranslatef(+0.23,0,0);
        hand();
        glPushMatrix();
            glTranslatef(+0.23,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(+0.23,0,0);
            hand();
            glPushMatrix();
                glTranslatef(+0.185,-0.01,0);
                glRotatef(angle,0,0,1);
                glTranslatef(+0.185,-0.01,0);
                hand1();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左手
    glTranslatef(-0.23,0,0);
    glRotatef(-angle,0,0,1);
        glTranslatef(-0.23,0,0);
        hand();
        glPushMatrix();
            glTranslatef(-0.23,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.23,0,0);
            hand();
            glPushMatrix();
                glTranslatef(-0.185,-0.01,0);
                glRotatef(+angle,0,0,1);
                glTranslatef(-0.185,-0.01,0);
                hand1();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();


    body();///身體
    head();///頭
    glPushMatrix();///左腳
        glTranslatef(-0.2,-0.8,0);
        glRotatef(90,0,0,1);
        glScalef(0.75,0.1,0.1);
        glColor3ub(255,201,14);
        glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();///右腳
        glTranslatef(0.2,-0.8,0);
        glRotatef(90,0,0,1);
        glScalef(0.75,0.1,0.1);
        glColor3ub(255,201,14);
        glutSolidCube(1);
    glPopMatrix();
    glutSwapBuffers();
    angle+=1;
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);
    glutCreateWindow("08160971_HW3");

    glutIdleFunc(display);
    glutDisplayFunc(display);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutMainLoop();
}

```
-----
Week08-1 茶壺貼圖
-----
```C
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
void init()
{
    IplImage * img = cvLoadImage("puipui.jpg"); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
   ///最後一行最難/最重要, 所貼圖影像的資料都設定好
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glTexCoord2f(0,1); glVertex3f(-1,-1,0);
        glTexCoord2f(1,1); glVertex3f(+1,-1,0);
        glTexCoord2f(1,0); glVertex3f(+1,+1,0);
        glTexCoord2f(0,0); glVertex3f(-1,+1,0);
    glEnd();
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);
    glutCreateWindow("Week08 08160971");

    init(); ///在這裡呼叫

    glutDisplayFunc(display);
    glutMainLoop();
}
```
-----
Week08-2 地球
-----
```C
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * quad;///TODO: Quad
void init()///copy 自 http://hackmd.io/@jsyeh/opengl
{
    IplImage * img = cvLoadImage("earth.jpg"); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    quad = gluNewQuadric();///TODO: Quad
}   ///最後一行最難/最重要, 所貼圖影像的資料都設定好
float angle=0;///TODO:
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///自動轉很帥///TODO:
        glRotatef(90, 1,0,0);///TODO:
        glRotatef(angle, 0,0,1);///自動轉很帥///TODO:
        gluQuadricTexture(quad, 1);///TODO:
        gluSphere(quad, 0.5, 30, 30);///glutSolidTeapot(0.3);///TODO:
    glPopMatrix();///自動轉很帥///TODO:
    ///glutSolidTeapot(0.3);
    glutSwapBuffers();
    angle++;///TODO:
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week08-2 texture");
    glutDisplayFunc(display);
    glutIdleFunc(display);///TODO:
    glEnable(GL_DEPTH_TEST);///TODO: 有3D的深度測試(前面會蓋掉後面)
    init();///上面把OpenGL都設好後, 才設定 OpenCV 的貼圖到 OpenGL上面
    glutMainLoop();
}
```
-----
Week 10 聲音
-----
```C
#include <windows.h>
#include <GL/glut.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='1') PlaySound("do.wav",NULL,SND_ASYNC);
    if(key=='2') PlaySound("re.wav",NULL,SND_ASYNC);
    if(key=='3') PlaySound("mi.wav",NULL,SND_ASYNC);
    if(key=='4') PlaySound("fa.wav",NULL,SND_ASYNC);
    if(key=='5') PlaySound("so.wav",NULL,SND_ASYNC);
}
void mouse(int button ,int state,int x,int y)
{
    if(state==GLUT_DOWN)PlaySound("shot.wav",NULL,SND_ASYNC);
}
int main(int argc,char**argv)
{
    mp3.Load("music.mp3");
    mp3.Play();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 sound");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
```
-----
Week10 茶壺立體(燈光)
-----
```C
#include <Gl/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week10 light");


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutDisplayFunc(display);
    glutMainLoop();

}
```
-----
Week11 模型 
-----
```C
#include "glm.h" ///使用glm.cpp外掛
GLMmodel*pmodel=NULL; ///pmodel指標
void drawmodel(void){ ///使用範例的程式
    if(!pmodel){
        pmodel=glmReadOBJ("data/porsche.obj");
        if(!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel,90.0);
    }
    glmDraw(pmodel,GLM_SMOOTH | GLM_MATERIAL);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotated(180,0,1,0);
        drawmodel(); ///使用範例的程式
    glPopMatrix();
    glutSwapBuffers();
}
///打光的陣列
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);
    glutCreateWindow("Week11");

    ///打光的設定
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutDisplayFunc(display);
    glutMainLoop();
}
```
-----
Week 12 All in
-----
```C
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <Gl/glut.h>

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week12 all in");
    glutDisplayFunc(display);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


    myTexture("Diffuse.jpg");
    glutMainLoop();
}
```
-----
Week 13 ROBOT
-----
```C
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h" ///使用外掛
GLMmodel * pmodel = NULL; ///glm模型的指標
GLMmodel * body = NULL;
GLMmodel * arm1 = NULL;
GLMmodel * arm2 = NULL;
///GLMmodel * hand1 = NULL;
///GLMmodel * hand2 = NULL;
void drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("gundam.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
}

GLuint id1, id2; ///TODO:增加2個 貼圖ID
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, id1);

    glPushMatrix();
        glTranslatef(0,-1,0);
        glRotatef(angle,0,1,0);
        ///drawmodel();
        glmDraw(body,GLM_SMOOTH | GLM_TEXTURE);
        glPushMatrix();
            glTranslatef(-0.35,+0.68+1,0);
            glRotatef(angle,0,0,1);
            glTranslatef(+0.35,-0.68-1,0);
            glmDraw(arm1,GLM_SMOOTH | GLM_TEXTURE);
        glPopMatrix();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, id2);
    glBegin(GL_POLYGON);
        glTexCoord2f( 0, 0 ); glVertex3f( -1, -1,0.8 );
        glTexCoord2f( 0, 1 ); glVertex3f( -1, +1 ,0.8 );
        glTexCoord2f( 1, 1 ); glVertex3f( +1, +1 ,0.8);
        glTexCoord2f( 1, 0 ); glVertex3f( +1, -1 ,0.8);
    glEnd();
    glutSwapBuffers();
    angle+=0.1;
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow(" Week13 ");
    glutDisplayFunc(display);
    glutIdleFunc(display);

    id1 = myTexture("Diffuse.jpg");
    id2 = myTexture("bg.jpg");
    body = glmReadOBJ("body.obj");
    arm1 = glmReadOBJ("arm1.obj");
    arm2 = glmReadOBJ("arm2.obj"); ///因為會被調掉

    pmodel=glmReadOBJ("gundam.obj");///完整的大模型
    float dimensions[3];
    glmDimensions( pmodel,dimensions);
    glmScale(pmodel,2.0/dimensions[1]);
    glmScale(body,  2.0/dimensions[1]);
    glmScale(arm1,  2.0/dimensions[1]);
    glmScale(arm2,  2.0/dimensions[1]);


    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
```
-----
Week14 Timer
-----
```C
#include <GL/glut.h>
int angle=0;
void drawArm1(){
    glPushMatrix();
        glScalef(1,0.5,0.5);
        glColor3f(1,0,0);glutSolidCube(0.3); ///左手紅
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);glutSolidCube(0.4); ///身體白
        glPushMatrix();
            glTranslatef(-0.2,+0.2,0); ///(3)掛到右上角
            glRotatef(angle,0,0,1); ///(2)轉動
            glTranslatef(-0.15,0,0); ///(1)把旋轉中心的關節軸放在中心
            drawArm1();
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers(); ///柳丁
}
int diff=2;
void timer(int t) ///鬧鐘響了，timer叫了
{
    glutTimerFunc(20,timer,t+1); ///馬上設定下一個鬧鐘，不要響太久
               ///倍速
    angle+=diff; ///上個廁所
    if(angle>180 || angle<0 ) diff=-diff;
    display(); ///喝個水
}///睡了
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_DEPTH);
    glutCreateWindow("Week14 timer");

    glutDisplayFunc(display);
    glutTimerFunc(0  ,  timer  ,0);
                ///要等多久 叫誰 參數
    glutMainLoop();

}
```
------
作業4
------
```C
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"///使用外掛

GLMmodel*body=NULL;
GLMmodel*lefthand=NULL;
GLMmodel*righthand=NULL;
GLMmodel*leftleg=NULL;
GLMmodel*rightleg=NULL;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

GLuint id1, id2;///增加2個貼圖ID
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float anglehl=-1;
float anglehr=1;
float anglell=1;
float anglelr=-1;
int diff1=2;
int diff2=2;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, id1);

    glPushMatrix();///畫左手
        glTranslatef(-0.35,0.5,0);
        glRotatef(anglehl,0,0,1);
        glTranslatef(0.45,-0.25,0);
        glRotatef(180,0,1,0);
        glScalef(0.2,0.2,0.2);
        glmDraw(lefthand,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();


    glPushMatrix();///畫右手
        glTranslatef(0.35,0.5,0);
        glRotatef(anglehr,0,0,1);
        glTranslatef(-0.45,-0.25,0);
        glRotatef(180,0,1,0);
        glScalef(0.2,0.2,0.2);
        glmDraw(righthand,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///畫左腳
        glTranslatef(-0.2,0.05,0);
        glRotatef(anglell,1,0,0);
        glTranslatef(0.2,0.2,0);
        glRotatef(180,0,1,0);
        glScalef(0.2,0.2,0.2);
        glmDraw(leftleg,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///畫右腳
        glTranslatef(0.2,0.05,0);
        glRotatef(anglelr,1,0,0);
        glTranslatef(-0.2,0.2,0);
        glRotatef(180,0,1,0);
        glScalef(0.2,0.2,0.2);
        glmDraw(rightleg,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();


    glBindTexture(GL_TEXTURE_2D, id2);
    glBegin(GL_POLYGON);
        glTexCoord2f( 0, 0 ); glVertex3f( -1, +1 ,0.8);
        glTexCoord2f( 0, 1 ); glVertex3f( -1, -1 ,0.8);
        glTexCoord2f( 1, 1 ); glVertex3f( +1, -1 ,0.8);
        glTexCoord2f( 1, 0 ); glVertex3f( +1, +1 ,0.8);
    glEnd();
    anglehl-=diff1;
    anglehr+=diff1;
    anglell+=diff2;
    anglelr-=diff2;

    if (anglehl<-50 || anglehl>0)diff1=-diff1;
    if (anglell> 25|| anglell<-25)diff2=-diff2;

    glDisable(GL_TEXTURE_2D);
    glPushMatrix();///畫身體
        glTranslatef(0,0.25,0);
        glRotatef(180,0,1,0);
        glScalef(0.2,0.2,0.2);
        glmDraw(body,GLM_SMOOTH | GLM_MATERIAL );
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("08160971_HW4");
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    id1 = myTexture("green.jpg"); ///大眼仔顏色
    id2 = myTexture("back.jpg");///背景

    body=glmReadOBJ("body.obj");
    lefthand=glmReadOBJ("left_hand.obj");
    righthand=glmReadOBJ("right_hand.obj");
    leftleg=glmReadOBJ("left_leg.obj");
    rightleg=glmReadOBJ("right_leg.obj");


    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
```
-----
Week15_File
------
```C
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
```
-----
