.PHONY: all mk gen compile test

BUILD_DIR = build

all: mk gen compile

test: all
	cd $(BUILD_DIR) && ctest . 

compile: gen
	cd $(BUILD_DIR) && cmake --build .

gen:
	cd $(BUILD_DIR) && cmake ..

mk:
	-mkdir -p $(BUILD_DIR)
