#pragma once
#ifndef _OPTION_H_
#define _OPTION_H_
#include "Display.h"
#include "Cube.h"
#include "Number.h"
#define ROW 46
#define COL 64
class Option
{
public:
	static void init(Cube wall[2 * ROW + 2 * COL], Cube snake[2048], Cube& food, Number& num);//��ʼ����Ϸ����
	static void DrawMap(Cube wall[2 * ROW + 2 * COL], Cube snake[2048], Cube& food, Number& num);//���Ƶ�ͼ
	static bool IsWall(Cube wall[2 * ROW + 2 * COL], int x, int y);
	static bool IsSnake(Cube snake[2048], int x, int y, Number& num);
	static void addfood(Cube wall[2 * ROW + 2 * COL], Cube snake[2048], Cube& food, Number& num);
	static bool move(Cube wall[2 * ROW + 2 * COL], Cube snake[2048], Cube& food, Number& num);//�����ƶ�
	static bool ChangeDir(Number &num);//��ȡ��Ҳ���
};
#endif

