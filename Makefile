CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -Wall -Wextra -pedantic
LD_FLAGS := -lboost_program_options-mt
GXX := g++

bin/noted: $(OBJ_FILES)
	mkdir -p bin
	$(GXX) -o $@ $^ $(LD_FLAGS)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(GXX) $(CC_FLAGS) -c -o $@ $<

clean:
	rm -f obj/*.o bin/*
