#ifndef WORKGL_H
#define WORKGL_H

#include <QGLWidget>
#include <QWidget>
#include <QObject>
#include <QTimer>
#include <QPoint>
#include <QMouseEvent>
#include <QtMath>
#include <QOpenGLFunctions>
#include <math.h>
#include <QWheelEvent>
#include "cube.h"
#include "figure.h"
#include "dialog.h"
#include "test.h"
#include "line.h"
#include "squarepyramid.h"
#include "trianglepyramid.h"
class workGL : public QGLWidget
{
    Q_OBJECT
public:
     //cube cub;
    int tst;
    int mc;
     figure* fg;
     //figure* fig;
     float nRot, pointWidth;
     explicit workGL(QWidget *parent = 0);
     float dimensionX, dimensionY, dimensionZ;
private:

    void initializeGL()override;
    void resizeGL(int w, int h)override;
    void paintGL()override;
    QTimer mTimer;
    QPoint mPos;
    //float* getPoint();
   //static float point[];
    void drawPoint();
    void mousePressEvent(QMouseEvent*)override;
    void mouseReleaseEvent(QMouseEvent *) override;
    //void mouseMoveEvent(QMouseEvent*)override;
    void drawMinCube();

    int getI( float Widgetx, float Widgety);
    signals:
private slots:
  //  void checkMouseCoords(QMouseEvent*);
protected:
    virtual void wheelEvent(QWheelEvent *) override;
};

#endif // WORKGL_H
