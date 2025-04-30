#include "../head/Battle.h"
#include "../head/GameState.h"
#include "../head/Display.h"

void battle(GameState* game, int numberOfGame, int ai1, int ai2)
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
				color = AIAnswer(game, ai1, PLAYER_1);
				GRe_update_map(game, color, PLAYER_1);
				j1turn = 0;
			} else
			{
				color = AIAnswer(game, ai2, PLAYER_2);
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

int AIAnswer(GameState* game, int ai, Color player)
{
	switch (ai)
	{
		default:
			return ERRORAI;
		case ALEATOIRE:
			return GRe_Joueur_aleatoire(game, player);
		case ALEATOIREADJ:
			return GRe_Joueur_aleatoire_adjacent(game, player);
		case GLOUTON:
			return GRe_joueur_glouton(game, player);
		case FRONTIERE:
			return GRe_joueur_frontiere(game, player);
		case FRONTIEREGL:
			return GRe_joueur_frontiere_glouton(game, player);
	}
}


