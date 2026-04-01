export module math;

export {
  struct vec3 {
    double x, y, z;

    vec3();
    vec3(double x, double y, double z);

    double length() const;
    vec3 normalized() const;
  };

  vec3 operator+(const vec3& a, const vec3& b);
  vec3 operator-(const vec3& a, const vec3& b);
  vec3 operator*(const vec3& v, double s);
  vec3 operator*(double s, const vec3& v);

  double dot(const vec3& a, const vec3& b);
  vec3 cross(const vec3& a, const vec3& b);
}
