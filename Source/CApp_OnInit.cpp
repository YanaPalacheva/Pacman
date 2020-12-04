#include "CApp.h"
#include "Field.h"
#include "Ghost.h"
#include "Pacman.h"
#include<fstream>
using namespace std;


bool CApp::OnInit(Field &gameField, Pacman &pac, bool ghostFood) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(380, 420, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }


    gameField.fillField();

    gameField.field[1][17].status = pacman;

    gameField.field[9][9].ghost = ghst;
    gameField.field[9][10].ghost = ghst;
    gameField.field[10][10].ghost = ghst;
    gameField.field[8][10].ghost = ghst;

    OnRender(gameField, pac, ghostFood);

    return true;
}
