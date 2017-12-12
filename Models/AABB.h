//
// Created by Mohamed El Zarei on 12/11/17.
//

#ifndef GFX_PROJECT_AABB_H
#define GFX_PROJECT_AABB_H
struct Vec3 {
  double x, y, z;
};
struct Box {
  Vec3 center, m_vecMax, m_vecMin;
  double height, width, depth;
  Box(const Vec3 &center, double height, double width, double depth);
  void Update();
  bool didCollide(Box *tBox2);
};
#endif //GFX_PROJECT_AABB_H
