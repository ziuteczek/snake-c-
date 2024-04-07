#include <iostream>
#include <windows.h>
#include <vector>
#include <conio.h>

#include "./draw/gen_board.hpp"
#include "./draw/draw.hpp"
#include "./draw/gen_entities.hpp"

using namespace std;

// O - X | 1 - Y
// true + | false -
int main()
{
	const int width = 20, height = 20;
	vector<char> tail;
	tail.push_back('E');
	tail.push_back('N');
	vector<vector<char>> board;
	while (true)
	{
		system("cls");
		board = gen_board();
		gen_player(board, tail, 5, 5);
		draw_board(board);
	}
	system("pause");
	return 0;
}