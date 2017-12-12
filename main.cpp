#include <iostream>
#include <GLUT/glut.h>
#include "Game/GameManager.h"
#include "Models/Scence.h"
#include "Models/DartGoblin.h"
#include "Models/Fence.h"
#include "Models/Log.h"
#include "Models/Balloon.h"
#include "Models/Rocket.h"
#include "Models/Potions.h"

double angle = 0, alpha = 0;

#define ARENA_CHANGING_TIME 6000
#define SHOW_SPELL_EVERY 20000
GameManager *gm;
Scence *scence;
Fence *fence;
GameState *state;
Log *obstacleLog;
Rocket *rocket;
Balloon *balloon;
DartGoblin *dartGoblin;
Potion *heal;
Potion *rage;
GLuint textures[10];
GLuint grounds[3];
GLuint materials[3];

void SetupLights() {
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  GLfloat ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
  GLfloat diffuse[] = {0.3f, 0.3f, 0.3f, 1.0f};
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
  GLfloat specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
  glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

  glPushMatrix();
  GLfloat lightPosition[] = {0.0f, 300.0f, static_cast<GLfloat>(angle), 0.0f };
  glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
  glPopMatrix();

}
void setupCamera() {
  glMatrixMode(GL_PROJECTION);
  gluPerspective(0, 800/600, 0.001, 100);
  glMatrixMode(GL_MODELVIEW);
  scence->AdjustCameraOrientation(scence->isThirdPersonCamera, dartGoblin->xPos, dartGoblin->yInc);
}

void init() {
  // Load textures
  loadBMP(&textures[0], "../Content/Textures/bone_arena.bmp", 832, 1048, true);
  loadBMP(&textures[1], "../Content/Textures/training_camp.bmp", 256, 256, true);
  loadBMP(&textures[2], "../Content/Textures/jungle-2.bmp", 1024, 784, true);
//  loadBMP(&textures[3], "../Content/Textures/sky-tex.bmp", 1600, 960, true);
  loadBMP(&textures[3], "../Content/Textures/sky-c.bmp", 1024, 1024, true);
//  loadBMP(&textures[3], "../Content/Textures/sky-tex-2.bmp", 1024, 1024, true);
//  loadBMP(&textures[3], "../Content/Textures/sky-jpg.bmp", 640, 159, true);
//  loadBMP(&textures[3], "../Content/Textures/sky4-jpg.bmp", 640, 360, true);
  loadBMP(&materials[0], "../Content/Textures/wood-3.bmp", 612, 408, true);
  loadBMP(&materials[1], "../Content/Textures/wood-5.bmp", 600, 600, true);
  materials[2] = materials[0];
  loadBMP(&grounds[0], "../Content/Textures/sand.bmp", 256, 256, true);
  loadBMP(&grounds[1], "../Content/Textures/water.bmp", 800, 600, true);
  loadBMP(&grounds[2], "../Content/Textures/ground.bmp", 956, 956, true);
  state = new GameState();
  int c = state->currentScence;
  scence = new Scence(0.01, 0, 0, 10.0f, 1, 6.0f, grounds[c], textures[c], textures[3], state);
  fence = new Fence(materials[1]);
  dartGoblin = new DartGoblin();
  gm = new GameManager();
  obstacleLog = new Log(gm);
  rocket = new Rocket(gm);
  balloon = new Balloon(gm);
  heal = new Potion(gm, false);
  rage = new Potion(gm, true);
}

void Reshape(int w, int h) {
  // Prevent a divide by zero, when window is too short
  if (h==0)
    h = 1;
  double ratio = w/h*1.0;
  // Use the Projection Matrix
  glMatrixMode(GL_PROJECTION);
  // Reset Matrix
  glLoadIdentity();
  // Set the viewport to be the entire window
  glViewport(0, 0, w, h);
  // Set the correct perspective.
  gluPerspective(45, ratio, 1, 1000);
  // Get Back to the Modelview
  glMatrixMode(GL_MODELVIEW);
}
void Display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  SetupLights();
  setupCamera();
  glPushMatrix();
  scence->Render();
  glPopMatrix();
  glPushMatrix();
  glRotated(180, 0, 1, 0);
  glScaled(0.5, 0.5, 0.5);
  glTranslated(0, -1, -12);
  dartGoblin->Animate();
  glPopMatrix();

  glPushMatrix();
  fence->Render();
  glPopMatrix();

  if (state->didFinishLoading) { // load obstacles
    switch (state->currentScence) {
      case 0:obstacleLog->Animate();
        break;
      case 1:rocket->Animate();
        break;
      default:
        balloon->Animate();
        break;
    }
    glPushMatrix();
    if (state->startShowingSpells) {
      if (state->rageShown) {
        heal->Animate();
      } else {
        rage->Animate();
      }
    }
    glPopMatrix();
  }

  if (state->gameEnded) {
    scence->DrawGameLost();
  }
  glutSwapBuffers();
}

void KeyPressed(unsigned char key, int x, int y) {
  if (key == 'n' && state->gameEnded) {
    init();
  }
  if (key == 'q' && state->gameEnded) {
    exit(EXIT_SUCCESS);
  }
  if (state->gameEnded) return;
  if (key=='r') {
    scence->factor = 1;
    scence->AdjustCamera(true);
  }
  if (key=='e') {
    scence->factor = -1;
    scence->AdjustCamera(true);
  }
  if (key=='a') {
    gm->PlayGoblinWalk();
    dartGoblin->Move(1);
  }
  if (key=='d') {
    gm->PlayGoblinWalk();
    dartGoblin->Move(-1);
  }
  if (key=='w') {
    if (!dartGoblin->isGoingDown) {
      dartGoblin->isJumping = true;
      gm->PlayGoblinJump();
    }
  }
  if (key=='c') {  // Change Camera
    printf("%d\n", scence->isThirdPersonCamera);
    scence->isThirdPersonCamera = !scence->isThirdPersonCamera;
  }
  glutPostRedisplay();
}
void CollisionDetectionTimer(int o) {
  switch (state->currentScence) {
    case 0:
      if (dartGoblin->collisionBox->didCollide(obstacleLog->collisionBox)) {
        state->lives--;
        gm->PlayCollision();
      }
      break;
    case 1:
      if (dartGoblin->collisionBox->didCollide(rocket->collisionBox)) {
        state->lives--;
        gm->PlayCollision();
      }
      break;
    default:
      if (dartGoblin->collisionBox->didCollide(balloon->collisionBox)) {
        state->lives--;
        gm->PlayCollision();
      }
      break;
  }

  if (dartGoblin->collisionBox->didCollide(rage->collisionBox)) {
    state->mult++;
    rage->taken = true;
    gm->PlaySpellMusic(true);
  }

  if (dartGoblin->collisionBox->didCollide(heal->collisionBox)) {
    heal->taken = true;
    state->lives++;
    gm->PlaySpellMusic(false);
  }
  state->CheckGameState();
  if (state->gameEnded) {
    glutPostRedisplay();
  }
  glutTimerFunc(10, CollisionDetectionTimer, o);
}
void Timer(int o) {

  alpha += 0.1;// adjust the speed from here
  angle = cos(alpha) * 30;

  scence->arena_offset = scence->arena_offset < 0.0f ? 1.0f : scence->arena_offset;
  scence->arena_offset -= 0.005;
  scence->ground_offset = scence->ground_offset < 0.0f ? 1.0f : scence->ground_offset;
  scence->ground_offset -= 0.002;
  if (scence->cameraYpos <= 1.0 && !state->gameEnded)
    state->score += state->mult;

  if (o >= ARENA_CHANGING_TIME && !state->gameEnded) {
    state->currentScence = (state->currentScence + 1)%3;
    scence->ChangeArena(textures[state->currentScence], grounds[state->currentScence]);
    fence->texture = materials[state->currentScence];
    printf("Current Scence => %d\n", state->currentScence);
    o = 0;
    switch (state->currentScence) {
      case 0:obstacleLog = new Log(gm);
        break;
      case 1:rocket = new Rocket(gm);
        break;
      default:balloon = new Balloon(gm);
        break;
    }
  }

  gm->PlayBackgroundMusic();
  glutPostRedisplay();
  int add = 0;
  if (state->didFinishLoading) add = 25;

  glutTimerFunc(25, Timer, o + add);
}
void ShowSpellsTimer(int o) {
  if (o >= SHOW_SPELL_EVERY) {
    o = 0;
    state->startShowingSpells = true;
    if (state->rageShown) { // last spell was rage, show heal
      state->rageShown = false;
      heal = new Potion(gm, false);
    } else {
      rage = new Potion(gm, true);
      state->rageShown = true;
    }
  }
  glutTimerFunc(100, ShowSpellsTimer, o + 100);
}
int main(int argc, char **argv) {
  // Initialization
  glutInit(&argc, argv);
  glutInitWindowPosition(200, 100);
  glutInitWindowSize(800, 600);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow("Project");
  glDisable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

  glEnable(GL_DEPTH_TEST);
  init();

  glutDisplayFunc(Display);
  glutReshapeFunc(Reshape);
  glutKeyboardFunc(KeyPressed);
  glutTimerFunc(100, Timer, 0);
  glutTimerFunc(10, CollisionDetectionTimer, 0);
  glutTimerFunc(100, ShowSpellsTimer, 0);
  glutMainLoop();
}