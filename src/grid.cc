#include "grid.h"

Grid::Grid() {
  width_ = 5;
  height_ = 5;
}

Grid::Grid(const int &w, const int &h) {
  width_ = w;
  height_ = h;
}

void Grid::GenerateGrid() {
  grid_ = new Cell *[width_ + 2];

  for (size_t i = 0; i < width_; i++) {
    grid_[i] = new Cell[height_ + 2];
  }

  for (size_t i = -1; i <= width_; i++) {
    for (size_t j = -1; j <= height_; j++) {
      grid_[i][j].SetPosition(i, j);
    }
  }
}

std::ostream &operator<<(std::ostream &out, const Grid &grid) {
  const int width = grid.GetWidth();
  const int height = grid.GetHeight();

  for (size_t i = -1; i <= width; i++) {
    for (size_t j = -1; j <= height; j++) {
      std::cout << "#";
    }
    std::cout << std::endl;
  }
}
