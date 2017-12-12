//
// Created by Mohamed El Zarei on 12/10/17.
//

#include <cstdio>
#include "Log.h"
void Log::Render() {
  glPushMatrix();
  glTranslated(-0.35, -0.5, transZ);
  glScaled(0.2, 0.2, 0.2);
  glRotated(90, 0, 1, 0);
  DrawLog();
  glPopMatrix();
}
void Log::DrawSpike() {
  glPushMatrix();
  glScalef(0.2, 0.5, 0.5);
  glColor3f(0.5, 0.5, 0.5);

  glPushMatrix();
  glutSolidTetrahedron();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-2 / 3.0, 0, 0);
  glRotated(180, 0, 1, 0);
  glutSolidTetrahedron();
  glPopMatrix();

  glPushMatrix();
  glTranslated(-0.333, -0.5, 0);
  glScalef(1.9, 1, 0.77);
  glRotatef(45, 0, 1, 0);
  glutSolidCube(1);
  glPopMatrix();

  glPopMatrix();}
void Log::DrawLog() {
  glPushMatrix();
  GLUquadricObj *qobj;
  glTranslatef(0, 1.0 + jmpH, 0);

  glRotatef(th, 0, 0, 1);
  glPushMatrix();

  //Log body
  glPushMatrix();
  glColor3f(152/256.0, 80/256.0, 8/256.0);
  qobj = gluNewQuadric();
  gluQuadricDrawStyle(qobj, GLU_LINE);
  gluCylinder(qobj, 1, 1, 4, 300, 300);
  glPopMatrix();

  //Log sides
  glPushMatrix();
  glColor3f(255/256.0, 156/256.0, 57/256.0);

  glPushMatrix();
  glTranslated(0, 0, 4);
  qobj = gluNewQuadric();
  gluQuadricNormals(qobj, GL_SMOOTH);
  gluDisk(qobj, 0, 1, 50, 50);
  gluDeleteQuadric(qobj);
  glPopMatrix();

  glPushMatrix();
  qobj = gluNewQuadric();
  gluQuadricNormals(qobj, GL_SMOOTH);
  gluDisk(qobj, 0, 1, 50, 50);
  gluDeleteQuadric(qobj);
  glPopMatrix();

  glPopMatrix();

  glPopMatrix();

  //Spikes
  glPushMatrix(); // top row of 3
  glTranslated(0, 1, 0);

  glTranslated(0, 0, 1);
  DrawSpike();

  glTranslated(0, 0, 1);
  DrawSpike();

  glTranslated(0, 0, 1);
  DrawSpike();

  glPopMatrix();
  ///

  ///
  glPushMatrix(); // bottom row of 3
  glTranslated(0, -1, 0);
  glRotatef(180, 0, 0, 1);

  glTranslated(0, 0, 1);
  DrawSpike();

  glTranslated(0, 0, 1);
  DrawSpike();

  glTranslated(0, 0, 1);
  DrawSpike();

  glPopMatrix();
  ///

  //
  glPushMatrix(); // side row of 2
  glTranslated(-1, 0, 0);
  glRotatef(90, 0, 0, 1);

  glTranslated(0, 0, 4/3.0);
  DrawSpike();

  glTranslated(0, 0, 4/3.0);
  DrawSpike();

  glPopMatrix();
  //

  //
  glPushMatrix(); // other side row of 2
  glTranslated(1, 0, 0);
  glRotatef(-90, 0, 0, 1);

  glTranslated(0, 0, 4/3.0);
  DrawSpike();

  glTranslated(0, 0, 4/3.0);
  DrawSpike();

  glPopMatrix();
  glPopMatrix();
  glPopMatrix();

  glColor3f(1.0, 1.0, 1.0);
}
void Log::Animate() {
  if (!playedMusic) {
    PlayMusic();
    playedMusic = true;
  }
  transZ += 0.5;
  th += 10;
  if (jmpDir==1)
    jmpH += 0.15;
  else
    jmpH -= 0.15;

  if (jmpH > 2.5 || jmpH <= 0)
    jmpDir ^= 1;
  Update();
  Render();
}
void Log::Update() {
  collisionBox->center.y = jmpH / 4;
  collisionBox->center.z = transZ;
  collisionBox->Update();
}
Log::Log(GameManager *gm) {
  collisionBox = new Box(Vec3{-0.35, -0.5 + jmpH, transZ / 2}, 1, 0.5 ,0);
  this->gm = gm;
}
void Log::PlayMusic() {
  gm->PlayLogMusic();
}
