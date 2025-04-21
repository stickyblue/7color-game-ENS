#include "../head/GameState.h"
#include "../head/Display.h"
#include "../head/AIGlouton.h"
#include "../head/AIRandom.h"
#include "../head/AIFrontiere.h"
#include "../head/UpdateGame.h"


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


void GRe_play_game_two_players(GameState* game, Color player)
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

//Espace intelligences artificielles


//Battle 

void GRe_AI_aleatoire_vs_glouton(GameState* game, int numberOfGame)
{
	int j1win = 0;
	int j2win = 0;
	Color color = ERROR;
	int j1turn = 1;
	for (int k = 0; k < numberOfGame; k++)
	{
		while (GRe_is_game_over(game) == 0)
		{
			if (j1turn == 1)
			{
				color = GRe_Joueur_aleatoire(game, 1);
				GRe_update_map(game, color, PLAYER_1);
				j1turn = 0;
			} else
			{
				color = GRe_joueur_glouton(game, 2);
				GRe_update_map(game, color, PLAYER_2);
				j1turn = 1;
			}
		}
		GRe_is_game_over(game) == 1 ? j1win++ : j2win++;
		fill_map(game);
	}
	if (j1win > j2win)
	{
		printf("Victoire joueur 1 avec %d victoires sur %d\n", j1win, numberOfGame);
	}
	else
	{
		printf("Victoire joueur 2 avec %d victoires sur %d\n", j2win, numberOfGame);
	}
}


int main(int argc, char** argv)
{
	srand(time(NULL));
	int mapsize = 0;
	sscanf(argv[1], "%d", &mapsize);
	create_empty_game_state(&state, mapsize);
	fill_map(&state);
	//GRe_play_game_two_players(&state , mapsize);
	//GRe_play_game_AI_aleatoire(&state, 2);
	//GRe_play_AI_aleatoire_adjacent(&state, 2);
	//GRe_play_game_AI_glouton(&state, 2);
	//GRe_AI_aleatoire_vs_glouton(&state, 500);
	//GRe_play_AI_frontiere(&state, 2);
	GRe_play_AI_frontiere_glouton(&state, 2);


	free(state.map);
	return 0;

}

