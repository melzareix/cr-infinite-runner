//
// Created by Mohamed El Zarei on 12/12/17.
//

#include "Potions.h"
void Potion::Render() {
  if (!rage) {
    glPushMatrix();
    glTranslated(0, -0.5, transZ);
    glScaled(0.35, 0.35, 0.35);
    glRotated(rotationAngle, 0, 1, 0);
    glPushMatrix(); //healing potion
    glColor4f(1, 1, 0, 0.9);
    glutSolidCube(1);
    glPopMatrix();
    DrawBottle();
    glPopMatrix();
  } else {
    glPushMatrix();
    glTranslated(0, -0.5, transZ);
    glScaled(0.35, 0.35, 0.35);
    glRotated(rotationAngle, 0, 1, 0);
    glPushMatrix(); //rage potion
    glColor4f(102 / 255.0, 0, 51 / 255.0, 0.9);
    glTranslatef(0, 0.55, 0);
    glutSolidCube(1);
    glPopMatrix();
    DrawBottle();
    glPopMatrix();
  }
  glColor3f(1, 1, 1);
}
void Potion::Animate() {
  Update();
  Render();
}
void Potion::Update() {
  if (taken) transZ = 10000;
  rotationAngle += 1;
  transZ += 0.2;
  collisionBox->center.x = 0;
  collisionBox->center.z = transZ;
  collisionBox->Update();
  if (rotationAngle >= 360) rotationAngle = 0;
}

Potion::Potion(GameManager *gm, bool rage) {
  this->gm = gm;
  this->rage = rage;
  collisionBox = new Box(Vec3{0, 0, 0}, 0.4, 0.5, 0);
}

void Potion::DrawPyramidFace() {
  glBegin(GL_POLYGON);
  glVertex3d(-1.05, 0, 0);
  glVertex3d(1.05, 0, 0);
  glVertex3d(0, 0.75, 1.05);
  glEnd();
}

void Potion::DrawPyramidHead() {
  glPushMatrix();
  glTranslated(0, 0, -1.05);
  DrawPyramidFace();
  glPopMatrix();

  glPushMatrix();
  glTranslated(0, 0, 1.05);
  glRotated(180, 0, 1, 0);
  DrawPyramidFace();
  glPopMatrix();

  glPushMatrix();
  glTranslated(-1.05, 0, 0);
  glRotated(90, 0, 1, 0);
  DrawPyramidFace();
  glPopMatrix();

  glPushMatrix();
  glTranslated(1.05, 0, 0);
  glRotated(-90, 0, 1, 0);
  DrawPyramidFace();
  glPopMatrix();
}
void Potion::DrawBottle() {
  glPushMatrix(); //glass bottle
  glColor4f(1, 1, 1, 0.3);
  glScalef(1, 1.3, 1);
  glTranslated(0, 0.5*1.05, 0);
  glutSolidCube(1.05);
  glPopMatrix();

  glPushMatrix();
  glTranslated(0, 1.3*1.05, 0);
  glScaled(0.5, 0.5, 0.5);
  DrawPyramidHead();
  glPopMatrix();

  GLUquadricObj *qobj;
  qobj = gluNewQuadric();
  gluQuadricNormals(qobj, GL_SMOOTH);

  glPushMatrix(); //bottle neck
  glTranslated(0, 1.55, 0);
  glRotated(-90, 1, 0, 0);
  gluCylinder(qobj, 0.2, 0.2, 0.2, 30, 30);
  glPopMatrix();

  qobj = gluNewQuadric();
  gluQuadricNormals(qobj, GL_SMOOTH);

  glPushMatrix();
  glColor3f(224/255.0, 112/255.0, 0);

  glPushMatrix(); //cork
  glColor3f(224/255.0, 112/255.0, 0);

  glTranslated(0, 1.75, 0);
  glRotated(-90, 1, 0, 0);
  gluCylinder(qobj, 0.22, 0.22, 0.1, 30, 30);
  glPopMatrix();

  glPushMatrix();
  glTranslated(0, 1.85, 0);
  glScaled(1, 0.00001, 1);
  glutSolidSphere(0.22, 30, 30);

  glPopMatrix();

  glPopMatrix();
}
void Potion::PlayMusic() {
  gm->PlaySpellMusic(rage);
}
