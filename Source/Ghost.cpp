#include "CApp.h"

class Ghost{
private:
    bool pacman = false;
public:
    int x;
    int y;
    int radius = 2;
    direction d;
    bool food = false ;
    bool evilGhost = false;

    Ghost(direction d, int x = 10, int y = 10) : d(d), x(x), y(y) {}

    void go(){
        for (int i=x-radius; !pacman && i<=x+radius; i++)
            for (int j=y+radius; !pacman && j>=y-radius; j--)
                if (pacman.x == x && pacman.y == y){
                    pacman = true;
                    shortWay(x, y, pacman.x, pacman.y);
                }
        if (!pacman){
            switch (direction){
                case right:
                    if (x+1 == 0) x++;
                    else direction = rand()%3;
                    break;
                case left:
                    if (x-1 == 0) x--;
                    else direction = rand()%3;
                    break;
                case up:
                    if (y+1 == 0) y++;
                    else direction = rand()%3;
                    break;
                case down:
                    if (y-1 == 0) y--;
                    else direction = rand()%3;
            }
        }
    }

};
