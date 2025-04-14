#include <iostream>

struct Vector2 {
  int x;
  int y;

  Vector2() : x(0), y(0) {}

  Vector2(const int &x_, const int &y_) {
    x = x_;
    y = y_;
  }
  friend std::ostream &operator<<(std::ostream &out, const Vector2 vec) {
    out << vec.x << ',' << vec.y;
    return out;
  }

  friend bool operator!=(const Vector2 v1, const Vector2 v2) {
    if (v1.x == v2.x && v1.y == v2.y) return false;
    return true;
  }

  friend bool operator==(const Vector2 v1, const Vector2 v2) {
    if (v1.x == v2.x && v1.y == v2.y) return true;
    return false;
  }
};

struct Pheromone {
  float value;
  Pheromone() : value(0) {}
  void Set(const float &v) { value = v; }
  void Add(const float &v) { value += v; }
  void Sub(const float &v) { value *= v; }
  float Get() { return value; }
};
