# 🐜 **Ant Colony Simulation with Pheromones - Game of Life Version**

Inspired by Conway's classic *Game of Life*, but with ant colony behaviour.

---

## 📦 **Cell State:**

- Each cell can either be **empty** or contain an **ant**.
- Each cell has a **pheromone level** (`float` between 0 and 1).

---

## ⚙️ **1. Pheromones**

- All cells have a `pheromone` value ∈ [0, 1].
- Each **ant leaves pheromones** as it moves (e.g., `+0.3`).
- Each turn, the pheromones **evaporate** (e.g., `pheromone *= 0.95`).

---

## 🚶 **2. Ant Movement**

- Ants **can move to an empty neighbouring cell**.
- Movement priority: **towards the neighbouring cells with more pheromones**.
- If multiple cells have the same pheromone level, the ant will choose **randomly**.

---

## 🧬 **3. Reproduction**

- If a cell has 2 or more neighbouring ants, and is empty:
  - There is a chance (e.g., 25%) that a new ant will spawn there.
  - Optional: This could also depend on the pheromone level.

---

## 💀 **4. Death by Isolation or Overcrowding**

- An ant dies if:
  - It is **isolated** (0 or 1 neighbouring ants).
  - It is **surrounded by too many ants** (e.g., ≥ 5).

This simulates the need for collaboration but also for space.

---

## **5. Pheromone Evaporation**

- Each turn, the entire pheromone map is updated by lowering the pheromone levels in each cell.

---

## ⚙️ **How it works**

1. **Compiling the Program**:
   - A **Makefile** is used to compile the project. It handles dependencies and the compilation process automatically.

2. **Running the Program**:
   - Once compiled, the executable can be run from the terminal.

3. **User Interaction**:
   - After launching the program, the user will be prompted to:
     1. Enter the **grid size** (width and height).
     2. Enter the **number of ants** to place on the grid.
     3. **Define the positions** for each ant.
     4. Specify the number of **iterations** to simulate.

4. **Simulation**:
   - After these inputs, the program will simulate the ant colony's behaviour over the specified number of iterations.
