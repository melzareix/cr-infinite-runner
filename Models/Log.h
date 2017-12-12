//
// Created by Mohamed El Zarei on 12/10/17.
//

#ifndef GFX_PROJECT_LOG_H
#define GFX_PROJECT_LOG_H
#include <GLUT/glut.h>
#include "AABB.h"
#include "../Game/GameManager.h"

struct Log {
 public:
  Box * collisionBox;
  int jmpDir = 1, th = 0;
  double jmpH = 0, transZ = -50;
  bool playedMusic = false;
  GameManager *gm;
  Log(GameManager *gm);
  void Render();
  void Animate();
  void PlayMusic();
 private:
  void DrawSpike();
  void DrawLog();
  void Update();
};
#endif //GFX_PROJECT_LOG_H
