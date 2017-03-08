#include "control.hpp"
#include "myHeader.hpp"

bool isBottom(Map *gameMap, Block *block) {

    for(int r=0; r < block->row; r++) {
        for(int c=0; c < block->col*2 ; c+=2) { //because бс hold 2pixels
            if(block->arr[r][c/2] == 1) {
                int checkY =(r+1) + block->startY; //predict next block
                int checkX = c + block->startX;

                    if(checkY == gameMap->rightBottomY+1) { //check maximum Y of map
                        return true;
                    }

                    else if(gameMap->mapArr[checkY - gameMap->leftTopY][checkX - gameMap->leftTopX] == 1){
                        return true;
                    }
            }
        }
    }
    return false;
}


void addBlock(Map *gameMap, Block *block) {
    for(int r=0; r < block->row; r++) {
        for(int c=0; c < block->col; c++) {
             if(block->arr[r][c] == 1){
                int addY = r + block->startY;
                int addX = c*2 + block->startX;

                gameMap->mapArr[addY - gameMap->leftTopY][addX - gameMap->leftTopX] = 1;
            }
        }
    }
}

bool isLeftOk(Map *gameMap, Block *block) {

    for(int r=0; r < block->row; r++) {
        for(int c=0; c < block->col*2 ; c+=2) {
            if(block->arr[r][c/2] == 1) {
                int checkY =r + block->startY;
                int checkX = (c-2) + block->startX;

                if(gameMap->mapArr[checkY - gameMap->leftTopY][checkX  - gameMap->leftTopX] == 1){
                    return false;                }
            }
        }
    }

    return true;
}

bool isRightOk(Map *gameMap, Block *block) {

    for(int r=0; r < block->row; r++) {
        for(int c=0; c < block->col*2 ; c+=2) {
            if(block->arr[r][c/2] == 1) {
                int checkY =r + block->startY;
                int checkX = (c+2) + block->startX;

                if(gameMap->mapArr[checkY - gameMap->leftTopY][checkX  - gameMap->leftTopX] == 1){
                        return false;
                }
            }
        }
    }

    return true;
}

bool isTurnOk (Map *gameMap, Block *block) {

    int endY = block->startY + block->col;

    if( endY > gameMap->rightBottomY) return false;

    int checkY = endY;
    int checkX=0;

    for(int r=0; r < block->row; r++) {
        checkX = block->startX + r*2;

        if(gameMap->mapArr[checkY - gameMap->leftTopY][checkX  - gameMap->leftTopX] == 1) {
            return false;
        }
    }
    return true;
}


