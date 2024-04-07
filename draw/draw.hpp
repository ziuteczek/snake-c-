#include <iostream>
#include <vector>


void draw_board(std::vector<std::vector<char>> board)
{
    for (int row = 0; row < board.size(); row++)
    {
        for (int column = 0; column < board[0].size(); column++)
        {
            std::cout << board[row][column];
        }
        std::cout << std::endl;
    }
}