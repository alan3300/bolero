#pragma once
#include <iostream>
#include <ncurses.h>


class Paleta
{
  public:
    Paleta(int x, int y);
    void update();
    void draw();

  private:
    int p_x, p_y;
};


class Pelota
{

  public:
    Pelota(int x, int y);
    void update();
    void draw();

  private:
    int p_x, p_y;

};
