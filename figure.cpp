#include "figure.h"

figure::figure()
{

}
void figure::fCoord(){};
void figure::moreToOne(int i , float newX, float newY, float newZ){
    printf("OK");
};
float figure::points[]{
    0,0,0,  0,0,0,  0,0,0,  0,0,0,
     0,0,0,  0,0,0,  0,0,0,  0,0,0,
     0,0,0,  0,0,0,  0,0,0,  0,0,0,
     0,0,0,  0,0,0,  0,0,0,  0,0,0,
     0,0,0,  0,0,0,  0,0,0,  0,0,0,


};
float* figure::getPoints(){
    //customUpdate(-3);
    return points;
}
float* figure::getPoint(int i){

    static float point[]{
        points[i], points[i+1], points[i+2]
    };

    point[0] = points[i];
    point[1] = points[i+1];
    point[2] = points[i+2];
    return point;
}
void figure::updatePoint(int i,float x, float y, float z){
    points[i] = x;
    points[i+1] = y;
    points[i+2] = z;
}
int figure::getPointSize(){
    return  (int) sizeof (points) / sizeof (points[0]);
}
float* figure::GetGlobalCubeCoordinates()
{
    static float globalCubeCoordinates [] {
      /*  -1,-1,-1,   1,-1,-1, 1,1,-1, -1,1,-1,
         -1,1,1, 1,1,1,  -1,-1,1,    1,-1,1,
         0,-1,-1,    0,1,-1, -1,0,-1,    1,0,-1,
         1,1,0,  1,-1,0, -1,-1,0,    -1,1,0,
          0,1,1,  -1,0,1, 1,0,1,  0,-1,1*/
        -1,-1,-1,   1,-1,-1, -1,1,-1, -1,-1,1,  //1 //2 //3 //4
       1,1,1, 1,1,-1, -1,1,1, 1,-1,1,  //5 //6 //7 //8
        0,-1,-1,    -1,0,-1,    -1,-1,0,          //12 //13  //14
       1,1,0,  0,1,1,  1,0,1,  //56  //57 //58
       1,-1,0, 0,1,-1, 0,-1,1, -1,0,1,     //28   //36  /48 //47
       -1,1,0,     1,0,-1,         //37    //26

    };
    return globalCubeCoordinates;
}
float figure::GetIGlobalCoordinate(int i){
    float* gc = GetGlobalCubeCoordinates();
    return *(gc+i);
}


QList<float*> figure::GetMinCubes(int n, int m, int k){
    float st_x = -1;
    float st_y = -1;
    float st_z = -1;
    float x,y,z;
    x=y=z = 1;
    QList <float*> lst;
    for (int i = 0; i < n; i++){
            st_y = -1;
        for(int j = 0; j < m; j++){
            st_z = -1;
            for (int l = 0; l <k; l++){

                float cb[]{
                    st_x,st_y,st_z,      st_x + (x+1)/n,st_y,st_z,  st_x,st_y + (y+1)/m,st_z,   st_x,st_y,st_z + (z+1)/k,
                    st_x + (x+1)/n,st_y+(y+1)/m,st_z+(z+1)/k,      st_x,st_y+(y+1)/m,st_z+(z+1)/k,         st_x + (x+1)/n,st_y+(y+1)/m,st_z,    st_x + (x+1)/n,st_y,st_z+(z+1)/k,

                };

                for (int hlp = 0; hlp < 24; hlp +=3){
                    float cb_x = cb[hlp];
                   // printf("%f\n",cb_x);
                    float cb_y = cb[hlp + 1];
                    float cb_z = cb[hlp + 2];
                    float*p = new float[] {cb_x, cb_y, cb_z};
                    //lst.append(p);
                    bool bl = true;
                    for(int hlp2 = 0; hlp2 < lst.size(); hlp2++){
                        if (lst.value(hlp2)[0] == p[0] && lst.value(hlp2)[1] == p[1] && lst.value(hlp2)[2] == p[2] ){
                            bl = false;
                            hlp2 = lst.size();
                        }
                    }
                    if(bl){
                        lst.append(p);
                    }

                }
                st_z = st_z + (z+1)/k;
            }
             st_y = st_y + (y+1)/m;
        }
        st_x = st_x + (x+1)/n;
    }


    return lst;
}
//todo remake getmin cubes

void figure::customUpdate(int i){
    i =  i /3;
    if(i ==0){
        get12();
        get13();
        get14();
    }if(i == 1){
        get12();
        get26();
        get28();
    }if(i == 2){
        get13();
        get36();
        get37();
    }if(i == 3){
        get14();
        get47();
        get48();
    }if(i == 4){
        get56();
        get57();
        get58();
    }if(i == 5){
        get26();
        get36();
        get56();
    }if(i == 6){
        get37();
        get47();
        get57();
    }if(i == 7){
        get28();
        get48();
        get58();
    }
    if(i == -1){
        get12();
        get13();
        get14();
        get26();
        get28();
        get36();
        get37();
        get47();
        get48();
        get56();
        get57();
        get58();
    }

}
void figure::get12(){
    points[24] = (points[0] + points[3])/2;
    points[25] = (points[1] + points[4]) / 2;
    points[26] = (points[2] + points[5]) / 2;
}
void figure::get13(){
    //13
    points[27] = (points[0] + points[6])/2;
    points[28] = (points[1] + points[7]) / 2;
    points[29] = (points[2] + points[8]) / 2;
}
void figure::get14(){
    //14
    points[30] = (points[0] + points[9])/2;
    points[31] = (points[1] + points[10]) / 2;
    points[32] = (points[2] + points[11]) / 2;
}
void figure::get26(){
    //26
    points[57] = (points[3] + points[15])/2;
    points[58] = (points[4] + points[16]) / 2;
    points[59] = (points[5] + points[17]) / 2;
}
void figure::get28(){
    //28
    points[42] = (points[3] + points[21])/2;
    points[43] = (points[4] + points[22]) / 2;
    points[44] = (points[5] + points[23]) / 2;

}
void figure::get36(){
    //36
    points[45] = (points[6] + points[15])/2;
    points[46] = (points[7] + points[16]) / 2;
    points[47] = (points[8] + points[17]) / 2;
}
void figure::get37(){
    //37
    points[54] = (points[6] + points[18])/2;
    points[55] = (points[7] + points[19]) / 2;
    points[56] = (points[8] + points[20]) / 2;
}
void figure::get47(){
    //47
    points[51] = (points[9] + points[18])/2;
    points[52] = (points[10] + points[19]) / 2;
    points[53] = (points[11] + points[20]) / 2;
}
void figure::get48(){
    //48
    points[48] = (points[9] + points[21])/2;
    points[49] = (points[10] + points[22]) / 2;
    points[50] = (points[11] + points[23]) / 2;

}
void figure::get56(){
    //56
    points[33] = (points[12] + points[15])/2;
    points[34] = (points[13] + points[16]) / 2;
    points[35] = (points[14] + points[17]) / 2;

}
void figure::get57(){
    //57
    points[36] = (points[12] + points[18])/2;
    points[37] = (points[13] + points[19]) / 2;
    points[38] = (points[14] + points[20]) / 2;

}
void figure::get58(){
    //58
    points[39] = (points[12] + points[21])/2;
    points[40] = (points[13] + points[22]) / 2;
    points[41] = (points[14] + points[23]) / 2;

}
void figure::tst(){
     printf("figure");
}
void figure::valueUp(){
    for(int i = 0; i < getPointSize(); i++){
        points[i] *= 2;
    }
}
void figure::valueDown(){
    for(int i = 0; i < getPointSize(); i++){
        points[i] /= 2;
    }
}
float* figure::getNewPhi(float a, float b, float c){
   static float phi[20];
   for ( int i = 0; i < 20; i++){
       float _a = GetIGlobalCoordinate(i*3);
       float _b = GetIGlobalCoordinate( i*3+1);
       float _c = GetIGlobalCoordinate( i * 3 + 2);
       float hlp = (1 + a * _a) * ( 1 + b * _b) * ( 1 + c * _c);
       if (i < 8){
            phi[i] = hlp *  (a * _a + b * _b + c * _c -2 ) / 8;
       }else{
           phi[i] = hlp * ( 1 - pow(a * _b * _c,2) - pow(b * _a * _c, 2) - pow(c * _b * _a,2)) / 4;
       }
   }
   return phi;
}









