#include <vector>
#include <ctime>

#include "./draw/gen_board.hpp"
#include "./draw/draw.hpp"
#include "./draw/gen_snake.hpp"
#include "./draw/gen_orange.hpp"

#include "./move/move_snake.hpp"
#include "./move/get_key.hpp"

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

int main()
{
	srand(time(NULL));

	const int width = 20, height = 20;
	int x_pos = width / 2, y_pos = height / 2;
	char direction = 'N';

	const char orange_char = '@', tail_char = '*', head_char = 'x';

	std::vector<char> tail;
	std::vector<std::vector<char>> board;
	while (true)
	{
		int key = get_key();
		move_snake(x_pos, y_pos, direction, key);
		system("cls");
		board = gen_board();
		gen_player(board, tail, x_pos, y_pos);
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