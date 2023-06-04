#include <windows.h>

#include <GL/glut.h>

#include <stdlib.h>

#include <math.h>

static float tp3 = 0;
static float pm = 300.0;
static float bm = 350.0;
static float tm = 300.0;
static float cm = -300.0;
float spin = 0.0;
float s = 100.00;

GLfloat tx = 5;
GLfloat ty = 5;
float tp = 0;
float treeArrayF[2000];
float treeArrayS[3000];
float skyArrayX[100];
float skyArrayY[100];
void drawLines(GLfloat x ,GLfloat y,GLfloat x1,GLfloat y1){
    glBegin(GL_LINES);

    glVertex2d(x,y);
    glVertex2d(x1,y1);
    glEnd();
}
void circle(GLfloat rx, GLfloat ry, GLfloat x, GLfloat y) {
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    for (i = 0; i <= 360; i++) {
        rad = i * (3.1416 / 180);
        glVertex2f(x + rx * cos(rad), y + ry * sin(rad));
    }
    glEnd();
}

void rectangle(int x, int y, int x1, int y1) {
    glBegin(GL_QUADS);
    glVertex2d(x, y);
    glVertex2d(x, y1);
    glVertex2d(x1, y1);
    glVertex2d(x1, y);
    glEnd();
}

void triangle(int x, int y, int x1, int x2, int y1) {
    glBegin(GL_POLYGON);
    glVertex2d(x, y);
    glVertex2d(x1, y);
    glVertex2d(x2, y1);
    glEnd();
}

void rectangle1(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    glBegin(GL_QUADS);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glVertex2d(x3, y3);
    glVertex2d(x4, y4);
    glEnd();
}

void sun() {
    glPushMatrix();
    glTranslated(50, 85, 0);
    glColor3ub(251, 252, 234);
    circle(2.5, 5, 0, 0);
    glPopMatrix();
}
void plane()
{
    glPushMatrix();
    glTranslated(s,0,0);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(90,90);
    glVertex2f(89,89);

    glVertex2f(93,89);
    glVertex2f(93,90);
    glVertex2f(94,91);
    glEnd();

    glColor3f(1,1,1);
    circle(.1,.1,90,90);
    glColor3f(0,0,1);
    circle(.1,.1,93,90);
    glColor3f(1,0,0);
    circle(.1,.1,93,89.5);
    glPopMatrix();
}

void planeMove(){
    if(s >= -100){
         s -= .05;

    }else{
        s = 100.00;
    }
    glutPostRedisplay();
}
void sky() {
    // Night Background - Upper Half with stars and moon
    glBegin(GL_QUADS);
    glColor3ub(24, 53, 69);

    glVertex2d(1, 50);
    glVertex2d(99, 50);
    // Dark blue color at the top of the gradient
    glVertex2d(99, 99);
    glVertex2d(1, 99);
    glEnd();

    // Stars
    glBegin(GL_POINTS);
    for (int i = 0; i < 100; i++) {
        glColor3ub(255, 255, 255);

            glVertex2d(skyArrayX[i], skyArrayY[i]);
    }
    glEnd();


    sun();
    planeMove();
    plane();




}
void pushStarsArraXY(){
   int lb = 50, ub = 99,lb1 = 1;
   float z;
   for(int i = 0; i < 100;i++){
   z = (rand() % (ub - lb + 1)) + lb;
    skyArrayY[i] = z;
   }
   for(int i = 0; i < 100;i++){
   z = (rand() % (ub - lb1 + 1)) + lb1;
    skyArrayX[i] = z;
   }


}

void moonShadow() {
    // Darker pale yellow color for the moonlight reflection


    glBegin(GL_QUADS);
     glColor3ub(24, 53, 69); // sky color
    glVertex2d(1, 70);
     glColor3ub(24, 53, 69); // sky color
    glVertex2d(99, 70);
    glColor3ub(122, 126, 109);
 // Darker pale yellow color for the moonlight reflection
    glVertex2d(99, 40);
    glColor3ub(122, 126, 109);
 // Darker pale yellow color for the moonlight reflection
    glVertex2d(1, 40);
    glEnd();




}
void boat()
{

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(59,45,0);
    glVertex3f(65,45,0);
    glVertex3f(66,48,0);
    glVertex3f(61,48,0);
    glVertex3f(61,51,0);
    glVertex3f(60,51,0);
    glVertex3f(60,48.5,0);
    glVertex3f(58,48,0);
    glEnd();
    glColor3f(1,1,1);
    circle(.1,.1,60,47);
    glColor3f(1,1,1);
    circle(.1,.1,61,47);
    glColor3f(1,1,1);
    circle(.1,.1,62,47);
    glColor3f(1,1,1);
    circle(.1,.1,63,47);
    glColor3f(1,1,1);
    circle(.1,.1,64,47);
    glColor3ub(249, 252, 75);
    circle(.2,.2,61,51);

    glColor3ub(6, 0, 43);
    glBegin(GL_QUADS);
    glVertex2d(40,99);
    glVertex2d(50,60);
    glVertex2d(50,51);
    glVertex2d(41,99);
    glEnd();

}
void river() {



    glColor3ub(36, 51, 94);
    rectangle(1, 1, 99, 40);



}

void moonLightReflection() {
    // glColor3ub(255, 255, 200);//brighter yellow moon light reflection
    // Less bright pale yellow color for the moonlight reflection
    //glColor3ub(220, 220, 160);
    // Darker pale yellow color for the moonlight reflection






}

void pushTreesArray(){
    float z;
    int lb = 0, ub = 5;
    for(int i = 0; i < 3000;i++){
        z = 47 + ((rand() % (ub - lb + 1)) + lb);
        treeArrayS[i] =  z;
    }

     for(int i = 0; i < 2000;i++){
         z = 50 + ((rand() % (ub - lb + 1)) + lb);
        treeArrayF[i] =  z;
    }

}

void trees(){
    glColor4ub(7,26,33,255);
     glLineWidth(.81);
     glBegin(GL_LINES);
     int x = 0,y = 1999;
    for(float i = 1;i < 99.0;i+=.2){
        glVertex2d(i, 45);
        float b = treeArrayF[x];
        if(treeArrayF[x]>55){
            b = 55;
        }
        glVertex2d(i,b);
        x++;
    }
        for(float i = 1.1;i < 99.0;i+=.09){
        float b = treeArrayF[y];
        if(treeArrayF[y]>55){
            b = 55;
        }
        glVertex2d(i, 45);
        glVertex2d(i,b);
        y--;

    }
     int x1 = 0, y1 = 2999;
     for(float i = 1.01;i < 99.0;i+=.05){
        float b = treeArrayS[x1];
        if(treeArrayF[x1]>55){
            b = 55;
        }
        glVertex2d(i, 45);
        glVertex2d(i,b);
        x1++;
    }
     for(float i = 2;i < 99.0;i+=.05){
         float b = treeArrayS[y1];
        if(treeArrayF[y1]>55){
            b = 55;
        }

        glVertex2d(i, 45);

        glVertex2d(i,b);
        y1--;
    }

    glEnd();
}


void hills() {

    glColor3ub(5, 50, 75);


    triangle(1,55,10,5,60);
    triangle(9,55,20,15,60);
    triangle(20,55,30,25,60);
    triangle(30,55,40,35,60);
    triangle(40,55,50,45,60);
    triangle(50,55,60,55,60);
    triangle(60,55,70,65,60);
    triangle(70,55,80,75,60);
    triangle(80,55,90,85,60);
    triangle(90,55,99,95,60);

    rectangle(1,40,99,55);
    trees();
    glColor3ub(0,0,2);
    //rectangle(1,45,99,55);










}


void darkGrass(){
    int y = 13,z=18;
    glColor3ub(0,0,2);
        for(int i = 0;i<=96;i+=2){

        triangle(i,y,i+1,i-1,z);
        triangle(i,y,i+1,i+.5,z);
        triangle(i,y,i+1,i+2,z);
        }
         y = 15;
         z = 19;

         for(int i = 0;i<=99;i+=3){
        triangle(i,y,i+1,i-1,z);
        triangle(i,y,i+1,i+.5,z);
        triangle(i,y,i+1,i+2,z);
        }
         y = 16;
         z = 21;

         for(int i = 0;i<=99;i+=3){
        triangle(i,y,i+1,i-1,z);
        triangle(i,y,i+1,i+.5,z);
        triangle(i,y,i+1,i+2,z);
        }

    }
void par(){
    glColor4ub(0,0,0,255);
    rectangle(1,1,99,15);
    darkGrass();

}

void car(){
    if(tp <= 100){
        tp += .005;
    }else{
        tp = -1;
    }
    glutPostRedisplay();

    glPushMatrix();
    glTranslated(tp,0,0);
    glColor4ub(204,27,75,255);
    rectangle(5,44,10,47);
    glColor4ub(71,70,73,255);
    circle(.5,1,9,44);
    circle(.5,1,6,44);
    glColor4ub(204,27,75,255);
    rectangle(7,46,9.5,49);
    glColor4ub(255,255,255,255);
    circle(.2,.5,10,46);
    glColor4ub(255,255,255,255);
    rectangle(7.9,46.1,9.4,49);
    glPopMatrix();


}
void lampPost1(){




   glColor3ub(0,0,2);
   glLineWidth(3);
    drawLines(10,46,10,60);
    drawLines(7,60,10,60);
    drawLines(7,58,7,60);
    rectangle(6,56,8,58);


    glLineWidth(5);
    glColor4ub(229, 223, 200, 0.5);
    drawLines(6.5,56,7.5,56);
    glPopMatrix();
}
void lampPost2(){
     int ub = 100, lb = 0;
    int  z = (rand() % (ub - lb + 1)) + lb;
    glutPostRedisplay();


   glColor3ub(0,0,2);
   glLineWidth(3);
    drawLines(10,46,10,60);
     drawLines(10,60,13,60);
     drawLines(13,58,13,60);
     rectangle(12,56,14,58);
    glLineWidth(5);
    if(z>50){
        glColor4ub(229, 223, 200, 0.5);
    }else{
        glColor3ub(0,0,2);
    }
    drawLines(12.5,56,13.5,56);



    glPopMatrix();

}
void lampPost(){
   // glColor4ub(229, 223, 200, 0.5);
    int ub = 100, lb = 0;
    int  z = (rand() % (ub - lb + 1)) + lb;
    glutPostRedisplay();

   glPushMatrix();
   glTranslated(43,0,0);
   glColor3ub(0,0,2);
   glLineWidth(3);
    drawLines(10,46,10,60);
    drawLines(7,60,10,60);
    drawLines(7,58,7,60);

     drawLines(10,60,13,60);
     drawLines(13,58,13,60);
    rectangle(6,56,8,58);
    rectangle(12,56,14,58);
    glLineWidth(5);
    glColor4ub(229, 223, 200, 0.5);
    drawLines(6.5,56,7.5,56);
    if(z>50){
        glColor4ub(229, 223, 200, 0.5);
    }else{
        glColor3ub(0,0,2);
    }
    drawLines(12.5,56,13.5,56);



    glPopMatrix();


}
void busStand(){
glPushMatrix();
glTranslated(38,0,0);
 glColor4ub(52,52,52,255);
 rectangle1(7,52,15,52,14,51,8,51);
 rectangle(8,48,14,50);
 glColor3ub(0,0,2);
 glLineWidth(2);
 drawLines(8,46,8,51);
  drawLines(11,46,11,51);
  drawLines(14,46,14,51);
  glPopMatrix();

  //chairs



}
void road(){
    //full view
    glColor4ub(45,72,89,255);
    rectangle(1,40,99,48);
    //road
    glColor3ub(0,0,2);
    rectangle(1,42,99,46);
    glColor4ub(233,226,200,255);
    glBegin(GL_LINES);
    glVertex2d(2,44);
    glVertex2d(33,44);
    glVertex2d(35,44);
    glVertex2d(65,44);
    glVertex2d(67,44);
    glVertex2d(98,44);
    glEnd();
   // busStand();
    bool check = false;

   for(int i = -6 ; i<100;i+=10){
       glPushMatrix();
       glTranslated(i,0,0);
       if(check == false){
       lampPost2();
       check = true;
       }else{
           lampPost1();
           check = false;
       }
       glPopMatrix();

   }


    car();
}


void grass(){
   glColor3ub(77, 130, 4);
   rectangle1(1,40,99,40,99,55,1,55);

}
void whiteLines(){
    glColor3ub(255,255,255);
    rectangle(99,0,100,100);
     rectangle(0,99,100,100);
     rectangle(0,0,1,100);
}
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    moonShadow();
    hills();
    river();
    moonLightReflection();
    road();
    par();
    whiteLines();

    glFlush();
}

void init() {
    glClearColor(182, 182, 164, 0);
    glOrtho(0, 100, 0, 100, -150, 500);

}

int main(int argc, char ** argv) {
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1500, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Computer Graphics Project");
    pushStarsArraXY();
    pushTreesArray();
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
