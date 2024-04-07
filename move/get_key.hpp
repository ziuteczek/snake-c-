#include <conio.h>
char get_key()
{
    int key;
    do
    {
        key = getch();
    } while (key != 119 && key != 97 && key != 115 && key != 100);
    return key;
}