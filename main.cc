#include <iostream>

#include "cell.h"
#include "grid.h"

int main() {
  Grid grid;
  grid.GenerateGrid();

  std::cout << grid << std::endl;
  return 0;
}
