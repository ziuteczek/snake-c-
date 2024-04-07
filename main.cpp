#include <windows.h>
#include <vector>
#include <conio.h>
#include <ctime>

#include "./draw/gen_board.hpp"
#include "./draw/draw.hpp"
#include "./draw/gen_snake.hpp"
#include "./draw/gen_orange.hpp"

bool vector_2d_includes(std::vector<std::vector<char>> v, char to_check)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] == to_check)
			{
				return true;
			}
		}
	}
	return false;
}
void gen_orange(std::vector<std::vector<char>> board, int width, const int height, char orange_char, char allow_orange_spawn_char)
{
	int orange_x, orange_y;
	do
	{
		orange_x = rand() % (width - 1) + 1;
		orange_y = rand() % (width - 1) + 1;
	} while (board[orange_y][orange_x] != allow_orange_spawn_char);
	board[orange_y][orange_x] == orange_char;
}
int main()
{
	srand(time(NULL));
	const int width = 20, height = 20;
	const char orange_char = '@', tail_char = '*', head_char = 'x';
	std::vector<char> tail;
	std::vector<std::vector<char>> board;
	while (true)
	{
		system("cls");
		board = gen_board();
		gen_player(board, tail, 5, 5);
		if (!vector_2d_includes(board, orange_char))
		{
			gen_orange(board, width, height, orange_char, ' ');
		}
		draw_orange(board, 8, 3, orange_char);
		draw_board(board);
	}
	system("pause");
	return 0;
}