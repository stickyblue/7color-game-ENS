#ifndef AIRandom_h
#define AIRandom_h
#include "../head/GameState.h"
#include "../head/Display.h"
#include "../head/UpdateGame.h"


void GRe_play_game_AI_aleatoire(GameState* game, Color player);
int GRe_Joueur_aleatoire(GameState* map, Color joueur);
int GRe_Joueur_aleatoire_adjacent(GameState* map, Color player);
void GRe_play_AI_aleatoire_adjacent(GameState* game, Color player);

#endif
