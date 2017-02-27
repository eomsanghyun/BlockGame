#ifndef CONTROL_HPP_INCLUDED
#define CONTROL_HPP_INCLUDED


#include <conio.h>
#include <iostream>

#include "block.hpp"
#include "layout.hpp"


using namespace std;
bool isBottom(Map *gameMap, Block *block);
void addBlock(Map *gameMap, Block *block);

#endif // CONTROL_HPP_INCLUDED
