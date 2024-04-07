#include <vector>

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

void gen_player(std::vector<std::vector<char>> &board, std::vector<char> tail, int player_x, int player_y, char player_char = '*')
{
    board[player_x][player_y] = player_char;
    int last_x = player_x, last_y = player_y;
    for (int tail_n = 0; tail_n < tail.size(); tail_n++)
    {
        switch (tail[tail_n])
        {
        case 'N':
            board[++last_y][last_x] = player_char;
            break;
        case 'S':
            board[--last_y][last_x] = player_char;
            break;
        case 'W':
            board[last_y][--last_x] = player_char;
            break;
        case 'E':
            board[last_y][++last_x] = player_char;
            break;
        default:
            break;
        }
    }
}