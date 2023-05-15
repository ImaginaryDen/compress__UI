#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphicsview.h"
#include "fractalcomression.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	sceneOrigin = std::make_unique<QGraphicsScene>();
	ui->OriginView->setScene(sceneOrigin.get());
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
	itemOrigin = std::make_unique<QGraphicsPixmapItem>(QPixmap::fromImage(image));
	sceneOrigin->addItem(itemOrigin.get());
}

void MainWindow::on_pushButton_clicked()
{
    openPhoto();
}

void MainWindow::on_compressionButton_clicked()
{
	FractalComression FrComresion((QGraphicsPixmapItem *)itemOrigin.get());

	FrComresion.Comression();
	FrComresion.Decomression();

	sceneNew = std::make_unique<QGraphicsScene>();
	ui->resultView->setScene(sceneNew.get());
	std::cout << "compression done" << std::endl;

	QString fileName(FrComresion.fileNameResult.c_str());
	QImage image(fileName);
	itemNew = std::make_unique<QGraphicsPixmapItem>(QPixmap::fromImage(image));
	sceneNew->addItem(itemNew.get());
}

