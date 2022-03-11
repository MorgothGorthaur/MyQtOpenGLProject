#include "squarepyramid.h"

squarePyramid::squarePyramid()
{

}
void squarePyramid::fCoord(){
    float testPoints[]{
       /*-1,-1,-1,   1,-1,-1, 1,1,-1, -1,1,-1,  //1  //2 //3 //4
        -1,1,1, 1,1,1,  -1,-1,1,    1,-1,1, //5 //6 //7 //8
         0,-1,-1,    1,0,-1, 0,1,-1, -1,0,-1,      //12  //24 //34 //13
         //1,1,0,  1,-1,0, -1,-1,0,    -1,1,0,
          0,1,1, // -1,0,1, 1,0,1,  0,-1,1*/
         0,0,-1,   0,0,-1, 0,0,-1, -1,-1,1,  //1 //2 //3 //4
        1,1,1, 0,0,-1, -1,1,1, 1,-1,1,  //5 //6 //7 //8
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

void squarePyramid::moreToOne(int i, float newX, float newY, float newZ){
    if(i == 0 || i == 3 || i == 6 || i ==15){
        points[0] = points[3] = points[6] = points[15] = newX;
        points[1] = points[4] = points[7] = points[16] = newY;
        points[2] = points[5] = points[8] = points[17] = newZ;
        customUpdate(0);
        customUpdate(3);
        customUpdate(6);
        customUpdate(15);
    }
};
