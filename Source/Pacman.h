#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

#include "Structures.h"
#include "Field.h"

class Pacman {
private:
    int score;
    int life;
    int killed;

public:
    int x;
    int y;

    Pacman(int y = 1, int x = 17,  int score = 0, int life = 3, int killed = 3) : y(y), x(x), score(0), life(3), killed(3) {}

    int getLife(){
        return life;
    }

    int getScore(){
        return score;
    }

    int getKilled(){
        return killed;
    }
    void setKilled(int k){
        killed = k;
    }

    void go(direction key, Field gameField){
        switch (key){
            case goright:
                if (gameField.field[y+1][x].status != wall && gameField.field[y+1][x].status != ghostGate) y++;
                break;
            case goleft:
                if (gameField.field[y-1][x].status != wall && gameField.field[y-1][x].status != ghostGate) y--;
                break;
            case goup:
                if (gameField.field[y][x-1].status != wall && gameField.field[y][x-1].status != ghostGate) x--;
                break;
            case godown:
                if (gameField.field[y][x+1].status != wall && gameField.field[y][x+1].status != ghostGate) x++;
        }
    }
    int eat(cellStatus type){
        switch (type){
            case food: score+=10;
                break;
            case bigFood: score+=25;
                return 1;
            case heart: if (life < 3) life++;
                return 2;
        }
        return 0;
    }

    void eatGhost(){
        score+=100;
        if (killed>0)
            killed--;
    }

    void die(){
        y = 1;
        x = 17;
        if (life>0)
            life--;
    }
};



#endif // PACMAN_H_INCLUDED
