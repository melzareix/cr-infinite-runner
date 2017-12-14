//
// Created by Mohamed El Zarei on 12/12/17.
//

#ifndef GFX_PROJECT_POTIONS_H
#define GFX_PROJECT_POTIONS_H
#include "../Game/GameState.h"
#include "../Game/GameManager.h"
#include "AABB.h"
#include <GLUT/glut.h>

struct Potion {
  GameState* state;
  GameManager* gm;
  Box * collisionBox;
  bool rage;
  double rotationAngle = 0, transZ = -40;
  bool taken = false;
  float alpha = 0.3;
  int alphaFactor = 1;
  explicit Potion(GameManager *gm, bool);
  void Render();
  void Animate();
  void PlayMusic();
 private:
  void DrawPyramidFace();
  void DrawPyramidHead();
  void DrawBottle();
  void Update();
};
#endif //GFX_PROJECT_POTIONS_H
