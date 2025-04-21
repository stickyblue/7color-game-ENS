#include "../head/AIFrontiere.h"
#include "../head/GameState.h"
#include "../head/Display.h"


//Joueur frontière

int GRe_joueur_frontiere(GameState* game, Color player)
{
	int maxColorAvailable[] = {0, 0};
	int mapsize = game -> size;
	Color max = WHITE;
	Color min = RED;
	for (int k = min; k <= max; k++)
	{
		GameState mapcopy = {.map = NULL, .size = 0};
		create_empty_game_state(&mapcopy, mapsize);
		for (int i = 0; i < mapsize; i++)
		{
			for (int j = 0; j < mapsize; j++)
			{
				set_map_value(&mapcopy, j, i, get_map_value(game, j, i));
			}
		}
		GRe_update_map(&mapcopy, k, player);
		int actualCount = 0;

		for (int i = 0; i<mapsize; i++)
		{
			for (int j = 0; j < mapsize; j++)
			{
				if (get_map_value(&mapcopy, j, i) == player)
				{
					if (j - 1 >= 0 && get_map_value(&mapcopy, j - 1, i) != player)
					{
						actualCount++;
					}
					if (j + 1 < mapsize && get_map_value(&mapcopy, j + 1, i) != player)
					{
						actualCount++;
					}
					if (i - 1 >= 0 && get_map_value(&mapcopy, j, i - 1) != player)
					{
						actualCount++;
					}
					if (i + 1 < mapsize && get_map_value(&mapcopy, j, i + 1) != player)
					{
						actualCount++;
					}
				}
			}

		}
		if (actualCount > maxColorAvailable[1])
		{
			maxColorAvailable[0] = k;
			maxColorAvailable[1] = actualCount;
		}
		free(mapcopy.map);
	}
	return maxColorAvailable[0];

}

int GRe_joueur_frontiere_glouton(GameState* game, Color player)
{
	int maxColorAvailable[] = {0, 0};
	int mapsize = game -> size;
	Color max = WHITE;
	Color min = RED;
	int actualCountReal = 0;
	for (int i = 0; i < mapsize; i++)
	{
		for (int j = 0; j < mapsize; j++)
		{
			if (get_map_value(game, j, i) == player)
			{
				if (j - 1 >= 0 && get_map_value(game, j - 1, i) != player)
				{
					actualCountReal++;
				}
				if (j + 1 < mapsize && get_map_value(game, j + 1, i) != player)
				{
					actualCountReal++;
				}
				if (i - 1 >= 0 && get_map_value(game, j, i - 1) != player)
				{
					actualCountReal++;
				}
				if (i + 1 < mapsize && get_map_value(game, j, i + 1) != player)
				{
					actualCountReal++;
				}
			}
		}
	}

	for (int k = min; k <= max; k++)
	{
		GameState mapcopy = {.map = NULL, .size = 0};
		create_empty_game_state(&mapcopy, mapsize);
		for (int i = 0; i < mapsize; i++)
		{
			for (int j = 0; j < mapsize; j++)
			{
				set_map_value(&mapcopy, j, i, get_map_value(game, j, i));
			}
		}
		GRe_update_map(&mapcopy, k, player);
		int actualCount = 0;

		for (int i = 0; i<mapsize; i++)
		{
			for (int j = 0; j < mapsize; j++)
			{
				if (get_map_value(&mapcopy, j, i) == player)
				{
					if (j - 1 >= 0 && get_map_value(&mapcopy, j - 1, i) != player)
					{
						actualCount++;
					}
					if (j + 1 < mapsize && get_map_value(&mapcopy, j + 1, i) != player)
					{
						actualCount++;
					}
					if (i - 1 >= 0 && get_map_value(&mapcopy, j, i - 1) != player)
					{
						actualCount++;
					}
					if (i + 1 < mapsize && get_map_value(&mapcopy, j, i + 1) != player)
					{
						actualCount++;
					}
				}
			}

		}
		if (actualCount > maxColorAvailable[1])
		{
			maxColorAvailable[0] = k;
			maxColorAvailable[1] = actualCount;
		}
		free(mapcopy.map);
	}
	return maxColorAvailable[0] > actualCountReal ? maxColorAvailable[0] : GRe_joueur_glouton(game, player);

}

void GRe_play_AI_frontiere(GameState* game, Color player)
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
			
			color = GRe_joueur_frontiere(game, player);
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
		}	}
}

void GRe_play_AI_frontiere_glouton(GameState* game, Color player)
{
	Color color = ERROR;
	int j1turn = 1;
	printf("Jeu lancé\n");
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
			
			color = GRe_joueur_frontiere_glouton(game, player);
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
		}	}
}
