#ifndef CUBE_H
#define CUBE_H

#include "figure.h"
class cube: public figure
{
public:
    cube();
    //void cubeCoords();
    void fCoord() override;

};

#endif // CUBE_H
