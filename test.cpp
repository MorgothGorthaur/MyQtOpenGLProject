#include "test.h"

test::test()
{
    //testCorrds();
    //fCoord();
}
void test::fCoord(){
    float testPoints[]{
       /*-1,-1,-1,   1,-1,-1, 1,1,-1, -1,1,-1,  //1  //2 //3 //4
        -1,1,1, 1,1,1,  -1,-1,1,    1,-1,1, //5 //6 //7 //8
         0,-1,-1,    1,0,-1, 0,1,-1, -1,0,-1,      //12  //24 //34 //13
         //1,1,0,  1,-1,0, -1,-1,0,    -1,1,0,
          0,1,1, // -1,0,1, 1,0,1,  0,-1,1*/
         -2,-2,-2,   -2,-2,-2, -2,-2,-2, -2,-2,-2,  //1 //2 //3 //4
        1,1,1, 1,1,-1, -1,1,1, 1,-1,1,  //5 //6 //7 //8
         0,-1,-1,    -1,0,-1,    -1,-1,0,          //12 //13  //14
        1,1,0,  0,1,1,  1,0,1,  //56  //57 //58
        1,-1,0, 0,1,-1, 0,-1,1, -1,0,1,     //28   //36  /48 //47
        -1,1,0,     1,0,-1,         //37    //26

    };
    for(int i = 0; i < getPointSize(); i++){
        points[i] = testPoints[i];
    }
    customUpdate(-3);
}
void test::tst(){
    printf("test");
}