//
// Created by Mohamed El Zarei on 12/9/17.
//

#include <cstdio>
#include "DartGoblin.h"
void DartGoblin::Render() {
  glPushMatrix();
  glTranslated(xPos, yInc, 0);
  // mask
  glPushMatrix();
  glColor3d(0.8627, 0.549, 0.294);
  glTranslated(0, 1, 0);
  glScaled(1, 1.2, 0.4);
  glutSolidCube(0.5);
  glPopMatrix();

  // eyes
  glPushMatrix();
  glColor3d(0.4588, 0.733, 0.8784);
  glTranslated(0.13, 1.1, 0.12);
  GLUquadric *eye1 = gluNewQuadric();
  gluDisk(eye1, 0.05, 0.07, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3d(0, 0, 0);
  glTranslated(0.13, 1.1, 0.12);
  GLUquadric *eyeins1 = gluNewQuadric();
  gluDisk(eyeins1, 0, 0.05, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3d(1, 0, 0);
  glTranslated(0.13, 1.1, 0.13);
  GLUquadric *eyee1 = gluNewQuadric();
  gluDisk(eyee1, 0, 0.01, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3d(0.4588, 0.733, 0.8784);
  glTranslated(-0.13, 1.1, 0.12);
  GLUquadric *eye2 = gluNewQuadric();
  gluDisk(eye2, 0.05, 0.07, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3d(0, 0, 0);
  glTranslated(-0.13, 1.1, 0.12);
  GLUquadric *eyeins2 = gluNewQuadric();
  gluDisk(eyeins2, 0, 0.05, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3d(1, 0, 0);
  glTranslated(-0.13, 1.1, 0.13);
  GLUquadric *eyee2 = gluNewQuadric();
  gluDisk(eyee2, 0, 0.01, 100, 100);
  glPopMatrix();

  // mouth
  glPushMatrix();
  glColor3d(0.4588, 0.733, 0.8784);
  glTranslated(-0, 0.9, 0.12);
  GLUquadric *mouth = gluNewQuadric();
  gluDisk(mouth, 0.045, 0.07, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3d(0, 0, 0);
  glTranslated(0, 0.9, 0.12);
  GLUquadric *mouthins = gluNewQuadric();
  gluDisk(mouthins, 0, 0.045, 100, 100);
  glPopMatrix();

  // ears
  glPushMatrix();
  glColor3f(0.45098, 0.8129, 0.23529);
  glTranslated(0.25, 1, 0);
  GLUquadric *ear1front = gluNewQuadric();
  gluDisk(ear1front, 0, 0.07, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.45098, 0.8129, 0.23529);
  glTranslated(0.25, 1, 0);
  glRotated(180, 0, 1, 0);
  GLUquadric *ear1back = gluNewQuadric();
  gluDisk(ear1back, 0, 0.07, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.45098, 0.8129, 0.23529);
  glTranslated(-0.25, 1, 0);
  GLUquadric *ear2 = gluNewQuadric();
  gluDisk(ear2, 0, 0.07, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.45098, 0.8129, 0.23529);
  glTranslated(-0.25, 1, 0);
  glRotated(180, 0, 1, 0);
  GLUquadric *ear2back = gluNewQuadric();
  gluDisk(ear2back, 0, 0.07, 100, 100);
  glPopMatrix();

  // body
  glPushMatrix();
  glColor3f(0.45098, 0.8129, 0.23529);
  glTranslated(0, 0.6, 0);
  glScaled(1, 0.8, 0.6);
  glutSolidCube(0.3);
  glPopMatrix();

  // hand
  glPushMatrix();
  glColor3f(0.45098, 0.8129, 0.23529);
  glTranslated(0.17, 0.5, 0.1);
  glRotated(-60 + dartHandAngle, 1, 0, 0);
  glScaled(0.32, 2, 0.4);
  glutSolidSphere(0.07, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.45098, 0.8129, 0.23529);
  glTranslated(-0.17, 0.5, 0.1);
  glRotated(-60 - dartHandAngle, 1, 0, 0);
  glScaled(0.32, 2, 0.4);
  glutSolidSphere(0.07, 100, 100);
  glPopMatrix();

  // weapon
  glPushMatrix();
  glColor3f(0.5411, 0.5411, 0.266);
  glTranslated(-0.17, 0.4, 0.18);
  glRotated(-90 - (dartHandAngle/3), 1, 0, 0);
  GLUquadric *weapon = gluNewQuadric();
  gluCylinder(weapon, 0.02, 0.02, 0.4, 100, 100);
  glPopMatrix();

  // legs
  glPushMatrix();
  glColor3f(0.3725, 0.2352, 0.1372);
  glRotated(dartLegAngle, 1, 0, 0);
  glTranslated(0.07, 0.4, 0);
  glScaled(0.8, 2, 0.8);
  glutSolidCube(0.1);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.3725, 0.2352, 0.1372);
  glRotated(-dartLegAngle, 1, 0, 0);
  glTranslated(-0.07, 0.4, 0);
  glScaled(0.8, 2, 0.8);
  glutSolidCube(0.1);
  glPopMatrix();

  // hair
  glPushMatrix();
  glColor3f(0.2627, 0.61568, 0.30588);
  glTranslated(0.19, 1.36, 0);
  glRotated(-30, 0, 0, 1);
  glScaled(0.7, 2, 0.4);
  glutSolidSphere(0.07, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.2627, 0.61568, 0.30588);
  glTranslated(0.05, 1.36, 0);
  glScaled(0.7, 2, 0.4);
  glutSolidSphere(0.07, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.2627, 0.61568, 0.30588);
  glTranslated(-0.06, 1.36, 0);
  glScaled(0.7, 2, 0.4);
  glutSolidSphere(0.07, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.2627, 0.61568, 0.30588);
  glTranslated(-0.19, 1.36, 0);
  glRotated(30, 0, 0, 1);
  glScaled(0.7, 2, 0.4);
  glutSolidSphere(0.07, 100, 100);
  glPopMatrix();
  glPopMatrix();
}
void DartGoblin::Animate() {
  if (handAngleInc) {
    dartHandAngle += 1.1;
    dartWeaponTrans += 0.01;
  } else {
    dartHandAngle -= 1.1;
    dartWeaponTrans -= 0.01;
  }

  if (legAngleInc) {
    dartLegAngle += 0.7;
  } else {
    dartLegAngle -= 0.7;
  }

  if (dartHandAngle > 25 || dartHandAngle < -25) {
    handAngleInc = !handAngleInc;
  }

  if (dartLegAngle > 4 || dartLegAngle < -4) {
    legAngleInc = !legAngleInc;
  }
  Jump();
  Update();
  Render();
}
void DartGoblin::Move(int dir) {
  if (dir == 1 && xPos >= 2 * 0.3) return;
  if (dir == -1 && xPos < -0.5) return;
    xPos += dir * 0.5;
}
void DartGoblin::Jump() {
  if (isJumping) {
    yInc += 0.25;
    if (yInc > 4.5) {
      isJumping = false;
      isGoingDown = true;
    }
  }
  if (isGoingDown) {
    yInc -= 0.25;
    if (yInc <= 0.0) {
      yInc = 0;
      isGoingDown = isJumping = false;
    }
  }
}
void DartGoblin::DrawBox() {
  glBegin(GL_QUADS);
  // top
  glColor3f(1.0f, 0.0f, 0.0f);
  glNormal3f(0.0f, 1.0f, 0.0f);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glVertex3f(0.5f, 0.5f, 0.5f);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glVertex3f(-0.5f, 0.5f, -0.5f);

  glEnd();

  glBegin(GL_QUADS);
  // front
  glColor3f(0.0f, 1.0f, 0.0f);
  glNormal3f(0.0f, 0.0f, 1.0f);
  glVertex3f(0.5f, -0.5f, 0.5f);
  glVertex3f(0.5f, 0.5f, 0.5f);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glVertex3f(-0.5f, -0.5f, 0.5f);

  glEnd();

  glBegin(GL_QUADS);
  // right
  glColor3f(0.0f, 0.0f, 1.0f);
  glNormal3f(1.0f, 0.0f, 0.0f);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glVertex3f(0.5f, 0.5f, 0.5f);
  glVertex3f(0.5f, -0.5f, 0.5f);
  glVertex3f(0.5f, -0.5f, -0.5f);

  glEnd();

  glBegin(GL_QUADS);
  // left
  glColor3f(0.0f, 0.0f, 0.5f);
  glNormal3f(-1.0f, 0.0f, 0.0f);
  glVertex3f(-0.5f, -0.5f, 0.5f);
  glVertex3f(-0.5f, 0.5f, 0.5f);
  glVertex3f(-0.5f, 0.5f, -0.5f);
  glVertex3f(-0.5f, -0.5f, -0.5f);

  glEnd();

  glBegin(GL_QUADS);
  // bottom
  glColor3f(0.5f, 0.0f, 0.0f);
  glNormal3f(0.0f, -1.0f, 0.0f);
  glVertex3f(0.5f, -0.5f, 0.5f);
  glVertex3f(-0.5f, -0.5f, 0.5f);
  glVertex3f(-0.5f, -0.5f, -0.5f);
  glVertex3f(0.5f, -0.5f, -0.5f);

  glEnd();

  glBegin(GL_QUADS);
  // back
  glColor3f(0.0f, 0.5f, 0.0f);
  glNormal3f(0.0f, 0.0f, -1.0f);
  glVertex3f(0.5f, 0.5f, -0.5f);
  glVertex3f(0.5f, -0.5f, -0.5f);
  glVertex3f(-0.5f, -0.5f, -0.5f);
  glVertex3f(-0.5f, 0.5f, -0.5f);

  glEnd();
}
DartGoblin::DartGoblin() {
  collisionBox = new Box(Vec3{xPos, yInc, 6}, 0.3, 0.3, 0.05);
}
void DartGoblin::Update() {
  collisionBox->center.x = xPos;
  collisionBox->center.y = yInc;
  collisionBox->Update();
}
