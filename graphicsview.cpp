#include "graphicsview.h"
#include "qapplication.h"

graphicsView::graphicsView(QWidget *parent) : QGraphicsView(parent)
{}

void graphicsView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.2;

    if(event->angleDelta().y() > 0)
    {
        scale(scaleFactor, scaleFactor);
    }
    else
    {
        scale(1/scaleFactor, 1/scaleFactor);
    }
}

void graphicsView::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton) {
        m_lastPos = event->pos();
        QApplication::setOverrideCursor(Qt::SizeAllCursor);
    }
    QGraphicsView::mousePressEvent(event);
}


