all: run

run:
	cd build && cmake .. && make && echo build done && echo "" && echo "" && ./../bin/appnotex

builddir:
	mkdir build bin data

clean:
	rm -r build
	rm -r bin
	rm -r data