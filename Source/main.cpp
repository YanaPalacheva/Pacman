#include <SDL/SDL.h>

void showField (Field gameField) {
    for (int i=0; i<gameField.height; i++) {
        for (int j=0; j<gameField.width; j++) {
            switch(gameField.field[i][j]) {
                case emptyCell:
                    if((Surf_Source = CSurface::OnLoad("emptyCell.bmp")) == NULL) {
                        return false;
                    }
                    break;
                case wall:
                    if((Surf_Source = CSurface::OnLoad("wall.bmp")) == NULL) {
                        return false;
                    }
                    break;
                case food:
                    if((Surf_Source = CSurface::OnLoad("food.bmp")) == NULL) {
                        return false;
                    }
                    break;
                case bigFood:
                    if((Surf_Source = CSurface::OnLoad("bigFood.bmp")) == NULL) {
                        return false;
                    }
                    break;
                case ghost:
                    if((Surf_Source = CSurface::OnLoad("ghost.bmp")) == NULL) {
                        return false;
                    }
                    break;
                case heart:
                    if((Surf_Source = CSurface::OnLoad("heart.bmp")) == NULL) {
                        return false;
                    }
                    break;
                case pacman:
                    if((Surf_Source = CSurface::OnLoad("pacman.bmp")) == NULL) {
                        return false;
                    }
                    break;
            }
            CSurface::OnDraw(Surf_Display, Surf_Source, i*20, j*20);
        }
    }
}


int main(){
    Field gameField;
    showField(gameField);
    return 0;
}
