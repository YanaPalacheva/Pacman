#include "CApp.h"
#include "Field.h"
#include "Pacman.h"
#include "Ghost.h"
#include <ctime>
using namespace std;

 int** readToPac (){
        int **toPac;
        int sz = 19;
        toPac = new int *[sz*sz];
        for (int i=0; i< sz*sz; i++){
            toPac[i] = new int[sz*sz];
            for (int j=0; j< sz*sz; j++)
                toPac[i][j] = -1;
        }
        ifstream fin("text\\toPac.txt");
        int px, py, gx, gy, r;
        while (!fin.eof()) {
            fin>>gy>>gx;
            fin>>py>>px;
            fin>>r;
            toPac[gy*sz+gx][py*sz+px] = r;
        }
        return toPac;
}

CApp::CApp() {
    Surf_Source = NULL;
    Surf_Display = NULL;

    Running = true;
}

int CApp::OnExecute() {
    Field gameField = Field();
    Pacman pac = Pacman();
    bool ghostFood = false;
    if(OnInit(gameField, pac, ghostFood) == false) {
        return -1;
    }
    SDL_Event Event;
    Ghost ghost1 = Ghost(goup, 9, 9);
     //ghost1.shortWay(gameField);

    gameField.field[ghost1.y][ghost1.x].ghost = ghst;
    Ghost ghost2 = Ghost(goleft, 10, 10);
    gameField.field[ghost2.y][ghost2.x].ghost = ghst;
    Ghost ghost3 = Ghost(goup, 10, 9);
    gameField.field[ghost3.y][ghost3.x].ghost = ghst;
    Ghost ghost4 = Ghost(goright, 10, 8);
    gameField.field[ghost4.y][ghost4.x].ghost = ghst;

    ghost1.toPac = readToPac();
    ghost2.toPac = readToPac();
    ghost3.toPac = readToPac();
    ghost4.toPac = readToPac();

    direction key = goup;
    srand ( time(NULL) );
    while(Running) {
       if(SDL_PollEvent(&Event)) {
        key = OnEvent(gameField, pac, &Event, key);
       }
        OnLoop(gameField, pac, key, ghost1, ghost2, ghost3, ghost4, ghostFood);
        OnRender(gameField, pac, ghostFood);
        SDL_Delay(200);
    }

    OnCleanup(gameField, ghost1, ghost2, ghost3, ghost4);

    return 0;
}

int main(int argc, char* argv[]) {
    CApp theApp;
    return theApp.OnExecute();
}

