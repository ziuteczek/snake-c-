#include <vector>
void gen_player(std::vector<std::vector<char>> &board, std::vector<char> tail, int player_x, int player_y, char player_char = 'x', char tail_char = '*')
{
    board[player_x][player_y] = player_char;
    int last_x = player_x, last_y = player_y;
    for (int tail_n = 0; tail_n < tail.size(); tail_n++)
    {
        switch (tail[tail_n])
        {
        case 'N':
            board[++last_y][last_x] = tail_char;
            break;
        case 'S':
            board[--last_y][last_x] = tail_char;
            break;
        case 'W':
            board[last_y][--last_x] = tail_char;
            break;
        case 'E':
            board[last_y][++last_x] = tail_char;
            break;
        default:
            break;
        }
    }
}