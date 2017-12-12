//
// Created by Mohamed El Zarei on 12/12/17.
//

#include <cmath>
#include <cstdlib>
#include <cstdio>
#include "Balloon.h"

void Balloon::Render() {
  glPushMatrix();
  glTranslated(balloonX, balloonY, balloonZ);
  DrawBalloon();
  glPopMatrix();
  if (bombEnable) {
    glPushMatrix();
    glTranslated(bombX, bombY, bombZ);
    DrawBalloonBomb();
    glPopMatrix();
  }
}
void Balloon::Animate() {
  Update();
  Render();
}
void Balloon::PlayMusic() {
  gm->PlayBombMusic();
}
void Balloon::Update() {

  balloonZ += 0.25; // lsa mbaztsh
  balloonX = sin(balloonZ);

  // don't forget to reset bombEnable
  if (balloonZ >= dropValue && !bombEnable) {
    bombEnable = true;
    bombX = balloonX;
    bombY = balloonY;
    bombZ = balloonZ;
    PlayMusic();
  }

  if (bombY >= 0) {
    bombY -= 0.7;
  }
  bombZ += 0.25;

  if (bombEnable) {
    collisionBox->center.x = -bombX;
    collisionBox->center.y = 0;
    collisionBox->center.z = bombZ;
  }
  collisionBox->Update();

}
void Balloon::DrawBalloon() {
  glPushMatrix();

  // body
  glPushMatrix();
  glColor3f(0.439, 0.3333, 0.227);
  glutSolidCube(0.5);
  glPopMatrix();

  // ropes
  glPushMatrix();
  glColor3f(1, 1, 1);
  glTranslated(0.25, 0.25, 0.25);
  glRotated(-70, 1, 0, 0);
  GLUquadric *rope1 = gluNewQuadric();
  gluCylinder(rope1, 0.01, 0.01, 1, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 1, 1);
  glTranslated(-0.25, 0.25, 0.25);
  glRotated(-70, 1, 0, 0);
  GLUquadric *rope3 = gluNewQuadric();
  gluCylinder(rope3, 0.01, 0.01, 1, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 1, 1);
  glTranslated(0.25, 0.25, -0.25);
  glRotated(-110, 1, 0, 0);
  GLUquadric *rope2 = gluNewQuadric();
  gluCylinder(rope2, 0.01, 0.01, 1, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 1, 1);
  glTranslated(-0.25, 0.25, -0.25);
  glRotated(-110, 1, 0, 0);
  GLUquadric *rope4 = gluNewQuadric();
  gluCylinder(rope4, 0.01, 0.01, 1, 100, 100);
  glPopMatrix();

  // balloon
  glPushMatrix();
  glColor3f(0.196, 0.3137, 0.4313);
  glTranslated(0, 1.3, 0);
  glutSolidSphere(0.7, 100, 100);
  glPopMatrix();
  glPopMatrix();

  glColor3f(1, 1, 1);
}
Balloon::Balloon(GameManager *gm) {
  double f[] = {-6, -2, -8};
  dropValue = f[random()%3];
  printf("%.2f\n", dropValue);
  this->gm = gm;
  collisionBox = new Box(Vec3{-1000, -1000, -1000}, 0, 0.3, 0);
}
void Balloon::DrawBalloonBomb() {
  // Sphere
  glPushMatrix();
  glutSolidSphere(0.2, 100, 100);
  glPopMatrix();

  // head
  glPushMatrix();
  glColor3f(0.898, 0.635, 0.298);
  glTranslated(0, 0.2, 0);
  glRotated(-90, 1, 0, 0);
  GLUquadric *head = gluNewQuadric();
  gluCylinder(head, 0.07, 0.07, 0.05, 100, 100);
  glPopMatrix();

  // head covers
  glPushMatrix();
  glColor3f(0.898, 0.635, 0.298);
  glTranslated(0, 0.2, 0);
  glRotated(-90, 1, 0, 0);
  GLUquadric *cover1 = gluNewQuadric();
  gluDisk(cover1, 0, 0.07, 100, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.898, 0.635, 0.298);
  glTranslated(0, 0.25, 0);
  glRotated(-90, 1, 0, 0);
  GLUquadric *cover2 = gluNewQuadric();
  gluDisk(cover2, 0, 0.07, 100, 100);
  glPopMatrix();

  // fire head
  glPushMatrix();
  glColor3f(0.98, 0.90, 0.843);
  glTranslated(0, 0.2, 0);
  glRotated(-90, 1, 0, 0);
  GLUquadric *fireHead = gluNewQuadric();
  gluCylinder(fireHead, 0.04, 0.04, 0.12, 100, 100);
  glPopMatrix();

  // fire
  glPushMatrix();
  glColor3f(0.98, 0.66, 0.1568);
  glTranslated(0, 0.35, 0);
  glRotated(-90, 0, 1, 0);
  glScaled(0.5, 1, 0.15);
  glutSolidSphere(0.07, 100, 100);
  glPopMatrix();

  glColor3f(1, 1, 1);
}
