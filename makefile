# declaring variables
CXX = g++
OBJ_DIR = ./objects
OBJS = $(shell find $(OBJ_DIR) -name '*.o')
SRC_DIR = ./src
SRCS = $(shell find $(SRC_DIR) -name '*.cpp')
# REQ = Wordlist.o Game.o FileManager.o main.o
REQ = $(shell echo $(SRCS) | sed -r 's/src\//objects\//g' | sed -r 's/\.cpp/.o/g')
CXXFLAGS =

debug: CXXFLAGS += -g

# list of targets to do
all: hangman $(OBJ_DIR)

# $^ = all requirements
# $@ = target name
hangman: $(REQ)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# $< first requirement
objects/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(OBJ_DIR):
	mkdir objects

debug: clean all

clean:
	rm hangman $(OBJS)

test:
	echo $(REQ)
	
# clean:
# 	rm *.o