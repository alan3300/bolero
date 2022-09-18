#pragma once
#include <iostream>
#include <ncurses.h>

using namespace std;

class Dibujos
{
  public:
    void presentacion(int x, int y);
    void nivel1(int x, int y);
    void nivel2(int x, int y);
    void nivel3(int x, int y);
};