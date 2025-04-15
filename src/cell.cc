#include "cell.h"

/**
 * @brief Constructor for the Cell class.
 *
 * This constructor initialises the cell with default values: pheromone level is
 * set to 0, the position is set to (0, 0), and the updated flag is set to
 * false.
 */
Cell::Cell() {
  pheromone_.value = 0;
  position_ = Vector2(0, 0);
  updated_ = false;
}

/**
 * @brief Identifies and stores the neighbouring cells of the current cell.
 *
 * This method checks the neighbouring cells of the current cell in a 3x3 grid,
 * excluding the cell itself. It filters out border cells and cells that already
 * contain ants. Valid neighbouring cells are added to the `neighbors_` vector.
 *
 * @param grid The grid object that contains the cells.
 */
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

/**
 * @brief Outputs a visual representation of the cell's state.
 *
 * This method outputs a character representing the current state of the cell:
 * - A space (" ") for an EMPTY cell
 * - A plus sign ("+") for an ANT cell
 * - A hash ("#") for a BORDER cell
 *
 * @param out The output stream to which the cell representation is written.
 * @param cell The cell whose state is being represented.
 * @return The output stream after writing the cell's representation.
 */
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
