#include <pdcurses/curses.h>

int main(void) {
    initscr();                  // Initialize terminal mode
    printw("PDCurses is working!"); // Print text to virtual screen
    refresh();                  // Render output to screen
    getch();                    // Wait for user input
    endwin();                   // End curses mode cleanly
    return 0;
}