all: run

run:
	cd build && cmake .. && make appnotex && echo build done && echo "" && echo "" && ./../bin/appnotex

builddir:
	mkdir build bin data

clean:
	rm -r build
	rm -r bin
	rm -r data

install:
	# mkdir ~/.local/bin/AppNotEx
	# cp bin ~/.local/bin/AppNotEx -r
	# ln -sf ~/.local/bin/AppNotEx/bin/appnotex ~/.local/bin
	# echo "appnotex installation complete"

uninstall:
	# rm -r ~/.local/bin/AppNotEx -r
	# rm ~/.local/bin/appnotex
	# rm ~/.local/bin/data -r

runtest:
	cd build && cmake .. && make appnotexTest && echo build done test build && echo "" && echo "" && ./../bin/appnotexTest