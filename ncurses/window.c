#include <ncurses.h>

int main()
{
	int key;
	int window_line = 3;
	int window_col = 6;
	int window_selected = -1;
	WINDOW *left, *top, *right, *bottom;

	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);

	start_color();
	
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);
	init_pair(3, COLOR_WHITE, COLOR_RED);

	bkgd(COLOR_PAIR(1));

	left = subwin(stdscr, window_line, window_col, 3, 0);
	right = subwin(stdscr, window_line, window_col, 3, 12);
	top = subwin(stdscr, window_line, window_col, 0, 6);
	bottom = subwin(stdscr, window_line, window_col, 6, 6);
	
	wbkgd(left, COLOR_PAIR(2));
	wbkgd(right, COLOR_PAIR(2));
	wbkgd(top, COLOR_PAIR(2));
	wbkgd(bottom, COLOR_PAIR(2));

	mvwprintw(left, 1, 1, "Left");
	mvwprintw(top, 1, 1, "Top");
	mvwprintw(right, 1, 0, "Right");
	mvwprintw(bottom, 1, 0, "Bottom");

	refresh();

	while(1)
	{
		key = getch();

		wbkgd(left, COLOR_PAIR(2));
		wbkgd(right, COLOR_PAIR(2));
		wbkgd(top, COLOR_PAIR(2));
		wbkgd(bottom, COLOR_PAIR(2));

		if( key == KEY_LEFT)
			wbkgd(left, COLOR_PAIR(3));
		else if ( key == KEY_UP)
			wbkgd(top, COLOR_PAIR(3));
		else if ( key == KEY_RIGHT)
			wbkgd(right, COLOR_PAIR(3));
		else if (key == KEY_DOWN)
			wbkgd(bottom, COLOR_PAIR(3));
		else if (key == 'q')
			break;
		touchwin(stdscr);	
		refresh();
	}

	endwin();	
	return 0;
}