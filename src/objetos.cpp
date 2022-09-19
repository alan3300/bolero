#include "objetos.h"


Paleta::Paleta()
{

}


void Paleta::setup()
{
  largo = 4;
}

void Paleta::update()
{


}

void Paleta::draw()
{
  for (int i = 0 ; i < largo; ++i)
    {
      mvaddch(x + i, y, '|');
    }  
}


///////////////////////////////////////////////////////////////////////////

Pelota::Pelota()
{

}



void Pelota::setup()
{

}

void Pelota::update()
{

}

void Pelota::draw()
{
  mvaddch(x, y, 'o');
}
