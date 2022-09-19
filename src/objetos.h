#pragma once
#include <iostream>
#include <ncurses.h>


class Paleta
{
  public:
    Paleta();
    void setup();
    void update();
    void draw();

    int x, y, puntaje, largo;
    bool saque;
};


class Pelota
{

  public:
    Pelota();
    void setup();
    void update();
    void draw();
    int x, y;
    
    int inicio;
    bool sentido;
    
        

};
