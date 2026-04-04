module;
#include <cmath>
#include <stdexcept>

module math;

vec3::vec3() : x(0), y(0), z(0) {}

vec3::vec3(double x, double y, double z) : x(x), y(y), z(z) {}

double vec3::length() const {
  return std::sqrt(x * x + y * y + z * z);
}

vec3 vec3::normalized() const {
  double len = length();
  return {x / len, y / len, z / len};
}

double vec3::operator[](int i) const {
  switch (i) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    default:
      throw std::out_of_range("vec3 index out of range");
  }
}

double& vec3::operator[](int i) {
  switch (i) {
    case 0: return x;
    case 1: return y;
    case 2: return z;
    default:
      throw std::out_of_range("vec3 index out of range");
  }
}

vec3 operator+(const vec3& a, const vec3& b) {
  return {a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3 operator-(const vec3& a, const vec3& b) {
  return {a.x - b.x, a.y - b.y, a.z - b.z};
}

vec3 operator*(const vec3& v, double s) {
  return {v.x * s, v.y * s, v.z * s};
}

vec3 operator*(double s, const vec3& v) {
  return v * s;
}

double dot(const vec3& a, const vec3& b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 cross(const vec3& a, const vec3& b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
