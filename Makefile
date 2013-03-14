CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -Wall -Wextra -pedantic -std=c++11 -I../shared/
GXX := /usr/local/Cellar/gcc/4.7.2/bin/g++-4.7

bin/noted: $(OBJ_FILES)
	mkdir -p bin
	$(GXX) -o $@ $^

obj/%.o: src/%.cpp
	mkdir -p obj
	$(GXX) $(CC_FLAGS) -c -o $@ $<

clean:
	rm -f obj/*.o bin/*
