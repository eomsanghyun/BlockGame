#include "myHeader.hpp"
#include "layout.hpp"
#include "block.hpp"
#include "control.hpp"

unsigned int microseconds = 50000;

bool isOver = false;
bool regen = true;

Block *newBlock;
Map *gameMap;


int main()
{
    gameMap = new Map();
    srand(time(NULL));

    while(1) {
        system("CLS");

        drawLayout();

        gameMap->drawBlock();

        if(regen) {
            int randomNum = rand()%7;
            newBlock = new Block(randomNum);
            regen = false;
        }

        if(GetAsyncKeyState(VK_LEFT)) {
                if( isLeftOk(gameMap,newBlock) ) {
                    newBlock->shiftLeft();
                }
        }

        else if(GetAsyncKeyState(VK_RIGHT)) {
                if( isRightOk(gameMap,newBlock)) {
                    newBlock->shiftRight();
                }
        }

        else if(GetAsyncKeyState(VK_UP)) {
                if( isTurnOk(gameMap,newBlock)) {
                    newBlock->turnRight();
                }
        }

        newBlock->draw();

        if(isBottom(gameMap,newBlock)) {
            addBlock(gameMap,newBlock);
           // checkTetris(gameMap,newBlock);
            regen = true;

            delete newBlock;
        }
        else  newBlock->dropDown();

        usleep(microseconds);
    }
    return 0;
}
