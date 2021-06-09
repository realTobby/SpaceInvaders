LIBS= -lsfml-graphics -lsfml-window -lsfml-system

CXX := g++

all: spaceinvaders

%.o: src/%.cpp
	$(CXX) -c $< -o $@

%.o: src/%.hpp
	$(CXX) -c $< -o $@

spaceinvaders: logging.o drawable.o enemy.o main.o game.o starfield.o enemyhandler.o player.o 
	echo "** Building the game"
	$(CXX) -o spaceinvaders logging.o drawable.o enemy.o main.o game.o starfield.o enemyhandler.o player.o $(LIBS)


clean:
	@echo "** Removing object files and executable..."
	rm -f spaceinvaders
	rm -f *.o



install:
	@echo '** Installing...'
	cp spaceinvaders /usr/bin/

uninstall:
	@echo '** Uninstalling...'
	$(RM) /usr/bin/spaceinvaders
