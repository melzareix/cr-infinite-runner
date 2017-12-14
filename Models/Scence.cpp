#include <cstdio>
#include <cstring>
#include <string>
#include "Scence.h"

void Scence::DrawWall(double thickness) {
  glPushMatrix();
  glTranslated(0.5, 0.5*thickness, 0.5);
  glScaled(1.0, thickness, 1.0);
  glutSolidCube(1);
  glPopMatrix();
  glColor3f(1.0, 1.0, 1.0);
  glPopMatrix();
}

void printToScreen(float x, float y, float z, const char *string, bool window) {
  int len, i;

  //set the position of the text in the window using the x and y coordinates
  if (window)
    glWindowPos3f(x, y, z);
  else
    glRasterPos3f(x, y, z);


  //get the length of the string to display
  len = (int) strlen(string);

  //loop to display character by character
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
  }
}
void Scence::Render() {
  DrawBox();
}
void Scence::DrawBox() {
  glPushMatrix();
  glTranslated(0, -0.8, 0);
  RenderGround();
  glPopMatrix();

  glPushMatrix();
  glTranslated(0, -0.75, 0);
  glScaled(1, 100, 1);
  RenderArena();
  glPopMatrix();

  glPushMatrix();
//  glScaled(10, 10, 10);
  glTranslated(0, 1, 0);
  glRotated(90,1,0,1);
  RenderSky();
  glPopMatrix();

  if (!state->gameEnded) {
  std::string s = "Score: " + std::to_string(state->score) + " (" + std::to_string(state->mult) + "x)";
  glColor3f(1.0, 0, 0);
  printToScreen(620, 550, 0, s.c_str(), true);

  s = "Lives: " + std::to_string(state->lives);
  glColor3f(1.0, 0, 0);
  printToScreen(620, 520, 0, s.c_str(), true);
  glColor3f(1.0, 1.0, 1.0);
  }
}
void Scence::AdjustCamera(int inc = 0) {
  double rad = cameraRadius;
  if (isThirdPersonCamera) rad = third_person_radius;
  if (inc) angle += 0.005f * inc *factor;
  x = sin(angle)*rad;
  z = cos(angle)*rad;
  if (angle >= 6.28) angle = 0.0;
}
void Scence::AdjustCameraOrientation(bool adjust, double xPos, double yInc) {
  if (cameraYpos > 1.0) cameraYpos -= 0.2;
  else state->didFinishLoading = true;
  AdjustCamera(0);
  if (!adjust) xPos = yInc = 0;
  gluLookAt(x - xPos, cameraYpos + yInc, z, -xPos, 1.0 + yInc, 0.0f, 0.0, 1.0f, 0.0);
}
Scence::Scence(double angle, double x, double z, double cameraRadius,
               int factor, double third_person_radius, GLuint tex_ground, GLuint tex_arena, GLuint tex_sky,
              GameState *state) {
  this->state = state;
  this->x = x;
  this->z = z;
  this->third_person_radius = third_person_radius;
  this->cameraRadius = cameraRadius;
  this->factor = factor;
  this->angle = angle - 0.01f*factor;
  this->tex_ground = tex_ground;
  this->tex_arena = tex_arena;
  this->tex_sky = tex_sky;
  AdjustCamera();
}

void Scence::DrawSky() {
  glDisable(GL_LIGHTING);    // Disable lighting
  glEnable(GL_TEXTURE_2D);    // Enable 2D texturing
  glMatrixMode(GL_TEXTURE);
  glBindTexture(GL_TEXTURE_2D, tex_sky);    // Bind the ground texture
  glPushMatrix();
  glBegin(GL_QUADS);
  float tex_cord = 0.49;
  glNormal3f(0, 1, 0);    // Set quad normal direction.
  glTexCoord2f(0, 0.0);
  glVertex3f(-110, 0, -110);
  glTexCoord2f(tex_cord, 0.0);
  glVertex3f(110, 0, -110);
  glTexCoord2f(tex_cord, tex_cord);
  glVertex3f(110, 0, 110);
  glTexCoord2f(0, tex_cord);
  glVertex3f(-110, 0, 110);
  glEnd();
  glPopMatrix();
  glEnable(GL_LIGHTING);    // Enable lighting again for other entites coming throung the pipeline.
  glDisable(GL_TEXTURE_2D);
  glMatrixMode(GL_MODELVIEW);
  glColor3f(1, 1, 1);    // Set material back to white instead of grey used for the ground texture.
}
void Scence::RenderSky() {
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
  GLUquadricObj * qobj = gluNewQuadric();
  glBindTexture(GL_TEXTURE_2D, tex_sky);
  gluQuadricTexture(qobj,GL_TRUE);
  gluQuadricNormals(qobj,GL_SMOOTH);
  gluSphere(qobj, 50, 100, 100);
  gluDeleteQuadric(qobj);
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}
void Scence::RenderGround() {
  glDisable(GL_LIGHTING);    // Disable lighting
  glEnable(GL_TEXTURE_2D);    // Enable 2D texturing
  glMatrixMode(GL_TEXTURE);
  glBindTexture(GL_TEXTURE_2D, tex_ground);    // Bind the ground texture
  glPushMatrix();
  glTranslatef(0, ground_offset, 0);
  glBegin(GL_QUADS);
  glNormal3f(0, 1, 0);    // Set quad normal direction.
  glTexCoord2f(0, 0.0);
  glVertex3f(-200, 0, -200);
  glTexCoord2f(50, 0.0);
  glVertex3f(200, 0, -200);
  glTexCoord2f(50, 50);
  glVertex3f(200, 0, 200);
  glTexCoord2f(0, 50);
  glVertex3f(-200, 0, 200);
  glEnd();
  glPopMatrix();
  glEnable(GL_LIGHTING);    // Enable lighting again for other entites coming throung the pipeline.
  glDisable(GL_TEXTURE_2D);
  glMatrixMode(GL_MODELVIEW);
  glColor3f(1, 1, 1);    // Set material back to white instead of grey used for the ground texture.
}
void Scence::RenderArena() {
  glDisable(GL_LIGHTING);    // Disable lighting
  glEnable(GL_TEXTURE_2D);    // Enable 2D texturing
  glMatrixMode(GL_TEXTURE);
  glBindTexture(GL_TEXTURE_2D, tex_arena);    // Bind the ground texture
  glPushMatrix();
  glTranslatef(0, arena_offset, 0);
  glBegin(GL_QUADS);
  glNormal3f(0, 1, 0);    // Set quad normal direction.
  glTexCoord2f(0, 0.0);
  glVertex3f(-2, 0, -200);
  glTexCoord2f(3, 0.0);
  glVertex3f(2, 0, -200);
  glTexCoord2f(3, 30);
  glVertex3f(1, 0, 200);
  glTexCoord2f(0, 30);
  glVertex3f(-1, 0, 200);
  glEnd();
  glPopMatrix();
  glEnable(GL_LIGHTING);    // Enable lighting again for other entites coming throung the pipeline.
  glDisable(GL_TEXTURE_2D);
  glMatrixMode(GL_MODELVIEW);
  glColor3f(1, 1, 1);    // Set material back to white instead of grey used for the ground texture.
}
void Scence::ChangeArena(GLuint arena, GLuint ground) {
  this->tex_arena = arena;
  this->tex_ground = ground;
}
void Scence::DrawGameLost() {
  glColor4f(1, 1, 1, 0.5);
  glPushMatrix();
  glTranslated(-1, 3, 0);
  glScaled(2, 3, 1);
  glRotated(90, 1, 0, 0);
  DrawWall(0.1);
  glPopMatrix();

  glColor4f(1, 0, 0, 1);
  std::string s = "Final Score\n";
  glColor3f(1.0, 0, 0);
  printToScreen(-0.6f, 2, 1, s.c_str(), false);

  s = std::to_string(state->score);
  glColor3f(1.0, 0, 0);
  printToScreen(-0.2f, 1.4, 1, s.c_str(), false);

  s = "Press N to reset\n";
  glColor3f(1.0, 0, 0);
  printToScreen(-0.8f, 1, 1, s.c_str(), false);

  s = "Press Q to quit\n";
  glColor3f(1.0, 0, 0);
  printToScreen(-0.8f, 0.5, 1, s.c_str(), false);

  if (state->lives == 0) {
    factor = -1;
    AdjustCamera(30);
    AdjustCameraOrientation(false, 0, 0);
    state->lives = -1;
  }

  glColor3f(1, 1, 1);
}
