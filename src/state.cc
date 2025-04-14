// state.cpp
#include "state.h"

#include "cell.h"

BorderState borderState;
EmptyState emptyState;
AntState antState;

void BorderState::Update(Cell& cell) {
  // Por ahora no hace nada
}

void EmptyState::Update(Cell& cell) {
  // Por ahora no hace nada
}

void AntState::Update(Cell& cell) {
  std::vector<Cell*> neighbors = cell.GetNeighbors();

  float currentPherLevel = 0;
  Cell* possibleCell = nullptr;

  // Buscar la mejor celda que NO tenga ya una hormiga
  for (Cell* cll: neighbors) {
    // evita colisiones
    if (cll->GetState()->GetType() == ANT || cll->IsUpdated()) continue;
    if (cll->GetPheroLevel() > currentPherLevel) {
      currentPherLevel = cll->GetPheroLevel();
      possibleCell = cll;
    }
  }

  // Vaciamos la celda actual y añadimos feromonas
  cell.SetState(&emptyState);
  cell.AddPheroLevel(0.3);
  cell.ToggleUpdated();

  // Si no encontró celda con feromonas, intenta moverse a una celda aleatoria
  // libre
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
    // Si no hay vecinos libres, simplemente no se mueve
  } else if (possibleCell != nullptr) {
    possibleCell->SetState(&antState);
    possibleCell->ToggleUpdated();
  }
}
