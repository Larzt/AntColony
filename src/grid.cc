#include "grid.h"

#include "state.h"

// EmptyState emptyState;
// AntState antState;

Grid::Grid() : width_(5), height_(5) {}

Grid::Grid(const int &w, const int &h) : width_(w), height_(h) {}

void Grid::GenerateGrid() {
  grid_ = new Cell *[width_ + 2];
  for (int i = 0; i < width_ + 2; i++) {
    grid_[i] = new Cell[height_ + 2];
  }

  for (int x = -1; x <= width_; x++) {
    for (int y = -1; y <= height_; y++) {
      Cell &cell = grid_[x + 1][y + 1];
      cell.SetPos(Vector2(x, y));
      if (x == -1 || x == width_ || y == -1 || y == height_) {
        cell.SetState(&borderState);
      } else {
        cell.SetState(&emptyState);
      }
    }
  }
}

void Grid::SetToAnt(const int &x, const int &y) {
  grid_[x + 1][y + 1].SetState(&antState);
}

Cell *Grid::GetCell(Vector2 position) const {
  return &grid_[position.x + 1][position.y + 1];
}

void Grid::Neighbors() {
  for (int y = 1; y <= height_; y++) {
    for (int x = 1; x <= width_; x++) {
      grid_[y][x].SetUpdated(false);
      grid_[y][x].Neighbors(*this);
      grid_[y][x].SubPheroLevel(0.5);
    }
  }

  NextStep();
}

void Grid::NextStep() {
  for (int y = 1; y <= height_; y++) {
    for (int x = 1; x <= width_; x++) {
      if (grid_[y][x].IsUpdated()) continue;
      grid_[y][x].GetState()->Update(grid_[y][x]);
    }
  }
}

std::ostream &operator<<(std::ostream &out, const Grid &grid) {
  int width = grid.GetWidth();
  int height = grid.GetHeight();

  for (int y = 0; y <= height + 1; y++) {
    for (int x = 0; x <= width + 1; x++) {
      out << grid.GetGrid()[y][x];
    }
    out << std::endl;
  }

  return out;
}
