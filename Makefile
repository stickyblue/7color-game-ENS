FLAGS=-Wall -Werror -g

7color : o/GameState.o o/Display.o o/AIRandom.o o/AIGlouton.o o/AIFrontiere.o o/UpdateGame.o o/Battle.o
	gcc $(FLAGS) o/GameState.o o/Display.o o/AIRandom.o o/AIGlouton.o o/AIFrontiere.o o/UpdateGame.o o/Battle.o -o 7color -lm
	
o/GameState.o: head/GameState.h src/GameState.c
	gcc $(FLAGS) -c src/GameState.c -o o/GameState.o

o/Display.o: head/Display.h src/Display.c
	gcc $(FLAGS) -c src/Display.c -o o/Display.o

o/AIRandom.o: head/AIRandom.h src/AIRandom.c
	gcc $(FLAGS) -c src/AIRandom.c -o o/AIRandom.o

o/AIGlouton.o: head/AIGlouton.h src/AIGlouton.c
	gcc $(FLAGS) -c src/AIGlouton.c -o o/AIGlouton.o

o/AIFrontiere.o: head/AIFrontiere.h src/AIFrontiere.c
	gcc $(FLAGS) -c src/AIFrontiere.c -o o/AIFrontiere.o

o/UpdateGame.o: head/UpdateGame.h src/UpdateGame.c
	gcc $(FLAGS) -c src/UpdateGame.c -o o/UpdateGame.o
	
o/Battle.o: head/Battle.h src/Battle.c
	gcc $(FLAGS) -c src/Battle.c -o o/Battle.o
