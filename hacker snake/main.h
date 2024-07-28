#pragma once
#ifndef _MAIN_H_
#define _MAIN_H_

#include <easyX.h>
#include <conio.h>
#include <cstdio>
#include "Option.h"
#include "Display.h"

DWORD t1 = 0, t2 = 0;
Cube wall[2 * ROW + 2 * COL];//储存墙体的位置
Cube snake[2048];   //储存蛇体位置
Cube arrow[4];   ///储存箭头位置
Cube food;    //食物位置
Number num;   //游戏的一些基本参数，如：颜色、难度等

#endif