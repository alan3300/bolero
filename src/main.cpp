#include <iostream>
#include <random>
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

Paleta jugador1 = Paleta();
Paleta jugador2 = Paleta();
Pelota pelota = Pelota();

void setup();
void input();
void update();
void draw();

enum teclado
{
	PALETA1_ARRIBA = KEY_UP,
	PALETA1_ABAJO = KEY_DOWN,
	PALETA2_ARRIBA = 119, // w
	PALETA2_ABAJO = 115, // s
	PAUSA,
	SALIR = 27, // esc
	NIVEL_1,
	NIVEL_2,
	NIVEL_3
};

const int PARCOLOR_FONDO = 1;


//----------------------------------------------------------------------------------


int random_bool()
{

	int s{};
	srand(time(0));
	s = rand() % 2;
	return s;
}




void setup()
{
	initscr();
	noecho();
	curs_set(false);
	keypad(stdscr, true);
	nodelay(stdscr, true);

	start_color();

	game_over = false;
	juego_activo = true;
	puntaje = 0;

	jugador1.x = 10;
	jugador1.y = 4;

	jugador2.x = 10;
	jugador2.y = ANCHO - 4;

	pelota.x = 20;
	pelota.y = 60;
	pelota.sentido = random_bool();


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
		case PALETA1_ARRIBA:
			jugador1.x++;
			break;
		case PALETA1_ABAJO:
			jugador1.x--;
			break;
		case PALETA2_ARRIBA:
			jugador2.x++;
			break;
		case PALETA2_ABAJO:
			jugador2.x--;
			break;
		case 27:
			salir = TRUE;
			break;
		default:
			break;
	}
}


bool colision_borde()
{
  if (pelota.x == ALTO || pelota.x == 0)
  	return TRUE;

  if (pelota.y == ANCHO || pelota.y == 0)
  	return TRUE;

  return FALSE;
}


bool colision_paleta()
{


}


bool anotacion()
{



}


//----------------------------------------------------------
void update(){

	jugador1.update();
	jugador2.update();
	pelota.update();

	if (colision_borde())
	{



	}


	if (colision_paleta())
	{

	}

	if (anotacion())
	{



	}

}

//----------------------------------------------------------


void marco()
{
    	attron(COLOR_PAIR(PAR_FONDO));
		box(stdscr, 0, 0);
		mvprintw(0, 5, "[PUNTOS: %d  ]", puntaje);
		mvprintw(0, ANCHO - 18, "[PUNTOS: %d  ]", puntaje);
		attroff(COLOR_PAIR(PAR_FONDO));
		refresh();
}


void draw()
{
	marco();
	jugador1.draw();
	jugador2.draw();
	pelota.draw();
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

	// int r = random_bool();
	// endwin();
	// printf("random bool: %d\n\n", r);
	// exit(1);

	setup();

	while(!salir) 
	{

		while(!juego_activo)
		{
			menu();
		}

		jugador1.setup();
		jugador2.setup();
		pelota.setup();
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
