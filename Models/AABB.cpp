//
// Created by Mohamed El Zarei on 12/11/17.
//

#include <cstdio>
#include "AABB.h"
Box::Box(const Vec3 &center, double width, double height, double depth)
    : center(center), height(height), width(width), depth(depth) {
  m_vecMax.x = center.x + width;
  m_vecMin.x = center.x - width;

  m_vecMax.y = center.y + height;
  m_vecMin.y = center.y - height;

  m_vecMax.z = center.z + depth;
  m_vecMin.z = center.z - depth;

}
bool Box::didCollide(Box *tBox2) {
  Update();
  bool x1 = this->m_vecMax.x >= tBox2->m_vecMin.x;
  bool x2 = this->m_vecMin.x <= tBox2->m_vecMax.x;
  bool x =  x1 && x2;
  bool y = this->m_vecMax.y >= tBox2->m_vecMin.y && this->m_vecMin.y <= tBox2->m_vecMax.y;
  bool z = this->m_vecMax.z >= tBox2->m_vecMin.z && this->m_vecMin.z <= tBox2->m_vecMax.z;
  bool ans = x && y && z;
  if (ans) {
    printf("COLLIDE\n");
  }
  return ans;
}
void Box::Update() {
  m_vecMax.x = center.x + width;
  m_vecMin.x = center.x - width;

  m_vecMax.y = center.y + height;
  m_vecMin.y = center.y - height;

  m_vecMax.z = center.z + depth;
  m_vecMin.z = center.z - depth;
}
