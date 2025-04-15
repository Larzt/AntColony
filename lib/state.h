#ifndef STATE_H
#define STATE_H

#include <vector>

#include "cell.h"

/**
 * @enum EState
 * @brief Enumeration for the different types of states a cell can have.
 */
enum EState {
  BORDER,  ///< Represents the border of the grid where no ants or actions can
           ///< occur.
  EMPTY,   ///< A cell that is empty and unoccupied.
  ANT,     ///< A cell currently occupied by an ant.
};

// Forward declaration
class Cell;

/**
 * @class State
 * @brief Abstract base class that defines the behaviour of a cell state.
 */
class State {
 public:
  virtual ~State() {}

  virtual void Update(Cell& cell) = 0;
  virtual EState GetType() const = 0;
};

/**
 * @class BorderState
 * @brief Represents a cell that is part of the outer boundary of the grid.
 */
class BorderState : public State {
 public:
  void Update(Cell& cell) override;
  EState GetType() const override { return BORDER; }
};

/**
 * @class EmptyState
 * @brief Represents a cell that is unoccupied and available for state changes.
 */
class EmptyState : public State {
 public:
  void Update(Cell& cell) override;
  EState GetType() const override { return EMPTY; }
};

/**
 * @class AntState
 * @brief Represents a cell currently inhabited by an ant and handles ant
 * behaviour.
 */
class AntState : public State {
 public:
  void Update(Cell& cell) override;

  bool CheckOvercrowding(Cell& cell);
  void Move(Cell& cell);

  EState GetType() const override { return ANT; }
};

// Global instances
extern BorderState borderState;
extern EmptyState emptyState;
extern AntState antState;

#endif
