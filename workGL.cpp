#include "workGL.h"
#include <QDebug>
workGL::workGL(QWidget *parent) : QGLWidget(parent)
{
    this->mc = 1;
    tst = 1;
    setMouseTracking(true);
    //this->nRot = 420;
    this->nRot = 0;
    this->pointWidth = 5;
    this->dimensionX = this->dimensionY = this->dimensionZ = 10;
    connect(&mTimer,SIGNAL(timeout()),this,SLOT(updateGL()));
    mTimer.start(1);

}
void workGL::initializeGL(){
    glFrustum(-1,1,-1,1,1,5);
}
void workGL::resizeGL(int w, int h){
     glViewport(0,0,w,h);
     glMatrixMode(GL_PROJECTION);
     glOrtho(-dimensionX,dimensionX,-dimensionY,dimensionY,-dimensionZ,2* dimensionZ);
}
void workGL::paintGL(){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_POINT_SIZE);
    glRotatef(nRot ,1,0,0);
    glRotatef(nRot ,0,1,0);

    drawMinCube();
    drawPoint();
}
void workGL::drawPoint(){
    float* point  = fg->getPoints();
    float lb[fg->getPointSize() - 24];
    float lb2[24];
    for (int i = 24; i < fg->getPointSize(); i++){
        lb[i - 24] = *(point + i );
    }
    for(int  i = 0; i < 24;i++){
        lb2[i] = *(point + i );
    }

    qglColor(Qt::green);
    glVertexPointer(3,GL_FLOAT,0,&lb);
    glEnableClientState(GL_VERTEX_ARRAY);
    glPointSize(pointWidth);
    glDrawArrays(GL_POINTS,0,fg->getPointSize()/3 - 8);
    glDisableClientState(GL_VERTEX_ARRAY);

    qglColor(Qt::red);
    glVertexPointer(3,GL_FLOAT,0,&lb2);
    glEnableClientState(GL_VERTEX_ARRAY);
    glPointSize(pointWidth);
    glDrawArrays(GL_POINTS,0,8);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void workGL::mousePressEvent(QMouseEvent * mo){
    mPos=mo->pos();
    if(mo->button() == Qt::LeftButton){
         this->setCursor(QCursor(Qt::ClosedHandCursor));
    }


}

void workGL::mouseReleaseEvent(QMouseEvent *mo){
    if(mo->button() == Qt::LeftButton){

        // координаты виджета, куда кликнули мышкой
        float Widgetx = (mPos.x()-(float)QWidget::width()/2) / ((float)QWidget::width()/20);
        float Widgety = (mPos.y()-(float)QWidget::height()/2)/((float) QWidget::height()/20);

        // координаты виджета, куда перетащили мышку
        float WidgetX = (mo->pos().x()-(float)QWidget::width()/2) / ((float)QWidget::width()/20);
        float WidgetY =  -(mo->pos().y() -(float)QWidget::height()/2)/((float) QWidget::height()/20);
        if(WidgetY >10){
            WidgetY = 9.9;
        }
        if(WidgetY < -10){
            WidgetY = -9.9;
        }
        if(WidgetX > 10){
            WidgetX = 9.9;
        }
        if(WidgetX < -10){
            WidgetX = -9.9;
        }
        // поиск какой из точек соответствуют координаты виджета
        int i = getI(Widgetx, -Widgety);
        if(i != -1){
            float newX,newY, newZ;
            float cs = cos(nRot * M_PI / 180) ;
            float sn = sin(nRot * M_PI / 180);
            //int dbg = 0;
            if((int)nRot % 90  == 0 && cs!=1){
                newX = WidgetY /(sn*sn);
                newZ = WidgetX / sn;
                newY = WidgetY / sn;
                //dbg = 1;
            }else{
                float* point = fg->getPoint(i);
                float Z;
                Z = *(point +2) + (-WidgetY- Widgety) * sn;
                newZ = WidgetX * sn - WidgetY * sn*cs +Z *sn * cs*cs;
                if(newZ >= 10 || newZ <= -10){
                    newZ = *(point + 2);
                }
                newX = (float)(WidgetX - newZ * sn) / cs;
                newY = (float)(WidgetY - newX * sn*sn +  newZ * sn*cs) / cs;
            }

           fg->updatePoint(i,newX,newY,newZ);
           fg->customUpdate(i);
           fg->moreToOne(i,newX,newY,newZ);
        }
    }else if(mo->button() == Qt::RightButton){
        float Widgetx = (mPos.x()-(float)QWidget::width()/2) / ((float)QWidget::width()/20);
        float Widgety = -(mPos.y()-(float)QWidget::height()/2)/((float) QWidget::height()/20);

        // координаты виджета, куда перетащили мышку
        float WidgetX = (mo->pos().x()-(float)QWidget::width()/2) / ((float)QWidget::width()/20);
        float WidgetY =  -(mo->pos().y() -(float)QWidget::height()/2)/((float) QWidget::height()/20);

        //printf("%f\t%f\t%f\n",dx,dy,dz);
       for(int i =0; i < fg->getPointSize(); i+=3 ){
           float dX = WidgetX - Widgetx;
           float dY = WidgetY - Widgety;
           float dx,dy,dz;
           float cs = cos(nRot * M_PI / 180) ;
           float sn = sin(nRot * M_PI / 180);
           if(int(nRot) % 90 == 0 && cs!=1){
               dx = dY /(sn*sn);
               dz = dX / sn;
               dy = dY / sn;

           }else{
               float* point = fg->getPoint(i);
               float Z = *(point +2) + dY * sn;
               dz = dX * sn - dY * sn*cs +Z *sn * cs*cs;
               /*if(*(point + 2) + dz >= 10 || *(point + 2) + dz <= -10){
                   dz = 0;
               }*/
               //dz = dY* sn;
               dx = (float)(dX - dz * sn) / cs;
               dy = (float)(dY - dx * sn*sn +  dz * sn*cs) / cs;
           }
           float* point = fg->getPoint(i);
           float newX = *(point+0) + dx;
           float newY = *(point + 1) + dy;
           float newZ = *(point + 2) + dz;
           fg->updatePoint(i,newX,newY,newZ);
       }


    }else if( mo->button() == Qt::MiddleButton){

        float Widgety = -(mPos.y()-(float)QWidget::height()/2)/((float) QWidget::height()/20);

        // координаты виджета, куда перетащили мышку

        float WidgetY =  -(mo->pos().y() -(float)QWidget::height()/2)/((float) QWidget::height()/20);
        float dy = WidgetY - Widgety;
        if (dy > 0){
            fg->valueUp();

        }else{
            fg->valueDown();
        }


    }


}
int workGL::getI(float Widgetx, float Widgety){
    for ( int i = 0; i < fg->getPointSize(); i+=3){
        float cs = cos(nRot * M_PI / 180) ;
        float sn = sin(nRot * M_PI / 180);
        float* point = fg->getPoint(i);

        float x = *(point+0) * cs + *(point + 2) * sn;
        float y = *(point + 0) * sn*sn + *(point  + 1) * cs + *(point + 2) * -sn * cs;
        if ( Widgetx <= x + (float)pointWidth/10 && Widgetx >= x - (float)pointWidth/10){
            if ( Widgety <= y + (float)pointWidth/10 && Widgety >= y - (float)pointWidth/10){
                return i;
            }
        }
    }
    return -1;
}

void workGL::wheelEvent(QWheelEvent * mw){
     this->nRot += (float) mw->angleDelta().y() / 120;
}
void workGL::drawMinCube(){
    QList<float*> lst = fg->GetMinCubes(mc,mc,mc);
    float cb[3*lst.size()];
    for(int i = 0; i < lst.size()*3; i+=3){
        float *phi = fg->getNewPhi(lst.value(i/3)[0], lst.value(i/3)[1], lst.value(i/3)[2]);
        float x,y,z;
        x = y = z = 0;
        for (int j = 0; j < 20; j++){
            x+= fg->getPoint(j*3)[0] * phi[j];
            y+= fg->getPoint(j*3)[1] * phi[j];
            z+= fg->getPoint(j*3)[2] * phi[j];
        }
        cb[i] = x;
        cb[i+1] = y;
        cb[i+2] = z;
    }

    qglColor(Qt::yellow);

    glVertexPointer(3,GL_FLOAT,0,&cb);
    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_POINTS,0,(int)(lst.size()));
    glDisableClientState(GL_VERTEX_ARRAY);
}

//ToDo ненада
