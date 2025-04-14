#include <iostream>

#include "cell.h"
#include "grid.h"

int main() {
  srand(time(NULL));
  Grid grid;
  grid.GenerateGrid();

  // Y, X
  grid.SetToAnt(2, 2);
  grid.SetToAnt(4, 4);

  std::cout << grid << std::endl;
  for (int i = 0; i < 3; i++) {
    std::cout << "Iteracion " << i + 1 << std::endl;
    grid.Neighbors();
    std::cout << grid << std::endl;
  }

  return 0;
}
