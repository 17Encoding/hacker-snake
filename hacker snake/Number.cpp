#include "Number.h"
#include <easyx.h>

Number::Number() {
	snakenum = 3;
	score = 0;
	color = RGB(0, 255, 0);
	speed = 100;
	Dir = 'D';
}

void Number::addsnake() {
	snakenum++;
}

void Number::addscore() {
	score++;
}

void Number::setsnakenum(size_t sn) {
	snakenum = sn;
}

void Number::setscore(size_t sc) {
	score = sc;
}

size_t Number::getsnakenum() {
	return snakenum;
}

size_t Number::getscore() {
	return score;
}

void Number::setColor(int c) {
	color = c;
}

int Number::getColor() {
	return color;
}

void Number::setSpeed(int c) {
	speed = c;
}

int Number::getSpeed() {
	return speed;
}

void Number::setDir(char d) {
	Dir = d;
}

char Number::getDir() {
	return Dir;
}