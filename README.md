# 🐜 Reglas del “Juego de la Vida: Versión Hormigas con Feromonas”

 Inspirado en el clásico Juego de la Vida de Conway, pero con comportamiento tipo colonia de hormigas.

---

## 📦 Estado por celda:

- Cada celda puede estar **vacía** o contener una **hormiga**.
- Cada celda tiene un **nivel de feromonas** (`float` entre 0 y 1).

---

## ⚙️ 1. Feromonas

- Todas las celdas tienen un valor `pheromone ∈ [0, 1]`.
- Cada **hormiga deja feromonas** al moverse (por ejemplo: `+0.3`).
- Cada turno, las feromonas **se evaporan** (por ejemplo: `pheromone *= 0.95`).

---

## 🚶 2. Movimiento de las hormigas

- Las hormigas **pueden moverse a una celda vacía vecina**.
- Prioridad de movimiento: **a las celdas vecinas con más feromonas**.
- Si hay varias candidatas con igual nivel, elige **aleatoriamente**.


---

## 🧬 3. Reproducción
- Si una celda tiene 2 o más hormigas vecinas, y está vacía:

- Hay una probabilidad (ej: 25%) de que nazca una nueva hormiga ahí.

- Opcional: puede depender también del nivel de feromonas


---

## 💀 4. Muerte por aislamiento o saturación
- Una hormiga muere si:

- Está aislada (0 o 1 hormigas vecinas).

- Está rodeada por demasiadas hormigas (por ejemplo ≥5).

- Esto simula que necesita colaboración, pero también espacio.


---

## 5. Evaporación
- Cada turno, el mapa entero de feromonas se actualiza bajando el nivel de feromonas
