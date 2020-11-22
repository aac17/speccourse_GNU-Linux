#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "."

const char *roman_table[100] ={ "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", 
"XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII",
"XXVIII", "XXIX", "XXX", "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX",
  "XL", "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L", "LI", "LII", "LIII", 
  "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX", "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII",
   "LXVIII", "LXIX", "LXX", "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX",
    "LXXX", "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC",
     "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C" };
     
char *
to_roman(int x)
{
    return roman_table[x];
}

int 
main(int argc, char *argv[])
{
	char *dir;

	dir = dirname(realpath(argv[0], NULL));
	setlocale (LC_ALL, "");
	bindtextdomain ("guessnumber", LOCALE_PATH);
	textdomain ("guessnumber");
    
    if (argc > 1 && !strcmp(argv[1], "-r")) {
        puts(_("Think of a number between I and C\n"));
        int left_board = 1, right_board = 100, midpoint;
        char answ[100];
        
        while (left_board != right_board ) {
            midpoint = (right_board - left_board ) / 2 + left_board ;
            printf(_("Is the number greater than %s?\n"), to_roman(midpoint)); 
            scanf("%s", answ);
            if (!strcmp(answ, _("yes"))) {
                left_board = midpoint + 1;
            } else {
                right_board = midpoint;
            }
        }
        printf (_("Your number is %s\n"), to_roman(left_board));
    } else {

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
    }
    

	return 0;
}
