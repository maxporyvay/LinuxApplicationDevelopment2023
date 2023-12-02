/** @mainpage
 * # Bisect Guess Game
 * -f   Use roman numbers instead of decimal numbers
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <libintl.h>
#include <locale.h>
#include "config.h"

/** @file bisect.c
 * Implementation
 * 
 * Implementation of Bisect Guess Game.
 */

#define _(STRING) gettext(STRING)

char* return_help_message()
{
    return _("# Bisect Guess Game\n-f   Use roman numbers instead of decimal numbers");
}

char* decimal_to_roman_map[] = {"O", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI",
                                "XVII", "XVIII", "XIX", "XX", "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII",
                                "XXIX", "XXX", "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX",
                                "XL", "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L", "LI", "LII",
                                "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX", "LXI", "LXII", "LXIII", "LXIV", "LXV",
                                "LXVI", "LXVII", "LXVIII", "LXIX", "LXX", "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI",
                                "LXXVII", "LXXVIII", "LXXIX", "LXXX", "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI",
                                "LXXXVII", "LXXXVIII", "LXXXIX", "XC", "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII",
                                "XCVIII", "XCIX", "C"};  /**< Map to convert decimal numbers to roman numbers */

/** Translate int @p decimal to roman number
 *
 * @param decimal decimal number to translate
 * @return roman number
 */
char* decimal_to_roman(int decimal)
{
    return decimal_to_roman_map[decimal];
}

/** Translate char* @p roman to decimal number
 *
 * @param roman roman number to translate
 * @return decimal number
 */
int roman_to_decimal(char* roman)
{
    for (size_t i = 0; i < 101; i++)
        if (!(strcmp(roman, decimal_to_roman_map[i])))
            return i;
    return -1;
}


/** @page bisect
 * Bisect Guess Game
 * @section SYNOPSIS
 * bisect
 * @section DESCRIPTION
 * Generate a Bisect Guess Game.
 */
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, "po");
	textdomain(PACKAGE);

    bool roman_mode = false;

    if (argc == 2)
        if (!(strcmp(argv[1], "-r")))
            roman_mode = true;
        else if (!(strcmp(argv[1], "--help")))
        {
            puts(return_help_message());
            return 0;
        }

    int left = 1;
    int right = 100;

    printf(_("Guess a number from %d to %d\n"), left, right);

    while (right > left)
    {
        int mid = (left + right) / 2;

        if (roman_mode)
            printf(_("Is the number greater than %s? Enter yes or no\n"), decimal_to_roman(mid));
        else
            printf(_("Is the number greater than %d? Enter yes or no\n"), mid);
        char ans[10];
        scanf("%s", ans);
        if (!strcmp(ans, _("yes")))
            left = mid + 1;
        else if (!strcmp(ans, _("no")))
            right = mid;
    }

    printf(_("I think that your number is %d!\n"), left);

	return 0;
}
