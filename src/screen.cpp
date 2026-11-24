#include "screen.hpp"

int main(){
    test();
}

int test(void)
{
    initscr();              // Start ncurses mode.
    noecho();               // Don't echo user input.
    cbreak();               // Disable line buffering.
    curs_set(0);            // Hide the cursor.
    keypad(stdscr, TRUE);   // Enable special keys (arrow keys are special keys).

    // We get the dimensions of the terminal like this.
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // Set up the message and its initial position.
    const char *message = "Hello, World!";
    int msg_len = strlen(message);
    int y = yMax / 2;
    int x = (xMax - msg_len) / 2;

    int ch;

    while (1)
    {
        mvprintw(y, x, message);

        ch = getch();

        // Exit loop
        if ('q' == ch)
        {
            break;
        }

        // We clear the old message, the number of spaces
        // is fixed... This could be dynamic but works for this.
        mvprintw(y, x, "             ");

        switch (ch)
        {
            case KEY_UP:
                y--;
                break;
            case KEY_DOWN:
                y++;
                break;
            case KEY_LEFT:
                x--;
                break;
            case KEY_RIGHT:
                x++;
                break;
        }

        // Boundary checking.
        if (y < 0)
        {
            y = 0;
        }

        if (y >= yMax)
        {
            y = yMax - 1;
        }

        if (x < 0)
        {
            x = 0;
        }

        if (x + msg_len >= xMax)
        {
            x = xMax - msg_len;
        }
    }

    endwin(); // The cleanup part.

    return 0;
}
