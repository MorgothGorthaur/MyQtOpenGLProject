#ifndef TEST_H
#define TEST_H
#include "figure.h"

class test:public figure
{
public:
    test();
    //void test::tst();
    void tst() override;
    void fCoord() override;
private:

};

#endif // TEST_H
