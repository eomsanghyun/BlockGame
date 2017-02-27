#ifndef BLOCK_HPP_INCLUDED
#define BLOCK_HPP_INCLUDED

enum {J,L,S,O,Z,T,I};

class Block;

class Block {

public:
    int row;
    int col;
    int **arr;

    int startX = 10;
    int startY = 10;


    Block(int num);
    ~Block();

    void setArr();
    void draw();

    void dropDown();
    void shiftLeft();
    void shiftRight();
    void getYpoint();
    void turnRight();
};

#endif // BLOCK_HPP_INCLUDED
