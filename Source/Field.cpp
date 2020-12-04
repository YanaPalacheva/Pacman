#include<fstream>
#include "CApp.h"
using namespace std;

class Field{
public:
    int height = 19;
    int width = 19;
    CApp::cell field[height][width];


    void createField(){ //привидений сажаем при их создании (9 9, 10 8, 10 9, 10 10)
        int x, y;
        ifstream fin("field.txt");
        while (!fin.eof()){
            fin >> x >> y;
            field[x][y].status = wall;
        }
        field[18][0] = pacman;
    }

    direction shortWay(int x, int y, int xd, int yd){
        direction direction;




        return direction;
    }
};
