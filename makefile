# Nombre del objetivo final
TARGET = program

# Flags de compilación
CFLAGS = -Wall -I./lib

# Carpeta para los archivos objeto
OBJ_DIR = build

# Archivos objeto (guardados en la carpeta OBJ_DIR)
OBJ = $(OBJ_DIR)/main.o \
      $(OBJ_DIR)/src/grid.o \
      $(OBJ_DIR)/src/cell.o \
      $(OBJ_DIR)/src/state.o \

# Regla para construir el objetivo final
$(TARGET): $(OBJ)
	g++ $(CFLAGS) $(OBJ) -o $(TARGET)

# Regla para main.o (con la ruta a obj/)
$(OBJ_DIR)/main.o: main.cc lib/cell.h lib/grid.h
	mkdir -p $(OBJ_DIR)
	g++ -c $(CFLAGS) main.cc -o $(OBJ_DIR)/main.o

# Regla para otros objetos (con la ruta a obj/)
$(OBJ_DIR)/src/%.o: src/%.cc lib/%.h
	mkdir -p $(OBJ_DIR)/src
	g++ -c $(CFLAGS) $< -o $@

# Reglas de limpieza
.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR) $(TARGET)

clear:
	@rm -rf $(OBJ_DIR)
