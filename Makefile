# Variáveis
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -Wextra -Wpedantic -Wformat-security -Wconversion -Werror

BIN_FOLDER = ./bin/

$(shell mkdir -p $(BIN_FOLDER))

# Regra padrão
all:
	$(CXX) $(CXXFLAGS) "$(FILE)" -o ${BIN_FOLDER}a.out

# Limpeza
clean:
	rm -f a.out


# Uso
# Para compilar, execute:
# make FILE=seuarquivo.cpp
