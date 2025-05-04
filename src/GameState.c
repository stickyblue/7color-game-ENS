#include "../head/GameState.h"
#include "../head/Display.h"
#include "../head/AIGlouton.h"
#include "../head/AIRandom.h"
#include "../head/AIFrontiere.h"
#include "../head/UpdateGame.h"
#include "../head/Battle.h"

#include <math.h>
#include <string.h>


GameState state = {.map = NULL, .size = 0};
void create_empty_game_state (GameState* state, int size)
{
	state -> map = malloc(size * size * sizeof(int));
	state -> size = size;
}


void set_map_value (GameState* state, int x, int y, Color value)
{
	state -> map[y * state -> size + x] = value;
}




Color get_map_value (GameState* state, int x, int y)
{
	if (state -> map == NULL || x > state -> size || y > state -> size || x < 0 || y < 0)
	{
		return ERROR;
	}
	return state -> map[y * state -> size + x];
}




void fill_map(GameState* map)
{
	int taille_map = map -> size;

	Color max = WHITE;
	Color min = RED;
	Color J1 = PLAYER_1;
	Color J2 = PLAYER_2;

	for (int i = 0; i < taille_map; i++)
	{
		for (int j = 0; j < taille_map; j++)
		{
			set_map_value(map, j, i, rand() % (max+1 - min) + min);
		}
	}
	set_map_value(map, 0, taille_map - 1, J1);
	set_map_value(map, taille_map - 1, 0, J2);

}


void GRe_play_game_two_players(GameState* game)
{
	Color color = ERROR;
	int j1turn = 1;
	while (GRe_is_game_over(game) == 0)
	{
		if (j1turn == 1)
		{
			GRe_print_colored_map(game);
			printf("Tour joueur 1\n");
			scanf("%d", &color);
			GRe_update_map(game, color, PLAYER_1);
			j1turn = 0;
		}
		else
		{
			GRe_print_colored_map(game);
			printf("Tour joueur 2\n");
			scanf("%d", &color);
			GRe_update_map(game, color, PLAYER_2);
			j1turn = 1;
		}
		GRe_print_colored_map(game);
	}
}



int main(int argc, char** argv)
{
	srand(time(NULL));
	int mapsize = 0;
	sscanf(argv[1], "%d", &mapsize); // je sais le faire comme ça, mais je préfère utiliser atoi
	create_empty_game_state(&state, mapsize);
	fill_map(&state);
/*
	for (int i = 1; i<= FRONTIEREGL; i++)
	{
		for (int j = 1; j <= FRONTIEREGL; j++)
		{
			fill_map(&state);
			printf("AI 1 : %d, AI 2 : %d\n", i, j);
			GRe_battle(&state, 10, i, j);
		}
	}
*/
	for (int k = 0; k < argc; k++)
	{
		char* tempargv = argv[k];
		if (strcmp(tempargv, "--ai") == 0)
		{
			GameState givenstate = {.map = NULL, .size = 0};
			int givenmapsize = sqrt(argc - k);
			givenstate.map = malloc(givenmapsize * givenmapsize * sizeof(int));
			givenstate.size = mapsize;
			for (int i = 0; i < givenmapsize; i++)
			{
				for (int j = 0; j < givenmapsize; j++)
				{
					set_map_value(&givenstate, j, i, atoi(argv[k + 3 + i * givenmapsize + j]));
				}
			}
			int result = GRe_AIAnswer(&givenstate, atoi(argv[k+1]), atoi(argv[k+2]));
			printf("%d\n", result);
			free(givenstate.map);
			return result;
		}
		
	}

	GRe_play_game_two_players(&state);
	free(state.map);
	return 0;

}

