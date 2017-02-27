#include "myHeader.hpp"
#include "block.hpp"
#include "draw.hpp"
#include "layout.hpp"

extern int marginTop;
extern int marginLeft;

Block::Block(int num) {

    startX = 5;
    startY = 8;

    switch(num) {
        case J:
            row = 3;
            col = 2;
            setArr();

            arr[0][0] = 0;
            arr[1][0] = 0;
            break;

        case L:
            row = 3;
            col = 2;
            setArr();

            arr[0][1] = 0;
            arr[1][1] = 0;
            break;

        case S:
            row = 3;
            col = 2;
            setArr();

            arr[2][0] = 0;
            arr[0][1] = 0;
            break;

        case O:
            row = 2;
            col = 2;
            setArr();
            break;

        case Z:
            row = 3;
            col = 2;
            setArr();

            arr[0][0] = 0;
            arr[2][1] = 0;
            break;

        case T:
            row = 2;
            col = 3;
            setArr();

            arr[1][0] = 0;
            arr[1][2] = 0;
            break;

        case I:
            row = 4;
            col = 1;
            setArr();
            break;
    }
}


void Block::setArr() {
    arr = new int*[row];
    for(int i=0; i<row; i++) {
        arr[i] = new int[col];
    }

    for(int r=0; r<row; r++) {
        for(int c=0; c<col; c++) {
            arr[r][c] = 1;
        }
    }
}
Block::~Block() {
    for(int i=0; i<row; i++) {
        delete [] arr[i];
    }

    delete []arr;
}

void Block::draw() {

    for(int r=0; r<row; r++) {
        for(int c=0; c<col*2; c+=2) {
            if(arr[r][c/2] == 1) {
                gotoxy(startX+c,startY+r);
                printf("бс");
            }
        }
    }
}

void Block::dropDown() {
    this->startY+=1;
}

void Block::shiftLeft() {

    if( this->startX >= marginLeft+4)
        this->startX-=2;
}

void Block::shiftRight() {
    if( this->startX + ((this->col)-1)*2 <= marginLeft+WIDTH-4)
        this->startX+=2;
}

