//
// Created by Mohamed El Zarei on 11/19/17.
//

#ifndef ASSIGNMENT2_SCENCE_H
#define ASSIGNMENT2_SCENCE_H
#include <GLUT/glut.h>
#include <cmath>
#include "../TextureBuilder.h"
#include "../Game/GameState.h"

struct Scence {
  double angle, x, z, cameraRadius;
  int factor;
  double arena_offset = 1.0, ground_offset = 1.0, cameraYpos = 20.0, third_person_radius;
  bool isThirdPersonCamera = false;
  GLuint tex_ground, tex_arena, tex_sky;
  GameState *state;
  Scence(double angle,
         double x,
         double z,
         double cameraRadius,
         int factor,
         double third_person_radius,
         GLuint tex_ground,
         GLuint tex_arena,
         GLuint tex_sky,
         GameState *state);
  void DrawBox();
  void ChangeArena(GLuint, GLuint);
  void Render();
  void AdjustCamera(bool);
  void AdjustCameraOrientation(bool, double, double);
  void DrawGameLost();
 private:
  void RenderGround();
  void RenderArena();
  void RenderSky();
  void DrawSky();

  void DrawWall(double thickness);
};
#endif //ASSIGNMENT2_SCENCE_H
