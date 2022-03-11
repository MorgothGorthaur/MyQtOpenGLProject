#ifndef FIGURE_H
#define FIGURE_H
#include <math.h>
#include <QList>
class figure
{
public:
    figure();
    virtual void tst();
    virtual void fCoord();
    virtual void moreToOne(int i, float newX, float newY, float newZ);
    float* getPoints();
    float* getPoint(int i);
    void updatePoint(int i, float x, float y, float z);
    int getPointSize();
    float* GetGlobalCubeCoordinates();
    float GetIGlobalCoordinate(int i);
    //float GetPhi(float a, float b, float c, int i);
    QList<float*> GetMinCubes(int n, int m, int k);
    //float* GetNewCoord(float a, float b, float c);
    void customUpdate(int i);
    void get12();
    void get13();
    void get14();
    void get56();
    void get57();
    void get58();
    void get28();
    void get36();
    void get48();
    void get47();
    void get37();
    void get26();
    void valueUp();
    void valueDown();
    //void check(int i);
    static float points[];
    float* getNewPhi(float a, float b, float c);
private:

};

#endif // FIGURE_H
