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



