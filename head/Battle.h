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

#endif
