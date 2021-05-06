all: run

run:
	cd build && cmake .. && make && echo build done && echo "" && echo "" && ./../bin/appnotex

builddir:
	mkdir build bin

clean:
	rm -r build
	rm -r bin