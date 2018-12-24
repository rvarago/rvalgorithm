.PHONY: all mk gen compile test

BUILD_DIR = build

all: mk dep gen compile

test: all
	cd $(BUILD_DIR) && ctest . 

compile: gen
	cd $(BUILD_DIR) && cmake --build .

gen: dep
	cd $(BUILD_DIR) && cmake ..

dep: mk
	cd $(BUILD_DIR) && conan install ..

mk:
	-mkdir -p $(BUILD_DIR)
