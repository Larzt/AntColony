#ifndef CELL_H
#define CELL_H

#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
#include <iostream>
#include <vector>

#include "common.h"
#include "grid.h"
#include "state.h"

class Grid;
class State;

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
  Vector2 position_;
  std::vector<Cell *> neighbors_;
  State *state_;
  Pheromone pheromone_;
  bool updated_;
};

#endif
