#include "line.h"

line::line()
{

}
void line::fCoord(){
    float testPoints[]{
       /*-1,-1,-1,   1,-1,-1, 1,1,-1, -1,1,-1,  //1  //2 //3 //4
        -1,1,1, 1,1,1,  -1,-1,1,    1,-1,1, //5 //6 //7 //8
         0,-1,-1,    1,0,-1, 0,1,-1, -1,0,-1,      //12  //24 //34 //13
         //1,1,0,  1,-1,0, -1,-1,0,    -1,1,0,
          0,1,1, // -1,0,1, 1,0,1,  0,-1,1*/
         1,0,0,  1,0,0, 1,0,0, 1,0,0,  //1 //2 //3 //4
        -1,0,0, -1,0,0, -1,0,0, -1,0,0,  //5 //6 //7 //8
         0.75,0,0,    0.75,0,0,    0.75,0,0,          //12 //13  //14
        0.5,0,0,  0.5,0,0,  0.5,0,0,  //56  //57 //58
        -0.5,0,0, -0.5,0,0, -0.5,0,0, -0.5,0,0,     //28   //36  /48 //47
        -0.75,0,0,     -0.75,0,0,         //37    //26

    };
    for(int i = 0; i < getPointSize(); i++){
        points[i] = testPoints[i];
    }
    customUpdate(-3);
}
void line::moreToOne(int i, float newX, float newY, float newZ){
    if(i == 0 || i == 3 || i == 6 || i ==9){
        points[0] = points[3] = points[6] = points[9] = newX;
        points[1] = points[4] = points[7] = points[10] = newY;
        points[2] = points[5] = points[8] = points[11] = newZ;
        customUpdate(0);
        customUpdate(3);
        customUpdate(6);
        customUpdate(9);
    }
    if(i == 12 || i == 15 || i == 18 || i == 21){
        points[12] = points[15] = points[18] = points[21] = newX;
        points[13] = points[16] = points[19] = points[22] = newY;
        points[14] = points[17] = points[20] = points[23] = newZ;
        customUpdate(12);
        customUpdate(15);
        customUpdate(18);
        customUpdate(21);
    }
    if(i >=24){
        points[24] = points[27] = points[30] = newX;
        points[25] = points[28] = points[31] = newY;
        points[26] = points[29] = points[32] = newZ;
       customUpdate(24);
       customUpdate(27);
       customUpdate(30);
       points[33] = points[36] = points[39] = newX;
       points[34] = points[37] = points[40] = newY;
       points[35] = points[38] = points[41] = newZ;
      customUpdate(33);
      customUpdate(36);
      customUpdate(39);
      points[42] = points[45] = points[48] = points[51] = newX;
      points[43] = points[46] = points[49] = points[52] = newY;
      points[44] = points[47] = points[50] = points[53] = newZ;
      customUpdate(42);
      customUpdate(45);
      customUpdate(48);
      customUpdate(51);
      points[54] = points[57] = newX;
      points[55] = points[58] = newY;
      points[56] = points[59] = newZ;
    customUpdate(54);
    customUpdate(57);
    }




};
