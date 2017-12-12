//
// Created by Mohamed El Zarei on 12/10/17.
//

#include "Fence.h"
void Fence::DrawFenceBar(int factor) {
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
  glTranslated(factor * 1.35, -0.3, -25);
  glPushMatrix();
  glTranslated(0, 0.2, 0);
  glBindTexture(GL_TEXTURE_2D, texture);
  GLUquadric *cylinder = gluNewQuadric();
  gluQuadricTexture(cylinder, GL_TRUE);
  gluQuadricNormals(cylinder, GLU_SMOOTH);
  gluCylinder(cylinder, 0.05, 0.05, 100, 100, 100);
  gluDeleteQuadric(cylinder);
  glPopMatrix();

  glTranslated(0, -0.2, 0);
  gluCylinder(cylinder, 0.05, 0.05, 100, 100, 100);
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
  glColor3d(1,1,1);
}

void Fence::Render() {
  // first fence
  glPushMatrix();
  glScaled(0.3, 0.3, 0.3);
  glTranslated(4.5, -3.2, -300);
  for (int i = 0; i < 75; i++) {
    glPushMatrix();
    glTranslated(0, 2, -12 + 8*i);
    glScaled(4, 4, 4);
    DrawFenceCubes();
    glPopMatrix();
  }
  glPopMatrix();

  DrawFenceBar(1);

  // second fence
  glPushMatrix();
  glScaled(0.3, 0.3, 0.3);
  glTranslated(-4.5, -3.2, -300);
  for (int i = 0; i < 75; i++) {
    glPushMatrix();
    glTranslated(0, 2, -12 + 8*i);
    glScaled(4, 4, 4);
    DrawFenceCubes();
    glPopMatrix();
  }
  glPopMatrix();
  DrawFenceBar(-1);
}
void Fence::DrawFenceCubes() {
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_DEPTH);
  glPushMatrix();
  glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
  glEnable(GL_TEXTURE_GEN_T);
  glBindTexture(GL_TEXTURE_2D, texture);
  glPushMatrix();
  glScaled(1, 5, 1);
  glutSolidCube(0.15);
  glPopMatrix();
  glPopMatrix();
  glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
  glDisable(GL_TEXTURE_GEN_T);
  glDisable(GL_TEXTURE_2D);
  glColor3f(1, 1, 1);
}
Fence::Fence(GLuint texture) {
  this->texture = texture;
}
