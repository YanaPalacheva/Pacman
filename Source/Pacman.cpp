#include "CApp.h"

class Pacman {
private:
    int score;
    int life;

public:
    int x;
    int y;

    Pacman(int x = 0, int y = 0, int score = 0, int life = 3) : x(x), y(y){}

    void go(direction key){
        switch (key){
            case right:
                if (x+1 == 0) x++;
                break;
            case left:
                if (x-1 == 0) x--;
                break;
            case up:
                if (y+1 == 0) y++;
                break;
            case down:
                if (y-1 == 0) y--;
        }
    }
    void eat(foodType type){ //ask cell what do you have for me
        switch (type){
            case food: score+=10;
                break;
            case bigFood: score+=25; //мэйн: если пакман на еде, то спрашиваем у еды, какая она. посылаем тип еды в eat и сжираем еду
                         ghost1.food = true;
                         ghost2.food = true;
                         ghost3.food = true;
                         ghost4.food = true;
                break;
            case heart: if (life < 3) life++;
                break;
            case ghost: score+=100;
        }
    }

    void die(){ //наступил на привидешку мэйн проверка на жизни
        life--;
    }
};
