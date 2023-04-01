#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphicsview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = std::make_unique<QGraphicsScene>();
    ui->OriginView->setScene(scene.get());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openPhoto()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());
    QImage image(fileName);
    item = std::make_unique<QGraphicsPixmapItem>(QPixmap::fromImage(image));
    scene->addItem(item.get());
}

void MainWindow::on_pushButton_clicked()
{
    openPhoto();
}

void MainWindow::on_compressionButton_clicked()
{

}

