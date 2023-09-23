#include <ncurses.h>
#include <stdlib.h>

#define DX 3
#define BASE_SIZE 100

int main (int argc, char** argv)
{
	FILE *fileptr;
	char *text = malloc(sizeof(char) * BASE_SIZE);
	char curr_sym;
	int actual_size = 0;
	int str_cnt = 0;
	int actual_str_size = 0;
	int max_size = BASE_SIZE;

	initscr();
	int nlines = LINES - 2 * DX;
	int ncols = COLS - 2 * DX;
	int begin_y = DX;
	int begin_x = DX;

	fileptr = fopen(argv[1], "r");
	while (!feof(fileptr))
	{
		curr_sym = fgetc(fileptr);

		if ((int)curr_sym == 10)
		{
			str_cnt++;
			actual_str_size = 0;
		}
		else if ((int)curr_sym == 9)
		{
			actual_str_size += 8;
		}
		else
		{
			actual_str_size++;
		}

		if (actual_str_size < ncols)
		{
			if (actual_size + 1 > max_size)
			{
				max_size += BASE_SIZE;
				text = realloc(text, sizeof(char) * max_size);
			}

			if ((int)curr_sym > -1)
			{
				text[actual_size++] = curr_sym;
			}
		}
	}
	fclose(fileptr);

	WINDOW *win;
	int c;

	noecho();
	cbreak();
	curs_set(0);
	printw("File: %s; size: %d", argv[1], str_cnt);
	refresh();

	win = newwin(nlines, ncols, begin_y, begin_x);
	keypad(win, TRUE);
	box(win, 0, 0);

	int i = 0;
	bool already_exited = FALSE;
	while (i < actual_size)
	{
		int curr_line = 1;
		int curr_col = 1;
		wmove(win, curr_line, curr_col);
		while (i < actual_size && curr_line < nlines - 1)
		{
			char curr_sym = text[i++];
			wprintw(win, "%c", curr_sym);

			if ((int)curr_sym == 10)
			{
				curr_col = 1;
				wmove(win, ++curr_line, curr_col);
			}
			else if ((int)curr_sym != 9)
			{
				wmove(win, curr_line, ++curr_col);
			}
			else
			{
				curr_col += 8;
				wmove(win, curr_line, curr_col);
			}
		}
		box(win, 0, 0);

		char ch = wgetch(win);
		while ((int)ch != 27 && (int)ch != 32)
		{
			ch = wgetch(win);
		}
		if ((int)ch == 27)
		{
			already_exited = TRUE;
			break;
		}
		else if (i < actual_size)
		{
			werase(win);
		}
	}

	if (!already_exited)
	{
		while (wgetch(win) != 27)
		{

		}
	}

	endwin();

	free(text);

	return 0;
}
