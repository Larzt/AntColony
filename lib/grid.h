#ifndef GRID_H
#define GRID_H

#include <iostream>

#include "cell.h"

class Cell;

class Grid {
 public:
  Grid(void);
  Grid(const int& w, const int& h);

  void Neighbors();
  void NextStep();
  void GenerateGrid();
  void SetToAnt(const int& x, const int& y);

  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }
  Cell** GetGrid() const { return grid_; }
  Cell* GetCell(Vector2 position) const;

  friend std::ostream& operator<<(std::ostream&, const Grid&);

  ~Grid() {};

 private:
  int width_;
  int height_;
  Cell** grid_;
};

#endif
