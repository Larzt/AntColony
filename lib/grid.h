#include <iostream>

#include "cell.h"

class Grid {
 public:
  Grid(void);
  Grid(const int& w, const int& h);

  void GenerateGrid();

  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }
  Cell** GetGrid() const { return grid_; }

  friend std::ostream& operator<<(std::ostream&, const Grid&);

  ~Grid();

 private:
  int width_;
  int height_;
  Cell** grid_;
};
