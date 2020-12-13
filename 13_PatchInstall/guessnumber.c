#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>
//#include "gettext.h"
//#include "configure.h"

#define _(STRING) gettext(STRING)

int main(int argc, char *argv[])
{
	char *dir;

	dir = dirname(realpath(argv[0], NULL));
	setlocale (LC_ALL, "");
	bindtextdomain ("guessnumber", dir);
	textdomain ("guessnumber");

	puts(_("Think of a number between 1 and 100\n"));
    int left_board = 1, right_board = 100, midpoint;
    char answ[100];
    
    while (left_board != right_board ) {
        midpoint = (right_board - left_board ) / 2 + left_board ;
        printf(_("Is the number greater than %d?\n"), midpoint); 
        scanf("%s", answ);
        if (!strcmp(answ, _("yes"))) {
            left_board = midpoint + 1;
        } else {
            right_board = midpoint;
        }
    }
    printf (_("Your number is %d\n"), left_board);
    

	return 0;
}
