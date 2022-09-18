#include <iostream>
#include <ctime>
#include <ncurses.h>
#include <string>
#include <stdlib.h>

#include "objetos.h"
#include "dibujos.h"

using namespace std;

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 70; 
const int PAR_FONDO = 1;

bool game_over, salir, juego_activo;
int puntaje;

Paleta paleta1 = Paleta(0,0);
Paleta paleta2 = Paleta(120,0);
Pelota pelota = Pelota(60,60);

void setup();
void input();
void update();
void draw();

enum teclado
{
	PALETA1_ARRIBA = KEY_UP,
	PALETA1_ABAJO = KEY_DOWN,
	PALETA2_ARRIBA = 119,
	PALETA2_ABAJO = 115,
	PAUSA,
	SALIR = 27,
	NIVEL_1,
	NIVEL_2,
	NIVEL_3
};

const int PARCOLOR_FONDO = 1;



//----------------------------------------------------------------------------------


void setup()
{
	initscr();
	noecho();
	curs_set(false);
	keypad(stdscr, true);
	nodelay(stdscr, true);

	start_color();

	game_over = false;
	puntaje = 0;


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

	init_pair(PAR_FONDO, COLOR_WHITE, COLOR_RED); //TOCAR EL COLOR DE FONDO
}
//----------------------------------------------------------
void input(){

	int tecla = getch();

	switch (tecla)
	{
	case KEY_UP:
		break;
	case KEY_DOWN:
		break;
	case KEY_LEFT:
		break;
	case KEY_RIGHT:
		break;
	case 27:
		salir = TRUE;
		break;
	case 'e':
	default:
		break;
	}
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

void menu()
{
	Dibujos dibujos = Dibujos();
	dibujos.presentacion(20,80);
	refresh();
}


void input_menu()
{

	int tecla = getch();

	switch (tecla)
	{
	case 1:


		break;
	case KEY_DOWN:
		break;
	case KEY_LEFT:
		break;
	case KEY_RIGHT:
		break;
	case 27:
		salir = TRUE;
		break;
	case 'e':
	default:
		break;
	}
}


int main()
{
	setup();

	while(!salir) 
	{

		while(!juego_activo)
		{
			menu();
		}

		while (!game_over)
		{
			input();
			update();
			draw();
		}

	}

	endwin();

	cout << "Game Over!" << endl;
	cout << endl;
}
