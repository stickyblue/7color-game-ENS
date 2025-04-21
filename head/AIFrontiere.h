#ifndef AIFrontiere_h
#define AIFrontiere_h
#include "../head/GameState.h"
#include "../head/Display.h"
#include "../head/UpdateGame.h"
#include "../head/AIGlouton.h"

void GRe_play_AI_frontiere(GameState* game, Color player);
int GRe_joueur_frontiere(GameState* game, Color player);
int GRe_joueur_frontiere_glouton(GameState* game, Color player);
void GRe_play_AI_frontiere_glouton(GameState* game, Color player);

#endif
