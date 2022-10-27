folder = build

.PHONY: generate build clean

generate:
	mkdir -p $(folder); \
	cd $(folder); \
	cmake ..

build: generate
	cmake --build ./$(folder)

clean:
	rm -rf $(folder)
