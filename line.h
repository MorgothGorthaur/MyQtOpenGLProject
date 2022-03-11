#ifndef LINE_H
#define LINE_H
#include "figure.h"

class line:public figure
{
public:
    line();
    void fCoord() override;
    void moreToOne(int i, float newX, float newY, float newZ) override;
};

#endif // LINE_H
