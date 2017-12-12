//
// Created by Mohamed El Zarei on 12/10/17.
//

#ifndef GFX_PROJECT_FENCE_H
#define GFX_PROJECT_FENCE_H
#include <GLUT/glut.h>

struct Fence {
 public:
  GLuint texture;
  Fence(GLuint texture);
  void Render();
 private:
  void DrawFenceBar(int);
  void DrawFenceCubes();
};
#endif //GFX_PROJECT_FENCE_H
