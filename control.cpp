#include "control.hpp"
#include "myHeader.hpp"

bool isBottom(Map *gameMap, Block *block) {
    bool result = false;
    //check block bottom

    for(int r=0; r<block->row; r++) {
        for(int c=0; c < block->col*2 ; c+=2) {
            if(block->arr[r][c/2] == 1) {
                int checkY =(r+1) + block->startY;
                int checkX = c + block->startX;

                    if(checkY == gameMap->rightBottomY+1)  {
                        result = true;
                        break;
                    }

                    else if(gameMap->mapArr[checkY - gameMap->leftTopY][checkX  - gameMap->leftTopX] == 1){
                        result = true;
                        break;
                    }
            }
        }
    }

    return result;
}

void addBlock(Map *gameMap, Block *block) {
    for(int r=0; r < block->row; r++) {
        for(int c=0; c < block->col; c++) {
             if(block->arr[r][c] == 1){
                int addY = r + block->startY;
                int addX = c*2 + block->startX;

                gameMap->mapArr[addY - gameMap->leftTopY][addX  - gameMap->leftTopX] = 1;
            }
        }
    }
}

bool isLeftOk(Map *gameMap, Block *block) {
    bool result = true;

    for(int r=0; r < block->row; r++) {
        for(int c=0; c < block->col*2 ; c+=2) {
            if(block->arr[r][c/2] == 1) {
                int checkY =r + block->startY;
                int checkX = (c-2) + block->startX;

                if(gameMap->mapArr[checkY - gameMap->leftTopY][checkX  - gameMap->leftTopX] == 1){
                    result = false;
                    break;
                }
            }
        }
    }

    return result;
}

bool isRightOk(Map *gameMap, Block *block) {
    bool result = true;

    for(int r=0; r < block->row; r++) {
        for(int c=0; c < block->col*2 ; c+=2) {
            if(block->arr[r][c/2] == 1) {
                int checkY =r + block->startY;
                int checkX = (c+2) + block->startX;

                if(gameMap->mapArr[checkY - gameMap->leftTopY][checkX  - gameMap->leftTopX] == 1){
                        result = false;
                        break;
                }
            }
        }
    }

    return result;
}

bool isTurnOk (Map *gameMap, Block *block) {
    bool result = true;

    int endY = block->startY + block->row;

    if( endY > gameMap->rightBottomY) result = false;

    return result;
}

void checkTetris(Map *gameMap, Block *block) {
/*
    int checkStartY = block->startY - gameMap->leftTopY;
    int checkEndY= checkStartY + block->row - gameMap->leftTopY;

    for(int r= checkStartY; r=checkEndY; r++) {
        bool isTetris = true;
        for(int c=0; c < gameMap->col; c++) {
            if(c%2 == 0 ) {
                if(gameMap->mapArr[r][c] == 0) {
                    isTetris = false;
                }
            }
        }
    }

*/
}
