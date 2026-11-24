#include <ncurses.h>
#include <iostream>
using namespace std;

int main() {
    initscr();
    cbreak();
    noecho();

    char ch;
    
    ch = getch();
    cout << ch;
    return 0;
}
