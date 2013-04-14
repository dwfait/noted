CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -Wall -Wextra -pedantic -std=c++11
LD_FLAGS := -lboost_program_options-mt -lboost_filesystem-mt -lboost_system-mt
GXX := clang++

bin/noted: $(OBJ_FILES)
	mkdir -p bin
	$(GXX) -o $@ $^ $(LD_FLAGS)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(GXX) $(CC_FLAGS) -c -o $@ $<

install:
	cp bin/noted /usr/local/bin

clean:
	rm -f obj/*.o bin/*
