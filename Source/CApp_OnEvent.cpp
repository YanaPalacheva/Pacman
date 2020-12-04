#include "CApp.h"
#include "Field.h"
#include "Pacman.h"

direction CApp::OnEvent(Field gameField, Pacman pac, SDL_Event* Event, direction direct) {
    if(Event->type == SDL_QUIT) {
        Running = false;
    }
    switch( Event->key.keysym.sym ) {
                case SDLK_UP: if (gameField.field[pac.y][pac.x-1].status != wall && gameField.field[pac.y][pac.x-1].status != ghostGate) return goup; break;
                case SDLK_DOWN: if (gameField.field[pac.y][pac.x+1].status != wall && gameField.field[pac.y][pac.x+1].status != ghostGate) return godown; break;
                case SDLK_LEFT: if (gameField.field[pac.y-1][pac.x].status != wall && gameField.field[pac.y-1][pac.x].status != ghostGate) return goleft; break;
                case SDLK_RIGHT: if (gameField.field[pac.y+1][pac.x].status != wall && gameField.field[pac.y+1][pac.x].status != ghostGate) return goright; break;
            }
    return direct;
}
