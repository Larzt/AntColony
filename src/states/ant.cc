#include "cell.h"
#include "state.h"

/**
 * @brief Updates the state of the cell when it is in the Ant state.
 *
 * This method checks if the cell is overcrowded (more than a certain number of
 * ants around it). If overcrowded, it changes the cell's state to EMPTY.
 * Otherwise, it triggers the movement of the ant.
 *
 * @param cell The cell that is being updated.
 */
void AntState::Update(Cell& cell) {
  if (CheckOvercrowding(cell)) {
    cell.SetState(&emptyState);
    cell.ToggleUpdated();
    return;
  }

  Move(cell);
}

/**
 * @brief Checks whether the cell is overcrowded with ants.
 *
 * This method counts how many ants are present in the neighbouring cells and
 * returns true if the number of ants exceeds a predefined threshold
 * (maxNearbyAnts).
 *
 * @param cell The cell being checked for overcrowding.
 * @return True if the cell has more than the allowed number of ants in the
 * nearby cells, otherwise false.
 */
bool AntState::CheckOvercrowding(Cell& cell) {
  std::vector<Cell*> neighbors = cell.GetNeighbors();
  const int maxNearbyAnts = 5;
  int antCount = 0;

  for (Cell* cll: neighbors) {
    if (cll->GetState()->GetType() == ANT && !cll->IsUpdated()) {
      ++antCount;
    }
  }

  return antCount > maxNearbyAnts;
}

/**
 * @brief Moves the ant to a new cell based on pheromone levels.
 *
 * This method finds the neighbouring cell with the highest pheromone level and
 * moves the ant there. If no pheromone is detected, it moves to a random
 * neighbouring cell. The current cell is updated with pheromones.
 *
 * @param cell The cell where the ant currently resides, which will be updated
 * and moved.
 */
void AntState::Move(Cell& cell) {
  std::vector<Cell*> neighbors = cell.GetNeighbors();

  float currentPherLevel = 0;
  Cell* possibleCell = nullptr;

  for (Cell* cll: neighbors) {
    if (cll->GetState()->GetType() == ANT || cll->IsUpdated()) continue;
    if (cll->GetPheroLevel() > currentPherLevel) {
      currentPherLevel = cll->GetPheroLevel();
      possibleCell = cll;
    }
  }

  cell.SetState(&emptyState);
  cell.AddPheroLevel(0.3);
  cell.ToggleUpdated();

  if (currentPherLevel == 0 && !neighbors.empty()) {
    std::vector<Cell*> freeNeighbors;
    for (Cell* cll: neighbors) {
      if (cll->GetState()->GetType() != ANT && !cll->IsUpdated()) {
        freeNeighbors.push_back(cll);
      }
    }

    if (!freeNeighbors.empty()) {
      int randIndex = rand() % freeNeighbors.size();
      freeNeighbors[randIndex]->SetState(&antState);
      freeNeighbors[randIndex]->ToggleUpdated();
    }
  } else if (possibleCell != nullptr) {
    possibleCell->SetState(&antState);
    possibleCell->ToggleUpdated();
  }
}
