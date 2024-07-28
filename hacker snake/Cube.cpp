#include "Cube.h"
#include<easyx.h>

Cube::Cube() {
	X = 0;
	Y = 0;
};

void Cube::setX(int x) {
	X = x;
}

void Cube::setY(int y) {
	Y = y;
}

int Cube::getX() {
	return X;
}

int Cube::getY() {
	return Y;
}
