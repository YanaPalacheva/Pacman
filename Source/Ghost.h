#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED

#include "Structures.h"
#include <fstream>
#include <queue>
using namespace std;
#include "Pacman.h"
#include "Field.h"

class Ghost{
private:
    struct coord {
        int sx;
        int sy;
    };
    struct pq{
        int w;
        coord c;
        direction d;
    };
    int sz = 19;




public:
    int x;
    int y;
    int radius = 2;
    int diameter = 2*radius +1;
    direction d;
    bool food = false ;
    bool dead = false;
    bool evilGhost = false;
    int **toPac;
    Ghost(direction d, int x, int y) : d(d), x(x), y(y) {}

    void turnEvil() {
        evilGhost = true;
        radius = 9;
        dead = false;
    }

    void turnNormal(){
        evilGhost = false;
        radius = 2;
        dead = false;
    }

    void clear( deque<pq> &q )
        {
           deque<pq> empty;
           swap( q, empty );
        }

    void virgining (bool vis[19][19]) {
        for (int i=0; i<19; i++)
            for (int j=0; j<19; j++)
                vis[i][j] = false;
    }

    void shortWay(Field gameField){
        deque<pq> q;
        pq elem;
        int a, b, counter;
        bool firstStep;
        bool foundPac;
        direction d;
        bool vis[19][19] = {{false}};
        ofstream fout("text\\toPac.txt", ios::app);


        for (int i=0; i<gameField.height; i++)
        for (int j=0; j<gameField.height; j++)
            if (gameField.field[i][j].status != wall) {
                for (int k=0; k<gameField.height; k++) {
                for (int l=0; l<gameField.height; l++){
                        virgining(vis);
                if (gameField.field[k][l].status != wall && !(i==k && j==l)) {
                    elem.w = 0;
                    elem.c.sx = j;
                    elem.c.sy = i;
                    firstStep = true;
                    foundPac = false;
                    q.push_back(elem);
                    while (!foundPac) {
                        a = q.front().c.sy;
                        b = q.front().c.sx;
                        if (vis[a][b] == false) {
                            vis[a][b] = true;
                             if (a > 0 && gameField.field[a-1][b].status != wall) {
                                if (firstStep)
                                    elem.d = goleft;
                                else elem.d = q.front().d;
                                elem.w = q.front().w+1;
                                elem.c.sx = b;
                                elem.c.sy = a-1;
                                q.push_back(elem);
                            }
                            if (q.back().c.sy == k && q.back().c.sx == l) {
                                    foundPac = true;
                                    d = q.back().d;
                            }
                            if (!foundPac && b > 0 && gameField.field[a][b-1].status != wall) {
                                if (firstStep)
                                    elem.d = goup;
                                else elem.d = q.front().d;
                                elem.w = q.front().w+1;
                                elem.c.sx = b-1;
                                elem.c.sy = a;
                                q.push_back(elem);
                            }
                            if (q.back().c.sy == k && q.back().c.sx == l) {
                                    foundPac = true;
                                    d = q.back().d;
                            }
                            if (!foundPac && a < gameField.height-1 && gameField.field[a+1][b].status != wall) {
                                if (firstStep)
                                    elem.d = goright;
                                else elem.d = q.front().d;
                                elem.w = q.front().w+1;
                                elem.c.sx = b;
                                elem.c.sy = a+1;
                                q.push_back(elem);
                            }
                            if (q.back().c.sy == k && q.back().c.sx == l) {
                                    foundPac = true;
                                    d = q.back().d;
                            }
                            if (!foundPac && b < gameField.width-1 && gameField.field[a][b+1].status != wall) {
                                if (firstStep)
                                    elem.d = godown;
                                else elem.d = q.front().d;
                                elem.w = q.front().w+1;
                                elem.c.sx = b+1;
                                elem.c.sy = a;
                                q.push_back(elem);
                            }
                            if (q.back().c.sy == k && q.back().c.sx == l) {
                                    foundPac = true;
                                    d = q.back().d;
                            }
                            firstStep = false;
                        }
                        q.pop_front();
                    }
                    while (!q.empty()){
                        q.pop_front();
                    }
                    clear(q);
                    fout<<j<<' '<<i<<' '<<' '<<k<<' '<<l<<' '<<d<<endl;
                }
            }
            }
            }
    }

    void go(Field gameField, Pacman pac){
            if (!dead && pac.x <= x+radius && pac.x >= x-radius && pac.y <= y+radius && pac.y >= y-radius){
                d = (direction)toPac[x*sz+y][pac.y*sz+pac.x];
                if (food && !evilGhost)
                    switch (d){
                        case goright: d = goleft;
                            break;
                        case goleft: d = goright;
                            break;
                        case goup: d = godown;
                            break;
                        case godown: d = goup;
                            break;
                    }
            }
            switch (d){
                case goright:
                    if (gameField.field[y+1][x].status != wall && gameField.field[y+1][x].ghost == 0) y++;
                    else {
                        int i = rand()%4;
                        d = (direction)i;
                    }
                    break;
                case goleft:
                    if (gameField.field[y-1][x].status != wall && gameField.field[y-1][x].ghost == 0) y--;
                    else {
                        int i = rand()%4;
                        d = (direction)i;
                    }
                    break;
                case goup:
                    if (gameField.field[y][x-1].status != wall && gameField.field[y][x-1].ghost == 0) x--;
                    else {
                        int i = rand()%4;
                        d = (direction)i;
                    }
                    break;
                case godown:
                     if (gameField.field[y][x+1].status != wall && gameField.field[y][x+1].ghost == 0) x++;
                    else {
                        int i = rand()%4;
                        d = (direction)i;
                    }
            }
    }

    void die(){
        dead = true;
    }



};


#endif // GHOST_H_INCLUDED
