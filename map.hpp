#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED


class Map {
public:
    int **mapArr;

    int col;
    int row;

    int leftTopX;
    int leftTopY;
    int rightBottomX;
    int rightBottomY;



    Map();
    void checkMap();
    void drawBlock();


};

#endif // MAP_HPP_INCLUDED
