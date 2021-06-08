LIBS= -lsfml-graphics -lsfml-window -lsfml-system

CXX := g++

all: spaceinvaders

%.o: src/%.cpp
	$(CXX) -c $< -o $@

%.o: src/%.hpp
	$(CXX) -c $< -o $@

spaceinvaders: enemy.o main.o game.o
	echo "** Building the game"
	$(CXX) -o builds\spaceinvaders enemy.o main.o game.o $(LIBS)
	cp *.o builds
	rm -f *.o

clean:
	@echo "** Removing object files and executable..."
	rm -f builds\spaceinvaders
	rm -f builds\enemy.o
	rm -f builds\game.o
	rm -f builds\main.o
	rm -f spaceinvaders
	rm -f enemy.o
	rm -f game.o
	rm -f main.o


install:
	@echo '** Installing...'
	cp spaceinvaders /usr/bin/

uninstall:
	@echo '** Uninstalling...'
	$(RM) /usr/bin/spaceinvaders
