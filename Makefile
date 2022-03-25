TC_FOLDER = generated_tests/tests # change to tests
EXT_IN = in
EXT_OUT = out
EXT_ANS = ans
EXECUTABLE_FILENAME = main
ALL_SRCS := $(wildcard *.cpp)
SRCS     := $(filter-out check.cpp, $(ALL_SRCS))

all: compile test check

# Compile all cpp files except check.cpp
compile:
	g++ -std=c++17 -o $(EXECUTABLE_FILENAME) main.cpp classes/GameManager/GameManager.cpp classes/Inventory/Inventory.cpp classes/Slot/Slot.cpp classes/Storage/Storage.cpp classes/Recipe/Recipe.cpp classes/Craft/Craft.cpp classes/FileManager/FileManager.cpp classes/TerminalManager/TerminalManager.cpp

# Test
test: $(TC_FOLDER)/*.$(EXT_IN) $(EXECUTABLE_FILENAME)
	for inputfile in $(TC_FOLDER)/*.$(EXT_IN); do \
		./$(EXECUTABLE_FILENAME) < $$inputfile; \
	done;

# Check
check: FORCE check.cpp
	g++ -std=c++17 -o check check.cpp
	./check

FORCE: ;
