#include "grid.h"

#include "state.h"

/**
 * @brief Default constructor for the Grid class.
 *
 * This constructor initialises the grid with default dimensions: 5x5.
 */
Grid::Grid() : width_(5), height_(5) {}

/**
 * @brief Constructor for the Grid class with specified dimensions.
 *
 * This constructor initialises the grid with the specified width and height.
 *
 * @param w The width of the grid.
 * @param h The height of the grid.
 */
Grid::Grid(const int &w, const int &h) : width_(w), height_(h) {}

/**
 * @brief Generates the grid, creating cells and setting their initial states.
 *
 * This method allocates memory for the grid and sets the state of the cells:
 * - Border cells are assigned a BorderState.
 * - Interior cells are assigned an EmptyState.
 *
 * The grid is represented as a 2D array of `Cell` objects.
 */
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

/**
 * @brief Sets the cell at the specified coordinates to an ant.
 *
 * This method changes the state of the cell at the given (x, y) coordinates to
 * `AntState`.
 *
 * @param x The x-coordinate of the cell.
 * @param y The y-coordinate of the cell.
 */
void Grid::SetToAnt(const int &x, const int &y) {
  grid_[x + 1][y + 1].SetState(&antState);
}

/**
 * @brief Retrieves the cell at the specified position.
 *
 * This method returns a pointer to the cell at the given (x, y) coordinates,
 * adjusted for the grid's borders.
 *
 * @param position The position of the cell to retrieve.
 * @return A pointer to the cell at the given position.
 */
Cell *Grid::GetCell(Vector2 position) const {
  return &grid_[position.x + 1][position.y + 1];
}

/**
 * @brief Updates the state of all cells by checking their neighbours.
 *
 * This method iterates over all the cells in the grid, calls `Neighbors()` to
 * determine the neighbouring cells, and decreases the pheromone level in each
 * cell. It then calls `NextStep()` to update the state of the cells.
 */
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

/**
 * @brief Advances the grid to the next step by updating the state of each cell.
 *
 * This method updates the state of each cell in the grid by calling the
 * `Update()` method of the respective cell's state. It skips cells that have
 * already been updated during the current step.
 */
void Grid::NextStep() {
  for (int y = 1; y <= height_; y++) {
    for (int x = 1; x <= width_; x++) {
      if (grid_[y][x].IsUpdated()) continue;
      grid_[y][x].GetState()->Update(grid_[y][x]);
    }
  }
}

/**
 * @brief Outputs a visual representation of the grid.
 *
 * This method outputs a character for each cell in the grid, representing its
 * current state:
 * - A space (" ") for an EMPTY cell
 * - A plus sign ("+") for an ANT cell
 * - A hash ("#") for a BORDER cell
 *
 * @param out The output stream to which the grid representation is written.
 * @param grid The grid whose state is being represented.
 * @return The output stream after writing the grid's representation.
 */
std::ostream &operator<<(std::ostream &out, const Grid &grid) {
  int width = grid.GetWidth();
  int height = grid.GetHeight();

  for (int y = 0; y <= height + 1; y++) {
    for (int x = 0; x <= width + 1; x++) {
      // std::cout << y << ',' << x << std::endl;
      out << grid.GetGrid()[y][x];
    }
    out << std::endl;
  }

  return out;
}
