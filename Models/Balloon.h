//
// Created by Mohamed El Zarei on 12/12/17.
//

#ifndef GFX_PROJECT_BALLOON_H
#define GFX_PROJECT_BALLOON_H
#include <GLUT/glut.h>
#include "../Game/GameManager.h"
#include "AABB.h"

struct Balloon {
  Box * collisionBox;
  bool bombEnable = false;
  double bombX = 0.0f, bombY = 0.0f, bombZ = 0.0f;
  double balloonX = 0.0f, balloonY = 3.0f, balloonZ = -50.0f;
  double dropValue;
  GLuint texture, textureTop;
  GameManager *gm;
  Balloon(GameManager *gm, GLuint texture, GLuint textureTop);
  void Render();
  void Animate();
  void PlayMusic();
 private:
  void DrawBalloon();
  void DrawBalloonBomb();
  void Update();
};
#endif //GFX_PROJECT_BALLOON_H
