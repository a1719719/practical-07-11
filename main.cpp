#include <ncurses.h>
#include <string>
using namespace std;

int main()
{	

	initscr();
	curs_set(0);
	noecho();
	cbreak();
	if(!has_colors()){
		printw("this terminal does not have colours some errors may occur");
	}


	bool started=false;


	int height, width;
	getmaxyx(stdscr,height,width); //gets terminal size
	WINDOW* menu=newwin(height,width,0,0);
	refresh();
	box(menu,0,0);
	wrefresh(menu);
	int menuChoice;
	int endGame=0;
	//font size attribut here
	mvwprintw(menu,4,width/2-35," ___      ___   __   __  _______    _______  _______    ______   ___   _______ ");
	mvwprintw(menu,5,width/2-35,"|   |    |   | |  | |  ||       |  |       ||       |  |      | |   | |       |");
	mvwprintw(menu,6,width/2-35,"|   |    |   | |  |_|  ||    ___|  |_     _||   _   |  |  _    ||   | |    ___|");
	mvwprintw(menu,7,width/2-35,"|   |    |   | |       ||   |___     |   |  |  | |  |  | | |   ||   | |   |___ ");
	mvwprintw(menu,8,width/2-35,"|   |___ |   | |       ||    ___|    |   |  |  |_|  |  | |_|   ||   | |    ___|");
	mvwprintw(menu,9,width/2-35,"|       ||   |  |     | |   |___     |   |  |       |  |       ||   | |   |___ ");
	mvwprintw(menu,10,width/2-35,"|_______||___|   |___|  |_______|    |___|  |_______|  |______| |___| |_______|");

	mvwprintw(menu,height/2-2,width/2-2,"1: Start");
	mvwprintw(menu,height/2+2,width/2-2,"2: Exit");
	while(started==false){
		
		if(endGame!=0){
			endwin();
			return 0;
		}
		menuChoice=wgetch(menu);
		switch(menuChoice){
			case '1':started=true;
			break;
			case '2':endGame++;
			break;
			default:endGame=0;
			
		}
	}	
	
	wclear(menu);
	wrefresh(menu);
	delwin(menu);
	refresh();

	int windowh =height/2;
	int windoww =height;
	int middlew = width/2;
	int middleh = height/2;
	WINDOW* map=newwin(windowh,windoww,0,0);
	WINDOW* room=newwin(windowh,windoww,0,middlew);
	WINDOW* textOutline=newwin(windowh,windoww,middleh,middlew);
	WINDOW* text=newwin(windowh-2,windoww-2,middleh+1,middlew+1);
	WINDOW* commands=newwin(windowh,windoww,middleh,0);
	refresh();

	box(map,0,0);
	box(room,0,0);
	box(textOutline,0,0);
	box(commands,0,0);


	wrefresh(map);
	wrefresh(room);
	wrefresh(textOutline);
	wrefresh(commands);
	refresh();	



	//END OF WINDOW SETTUP

	int key =wgetch(commands);
	wclear(text);
	switch(key){
		case '1': mvwprintw(text,1,5,"You wake in a unfamiliar room");
		break;
		case '2': mvwprintw(text,1,5,"Congratulations you found a new death");
		break;
		default: mvwprintw(text,1,5,"Sorry but that isn't a new death");
	}
	wrefresh(text);

	getch();
	endwin();
	return 0;
}