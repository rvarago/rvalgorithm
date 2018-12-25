.PHONY: all mk gen compile test

BUILD_DIR = build

all: compile gen mk

test: all
	cd $(BUILD_DIR) && ctest . 

compile: gen
	cd $(BUILD_DIR) && cmake --build .

gen: mk
	cd $(BUILD_DIR) && cmake ..

mk:
	-mkdir -p $(BUILD_DIR)
