#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QScrollArea>
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QFileDialog>
#include <QDir>

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void openPhoto();
private slots:
    void on_pushButton_clicked();

    void on_compressionButton_clicked();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<QGraphicsScene> scene;
    std::unique_ptr<QGraphicsItem> item;

};
#endif // MAINWINDOW_H
