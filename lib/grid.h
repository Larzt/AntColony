#ifndef GRID_H
#define GRID_H

#include <iostream>

#include "cell.h"

class Cell;

/**
 * @class Grid
 * @brief Represents the two-dimensional grid environment for the simulation,
 *        containing all cells and managing their updates.
 *
 * This class manages the allocation and interaction of cells within a
 * rectangular space. It handles grid generation, simulation steps, and
 * user-defined ant placement.
 */
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
  ///< The logical width of the grid (not including borders).
  int width_;
  ///< The logical height of the grid (not including borders).
  int height_;
  ///< Two-dimensional array of cell pointers representing the grid.
  Cell** grid_;
};

#endif
