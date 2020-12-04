#include "CApp.h"
#include "Pacman.h"
#include "Field.h"
#include "Ghost.h"


bool bigF = false;
bool hrt = false;
bool evil = false;
int loopCountH = 0;
int loopCountGF = 0;
int loopCountGE[4] = {0};
int loopCountEvil = 0;

bool ghostOnPac (Ghost ghost, Pacman pac) {
    return (ghost.y==pac.y && ghost.x==pac.x);
}

bool eyeCount(Ghost ghost, unsigned num){
    if (loopCountGE[num] != 35){
        loopCountGE[num]++;
        if (loopCountGE[num] == 35){
            ghost.dead = false;
            loopCountGE[num] = 0;
            return true;
        }
    }
    return false;
}

void everyoneDies (Field &gameField, Pacman &pac, Ghost &ghost, bool &ghostFood, int gNum){
    if (ghostOnPac(ghost, pac)) {
        gameField.field[pac.y][pac.x].status = emptyCell;
        if ((ghost.evilGhost) || (!ghostFood && gameField.field[ghost.y][ghost.x].ghost != gDead)){
            pac.die();
        }
        else if (!ghost.evilGhost && ghostFood && gameField.field[ghost.y][ghost.x].ghost != gDead){
            pac.eatGhost();
            gameField.field[ghost.y][ghost.x].ghost = gDead;
            ghost.die();
        }
    }
}

void CApp::OnLoop(Field &gameField, Pacman &pac, direction direct, Ghost &ghost1, Ghost &ghost2, Ghost &ghost3, Ghost &ghost4, bool &ghostFood) {
    cellStatus cell;
    if (!bigF){
        int xF;
        int yF;
        do{
        xF = rand()%19;
        yF = rand()%19;
        } while (gameField.field[yF][xF].status == wall || gameField.field[yF][xF].status == heart || gameField.field[yF][xF].status == ghostGate);
        gameField.field[yF][xF].status = bigFood;
        bigF=true;
    }

    if (!hrt && loopCountH != 20){
        loopCountH++;
        if (loopCountH == 20){
            int xH;
            int yH;
            do{
            xH = rand()%19;
            yH = rand()%19;
            } while (gameField.field[yH][xH].status == wall || gameField.field[yH][xH].status == bigFood || gameField.field[yH][xH].status == ghostGate);
            gameField.field[yH][xH].status = heart;
            hrt = true;
            loopCountH = 0;
        }
    }

      if (ghostFood && loopCountGF != 35){
        loopCountGF++;
        if (loopCountGF == 35){
            ghostFood = false;
            ghost1.food = false;
            ghost2.food = false;
            ghost3.food = false;
            ghost4.food = false;
            loopCountGF = 0;
        }
    }

    if (evil && loopCountEvil != 55) {
        loopCountEvil++;
        if (loopCountEvil == 55) {
            ghost1.turnNormal();
            pac.setKilled(3);
            loopCountEvil = 0;
            evil = false;
            gameField.field[ghost1.y][ghost1.x].ghost = ghst;
        }
    }

    if (ghost1.dead && eyeCount(ghost1, 0)) {
        gameField.field[ghost1.y][ghost1.x].ghost = ghst;
    }
    if (ghost2.dead && eyeCount(ghost2, 1)){
        gameField.field[ghost2.y][ghost2.x].ghost = ghst;
    }
    if (ghost3.dead && eyeCount(ghost3, 2)){
        gameField.field[ghost3.y][ghost3.x].ghost = ghst;
    }
    if (ghost4.dead && eyeCount(ghost4, 3)){
        gameField.field[ghost4.y][ghost4.x].ghost = ghst;
    }

    ghostStatus st;

    st = gameField.field[ghost1.y][ghost1.x].ghost;
    gameField.field[ghost1.y][ghost1.x].ghost = noGhost;
    ghost1.go(gameField, pac);
    gameField.field[ghost1.y][ghost1.x].ghost = st;

    st = gameField.field[ghost2.y][ghost2.x].ghost;
    gameField.field[ghost2.y][ghost2.x].ghost = noGhost;
    ghost2.go(gameField, pac);
    gameField.field[ghost2.y][ghost2.x].ghost = st;

    st = gameField.field[ghost3.y][ghost3.x].ghost;
    gameField.field[ghost3.y][ghost3.x].ghost = noGhost;
    ghost3.go(gameField, pac);
    gameField.field[ghost3.y][ghost3.x].ghost = st;

    st = gameField.field[ghost4.y][ghost4.x].ghost;
    gameField.field[ghost4.y][ghost4.x].ghost = noGhost;
    ghost4.go(gameField, pac);
    gameField.field[ghost4.y][ghost4.x].ghost = st;

    everyoneDies (gameField, pac, ghost1, ghostFood, 0);
    everyoneDies (gameField, pac, ghost2, ghostFood, 1);
    everyoneDies (gameField, pac, ghost3, ghostFood, 2);
    everyoneDies (gameField, pac, ghost4, ghostFood, 3);
    if (pac.getKilled() == 0) {
        ghost1.turnEvil();
        evil = true;
        gameField.field[ghost1.y][ghost1.x].ghost = gEvil;
    }

    gameField.field[pac.y][pac.x].status = emptyCell;
    pac.go(direct, gameField);
    if (pac.eat(gameField.field[pac.y][pac.x].status) == 1) {
        bigF=false;
        ghostFood = true;
        loopCountGF = 0;
        ghost1.food = true;
        ghost2.food = true;
        ghost3.food = true;
        ghost4.food = true;
        } else if (pac.eat(gameField.field[pac.y][pac.x].status) == 2) {
            hrt = false;
        }

    everyoneDies (gameField, pac, ghost1, ghostFood, 0);
    everyoneDies (gameField, pac, ghost2, ghostFood, 1);
    everyoneDies (gameField, pac, ghost3, ghostFood, 2);
    everyoneDies (gameField, pac, ghost4, ghostFood, 3);
    if (pac.getKilled() == 0) {
        ghost1.turnEvil();
        evil = true;
        gameField.field[ghost1.y][ghost1.x].ghost = gEvil;
    }

    gameField.field[pac.y][pac.x].status = pacman;
}
