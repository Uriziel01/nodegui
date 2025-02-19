#pragma once

#include <QMainWindow>
#include "src/cpp/core/NodeWidget/nodewidget.h"
#include <QEvent>

class NMainWindow: public QMainWindow, public NodeWidget
{
    NODEWIDGET_IMPLEMENTATIONS(QMainWindow)
public:
    using QMainWindow::QMainWindow; //inherit all constructors of QMainWindow
private:
    void calculateLayout(){
        YGDirection direction = YGNodeStyleGetDirection(this->getFlexNode());
        YGNodeCalculateLayout(this->getFlexNode(),width(),height(),direction);
    }
    bool eventFilter(QObject *object, QEvent *event) { // This will be installed on mainwidgetwrap
        switch(event->type()) {
            case QEvent::LayoutRequest:
            case QEvent::ChildRemoved: {
                calculateLayout(); break;
            }
            default: ; // do nothing
        }
        return QMainWindow::eventFilter(object, event);
    }
    void resizeEvent(QResizeEvent * event){
        calculateLayout();
        QMainWindow::resizeEvent(event);
    }
};


