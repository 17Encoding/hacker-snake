#pragma once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include "Cube.h"
#include "Number.h"
class Display
{
public:
	static void start(Cube arrow[4], Number &num);//开始界面
	static bool chose1(Cube arrow[4], Number &num);//用户选择
	static void set(Cube arrow[4], Number& num);
	static bool chose2(Cube arrow[4], Number& num);
	static void colorband(Cube arrow[4], Number& num);
	static bool chose3(Cube arrow[4], Number& num);//在颜色选择界面的用户选择
	static void difficultyband(Cube arrow[4], Number& num);//难度选择界面
	static bool chose4(Cube arrow[4], Number& num);//难度选择
	static void end(Number& num);  //结束界面
};
#endif

