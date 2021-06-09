LIBS= -lsfml-graphics -lsfml-window -lsfml-system

CXX := g++

all: spaceinvaders

%.o: src/%.cpp
	$(CXX) -c $< -o $@

%.o: src/%.hpp
	$(CXX) -c $< -o $@

spaceinvaders: drawable.o enemy.o main.o game.o starfield.o enemyhandler.o player.o 
	echo "** Building the game"
	$(CXX) -o spaceinvaders drawable.o enemy.o main.o game.o starfield.o enemyhandler.o player.o $(LIBS)


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
