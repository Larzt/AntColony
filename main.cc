#include <cstdlib>
#include <ctime>
#include <iostream>

#include "grid.h"

int main() {
  // Seed the random number generator for random operations
  srand(time(NULL));

  // Ask the user if they want to use the default grid size or a custom one
  char useDefaultGrid;
  std::cout << "Would you like to use the default grid size (5x5)? (y/n): ";
  std::cin >> useDefaultGrid;

  Grid grid;

  // If user wants a custom grid size, ask for dimensions
  if (useDefaultGrid == 'n' || useDefaultGrid == 'N') {
    int width, height;
    std::cout << "Enter the grid width: ";
    std::cin >> width;
    std::cout << "Enter the grid height: ";
    std::cin >> height;
    if (width != height) {
      std::cout << "Width and Height must be the same (sorry)" << std::endl;
      return -1;
    }
    grid = Grid(width, height);  // Create grid with custom dimensions
  }

  // Default grid size will be used
  grid.GenerateGrid();

  // Ask how many ants the user wants to place
  int antCount;
  std::cout << "How many ants would you like to place?: ";
  std::cin >> antCount;

  // Ask for the coordinates to place each ant
  for (int i = 0; i < antCount; ++i) {
    int x, y;
    std::cout << "Enter coordinates for ant " << i + 1 << " (x y): ";
    std::cin >> x >> y;
    // Place the ant at the specified coordinates
    grid.SetToAnt(x, y);
  }

  // Display the initial grid state
  std::cout << std::endl << grid << std::endl;

  // Ask how many iterations the user wants to simulate
  int iterations;
  std::cout << "How many iterations would you like to run?: ";
  std::cin >> iterations;

  // Run the simulation for the specified number of iterations
  for (int i = 0; i < iterations; i++) {
    std::cout << "Iteration " << i + 1 << std::endl;
    // Executes the logic for updating the grid
    grid.Neighbors();
    // Output the grid after the iteration
    std::cout << grid << std::endl;
  }

  return 0;
}
