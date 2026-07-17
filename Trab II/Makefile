CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SRCS = main.cpp Personagem.cpp Guerreiro.cpp Ninja.cpp Mago.cpp
TARGET = combate

# Transforma a lista de .cpp em .o
OBJS = $(SRCS:.cpp=.o)

# O Alvo principal agora depende dos objetos (.o)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra implícita para compilar cada .cpp em .o individualmente
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: clean

