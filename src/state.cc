#include "state.h"

#include "cell.h"

// Global instances of state classes
BorderState borderState;
EmptyState emptyState;
AntState antState;

/**
 * @brief Update method for the BorderState class.
 *
 * This method does not perform any action since border cells remain static.
 * The border cells are not involved in any updates in this simulation.
 *
 * @param cell The cell in the border state that is being updated.
 */
void BorderState::Update(Cell& cell) {
  return;
}

/**
 * @brief Update method for the EmptyState class.
 *
 * This method checks the neighbouring cells for existing ants and attempts to
 * spawn a new ant if certain conditions are met. If there are at least two
 * ants in the neighbouring cells and the probability condition is satisfied,
 * an ant will be spawned in the current empty cell.
 *
 * @param cell The empty cell being updated.
 */
void EmptyState::Update(Cell& cell) {
  const int minAntToSpawn = 2;
  const int probToSpawn = 2;
  std::vector<Cell*> neighbors = cell.GetNeighbors();
  float antCount = 0;

  for (Cell* cll: neighbors) {
    if (cll->GetState()->GetType() == ANT && !cll->IsUpdated()) {
      ++antCount;
    }
  }

  if (rand() % 10 < probToSpawn) {
    if (antCount >= minAntToSpawn) {
      cell.SetState(&antState);
      cell.ToggleUpdated();
    }
  }
}
