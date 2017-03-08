#include "layout.hpp"
#include "draw.hpp"

int xPoint,yPoint=0;
int marginTop = 5;
int marginLeft = 3;

void drawLayout() {
    for (yPoint=marginTop; yPoint<marginTop+HEIGTH; yPoint++) {
        //draw left
        gotoxy(marginLeft,yPoint);
        printf("бр");

        //draw right
        gotoxy(marginLeft+WIDTH,yPoint);
        printf("бр");
    }

     for(xPoint=marginLeft; xPoint<=marginLeft+WIDTH; xPoint+=2) {
        //draw top
        gotoxy(xPoint,marginTop);
        printf("бр");

       //draw bottom
        gotoxy(xPoint,marginTop+HEIGTH);
        printf("бр");
    }

    //block window
    for(int x=56; x<67; x+=2) {
        gotoxy(x,18);
        printf("б┌");
        gotoxy(x,24);
        printf("б┌");
    }

    for(int y=18; y<24; y++) {
        gotoxy(56,y);
        printf("б┌");
        gotoxy(67,y);
        printf("б┌");
    }
}

Map::Map() {
    //set position
    this->leftTopX = marginLeft+2;
    this->leftTopY = marginTop+1;

    this->rightBottomX = marginLeft+WIDTH-1;
    this->rightBottomY = marginTop+HEIGTH-1;

    this->col = rightBottomX-leftTopX+1;
    this->row = rightBottomY-leftTopY+1;

    //dynamic alloc
    mapArr = new int*[row];
    for(int r=0; r<row; r++) {
        mapArr[r] = new int[col];
    }

    //initialize
    for(int r=0; r<row; r++) {
        for(int c=0; c<col; c++) {
            mapArr[r][c] = 0;
        }
    }
}

void Map::drawBlock() {
    for(int r=0; r < this->row; r++) {
        for(int c=0; c < this->col; c++) {
            if(mapArr[r][c] == 1) {
                gotoxy( c + this->leftTopX, r + leftTopY);
                printf("бс");
            }
        }
    }
}
