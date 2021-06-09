LIBS= -lsfml-graphics -lsfml-window -lsfml-system

CXX := g++

all: spaceinvaders

%.o: src/%.cpp
	$(CXX) -c $< -o $@

%.o: src/%.hpp
	$(CXX) -c $< -o $@

spaceinvaders: main.o game.o enemy.o player.o enemyhandler.o drawable.o starfield.o logging.o
	echo "** Building the game"
	$(CXX) -o spaceinvaders main.o game.o enemy.o player.o enemyhandler.o drawable.o starfield.o logging.o $(LIBS)


clean:
	@echo "** Removing object files and executable..."
	rm -f spaceinvaders
	rm -f spaceinvaders.exe
	rm -f *.o



install:
	@echo '** Installing...'
	cp spaceinvaders /usr/bin/

uninstall:
	@echo '** Uninstalling...'
	$(RM) /usr/bin/spaceinvaders
