#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#endif
#include <string>
#include "apple.hpp"
// # include "elipse.hpp"
#include "monkey.hpp"
#define SPACEBAR 32
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "crocodile.hpp"
unsigned int bg1, bg2, bg3, intro, moral;
int scene = 0;
bool appleMove = false;
bool appleDown = false;
bool displayCloudS1 = true;
bool displayCloudS2 = true;
bool crocMaleFemale = true;
bool crocMonkey = true;
bool crocMonkeyS3 = true;
bool monkeyDown = false;
bool moveMonkeyCroc = false;
bool displayCloudS3 = true;
bool displayCloudS4 = true;
bool displayCloudS5 = false;
bool dialogsDone = false;
bool crocMonkeyS4 = true;
bool crocMonkeyS5 = true;
char *maleLine;
char *maleLine2 = " ";
char *femaleLine;
char *femaleLine2 = " ";
char *monkeyLine;
char *monkeyLine2;
char *line = "Click to continue";
int maleCounter = 0;
int femaleCounter = 0;
int monkeyCounter = 0;
void idle();
void idle2();
void moveCroc();
void keyboard();
void timer(int value);
void idle3();
void idle4(int);
void moveCrocMonkey();
float xpos = 2870, ypos = 2900, cXpos = 915, axpos = 1500, mypos = 2600, mxpos = 3400, b1xpos, b2xpos;
void idle5();

void drawtext(float x, float y, char *s)
{
    glColor3f(0, 0, 0);
    glRasterPos2f(x, y);
    for (int i = 0; s[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
}

void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 5000, 0, 5000, 0, -500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);
}

void displayIntro()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, intro);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void displayMoral()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, moral);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void displayScene1()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Monkey monkey;
    monkey.drawMonkey(3400, 2600, 0.5);
    Crocodile crocodile;
    crocodile.draw(cXpos, 575, 280);
    Apple apple;
    glDisable(GL_TEXTURE_2D);
    apple.draw(3600, 2800, 1);
    apple.draw(3600, 3900, 1);
    apple.draw(3400, 2800, 1);
    apple.draw(3400, 3800, 1);
    apple.draw(3000, 3800, 1);
    apple.draw(2600, 3100, 1);
    apple.draw(xpos, ypos, 1, 0);
    if (displayCloudS1)
    {
        if (crocMonkey)
        {
            switch (monkeyCounter)
            {
            case 0:
                monkeyLine = "Hello Mr Croc";
                monkeyLine2 = " ";
                break;
            case 1:
                monkeyLine = "How are you??";
                monkeyLine2 = " ";
                break;
            case 2:
                monkeyLine = "Good to hear that";
                monkeyLine2 = " ";
                break;
            case 3:
                monkeyLine = "Sure, take as many as you want";
                monkeyLine2 = " ";
                line = "Press D to drop the Apples";
                appleDown = true;
                break;
            case 4:
                monkeyLine = "Yes they are the best in this region";
                monkeyLine2 = " ";
                break;
            case 5:
                monkeyLine = "Sure convey my good wishes to her!!";
                monkeyLine2 = "Goodbye!!";
                line = "Press SpaceBar to move to the next scene";
                dialogsDone = true;
            }
            crocodile.cloud(3900, 3600, monkeyLine, monkeyLine2);
        }
        else
        {
            switch (maleCounter)
            {
            case 0:
                maleLine = "Hello Mr Monkey";
                maleLine2 = " ";
                break;
            case 1:
                maleLine = "Im fine..thank you";
                maleLine2 = " ";
                break;
            case 2:
                maleLine = "Those apples look very delicious!";
                maleLine2 = "Can I please have a few??";
                break;
            case 3:
                maleLine = "They are the most delicious apples";
                maleLine2 = " I have ever tasted";
                line = "Click to continue";
                break;
            case 4:
                maleLine = "Can you please give some apples for my wife";
                maleLine2 = "She would love it";
                break;
            }
            crocodile.cloud(2300, 800, maleLine, maleLine2);
        }
    }
    drawtext(1300, 3800, line);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
}
void displayScene2()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
    Crocodile crocodile;
    Apple apple;
    crocodile.draw(cXpos, 1000, 270, 0.8);
    if (displayCloudS2)
    {
        crocodile.draw(5000, 1000, 270, 0.8, 1);
        apple.draw(axpos, 260, 1);
        if (crocMaleFemale)
        {
            switch (maleCounter)
            {
            case 0:
                maleLine = "Hello Mrs Croc!";
                maleLine2 = " ";
                break;
            case 1:
                maleLine = "How are you";
                maleLine2 = " ";
                break;
            case 2:
                maleLine = "I have some\n apples for you";
                maleLine2 = " ";
                appleMove = true;
                break;
            case 3:
                maleLine = "I knew you would like them";
                maleLine2 = "They are the best in the region";
                break;
            case 4:
                maleLine = "A monkey on the river bank gave it to me";
                maleLine2 = " ";
                break;
            case 5:
                maleLine = "His heart?? I cannot do that!!";
                maleLine2 = " ";
                break;
            case 6:
                maleLine = "Okay..I will get him here";
                maleLine2 = " ";
                line = "Press SpaceBar to move to the next scene";
                dialogsDone = true;
                break;
            }
            crocodile.cloud(1700, 1000, maleLine, maleLine2);
        }
        else
        {
            switch (femaleCounter)
            {
            case 0:
                femaleLine = "Hello Mr Croc!";
                femaleLine2 = " ";
                break;
            case 1:
                femaleLine = "Im fine...How are you";
                break;
            case 2:
                femaleLine = "Wow apples!!";
                femaleLine2 = "Thank you so much";
                break;
            case 3:
                femaleLine = "They are so delicious";
                femaleLine2 = "Who gave them to you??";
                break;
            case 4:
                femaleLine = "A monkey?? Imagine how tasty he would be";
                femaleLine2 = "Get me his heart..I have a craving for it";
                break;
            case 5:
                femaleLine = "Can you not do a simple favour for your wife??";
                femaleLine2 = " ";
                break;
            }
            crocodile.cloud(2900, 1000, femaleLine, femaleLine2);
        }
    }
    drawtext(1700, 4000, line);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg2);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void displayScene3()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Monkey monkey;
    monkey.drawMonkey(mxpos, mypos, 0.5);
    Crocodile crocodile;
    crocodile.draw(cXpos, 575, 280);
    Apple apple;
    glDisable(GL_TEXTURE_2D);
    apple.draw(3600, 2800, 1);
    apple.draw(3600, 3900, 1);
    apple.draw(3400, 2800, 1);
    apple.draw(3400, 3800, 1);
    apple.draw(3000, 3800, 1);
    apple.draw(2600, 3100, 1);

    if (displayCloudS3)
    {
        if (crocMonkeyS3)
        {
            xpos = 3900;
            ypos = 3600;
            switch (monkeyCounter)
            {
            case 0:
                monkeyLine = "Hello Mr Croc!!";
                monkeyLine2 = " ";
                break;
            case 1:
                monkeyLine = "Im fine...thank you";
                monkeyLine2 = "Want more apples??";
                break;
            case 2:
                monkeyLine = "But how will i cross the river??";
                monkeyLine2 = " ";
                break;
            case 3:
                monkeyLine = "Well, i cannot disrespect";
                monkeyLine2 = "Mrs Croc's hospitality..";
                break;
            case 4:
                monkeyLine = "All right, I will come";
                monkeyLine2 = " ";
                break;
            case 5:
                monkeyLine = "Lets go Mr Croc!!";
                monkeyLine2 = " ";
                line = "Press Space Bar to Continue";
                displayCloudS3 = false;
                moveMonkeyCroc = true;
                //xpos = 2500;
                //ypos = 1300;
                break;
            }
            crocodile.cloud(xpos, ypos, monkeyLine, monkeyLine2);
        }
        else
        {
            switch (maleCounter)
            {
            case 0:
                maleLine = "Hello Dear friend!!";
                maleLine2 = "How are you??";
                break;
            case 1:
                maleLine = "Actually I came here to";
                maleLine2 = "Invite you home for dinner";
                break;
            case 2:
                maleLine = "No worries...";
                maleLine2 = "You can cross the river on my back";
                break;
            case 3:
                maleLine = "Please do agree my friend";
                maleLine2 = " ";
                break;
            case 4:
                maleLine = "Great! Hop On";
                maleLine2 = " ";
                monkeyDown = true;
                break;
            }
            crocodile.cloud(3000, 1000, maleLine, maleLine2);
        }
    }
    drawtext(1300, 3800, line);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void displayScene4()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
    Crocodile crocodile;
    Monkey monkey;
    crocodile.draw(cXpos, 1000, 270);
    monkey.drawMonkey(mxpos, 300, 0.6);
    if (displayCloudS4)
    {
        if (crocMonkeyS4)
        {
            switch (monkeyCounter)
            {
            case 0:
                monkeyLine = "Mr Croc how far is your home";
                monkeyLine2 = " ";

                break;
            case 1:
                monkeyLine = "Okay..";
                monkeyLine2 = " ";
                break;
            case 2:
                monkeyLine = "Tell me the truth Mr.Croc";
                monkeyLine2 = "What are your intentions ";
                break;
            case 3:
                monkeyLine = "But Mr.Croc";
                monkeyLine2 = "I left my heart at home";
                break;
            case 4:
                monkeyLine = "Okay!!";
                monkeyLine2 = "";
                line = "";
                dialogsDone = true;
                displayCloudS4 = false;
                break;
            }
            crocodile.cloud(b1xpos, 1600, monkeyLine, monkeyLine2);
        }
        else
        {
            switch (maleCounter)
            {
            case 0:
                maleLine = "Dont worry dear friend....";
                maleLine2 = "Its just a few minutes from here";
                break;
            case 1:
                crocMonkeyS4 = true;
                maleCounter = 3;
                glutPostRedisplay();
                break;
            case 3:
                maleLine = "To tell the truth";
                maleLine2 = "My wife wants to eat your heart.";
                break;
            case 4:
                maleLine = "oh NOOO!!";
                maleLine2 = "Let's go back to your home ";
                break;
            }
            crocodile.cloud(b2xpos, 1000, maleLine, maleLine2);
        }
    }
    drawtext(1700, 4000, line);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg2);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void displayScene5()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Monkey monkey;
    monkey.drawMonkey(mxpos, mypos, 0.5);
    Crocodile crocodile;
    crocodile.draw(cXpos, 575, 280);
    Apple apple;
    if (displayCloudS5)
    {
        if (crocMonkeyS5)
        {
            switch (monkeyCounter)
            {
            case 0:
                monkeyLine = "You dumb creature!!";
                monkeyLine2 = " ";
                line = "Click to continue";
                break;
            case 1:
                monkeyLine = "How can a creature";
                monkeyLine2 = "Live without its heart??";
                break;
            case 2:
                monkeyLine = "You have lost ";
                monkeyLine2 = "My trust you stupid creature";
                break;
            case 3:
                monkeyLine = "Get away from my sight";
                monkeyLine2 = "you ungrateful creature";
                line = "Press Space Bar to Continue";
                displayCloudS5 = false;
                break;
            }
            crocodile.cloud(3800, 3500, monkeyLine, monkeyLine2);
        }
        else
        {
            switch (maleCounter)
            {
            case 0:
                maleLine = "You tricked me!!";
                maleLine2 = " ";
                break;
            case 1:
                maleLine = "What shall I tell";
                maleLine2 = "my wife now??";
                break;
            case 2:
                maleLine = "You proved too clever";
                maleLine2 = "for my cunning";
                break;
            }
            crocodile.cloud(2300, 1000, maleLine, maleLine2);
        }
    }
    drawtext(1300, 3800, line);
    glDisable(GL_TEXTURE_2D);
    apple.draw(3600, 2800, 1);
    apple.draw(3600, 3900, 1);
    apple.draw(3400, 2800, 1);
    apple.draw(3400, 3800, 1);
    apple.draw(3000, 3800, 1);
    apple.draw(2600, 3100, 1);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void moveCroc()
{
    if (cXpos <= 5000)
    {
        cXpos += 30;
        glutPostRedisplay();
    }
    else
    {
        glutIdleFunc(NULL);
        dialogsDone = false;
        cXpos = 0;
        monkeyCounter = 0;
        maleCounter = 0;
        if (scene == 1)
        {
            scene++;
            line = "Click to continue";
            glutDisplayFunc(displayScene2);
            glutPostRedisplay();
        }
        else
        {
            scene++;
            glutDisplayFunc(displayMoral);
            glutPostRedisplay();
        }

        glutIdleFunc(idle2);
    }
}

void moveCrocScene2()
{
    if (cXpos <= 5000)
    {

        cXpos += 30;
        glutPostRedisplay();
    }
    else
    {
        glutIdleFunc(NULL);
        scene += 1;
        maleCounter = 0;
        femaleCounter = 0;
        monkeyCounter = 0;
        line = "Click to continue";
        glutDisplayFunc(displayScene3);
        cXpos = 915;
        glutPostRedisplay();
    }
}

void moveCrocMonkey()
{
    if (cXpos <= 5000 && mxpos <= 5000)
    {

        cXpos += 30;
        mxpos += 30;
        glutPostRedisplay();
    }
    else
    {

        glutIdleFunc(NULL);
        scene += 1;
        maleCounter = 0;
        femaleCounter = 0;
        monkeyCounter = 0;
        dialogsDone = false;
        line = "Click to continue";
        glutDisplayFunc(displayScene4);
        glutTimerFunc(50, idle4, 0);
        cXpos = 0;
        mxpos = 1200;
        b1xpos = 1800;
        b2xpos = 2100;
        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q')
        exit(0);
    if (scene == 0)
    {
        if (key == SPACEBAR)
        {
            scene += 1;
            line = "Click to continue";
            glutDisplayFunc(displayScene1);
            glutPostRedisplay();
        }
    }
    else if (scene == 1)
    {
        if (key == 'd' | key == 'D')
        {
            glutIdleFunc(idle);
        }
        if (appleDown)
        {
            if (key == SPACEBAR)
            {
                displayCloudS1 = false;
                monkeyCounter = 0;
                maleCounter = 0;
                xpos = 6000;
                glutIdleFunc(moveCroc);
                glutPostRedisplay();
            }
        }
    }
    else if (scene == 2)
    {
        if (appleMove == false)
            if (key == SPACEBAR)
            {
                displayCloudS2 = false;
                glutIdleFunc(moveCrocScene2);
                glutPostRedisplay();
            }
    }
    else if (scene == 3)
    {

        if (moveMonkeyCroc)
        {
            if (key == SPACEBAR)
            {
                glutIdleFunc(idle3);
                glutPostRedisplay();
                //glutIdleFunc(moveCrocMonkey);
            }
        }
    }
    else if (scene == 5)
    {
        if (key == SPACEBAR)
        {
            glutIdleFunc(moveCroc);
        }
    }
    else if (scene == 6)
    {
        if (key == 27)
            exit(0);
    }
}
void wait(int value)
{
    ypos = 2900;
    line = "Click to continue";
    glutPostRedisplay();
}

void idle()
{
    if (appleDown)
    {
        if (ypos >= 300)
        {
            ypos -= 30;
            glutPostRedisplay();
        }
        else
        {
            appleDown = true;
            glutIdleFunc(NULL);
            glutTimerFunc(1000, wait, 0);
        }
    }
}
void disappearApple(int value)
{
    axpos = 6000;
    glutPostRedisplay();
}
void idle2()
{

    if (appleMove)
    {
        if (axpos <= 2300)
        {

            axpos += 30;
            glutPostRedisplay();
        }
        else
        {
            appleMove = false;
            glutTimerFunc(1000, disappearApple, 0);
            glutIdleFunc(NULL);
        }
    }
}

void idle3()
{
    if (monkeyDown)
    {
        if (mypos >= 200)
        {
            mypos -= 60;
            mxpos -= 30;
            glutPostRedisplay();
        }
        else
        {

            monkeyDown = false;
            glutPostRedisplay();
            glutIdleFunc(moveCrocMonkey);
        }
    }
}

void idle4(int value)
{
    if (mxpos <= 6000 && cXpos <= 6000)
    {
        mxpos += 10;
        cXpos += 10;
        b1xpos += 10;
        b2xpos += 10;
        glutPostRedisplay();
        glutTimerFunc(50, idle4, 0);
    }
    else
    {
        monkeyCounter = 0;
        maleCounter = 0;
        femaleCounter = 0;
        cXpos = 0;
        mxpos = 1200;
        scene += 1;
        line = "Click to move monkey";
        glutDisplayFunc(displayScene5);
        glutPostRedisplay();
    }
}

void idle5()
{
    if (!monkeyDown)
    {
        if (mypos <= 2600 && mxpos <= 3400)
        {
            mypos += 60;
            mxpos += 60;
            glutPostRedisplay();
        }
        else
        {

            monkeyDown = true;
            displayCloudS5 = true;
            glutPostRedisplay();
            glutIdleFunc(NULL);
        }
    }
}

void mouse(int button, int state, int x, int y)
{

    if (scene == 1)
    {
        if (!dialogsDone)
        {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                if (crocMonkey)
                {
                    crocMonkey = false;
                    monkeyCounter++;
                }
                else
                {
                    crocMonkey = true;
                    maleCounter++;
                }

                glutPostRedisplay();
            }
        }
    }

    else if (scene == 2)
    {
        if (!dialogsDone)
        {
            if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            {
                if (crocMaleFemale)
                {
                    crocMaleFemale = false;
                    maleCounter++;
                }
                else
                {
                    crocMaleFemale = true;
                    femaleCounter++;
                }

                glutPostRedisplay();
            }
        }
    }

    else if (scene == 3)
    {

        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {

            //glutIdleFunc(idle3);
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (crocMonkeyS3)
            {
                crocMonkeyS3 = false;
                monkeyCounter++;
            }
            else
            {
                crocMonkeyS3 = true;
                maleCounter++;
            }
            glutPostRedisplay();
        }
    }
    else if (scene == 4)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (crocMonkeyS4)
            {
                crocMonkeyS4 = false;
                monkeyCounter++;
            }
            else
            {
                crocMonkeyS4 = true;
                maleCounter++;
            }
            glutPostRedisplay();
        }
    }
    else if (scene == 5)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (monkeyDown)
            {
                if (crocMonkeyS5)
                {
                    crocMonkeyS5 = false;
                    monkeyCounter++;
                }
                else
                {
                    crocMonkeyS5 = true;
                    maleCounter++;
                }
                glutPostRedisplay();
            }
            else
                glutIdleFunc(idle5);
        }
    }
}

void loadIntro(void)
{
    glGenTextures(1, &intro);
    glBindTexture(GL_TEXTURE_2D, intro);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg1
    int width, height, nrChannels;
    unsigned char *data = stbi_load("intro.psd", &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}

void loadMoral(void)
{
    glGenTextures(1, &moral);
    glBindTexture(GL_TEXTURE_2D, moral);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg1
    int width, height, nrChannels;
    unsigned char *data = stbi_load("moral.psd", &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}

void loadBackground(void)
{
    glGenTextures(1, &bg1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg1
    int width, height, nrChannels;
    unsigned char *data = stbi_load("background1.psd", &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}

void loadBackground2(void)
{
    glGenTextures(1, &bg2);
    glBindTexture(GL_TEXTURE_2D, bg2);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg1
    int width, height, nrChannels;
    unsigned char *data = stbi_load("Scene_2_Final.png", &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}

void loadBackground3()
{
    glGenTextures(1, &bg3);
    glBindTexture(GL_TEXTURE_2D, bg3);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg1
    int width, height, nrChannels;
    unsigned char *data = stbi_load("ty.jpg", &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}

void timer(int value)
{
    glutPostRedisplay();
}
void processMenu(int option)
{
    switch (option)
    {
    case 1:
        scene = 0;
        appleMove = false;
        appleDown = false;
        displayCloudS1 = true;
        displayCloudS2 = true;
        crocMaleFemale = true;
        crocMonkey = true;
        crocMonkeyS3 = true;
        monkeyDown = false;
        moveMonkeyCroc = false;
        displayCloudS3 = true;
        displayCloudS4 = true;
        displayCloudS5 = false;
        dialogsDone = false;
        crocMonkeyS4 = true;
        crocMonkeyS5 = true;
        maleLine2 = " ";
        femaleLine2 = " ";
        maleCounter = 0;
        femaleCounter = 0;
        monkeyCounter = 0;
        xpos = 2870;
        ypos = 2900;
        cXpos = 915;
        axpos = 1500;
        mypos = 2600;
        mxpos = 3400;
        glutDisplayFunc(displayIntro);
        glutPostRedisplay();
        break;
    case 2:
        exit(0);
        break;
    }
}
void menu(void)
{

    int menu;

    // create the menu and
    // tell glut that "processMenuEvents" will
    // handle the events
    menu = glutCreateMenu(processMenu);

    //add entries to our menu
    glutAddMenuEntry("Reset", 1);
    glutAddMenuEntry("Exit", 2);

    // attach the menu to the right button
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("A Clever Monkey");
    // glutFullScreen();
    glutDisplayFunc(displayIntro);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    loadIntro();
    loadMoral();
    loadBackground();
    loadBackground2();
    glutTimerFunc(500, timer, 0);
    glEnable(GL_DEPTH_TEST);
    init();
    menu();
    glutMainLoop();
}
