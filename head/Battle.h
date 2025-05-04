#ifndef Battle_h
#define Battle_h
#include "../head/GameState.h"
#include "../head/Display.h"
#include "../head/UpdateGame.h"
#include "../head/AIGlouton.h"
#include "../head/AIRandom.h"
#include "../head/AIFrontiere.h"

typedef enum AI
{
    ERRORAI,
    ALEATOIRE,
    ALEATOIREADJ,
    GLOUTON,
    FRONTIERE,
    FRONTIEREGL
}AI;

void GRe_battle(GameState* game, int numberOfGame, int ai1, int ai2);
int GRe_AIAnswer(GameState* game, int ai, Color player);
#endif
