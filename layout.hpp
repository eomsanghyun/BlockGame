#ifndef LAYOUT_HPP_INCLUDED
#define LAYOUT_HPP_INCLUDED

#define WIDTH 40
#define HEIGTH 28

//Game map
class Map {
public:
    int **mapArr;
    int col;
    int row;
    int leftTopX;
    int leftTopY;
    int rightBottomX;
    int rightBottomY;
////
    Map();
    void checkMap();
    void drawBlock();
};

void drawLayout();
#endif // LAYOUT_HPP_INCLUDED
