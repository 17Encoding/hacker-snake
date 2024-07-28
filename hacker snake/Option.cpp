#include "Option.h"
#include <ctime>
#include <cstdlib>
#include <easyX.h>
#include <conio.h>
#include <cstdio>

void Option::init(Cube wall[2 * ROW + 2 * COL], Cube snake[2048], Cube& food, Number& num) {
	srand((unsigned)time(NULL));
	int z = 0;
	num.setDir('D');
	num.setscore(0);
	num.setsnakenum(3);
	//ÿһ�е� ��һ�� �� ���һ�� ��ǽ
	for (int i = 0; i < ROW; i++) {
		wall[z].setX(i), wall[z].setY(0);
		z++;
		wall[z].setX(i), wall[z].setY(COL - 1);
		z++;
	}

	//ÿһ�е� �ڶ��� �� �����ڶ��� ��ǽ
	for (int i = 1; i < COL - 1; i++) {
		wall[z].setX(0), wall[z].setY(i);
		z++;
		wall[z].setX(ROW - 1), wall[z].setY(i);
		z++;
	}

	//��ʼ����
	snake[0].setX(3), snake[0].setY(5);
	snake[1].setX(3), snake[1].setY(4);
	snake[2].setX(3), snake[2].setY(3);
	addfood(wall, snake, food, num);
}

void Option::DrawMap(Cube wall[2 * ROW + 2 * COL], Cube snake[2048], Cube& food, Number& num) {
	BeginBatchDraw();//��ʼ����
	settextcolor(num.getColor());
	settextstyle(0, 0, _T("����"));
	cleardevice();//����
	char arr[100];

	//����ܷ�
	sprintf_s(arr, "score:%d", num.getscore());
	outtextxy(0, 0, arr);//����Ļ���Ͻ����

	//����ǽ
	for (int i = 0; i < 2 * ROW + 2 * COL; i++) {
		setfillcolor(num.getColor());
		solidrectangle(wall[i].getY() * 10, wall[i].getX() * 10 + 20, wall[i].getY() * 10 + 10, wall[i].getX() * 10 + 30);
	}				//��                   //��                      //��                      //��
	//������
	for (int i = 0; i < num.getsnakenum(); i++) {
		setfillcolor(num.getColor());
		solidrectangle(snake[i].getY() * 10, snake[i].getX() * 10 + 20, snake[i].getY() * 10 + 10, snake[i].getX() * 10 + 30);
	}
	//����ʳ��
	setfillcolor(num.getColor());
	solidrectangle(food.getY() * 10, food.getX() * 10 + 20, food.getY() * 10 + 10, food.getX() * 10 + 30);
	EndBatchDraw();//��������
}

bool Option::IsWall(Cube wall[2 * ROW + 2 * COL], int x, int y) {
	for (int i = 0; i < 2 * ROW + 2 * COL; i++)
		if (wall[i].getX() == x && wall[i].getY() == y)
			return true;
	return false;
}

bool Option::IsSnake(Cube snake[2048], int x, int y, Number& num) {
	for (int i = 0; i < num.getsnakenum(); i++)
		if (snake[i].getX() == x && snake[i].getY() == y)
			return true;
	return false;
}

void Option::addfood(Cube wall[2 * ROW + 2 * COL], Cube snake[2048], Cube& food, Number& num) {
	int x, y;
	//ʳ��������ֵĵط�ֻ���ǿյأ����ܳ�����ǽ�ϡ��Լ���������
	do {
		x = rand() % (ROW - 1) + 1;
		y = rand() % (COL - 1) + 1;
	} while (IsWall(wall, x, y) || IsSnake(snake, x, y, num));
	food.setX(x);
	food.setY(y);
}

bool Option::move(Cube wall[2 * ROW + 2 * COL], Cube snake[2048], Cube& food, Number& num) {
	int x = 0, y = 0;
	switch (num.getDir()) {
	case 'A':
		x = snake[0].getX();
		y = snake[0].getY() - 1;
		break;
	case 'W':
		x = snake[0].getX() - 1;
		y = snake[0].getY();
		break;
	case 'D':
		x = snake[0].getX();
		y = snake[0].getY() + 1;
		break;
	case 'S':
		x = snake[0].getX() + 1;
		y = snake[0].getY();
		break;
	default:
		break;
	}
	if (IsWall(wall, x, y) || IsSnake(snake, x, y, num)) {
		Display::end(num);
		return false;
	}
	else if (food.getX() == x && food.getY() == y) {
		//��β����ͷ��������ƶ�һλ
		for (int i = num.getsnakenum(); i > 0; i--) {
			snake[i].setX(snake[i - 1].getX());
			snake[i].setY(snake[i - 1].getY());
		}
		snake[0].setX(x);
		snake[0].setY(y);
		//�߳߶ȼ�һ
		num.addscore(), num.addsnake();
		addfood(wall, snake, food, num);
	}
	else {
		//��β����ͷ�����ƶ�һλ
		for (int i = num.getsnakenum() - 1; i > 0; i--) {
			snake[i].setX(snake[i - 1].getX());
			snake[i].setY(snake[i - 1].getY());
		}

		//����һ��λ�ø���ͷ
		snake[0].setX(x);
		snake[0].setY(y);
	}
	return true;
}

bool Option::ChangeDir(Number &num) {
	switch (_getch()) {
	case 'A':
	case 'a':
	case 75:
		if (num.getDir() != 'D') num.setDir('A');//�߲��ܺ���
		break;
	case 'D':
	case 'd':
	case 77:
		if (num.getDir() != 'A') num.setDir('D');
		break;
	case 'W':
	case 'w':
	case 72:
		if (num.getDir() != 'S') num.setDir('W');
		break;
	case 'S':
	case 's':
	case 80:
		if (num.getDir() != 'W') num.setDir('S');
		break;
	case 32:
		_getch();
		break;
	case 27:
		return false;
	default:
		break;
	}
	return true;
}

