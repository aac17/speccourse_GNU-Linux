#include <ncurses.h>
#include <locale.h>
#include <stdio.h>

int
main (int argc, char * argv[])
{
    setlocale(LC_ALL, "");
    FILE *input = fopen(argv[1], "r");
    WINDOW *win;
    initscr ();
    noecho();
    cbreak();
    printw("File: %s", argv[1]);
    refresh();
    
    win = newwin(LINES - 6, COLS - 6, 3, 3);
    keypad(win, TRUE);
    scrollok(win, TRUE);
    int win_LINES = LINES - 6 - 2, win_COLS = COLS - 6 - 2;
    char str[win_COLS + 1];
    int flag = 0;
    int c = 32;
    do {
        if ((c == 32) && (flag == 0)) {
            werase(win);
            box(win, 0, 0);
            for (int i = 0; i < win_LINES; i++) {
                if (fgets(str, win_COLS, input) == NULL) {
                    flag = 1;
                    break;
                }
                mvwprintw(win, i + 1, 1, "%s", str);
            }
        }
        box(win, 0, 0);
        wrefresh(win);
    } while((c = wgetch(win)) != 27);
    fclose(input);
    endwin ();
    
}
