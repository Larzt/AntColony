#include "cell.h"

Cell::Cell() {
  pheromone_.value = 0;
  position_ = Vector2(0, 0);
  updated_ = false;
}

void Cell::Neighbors(const Grid &grid) {
  Vector2 position = this->position_;
  for (int x = -1; x <= 1; x++) {
    for (int y = -1; y <= 1; y++) {
      Vector2 currPos(position.x + x, position.y + y);
      if (currPos == position) continue;

      if (grid.GetCell(currPos)->GetState()->GetType() == BORDER) continue;
      if (grid.GetCell(currPos)->GetState()->GetType() == ANT) continue;

      Cell *cell = grid.GetCell(currPos);
      neighbors_.emplace_back(cell);
    }
  }
}

std::ostream &operator<<(std::ostream &out, const Cell &cell) {
  EState st = cell.GetState()->GetType();
  switch (st) {
    case EMPTY:
      out << " ";
      break;
    case ANT:
      out << "+";
      break;
    case BORDER:
      out << "#";
      break;
    default:
      out << "?";
      break;
  }
  return out;
}
