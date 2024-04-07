#include <vector>

void insert_row_border(std::vector<std::vector<char>> &board, unsigned const width, const char border_char)
{
    board.push_back(std::vector<char>());
    for (int i = 0; i < width; i++)
    {
        board[board.size() - 1].push_back(border_char);
    }
}

void gen_board_row(std::vector <std::vector <char>> &board,int row,int width,const char border_char)
{
        board.push_back(std::vector<char>());
        board[row].push_back(border_char);
        for (int column = 1; column < width - 1; column++)
        {
            board[row].push_back(' ');
        }
        board[row].push_back(border_char);
}
std::vector<std::vector<char>> gen_board(const int width = 20, const int height = 20, const char border_char = '+')
{
    std::vector<std::vector<char>> board;
    insert_row_border(board, width, border_char);
    for (int row = 1; row < height - 1; row++)
    {
        gen_board_row(board,row,width,border_char);
    }
    insert_row_border(board, width, border_char);
    return board;
}