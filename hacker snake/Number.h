#pragma once
#ifndef _NUMBER_H_
#define _NUMBER_H_
//数据存储类

class Number
{
private:
	size_t snakenum;//蛇长
	size_t score;//得分
	int color;//界面颜色
	int speed;//蛇的速度
	char Dir;//蛇的运动方向
public:
	Number();
	void addsnake();//蛇长增加
	void addscore();//得分增加
	void setsnakenum(size_t sn);//设置蛇长
	void setscore(size_t sc);//设置得分
	size_t getsnakenum();//获取蛇长
	size_t getscore();//获取得分
	void setColor(int c);//设置界面颜色
	int getColor();//获取界面颜色
	void setSpeed(int c);//设置蛇速
	int getSpeed();//获取蛇速
	void setDir(char d);//设置运动方向
	char getDir();//获取运动方向
};
#endif
