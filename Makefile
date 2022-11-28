folder = build

.PHONY: generate build clean

generate:
	mkdir -p $(folder); \
	cd $(folder); \
	cmake ..

build: generate
	cmake --build ./$(folder) --parallel

clean:
	rm -rf $(folder)
