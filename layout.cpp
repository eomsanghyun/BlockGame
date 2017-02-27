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
    /*
         gotoxy(marginLeft, marginTop);
         printf("бс");

         gotoxy(marginLeft+2, marginTop+1);
         printf("бс");

         gotoxy(marginLeft+WIDTH-2, marginTop+HEIGTH-1);
         printf("бс");
         */
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

void Map::checkMap() {
/*
    for(int r= this->leftTopY; r<= this->rightBottomY; r++) {
        for(int c=this->leftTopX; c<= this->rightBottomX; c++) {
            gotoxy(c,r);
            printf("t");
        }
    }
*/
     //initialize
    for(int r=0; r<this->row; r++) {
        for(int c=0; c<this->col; c++) {
            if(mapArr[r][c] == 0) {
                gotoxy(c+this->leftTopX,r+leftTopY);
                printf("a");
            }
        }
    }
}

void Map::drawBlock() {
      //initialize
    for(int r=0; r < this->row; r++) {
        for(int c=0; c < this->col; c++) {
            if(mapArr[r][c] == 1) {
                gotoxy( c + this->leftTopX, r + leftTopY);
                printf("бс");
            }
        }
    }
}
