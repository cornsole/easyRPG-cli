#include "bounce.hpp"
#define DELAY 12500 // Delay in microseconds.

int main(){
    test();
}

int test(void)
{
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    // Some color magic.
    // If we wanted to, we could go even lower and
    // set the colours ourselves with ANSI escape codes.
    // Maybe for another article.
    if (FALSE == has_colors())
    {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }

    start_color();
    // color pairs (ID, foreground, background).
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);


    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    int y = yMax / 2;
    int x = xMax / 2;
    int next_y = 1;
    int next_x = 1;
    int color_index = 1; // We start with red.

    int ch;

    while (1)
    {
        if ('q' == (ch = getch()))
        {
            break;
        }

        clear();

        // Turn on the color pair
        attron(COLOR_PAIR(color_index));

        mvprintw(y, x, "o");

        // Turn off the color pair
        attroff(COLOR_PAIR(color_index));

        refresh();
        usleep(DELAY);

        y += next_y;
        x += next_x;

        if (y >= yMax - 1 || y <= 0)
        {
            next_y *= -1;
            color_index++;
        }
        if (x >= xMax - 1 || x <= 0)
        {
            next_x *= -1;
            color_index++;
        }
        
        if (color_index > 5)
        {
            color_index = 1;
        }
    }

    endwin();

    return 0;

}
