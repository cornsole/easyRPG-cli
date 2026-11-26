#include "screen.hpp"
#include "saveLoader.hpp"

int main(){
    start_scene();
}

void print_menu(int x, int y, int menu_x, int menu_y){
    int chX = menu_y + 0;
    if(y==chX){
        mvprintw(chX, menu_x+3, "    ");
        mvprintw(chX, menu_x+2, "시작하기");
    }else{
        mvprintw(chX, menu_x+2, "    ");
        mvprintw(chX, menu_x+3, "시작하기");
    }

    chX = menu_y + 1;
    if(y==chX){
        mvprintw(chX, menu_x+3, "    ");
        mvprintw(chX, menu_x+2, "불러오기");
    }else{
        mvprintw(chX, menu_x+2, "    ");
        mvprintw(chX, menu_x+3, "불러오기");
    }
    
    chX = menu_y + 2;
    if(y==chX){
        mvprintw(chX, menu_x+3, "    ");
        mvprintw(chX, menu_x+2, "종료하기");
    }else{
        mvprintw(chX, menu_x+2, "    ");
        mvprintw(chX, menu_x+3, "종료하기");
    }
}

int walk(){
    endwin(); 
    initscr();

    return 0;
}

void start_scene(){
    setlocale(LC_ALL, "");
    initscr();              // Start ncurses mode.
    noecho();               // Don't echo user input.
    cbreak();               // Disable line buffering.
    curs_set(0);            // Hide the cursor.
    keypad(stdscr, TRUE);   // Enable special keys (arrow keys are special keys).

    // We get the dimensions of the terminal like this.
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    mvprintw(yMax/3-yMax/4, xMax/3-xMax/4, "[ 턴제 로그라이크 RPG ]");



    int msg_len = 1;
    int menu_y = yMax / 3;
    int menu_x = (xMax - msg_len) / 3;

    int y = menu_y;
    int x = menu_x;


    int ch;

    
    int chX = menu_y + 0;
    if(y==chX){
        mvprintw(chX, menu_x+3, "    ");
        mvprintw(chX, menu_x+2, "시작하기");
    }else{
        mvprintw(chX, menu_x+2, "    ");
        mvprintw(chX, menu_x+3, "시작하기");
    }

    chX = menu_y + 1;
    if(y==chX){
        mvprintw(chX, menu_x+3, "    ");
        mvprintw(chX, menu_x+2, "불러오기");
    }else{
        mvprintw(chX, menu_x+2, "    ");
        mvprintw(chX, menu_x+3, "불러오기");
    }

    chX = menu_y + 2;
    if(y==chX){
        mvprintw(chX, menu_x+3, "    ");
        mvprintw(chX, menu_x+2, "종료하기");
    }else{
        mvprintw(chX, menu_x+2, "    ");
        mvprintw(chX, menu_x+3, "종료하기");
    }
    while (1)
    {
        mvprintw(y, x, ">");
        
        ch = getch();
        
        // Exit loop
        if ('q' == ch)
        {
            break;
        }
        
        // We clear the old message, the number of spaces
        // is fixed... This could be dynamic but works for this.
        mvprintw(y, x, " ");
        
        switch (ch)
        {
            case KEY_UP:
            y--;
            break;
            case KEY_DOWN:
            y++;            
            break;
            
            // case KEY_LEFT:
            //     x--;
            //     break;
            // case KEY_RIGHT:
            //     x++;
            //     break;
        }
        
        
        
        // Boundary checking.
        if (y < yMax / 3)
        {
            y = yMax/3;
        }
        
        if (y >= yMax/3+3)
        {
            y = yMax/3+2;
        }
        
        

        int chX = menu_y + 0;
        if(y==chX){
            if (ch==10) walk();
            mvprintw(chX, menu_x+3, "    ");
            mvprintw(chX, menu_x+2, "시작하기");
        }else{
            mvprintw(chX, menu_x+2, "    ");
            mvprintw(chX, menu_x+3, "시작하기");
        }

        chX = menu_y + 1;
        if(y==chX){
            if (ch==10) walk();
            mvprintw(chX, menu_x+3, "    ");
            mvprintw(chX, menu_x+2, "불러오기");
        }else{
            mvprintw(chX, menu_x+2, "    ");
            mvprintw(chX, menu_x+3, "불러오기");
        }

        chX = menu_y + 2;
        if(y==chX){
            if (ch==10) break;
            mvprintw(chX, menu_x+3, "    ");
            mvprintw(chX, menu_x+2, "종료하기");
        }else{
            
            mvprintw(chX, menu_x+2, "    ");
            mvprintw(chX, menu_x+3, "종료하기");
        }
    }

    endwin(); // The cleanup part.
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
