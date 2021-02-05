# running `make` with no arguments builds the target named "all"
all:
	mkdir -p build
	cd build; cmake .. && make

# running `make clean` will remove all compiled stuff
clean:
	rm -rf build
