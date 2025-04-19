#include "../head/AIRandom.h"
#include "../head/GameState.h"
#include "../head/Display.h"

//Joueur aléatoire

int GRe_Joueur_aleatoire(GameState* map, Color joueur)
{
	Color max = WHITE;
	Color min = RED;
	return rand() % (max+1 - min) + min;
}


void GRe_play_game_AI_aleatoire(GameState* game, Color player)
{
	Color color = ERROR;
	int j1turn = 1;
	while (GRe_is_game_over(game) == 0)
	{
		if (j1turn == 1 && player == 2)
		{
			GRe_print_colored_map(game);
			printf("Tour joueur 1\n");
			scanf("%d", &color);
			GRe_update_map(game, color, PLAYER_1);
			j1turn = 0;
		}
		else if (j1turn == 0 && player == 1)
		{
			GRe_print_colored_map(game);
			printf("Tour joueur 2\n");
			scanf("%d", &color);
			GRe_update_map(game, color, PLAYER_2);
			j1turn = 1;
		}
		else
		{
			
			color = GRe_Joueur_aleatoire(game, player);
			if (j1turn == 1)
			{
				j1turn = 0;
				GRe_update_map(game, color, PLAYER_1);
			}
			else
			{
				j1turn = 1;
				GRe_update_map(game, color, PLAYER_2);
			}
		}
	}
}

// Joueur aleatoire parmis les couleur adjacentes

int GRe_Joueur_aleatoire_adjacent(GameState* map, Color player)
{
	int colorAvailable[7] = {0, 0, 0, 0, 0, 0, 0};
	int mapsize = map -> size;
	for (int i = 0; i < mapsize; i++)
	{
		for (int j = 0; j < mapsize; j++)
		{
			int slotValue = get_map_value(map, j, i);
			if (slotValue == player)
			{
				if (j - 1 >= 0 && get_map_value(map, j - 1, i) != EMPTY && get_map_value(map, j - 1, i) != 1 && get_map_value(map, j - 1, i) != 2)
				{
					colorAvailable[get_map_value(map, j - 1, i)-3] = 1;
				}
				if (j + 1 < mapsize && get_map_value(map, j + 1, i) != EMPTY && get_map_value(map, j + 1, i) != 1 && get_map_value(map, j + 1, i) != 2)
				{
					colorAvailable[get_map_value(map, j + 1, i)-3] = 1;
				}
				if (i - 1 >= 0 && get_map_value(map, j, i - 1) != EMPTY && get_map_value(map, j, i - 1) != 1 && get_map_value(map, j, i - 1) != 2)
				{
					colorAvailable[get_map_value(map, j, i - 1)-3] = 1;
				}
				if (i + 1 < mapsize && get_map_value(map, j, i + 1) != EMPTY && get_map_value(map, j, i + 1) != 1 && get_map_value(map, j, i + 1) != 2)
				{
					colorAvailable[get_map_value(map, j, i + 1)-3] = 1;
				}
			
			}
		}
	}
	Color min = RED;
	Color max = WHITE;
	int color = rand() % (max+1 - min) + min;
	while (colorAvailable[color] == 0)
	{
		color = rand() % (max+1 - min) + min;
	}
	return color + 3;

}

void GRe_play_AI_aleatoire_adjacent(GameState* game, Color player)
{
	Color color = ERROR;
	int j1turn = 1;
	while (GRe_is_game_over(game) == 0)
	{
		if (j1turn == 1 && player == 2)
		{
			GRe_print_colored_map(game);
			printf("Tour joueur 1\n");
			scanf("%d", &color);
			GRe_update_map(game, color, PLAYER_1);
			j1turn = 0;
		}
		else if (j1turn == 0 && player == 1)
		{
			GRe_print_colored_map(game);
			printf("Tour joueur 2\n");
			scanf("%d", &color);
			GRe_update_map(game, color, PLAYER_2);
			j1turn = 1;
		}
		else
		{
			
			color = GRe_Joueur_aleatoire_adjacent(game, player);
			if (j1turn == 1)
			{
				j1turn = 0;
				GRe_update_map(game, color, PLAYER_1);
			}
			else
			{
				j1turn = 1;
				GRe_update_map(game, color, PLAYER_2);
			}
		}

	}
}
