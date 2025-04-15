#ifndef CELL_H
#define CELL_H

#include <cstdlib>  // rand() srand()
#include <ctime>    // time()
#include <iostream>
#include <vector>

#include "common.h"
#include "grid.h"
#include "state.h"

// Forward declarations
class Grid;
class State;

/**
 * @class Cell
 * @brief Represents a single cell in the grid, which can hold different states
 * (e.g., empty, ant).
 *
 * This class manages the cell's position, state, pheromone level, and its
 * interactions with neighbours. The cell can be updated, moved, or have its
 * pheromone level altered. It is also responsible for tracking whether it has
 * been updated during the current iteration to avoid conflicting state changes.
 */
class Cell {
 public:
  Cell();
  ~Cell() {};

  void Neighbors(const Grid &grid);
  std::vector<Cell *> GetNeighbors() { return neighbors_; };

  void ToggleUpdated() { updated_ = true; }
  void SetUpdated(bool val) { updated_ = val; }
  bool IsUpdated() const { return updated_; }

  void SetPos(Vector2 pos) { position_ = pos; }
  Vector2 GetPos() const { return position_; }

  void SetState(State *st) { state_ = st; }
  State *GetState() const { return state_; }

  void SetPheroLevel(float lvl) { pheromone_.value = lvl; }
  void AddPheroLevel(float lvl) { pheromone_.Add(lvl); }
  void SubPheroLevel(float lvl) { pheromone_.Sub(lvl); }
  float GetPheroLevel() { return pheromone_.Get(); }

  friend std::ostream &operator<<(std::ostream &, const Cell &);

 private:
  ///< The position of the cell in the grid.
  Vector2 position_;
  ///< The neighbouring cells of this cell.
  std::vector<Cell *> neighbors_;
  ///< The current state of the cell (e.g., empty, ant).
  State *state_;
  ///< The pheromone level of the cell.
  Pheromone pheromone_;
  ///< Flag indicating whether the cell has been updated in the current
  ///< iteration.
  bool updated_;
};

#endif
