//
// Created by Mohamed El Zarei on 12/9/17.
//

#ifndef GFX_PROJECT_DARTGOBLIN_H
#define GFX_PROJECT_DARTGOBLIN_H
#include <GLUT/glut.h>
#include "AABB.h"

struct DartGoblin {
  int handAngleInc = 1;
  int legAngleInc = 1;
  float yInc = 0, xPos = 0;
  double dartHandAngle = 0.0f;
  double dartWeaponTrans = 0.0f;
  double dartLegAngle = 0.0f;
  bool isJumping = false, isGoingDown = false;
  Box *collisionBox;
  DartGoblin();
  void Render();
  void Animate();
  void Jump();
  void Update();
  void Move(int dir);
  void DrawBox();
};
#endif //GFX_PROJECT_DARTGOBLIN_H
