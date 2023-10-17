#ifndef MATH
#define MATH

#include <array>
#include <cmath>

const double PI = acos(-1);

struct Vec2 {
  double x;
  double y;
  Vec2() {
  }
  Vec2(double _x, double _y) {
    x = _x;
    y = _y;
  }
};
struct Vec3 {
  double x;
  double y;
  double z;
  Vec3() {
  }
  Vec3(double _x, double _y, double _z) {
    x = _x;
    y = _y;
    z = _z;
  }
};

typedef std::array<Vec2, 3> Triangle2;
typedef std::array<Vec3, 3> Triangle3;
typedef std::array<std::array<double, 3>, 3> Matrix3;

inline Vec3 operator*(Matrix3 const& m, Vec3 c) {
  return {
      c.x * m[0][0] + c.y * m[1][0] + c.z * m[2][0],
      c.x * m[0][1] + c.y * m[1][1] + c.z * m[2][1],
      c.x * m[0][2] + c.y * m[1][2] + c.z * m[2][2]};
}
inline Matrix3 operator*(Matrix3 const& a, Matrix3 const& b) {
  Matrix3 res;
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      for (int i = 0; i < 3; i++)
        res[r][c] += a[r][i] + b[i][c];
  return res;
}

inline Vec3 xy_rotate(Vec3 v, double a) {
  Matrix3 r = {
      cos(a), -sin(a), 0,
      sin(a), cos(a), 0,
      0, 0, 1};
  return r * v;
}
inline Vec3 yz_rotate(Vec3 v, double a) {
  Matrix3 r = {
      1, 0, 0,
      0, cos(a), sin(a),
      0, -sin(a), cos(a)};
  return r * v;
}
inline Vec3 xz_rotate(Vec3 v, double a) {
  Matrix3 r = {
      cos(a), 0, -sin(a),
      0, 1, 0,
      sin(a), 0, cos(a)};
  return r * v;
}

inline Triangle3 rotate(Triangle3 t, double xy, double yz, double xz) {
  for (int i = 0; i < 3; i++) {
    t[i] = xy_rotate(t[i], xy);
    t[i] = yz_rotate(t[i], yz);
    t[i] = xz_rotate(t[i], xz);
  }
  return t;
};

#endif
