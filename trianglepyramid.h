#ifndef TRIANGLEPYRAMID_H
#define TRIANGLEPYRAMID_H

#include "figure.h"
class trianglePyramid:public figure
{
public:
    trianglePyramid();
    void fCoord() override;
    void moreToOne(int i, float newX, float newY, float newZ) override;
};

#endif // TRIANGLEPYRAMID_H
