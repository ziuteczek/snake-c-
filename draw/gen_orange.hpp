#include <vector>
void draw_orange(std::vector<std::vector<char>> &board, int orange_x, int orange_y, const char orange_char = '@')
{
    board[orange_y][orange_x] = orange_char;
}