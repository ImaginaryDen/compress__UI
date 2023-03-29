#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include "qapplication.h"
#include <QWidget>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QDebug>
#include <QScrollBar>

class graphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit graphicsView(QWidget *parent = nullptr);
protected:
    virtual void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override
        {
            if (event->buttons() & Qt::LeftButton) {
                // ????????? ??????????, ?? ??????? ????????????? ????
                QPointF delta = mapToScene(event->pos()) - mapToScene(m_lastPos);
                // ?????????? ????? ?? ??? ??????????
                horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
                verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
                // ????????? ????????? ??????? ????
                m_lastPos = event->pos();
            }
            QGraphicsView::mouseMoveEvent(event);
        }

    void mouseReleaseEvent(QMouseEvent *event) override
    {
        QGraphicsView::mouseReleaseEvent(event);
        QApplication::restoreOverrideCursor();
    }
signals:

public slots:

private:
    QPoint m_lastPos;
};

#endif // GRAPHICSVIEW_H
