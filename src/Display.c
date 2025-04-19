#include "../head/GameState.h"
#include "../head/Display.h"


char GRe_color_name(Color color)
{
	switch (color)
	{
		case ERROR:
			return 'E';
		case EMPTY:
			return ' ';
		case PLAYER_1:
			return '1';
		case PLAYER_2:
			return '2';
		case RED:
			return 'R';
		case GREEN:
			return 'G';
		case BLUE:
			return 'B';
		case YELLOW:
			return 'Y';
		case MAGENTA:
			return 'M';
		case CYAN:
			return 'C';
		case WHITE:
			return 'W';
		default:
			return 'E';
	}
}

void GRe_print_map(GameState* map)
{
	for (int i = 0; i < map -> size; i++)
	{
		for (int j = 0; j < map -> size; j++)
		{
			printf("%c ", GRe_color_name(get_map_value(map, j, i)));
		}
		printf("\n");
	}
}

void GRe_print_colored_map(GameState* map)
{
	for (int i = 0; i < map -> size; i++)
	{
		for (int j = 0; j < map -> size; j++)
		{
			switch (get_map_value(map, j, i))
			{
				case RED:
					printf("\033[0;31mR \033[0m");
					break;
				case GREEN:
					printf("\033[0;32mG \033[0m");
					break;
				case BLUE:
					printf("\033[0;34mB \033[0m");
					break;
				case YELLOW:
					printf("\033[0;33mY \033[0m");
					break;
				case MAGENTA:
					printf("\033[0;35mM \033[0m");
					break;
				case CYAN:
					printf("\033[0;36mC \033[0m");
					break;
				case WHITE:
					printf("\033[0;37mW \033[0m");
					break;
				case PLAYER_1:
					printf("\033[0;16m1 \033[0m");
					break;
				case PLAYER_2:
					printf("\033[0;16m2 \033[0m");
					break;
				default:
					printf("E ");
					break;
			}
		}
		printf("\n");
	}
	printf("\n");
}
