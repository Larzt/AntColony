// state.h
#pragma once

#include <vector>

#include "cell.h"

enum EState {
  BORDER,
  EMPTY,
  ANT,
};

class Cell;  // forward declaration

class State {
 public:
  virtual ~State() {}

  virtual void Update(Cell& cell) = 0;
  virtual EState GetType() const = 0;
};

// ---------- BORDER ----------
class BorderState : public State {
 public:
  void Update(Cell& cell) override;
  EState GetType() const override { return BORDER; }
};

// ---------- EMPTY ----------
class EmptyState : public State {
 public:
  void Update(Cell& cell) override;
  EState GetType() const override { return EMPTY; }
};

// ---------- ANT ----------
class AntState : public State {
 public:
  void Update(Cell& cell) override;
  EState GetType() const override { return ANT; }
};

// Global instances
extern BorderState borderState;
extern EmptyState emptyState;
extern AntState antState;
