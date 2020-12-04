#include "CApp.h"

void delField(Field &gameField){
    for (int i=0; i<gameField.height; i++)
            delete[] gameField.field[i];
    delete gameField.field;
}

void delToPac(Ghost &ghost){
    for (int i=0; i<19; i++)
            delete[] ghost.toPac[i];
    delete ghost.toPac;
}

void CApp::OnCleanup(Field &gameField, Ghost &ghost1, Ghost &ghost2, Ghost &ghost3, Ghost &ghost4) {
        delField(gameField);
        delToPac(ghost1);
        delete ghost2.toPac;
        delete ghost3.toPac;
        delete ghost4.toPac;
        SDL_FreeSurface(Surf_Source);
        SDL_FreeSurface(Surf_Display);
        SDL_Quit();
}
