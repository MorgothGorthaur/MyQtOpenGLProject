#ifndef SQUAREPYRAMID_H
#define SQUAREPYRAMID_H
#include "figure.h"

class squarePyramid:public figure
{
public:
    squarePyramid();
    void fCoord() override;
    void moreToOne(int i, float newX, float newY, float newZ) override;
};

#endif // SQUAREPYRAMID_H
