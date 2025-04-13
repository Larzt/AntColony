struct Vector2 {
  int x_;
  int y_;
};

class Cell {
 public:
  Cell();
  ~Cell();
  void SetPosition(const int &x, const int &y);

 private:
  Vector2 position_;
};
