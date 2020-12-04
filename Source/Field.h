#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include<fstream>
using namespace std;
#include "Structures.h"



class Field{
public:
    int height;
    int width;
    cell **field;

    void fillField () {
        int x, y;
        ifstream fin("text\\field.txt");
        this->field = new cell *[this->height];
        for (int i=0; i<this->height; i++)
            this->field[i] = new cell[this->width];
        for (int i=0; i<19; i++) {
            this->field[0][i].status = wall;
            this->field[i][0].status = wall;
            this->field[i][18].status = wall;
            this->field[18][i].status = wall;
        }

        while (!fin.eof()){
            fin >> x >> y;
            this->field[y][x].status = wall;
        }
        this->field[10][9].status = ghostGate;
        this->field[8][9].status = ghostGate;
        this->field[9][9].status = ghostGate;
        this->field[9][10].status = ghostGate;
        this->field[10][10].status = ghostGate;
        this->field[8][10].status = ghostGate;

    }

    Field(int height = 19, int width = 19, cell **field = NULL ) : height(height), width(width), field(field)
    { }

};



#endif // FIELD_H_INCLUDED
