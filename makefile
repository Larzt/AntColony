# Nombre del objetivo final
TARGET = program

# Flags de compilación
CFLAGS = -Wall -I./lib

# Archivos objeto
OBJ = main.o \
      src/grid.o \
      src/cell.o \

# Regla para construir el objetivo final
$(TARGET): $(OBJ)
	g++ $(CFLAGS) $(OBJ) -o $(TARGET)

# Regla para construir archivos objeto a partir de archivos fuente
src/%.o: src/%.cc lib/%.h
	g++ -c $(CFLAGS) $< -o $@

# Regla para limpiar los archivos generados
.PHONY: clean
clean:
	@rm -f $(OBJ) $(TARGET)
clear:
	@rm -f $(OBJ)
