#ifndef FRACTALCOMRESSION_H
#define FRACTALCOMRESSION_H

#include "qgraphicsitem.h"
#include <QPixmap>

using namespace std;

class FractalComression
{
public:
	FractalComression(const QGraphicsPixmapItem * const item);
    void Comression();
	void Decomression();

	string fileNameResult;
protected:
	string fileNameSRC;
	string fileNameDIST;

	string pathForExe = "C:\\CLionProjects\\MyFractalCompression\\cmake-build-debug\\MyFractalCompression.exe";

	int block_size = 8;
	int quality = 100;
};

#endif // FRACTALCOMRESSION_H
