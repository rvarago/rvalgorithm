.PHONY: all mk gen build

BUILD_DIR = build

all: mk gen compile

compile: gen
	cd $(BUILD_DIR) && cmake --build .

gen: mk
	cd $(BUILD_DIR) && cmake ..

mk:
	-mkdir -p $(BUILD_DIR)
