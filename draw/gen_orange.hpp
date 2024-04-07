#include <vector>
#include <ctime>
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
void draw_orange(std::vector<std::vector<char>> &board, int orange_x, int orange_y, const char orange_char = '@')
{
    board[orange_y][orange_x] = orange_char;
}