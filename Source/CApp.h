#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL/SDL.h>

#include "CSurface.h"
#include <fstream>
#include "Structures.h"
#include "Pacman.h"
#include "Field.h"
#include "Ghost.h"


class CApp {

    private:

        bool            Running;

    public:

        CApp();

        int OnExecute();

        SDL_Surface*    Surf_Display;

        SDL_Surface*    Surf_Source;

    public:


        bool OnInit(Field &gameField, Pacman &pac, bool ghostFood);

        direction OnEvent(Field gameField, Pacman pac, SDL_Event* Event, direction direct);

        void OnLoop(Field &gameField, Pacman &pac, direction direct, Ghost &ghost1, Ghost &ghost2, Ghost &ghost3, Ghost &ghost4, bool &ghostFood);

        void OnRender(Field &gameField, Pacman &pac, bool ghostFood);

        void OnCleanup(Field &gameField, Ghost &ghost1, Ghost &ghost2, Ghost &ghost3, Ghost &ghost4);

        bool showField (Field gameField, bool ghostFood);

        void showBar(Pacman pac);

        void showBlack();

        void showGameOver();

        bool checkFood(Field gameField);

        void showYouWin();

};

#endif
