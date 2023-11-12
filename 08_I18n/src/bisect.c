#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#include "config.h"

#define _(STRING) gettext(STRING)

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, "po");
	textdomain(PACKAGE);

    int left = 1;
    int right = 100;

    printf(_("Guess a number from %d to %d\n"), left, right);

    while (right > left)
    {
        int mid = (left + right) / 2;
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
