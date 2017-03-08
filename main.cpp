#include "myHeader.hpp"
#include "layout.hpp"
#include "block.hpp"
#include "control.hpp"

void startGame();

unsigned int microseconds = 20000;
bool isOver = false;
bool regen = true;

Block *newBlock;
Map *gameMap;

int main()
{
   startGame();
}

//game start function
void startGame() {

    gameMap = new Map();
    srand(time(NULL));

    while(1) {
        // 1.clear window -> 2.draw layout -> 3.draw existing block
        system("CLS");
        drawLayout();
        gameMap->drawBlock();

        //get random block
        if(regen) {
            int randomNum = rand()%7;
            newBlock = new Block(randomNum);
            regen = false;
        }
        // keyboard input check
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

        //draw block
        newBlock->draw();

        //bottom check
        if(isBottom(gameMap,newBlock)) {
            addBlock(gameMap,newBlock);
            regen = true;

            delete newBlock;
        }
        else  newBlock->dropDown();

        usleep(microseconds);
    }
    return;
}
