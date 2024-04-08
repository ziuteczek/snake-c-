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
bool check_lose(int x_pos,int y_pos,int width,int height){
	return (x_pos == 0 || y_pos == width || y_pos == 0 || y_pos == height);
}
int main()
{
	srand(time(NULL));

	const int width = 20, height = 20;
	int x_pos = width / 2, y_pos = height / 2;
	int orange_x = orange_placement_rand(width), orange_y = orange_placement_rand(height);
	char direction = 'N';

	const char orange_char = '@', tail_char = '*', head_char = 'x';
	int points = 0;

	std::vector<char> tail;
	std::vector<std::vector<char>> board;
	while (true)
	{
		int key = get_key();
		move_snake(x_pos, y_pos, direction, key);
		board = gen_board();
		if (x_pos == orange_x && y_pos == orange_y)
		{
			gen_orange(board, width, height, orange_char, ' ', orange_x, orange_y);
			points++;
		}
		else
		{
			draw_orange(board, orange_x, orange_y, orange_char);
		}
		gen_player(board, tail, x_pos, y_pos);
		system("cls");
		draw_board(board);
		if (check_lose(x_pos,y_pos,width,height))
		{
			break;
		}
		std::cout << points << std::endl;
	}
	system("pause");
	return 0;
}