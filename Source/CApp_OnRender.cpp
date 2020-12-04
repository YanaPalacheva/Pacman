#include "CApp.h"
#include "Field.h"

bool pacNyam = true;

bool CApp::showField (Field gameField, bool ghostFood) {
    for (int i=0; i<gameField.height; i++) {
        for (int j=0; j<gameField.width; j++) {
            if (gameField.field[i][j].status == pacman){
                if (pacNyam) {
                    Surf_Source = CSurface::OnLoad("image\\pacman.bmp");
                    pacNyam = false;
                } else {
                    Surf_Source = CSurface::OnLoad("image\\pacman1.bmp");
                    pacNyam = true;
                }
            } else if (gameField.field[i][j].ghost == gEvil){
                   Surf_Source = CSurface::OnLoad("image\\evilGhost.bmp");
            } else if (gameField.field[i][j].ghost == ghst){
                if (ghostFood)
                   Surf_Source = CSurface::OnLoad("image\\foodGhost.bmp");
                else
                    Surf_Source = CSurface::OnLoad("image\\ghost.bmp");
            }
            else if (gameField.field[i][j].ghost == gDead)
                Surf_Source = CSurface::OnLoad("image\\ghostEyes.bmp");
            else {
                switch(gameField.field[i][j].status) {
                    case emptyCell:
                        if((Surf_Source = CSurface::OnLoad("image\\emptyCell.bmp")) == NULL) {
                            return false;
                        }
                        break;
                    case wall:

                        if((Surf_Source = CSurface::OnLoad("image\\wall.bmp")) == NULL) {
                            return false;
                        }
                        break;
                    case ghostGate:

                        if((Surf_Source = CSurface::OnLoad("image\\ghostGate.bmp")) == NULL) {
                            return false;
                        }
                        break;
                    case food:
                        if((Surf_Source = CSurface::OnLoad("image\\food.bmp")) == NULL) {
                            return false;
                        }
                        break;
                    case bigFood:
                        if((Surf_Source = CSurface::OnLoad("image\\bigFood.bmp")) == NULL) {
                            return false;
                        }
                        break;
                    case heart:
                        if((Surf_Source = CSurface::OnLoad("image\\heart.bmp")) == NULL) {
                            return false;
                        }
                        break;
                }
            }
                CSurface::OnDraw(Surf_Display, Surf_Source, i*20, j*20);
        }
    }
    return true;
}

void CApp::showBar(Pacman pac){
    Surf_Source = CSurface::OnLoad("image\\heartBar.bmp");
    CSurface::OnDraw(Surf_Display, Surf_Source, 20, 390);
    switch (pac.getLife()) {
        case 0: Surf_Source = CSurface::OnLoad("image\\0Bar.bmp");
            break;
        case 1: Surf_Source = CSurface::OnLoad("image\\1Bar.bmp");
            break;
        case 2: Surf_Source = CSurface::OnLoad("image\\2Bar.bmp");
            break;
        case 3: Surf_Source = CSurface::OnLoad("image\\3Bar.bmp");
            break;
    }
    CSurface::OnDraw(Surf_Display, Surf_Source, 50, 390);

    Surf_Source = CSurface::OnLoad("image\\scoreBar.bmp");
    CSurface::OnDraw(Surf_Display, Surf_Source, 100, 390);
    int score = pac.getScore();
    int counter = 0;
    do {
        switch (score%10) {
            case 0: Surf_Source = CSurface::OnLoad("image\\0Bar.bmp");
                break;
            case 1: Surf_Source = CSurface::OnLoad("image\\1Bar.bmp");
                break;
            case 2: Surf_Source = CSurface::OnLoad("image\\2Bar.bmp");
                break;
            case 3: Surf_Source = CSurface::OnLoad("image\\3Bar.bmp");
                break;
            case 4: Surf_Source = CSurface::OnLoad("image\\4Bar.bmp");
                break;
            case 5: Surf_Source = CSurface::OnLoad("image\\5Bar.bmp");
                break;
            case 6: Surf_Source = CSurface::OnLoad("image\\6Bar.bmp");
                break;
            case 7: Surf_Source = CSurface::OnLoad("image\\7Bar.bmp");
                break;
            case 8: Surf_Source = CSurface::OnLoad("image\\8Bar.bmp");
                break;
            case 9: Surf_Source = CSurface::OnLoad("image\\9Bar.bmp");
                break;
        }
        score/=10;
        CSurface::OnDraw(Surf_Display, Surf_Source, 220 - counter*15, 390);
        counter ++;
    } while (score != 0);

    Surf_Source = CSurface::OnLoad("image\\deadGhost.bmp");
    CSurface::OnDraw(Surf_Display, Surf_Source, 300, 390);
    switch (pac.getKilled()) {
        case 0: Surf_Source = CSurface::OnLoad("image\\0Bar.bmp");
            break;
        case 1: Surf_Source = CSurface::OnLoad("image\\1Bar.bmp");
            break;
        case 2: Surf_Source = CSurface::OnLoad("image\\2Bar.bmp");
            break;
        case 3: Surf_Source = CSurface::OnLoad("image\\3Bar.bmp");
            break;
        case 4: Surf_Source = CSurface::OnLoad("image\\4Bar.bmp");
            break;
        case 5: Surf_Source = CSurface::OnLoad("image\\5Bar.bmp");
            break;
    }
    CSurface::OnDraw(Surf_Display, Surf_Source, 330, 390);
}



void CApp::showGameOver(){
    Surf_Source = CSurface::OnLoad("image\\gameOver.bmp");
    CSurface::OnDraw(Surf_Display, Surf_Source, 0, 0);
}

bool CApp::checkFood(Field gameField) {
    for (int i=0; i<gameField.height; i++)
    for (int j=0; j<gameField.width; j++)
        if (gameField.field[i][j].status == food)
            return true;
    return false;
}

void CApp::showYouWin(){
    Surf_Source = CSurface::OnLoad("image\\youWin.bmp");
    CSurface::OnDraw(Surf_Display, Surf_Source, 0, 0);
}

void CApp::showBlack(){
    Surf_Source = CSurface::OnLoad("image\\black.bmp");
    CSurface::OnDraw(Surf_Display, Surf_Source, 0, 0);
}

int deathScreen = 0;
int turn = 0;

void CApp::OnRender(Field &gameField, Pacman &pac, bool ghostFood) {
    CApp::showBar(pac);
    bool gotAnyFood = CApp::checkFood(gameField);
    if (gotAnyFood) {
        if (pac.getLife() > 0) {
            if (pac.getKilled() == 0) {
                if (turn == 0)
                    deathScreen = 3;
                turn++;
            }
            if (deathScreen%2 == 1){
                CApp::showBlack();
            } else CApp::showField(gameField, ghostFood);
            if (deathScreen > 0)
                deathScreen--;
            if (turn > 55)
                turn = 0;
        } else CApp::showGameOver();
    } else CApp::showYouWin();
    SDL_Flip(Surf_Display);

}
