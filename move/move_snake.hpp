#include <vector>
void move_snake(int &x_pos, int &y_pos, char &direction, int key)
{
	switch (key)
	{
	case 'w':
		if (direction != 'S')
		{
			y_pos--;
			direction = 'N';
		}
		break;
	case 's':
		if (direction != 'N')
		{
			y_pos++;
			direction = 'S';
		}
		break;
	case 'a':
		if (direction != 'E')
		{
			x_pos--;
			direction = 'W';
		}
		break;
	case 'd':
		if (direction != 'W')
		{
			x_pos++;
			direction = 'E';
		}
		break;
	}
}
