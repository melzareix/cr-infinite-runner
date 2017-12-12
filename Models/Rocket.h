//
// Created by Mohamed El Zarei on 12/10/17.
//

#ifndef GFX_PROJECT_ROCKET_H
#define GFX_PROJECT_ROCKET_H
#include <GLUT/glut.h>
#include "AABB.h"
#include "../Game/GameManager.h"

struct Rocket {
 public:
  Box * collisionBox;
  double zTrans = 0.0f;
  double xTrans = 0.0f;
  double rocketAngle = 0.0f;
  double nextZ = 1.0f;
  double angleSign = 1.0f;
  int f = 1;
  bool playedMusic = false;
  GameManager *gm;
  Rocket(GameManager *gm);
  void Render();
  void Animate();
  void PlayMusic();
 private:
  void Update();
  void DrawRocket();
  void drawRocketTail();
};
#endif //GFX_PROJECT_ROCKET_H
