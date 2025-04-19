#include "../head/Display.h"
#include "../head/GameState.h"
#include "../head/UpdateGame.h"

void GRe_update_map(GameState* map, Color color, Color player)
{
	int found = 1;
	int taille_map = map -> size;
	while(1 == found)
	{
		found = 0;
		for (int i = 0; i < taille_map; i++)
		{
			for (int j = 0; j < taille_map; j++)
			{
				if (get_map_value(map, j, i) == color)
				{
					if (j - 1 >= 0 && get_map_value(map, j - 1, i) == player)
					{
						set_map_value(map, j, i, player);
						found = 1;
					}
					if (j + 1 < taille_map && get_map_value(map, j + 1, i) == player)
					{
						set_map_value(map, j, i, player);
						found = 1;
					}
					if (i - 1 >= 0 && get_map_value(map, j, i - 1) == player)
					{
						set_map_value(map, j, i, player);
						found = 1;
					}
					if (i + 1 < taille_map && get_map_value(map, j, i + 1) == player)
					{
						set_map_value(map, j, i, player);
						found = 1;
					}

				}
			}
		}
	}
}

int GRe_is_game_over(GameState* map)
{
	int taille_map = map -> size;
	int J1 = 0;
	int J2 = 0;
	for (int i = 0; i < taille_map; i++)
	{
		for (int j = 0; j < taille_map; j++)
		{
			if (get_map_value(map, j, i) == PLAYER_1)
			{
				J1++;
			}
			if (get_map_value(map, j, i) == PLAYER_2)
			{
				J2++;
			}
		}
	}
	if (J1 > taille_map * taille_map / 2)
	{
		//printf("Victoire joueur 1\n");
		return 1;
	}
	else if (J2 > taille_map * taille_map / 2)
	{
		//printf("Victoire joueur 2\n");
		return 2;
	} else {
		return 0;
	}
}
