#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_

#include <easyX.h>
#include <conio.h>
#include <cstdio>
#include "Option.h"
#include "Display.h"

DWORD t1 = 0, t2 = 0;
Cube wall[2 * ROW + 2 * COL];//����ǽ���λ��
Cube snake[2048];   //��������λ��
Cube arrow[4];   ///�����ͷλ��
Cube food;    //ʳ��λ��
Number num;   //��Ϸ��һЩ�����������磺��ɫ���Ѷȵ�

#endif