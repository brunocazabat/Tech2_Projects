/*
** EPITECH PROJECT, 2019
** ouioui
** File description:
** oui
*/

#include "Graphical.hpp"
#include "../include/module.hpp"
#include <curses.h>
#include <ncurses.h>

void background_print()
{
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    printw("\n    _______  _______  _______  _______  _______  _______                               __/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_        _______/\\\\\\\\\\______        __/\\\\\\\\\\\\\\\\\\\\\\\\\\___                                                       _         _\n");
    printw("   (_______)(_______)(_______)(_______)(_______)(_______)                               _\\///////\\\\\\/////__        _____/\\\\\\///\\\\\\____        _\\/\\\\\\/////////\\\\\\_                                                     /x\\       /x\\ \n");
    printw("    _______  _______  _______  _______  _______                                          _______\\/\\\\\\_______        ___/\\\\\\/__\\///\\\\\\__        _\\/\\\\\\_______\\/\\\\\\_                                                   /v\\x\\     /v\\/\\ \n");
    printw("   (_______)(_______)(_______)(_______)(_______)                                          _______\\/\\\\\\_______        __/\\\\\\______\\//\\\\\\_        _\\/\\\\\\\\\\\\\\\\\\\\\\\\\\/__                                                  \\><\\x\\   /></x/ \n");
    printw("    _______  _______  _______  _______                                                     _______\\/\\\\\\_______        _\\/\\\\\\_______\\/\\\\\\_        _\\/\\\\\\/////////____                                                  \\><\\x\\ /></x/ \n");
    printw("   (_______)(_______)(_______)(_______)                                                     _______\\/\\\\\\_______        _\\//\\\\\\______/\\\\\\__        _\\/\\\\\\_____________                                         __ __  __\\><\\x/></x/___ \n");
    printw("    _______  _______  _______                                                                _______\\/\\\\\\_______        __\\///\\\\\\__/\\\\\\____        _\\/\\\\\\_____________                                       /##_##\\/       \\</x/    \\ \n");
    printw("   (_______)(_______)(_______)                                                                _______\\/\\\\\\_______        ____\\///\\\\\\\\\\/_____        _\\/\\\\\\_____________                                     |###|###|  \\         \\    | \n");
    printw("    _______  _______                                                                           _______\\///________        ______\\/////_______        _\\///______________                                     \\##|##/ \\__\\____\\____\\__/\n");
    printw("   (_______)(_______)                                                                                                                                                                                          |_|   |  |  | |  | | \n");
    printw("    _______                                                                                                                                                                                                    \\*/   \\  |  | |  | /\n");
    printw("   (_______)\n");

    }

int	box_time()
{
    time_t now = time(0);
    tm *gmtm = gmtime(&now);
	WINDOW *timedate;

	start_color();
	init_pair(2, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	timedate = subwin(stdscr, 10, 40, 16, 9);
	wborder(timedate, ACS_VLINE, ACS_VLINE, ACS_VLINE, ACS_VLINE, 0, 0, 0, 0);
	mvwprintw(timedate, 0, 3, "TIME");

	std::string time_date = ctime(&now);
    if (time_date.length() == 0) {
		mvwprintw(timedate, 2, 2, "No local date");
        return (84);
    }
    std::cout << "Date: " << time_date;
    time_date = asctime(gmtm);
    if (time_date.length() == 0) {
		mvwprintw(timedate, 3, 2, "No UTC date");
        return (84);
    }

	mvwprintw(timedate, 3, 2, "UTC Date: \n");
	mvwprintw(timedate, 4, 2, time_date.c_str());
    attroff(COLOR_PAIR(2));
	return (0);
}

int	box_hostname()
{
	char *user = std::getenv("USER");
	char *hostname = std::getenv("HOSTNAME");
	WINDOW *host;

	start_color();
	init_pair(3, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(3));
	host = subwin(stdscr, 10, 40, 28, 9);
	wborder(host, ACS_VLINE, ACS_VLINE, ACS_VLINE, ACS_VLINE, 0, 0, 0, 0);
	mvwprintw(host, 0, 3, "HOST & USERNAME");

	if (user == NULL) {
		mvwprintw(host, 2, 2, "User doesn't exist");
        return (84);
    }
	mvwprintw(host, 2, 2, "Username: ");
	mvwprintw(host, 3, 2, user);

	if (hostname == NULL) {;
		mvwprintw(host, 4, 2, "Hostname doesn't exist");
        return (84);
    }
	mvwprintw(host, 4, 2, "Hostname: ");
	mvwprintw(host, 5, 2, hostname);

	attroff(COLOR_PAIR(3));
    return (0);
}

int	box_osversion()
{
	struct utsname sysinfo;
	WINDOW *osversion;

	start_color();
	init_pair(4, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(4));
	osversion = subwin(stdscr, 10, 40, 40, 9);
	wborder(osversion, ACS_VLINE, ACS_VLINE, ACS_VLINE, ACS_VLINE, 0, 0, 0, 0);
	mvwprintw(osversion, 0, 3, "OS VERSION");

	if(uname(&sysinfo)) exit(-1);
	mvwprintw(osversion, 2, 2, "System Name: ");
	mvwprintw(osversion, 3, 2, sysinfo.sysname);
	mvwprintw(osversion, 4, 2, "Release(Kernel) Version: ");
	mvwprintw(osversion, 5, 2, sysinfo.release);
	mvwprintw(osversion, 6, 2, "Machine Arch: ");
	mvwprintw(osversion, 7, 2, sysinfo.machine);

	attroff(COLOR_PAIR(4));
    return (0);
}

void	box_separ()
{
	WINDOW *separ;

	start_color();
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(5));
	separ = subwin(stdscr, 38, 3, 14, 60);
	wborder(separ, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, 0, 0, 0, 0);
	attroff(COLOR_PAIR(5));
}


int CPU_info()
{
	WINDOW *BOX;

	start_color();
	init_pair(10, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(10));
	BOX = subwin(stdscr, 6, 120, 13, 80);
	wborder(BOX, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_VLINE, 0, 0, 0, 0);
	mvwprintw(BOX, 0, 3, "CORE INFO");

	std::ifstream file("/proc/cpuinfo", std::ios::in);
    if (file) {
        std::string contenu;
        while(getline(file, contenu)) {
            if (!contenu.compare(0, 9, "vendor_id") || !contenu.compare(0, 9, "processor") ||
                !contenu.compare(0, 10, "model name") || !contenu.compare(0, 10, "cache size") ||
                 !contenu.compare(0, 7, "cpu MHz"))
				mvwprintw(BOX, 2, 2, contenu.c_str());
        }
        file.close();
    }
    else {
		mvwprintw(BOX, 2, 2, "No file");
        return (84);
    }
	attroff(COLOR_PAIR(10));
    return (0);
}

int	CPU_BOX1()
{
	WINDOW *BOX1;

	start_color();
	init_pair(6, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(6));
	BOX1 = subwin(stdscr, 6, 60, 20, 80);
	wborder(BOX1, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_VLINE, 0, 0, 0, 0);
	mvwprintw(BOX1, 0, 3, "CORE 1");

	std::ifstream file("/proc/stat", std::ios::in);
    if (file) {
        std::string contenu;
        while(getline(file, contenu)) {
            if (!contenu.compare(0, 4, "cpu0"))
				mvwprintw(BOX1, 2, 2, contenu.c_str());
        }
        file.close();
    }
    else {
		mvwprintw(BOX1, 2, 2, "No file");
        return (84);
    }
	attroff(COLOR_PAIR(6));
    return (0);
}

int	CPU_BOX2()
{
	WINDOW *BOX2;

	start_color();
	init_pair(7, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(7));
	BOX2 = subwin(stdscr, 6, 60, 20, 140);
	wborder(BOX2, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_VLINE, 0, 0, 0, 0);
	mvwprintw(BOX2, 0, 3, "CORE 2");

	std::ifstream file("/proc/stat", std::ios::in);
    if (file) {
        std::string contenu;
        while(getline(file, contenu)) {
            if (!contenu.compare(0, 4, "cpu1"))
				mvwprintw(BOX2, 2, 2, contenu.c_str());
        }
        file.close();
    }
    else {
		mvwprintw(BOX2, 2, 2, "No file");
        return (84);
    }
	attroff(COLOR_PAIR(7));
    return (0);
}

int	CPU_BOX3()
{
	WINDOW *BOX3;

	start_color();
	init_pair(8, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(8));
	BOX3 = subwin(stdscr, 6, 60, 26, 80);
	wborder(BOX3, ACS_VLINE, ACS_VLINE, ACS_VLINE, ACS_HLINE, 0, 0, 0, 0);
	mvwprintw(BOX3, 0, 3, "CORE 3");

	std::ifstream file("/proc/stat", std::ios::in);
    if (file) {
        std::string contenu;
        while(getline(file, contenu)) {
            if (!contenu.compare(0, 4, "cpu2"))
				mvwprintw(BOX3, 2, 2, contenu.c_str());
        }
        file.close();
    }
    else {
		mvwprintw(BOX3, 2, 2, "No file");
        return (84);
    }
	attroff(COLOR_PAIR(8));
    return (0);
}

int	CPU_BOX4()
{
	WINDOW *BOX4;

	start_color();
	init_pair(9, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(9));
	BOX4 = subwin(stdscr, 6, 60, 26, 140);
	wborder(BOX4, ACS_VLINE, ACS_VLINE, ACS_VLINE, ACS_HLINE, 0, 0, 0, 0);
	mvwprintw(BOX4, 0, 3, "CORE 4");

	std::ifstream file("/proc/stat", std::ios::in);
    if (file) {
        std::string contenu;
        while(getline(file, contenu)) {
            if (!contenu.compare(0, 4, "cpu3"))
				mvwprintw(BOX4, 2, 2, contenu.c_str());
        }
        file.close();
    }
    else {
		mvwprintw(BOX4, 2, 2, "No file");
        return (84);
    }
	attroff(COLOR_PAIR(9));
    return (0);
}

int    box_NETWORK()
{
    WINDOW *NET;

	start_color();
	init_pair(10, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(10));
	NET = subwin(stdscr, 7, 120, 44, 80);
	wborder(NET, ACS_VLINE, ACS_VLINE, ACS_VLINE, ACS_VLINE, 0, 0, 0, 0);
	mvwprintw(NET, 0, 3, "NETWORK");
	attroff(COLOR_PAIR(10));
		std::ifstream file("/proc/net/arp", std::ios::in);
    if (file) {
        std::string contenu;
        while(getline(file, contenu)) {
            if (!contenu.compare(0, 10, "IP address") ||
		!contenu.compare(0, 1, "1"))
				mvwprintw(NET, 2, 2, contenu.c_str());
        }
        file.close();
    }
    else {
		mvwprintw(NET, 2, 2, "No file");
        return (84);
    }
	attroff(COLOR_PAIR(10));

	return (0);
}

int box_RAM()
{
    WINDOW *RAM;

	start_color();
	init_pair(11, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(11));
	RAM = subwin(stdscr, 7, 120, 35, 80);
	wborder(RAM, ACS_VLINE, ACS_VLINE, ACS_VLINE, ACS_VLINE, 0, 0, 0, 0);
	mvwprintw(RAM, 0, 3, "RAM");
	attroff(COLOR_PAIR(11));

    return (0);
}

int box_create()
{
    background_print();
    box_time();
    box_hostname();
    box_osversion();
    box_separ();
    CPU_info();
    CPU_BOX1();
    CPU_BOX2();
    CPU_BOX3();
    CPU_BOX4();
    box_NETWORK();
    box_RAM();
    return 0;
}

int text_init(Graphical_t *data)
{
    int ch;
    data->key_quit = 'q';
    initscr();
    curs_set(FALSE);
    cbreak();
    while (ch != data->key_quit && ch != 27) {
        box_create();
        refresh();
        keypad(stdscr, TRUE);
	timeout(100);
        ch = getch();
        clear();
    }
    endwin();
    return (0);
}
