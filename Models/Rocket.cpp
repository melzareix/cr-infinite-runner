//
// Created by Mohamed El Zarei on 12/10/17.
//

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include "Rocket.h"
void Rocket::Render() {
  DrawRocket();
}
void Rocket::drawRocketTail() {
  // tail
  glPushMatrix();
  glColor3f(0.666, 0.666, 0.666);
  glTranslated(1, 0.5, -5);
  GLUquadric *tail1 = gluNewQuadric();
  gluCylinder(tail1, 0.1, 0.1, 0.05, 4, 100);
  glPopMatrix();

  // tail cover
  glPushMatrix();
  glColor3f(0.666, 0.666, 0.666);
  glTranslated(1, 0.5, -5);
  GLUquadric *cover1 = gluNewQuadric();
  gluDisk(cover1, 0, 0.1, 4, 100);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0.666, 0.666, 0.666);
  glTranslated(1, 0.5, -4.95);
  GLUquadric *cover2 = gluNewQuadric();
  gluDisk(cover2, 0, 0.1, 4, 100);
  glPopMatrix();
}
void Rocket::DrawRocket() {
  //lower cover of the rocket
  glPushMatrix();
  glColor3f(0.294, 0.294, 0.294);
  glRotated(-90, 1, 0, 0);
  GLUquadric *cover = gluNewQuadric();
  gluDisk(cover, 0, 0.2, 100, 100);
  glPopMatrix();

  // body
  glPushMatrix();
  glColor3f(0.294, 0.294, 0.294);
  glRotated(-90, 1, 0, 0);
  GLUquadric *body = gluNewQuadric();
  gluCylinder(body, 0.2, 0.2, 0.5, 100, 100);
  glPopMatrix();

  // head
  glPushMatrix();
  glColor3f(0.666, 0.666, 0.666);
  glTranslated(0, 0.5, 0);
  glRotated(-90, 1, 0, 0);
  GLUquadric *head = gluNewQuadric();
  gluCylinder(head, 0.2, 0, 0.2, 100, 100);
  glPopMatrix();

  // tails
  glPushMatrix();
  glTranslated(-0.8, -0.5, 5);
  drawRocketTail();
  glPopMatrix();

  glPushMatrix();
  glTranslated(-1.2, -0.5, 5);
  drawRocketTail();
  glPopMatrix();

  glPushMatrix();
  glTranslated(-4.98, -0.48, -0.8);
  glRotated(-90, 0, 1, 0);
  drawRocketTail();
  glPopMatrix();

  glPushMatrix();
  glTranslated(-4.98, -0.48, -1.2);
  glRotated(-90, 0, 1, 0);
  drawRocketTail();
  glPopMatrix();
}
void Rocket::Animate() {
  if (!playedMusic) {
    PlayMusic();
    playedMusic = true;
  }
  Update();
  glPushMatrix();
  glTranslated(xTrans, 0, -30 + zTrans);
//  glRotated(rocketAngle, 0, 1, 0);
  glRotated(110, 1, 0, 0);
  Render();
  glPopMatrix();
}
void Rocket::Update() {
  zTrans += 0.8;
//  xTrans = sin(zTrans) * 0.7;
//  rocketAngle += 2 * angleSign;

  if(zTrans >= nextZ) {
    nextZ += 2.0;
    f = 1;
  }

  if(zTrans >= nextZ - 1.0 && f) {
    angleSign *= -1;
    f = 0;
  }
  collisionBox->center.x = -xTrans;
  collisionBox->center.z = -30 + zTrans;
  collisionBox->Update();
}
Rocket::Rocket(GameManager *gm) {
  double r[] = {0.3, 0, -0.3};
  xTrans = r[random() % 3];
  collisionBox = new Box(Vec3{-xTrans, 0, 0}, 0.4, 0.5, 0);
  this->gm = gm;
}
void Rocket::PlayMusic() {
  gm->PlayRocketMusic();
}
