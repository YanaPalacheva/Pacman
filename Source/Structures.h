#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

enum direction{
            goleft,
            goright,
            goup,
            godown
        };

        enum cellStatus{
                emptyCell,
                wall,
                ghostGate,
                food,
                bigFood,
                heart,
                pacman
        };

        enum ghostStatus{
            noGhost,
            ghst,
            gDead,
            gEvil
        };
        struct cell{
                cellStatus status = food;
                ghostStatus ghost = noGhost;
        };

#endif // STRUCTURES_H_INCLUDED
