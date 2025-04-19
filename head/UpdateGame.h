#ifndef UpdateGame_h
#define UpdateGame_h
#include "../head/GameState.h"
#include "../head/Display.h"

void GRe_update_map(GameState* map, Color color, Color player);
int GRe_is_game_over(GameState* map);

#endif
