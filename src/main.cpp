#include <iostream>
#include <ctime>
#include <ncurses.h>
#include <random>
#include <string>
#include <stdlib.h>

using namespace std;

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 70; 

const int PAR_FONDO = 1;

//------------------------------------------------------------------------------------

bool game_over;

int x, y, puntaje;

void setup();
void input();
void update();
void draw();

//----------------------------------------------------------------------------------

int main()
{

	initscr();
	noecho();
	curs_set(false);
	keypad(stdscr, true);
	nodelay(stdscr, true);

	//Verificar si la terminal soporta colores
	if (LINES < ALTO || COLS < ANCHO)
	{
		endwin();
		printf("La terminal debe tener %dx%d\n\n", ANCHO, ALTO);
		exit(1);
	}
	
	if (has_colors()==false)
	{
		endwin();
		printf("La terminal no soporta color.\n\n");
		exit(2);
	}
	
	start_color();
	setup();

	while (!game_over)
	{
		input();
		update();
		draw();
	}

	endwin();

	cout << "Game Over!" << endl;
	cout << endl;
}

void setup()
{
	game_over = false;
	puntaje = 0;

	init_pair(PAR_FONDO, COLOR_WHITE, COLOR_RED); //TOCAR EL COLOR DE FONDO
}
//----------------------------------------------------------
void input(){

}
//----------------------------------------------------------
void update(){

}
//----------------------------------------------------------
void draw()
{
	attron(COLOR_PAIR(PAR_FONDO));
	box(stdscr, 0, 0);
	mvprintw(0, 5, "[PUNTOS: %d     ]", puntaje);
	
	for (int y = 1; y < ALTO - 1; y++)
	{
		mvhline(y, 1, ' ', ANCHO - 2);
	}

	attroff(COLOR_PAIR(PAR_FONDO));
	refresh();
	delay_output(DELAY);
};