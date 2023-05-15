#include "fractalcomression.h"
#include <cmath>
#include <numeric>
#include <stdexcept>
#include <vector>
#include <random>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <QDir>

using namespace std;

FractalComression::FractalComression(const QGraphicsPixmapItem * const item)
{
	fileNameDIST = "result.fr";
	fileNameSRC = "temp.bmp";
	fileNameResult = "result.bmp";

	QPixmap pixmap = item->pixmap();
	QImage image = pixmap.toImage();

	image.save(QString(fileNameSRC.c_str()), "BMP");
}

void FractalComression::Comression()
{
	std::stringstream ss;
	string currentPath = QDir::currentPath().toStdString();

	ss << pathForExe << " -c " << currentPath <<  "/" << fileNameSRC
	   << " " << currentPath <<  "/" << fileNameDIST << " -s " << block_size << " -q " << quality;

	std::cout << ss.str() << std::endl;
	if (std::system(ss.str().c_str()))
		throw std::runtime_error("ERROR Comression");
}

void FractalComression::Decomression()
{
	std::stringstream ss;
	string currentPath = QDir::currentPath().toStdString();

	ss << pathForExe << " -d " << currentPath <<  "/" << fileNameDIST << " " <<  currentPath <<  "/" << fileNameResult;
	std::cout << ss.str() << std::endl;
	if (std::system(ss.str().c_str()))
		throw std::runtime_error("ERROR Decomression");
}
