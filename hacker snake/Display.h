#pragma once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include "Cube.h"
#include "Number.h"
class Display
{
public:
	static void start(Cube arrow[4], Number &num);//��ʼ����
	static bool chose1(Cube arrow[4], Number &num);//�û�ѡ��
	static void set(Cube arrow[4], Number& num);
	static bool chose2(Cube arrow[4], Number& num);
	static void colorband(Cube arrow[4], Number& num);
	static bool chose3(Cube arrow[4], Number& num);//����ɫѡ�������û�ѡ��
	static void difficultyband(Cube arrow[4], Number& num);//�Ѷ�ѡ�����
	static bool chose4(Cube arrow[4], Number& num);//�Ѷ�ѡ��
	static void end(Number& num);  //��������
};
#endif

