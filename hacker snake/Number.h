#pragma once
#ifndef _NUMBER_H_
#define _NUMBER_H_
//���ݴ洢��

class Number
{
private:
	size_t snakenum;//�߳�
	size_t score;//�÷�
	int color;//������ɫ
	int speed;//�ߵ��ٶ�
	char Dir;//�ߵ��˶�����
public:
	Number();
	void addsnake();//�߳�����
	void addscore();//�÷�����
	void setsnakenum(size_t sn);//�����߳�
	void setscore(size_t sc);//���õ÷�
	size_t getsnakenum();//��ȡ�߳�
	size_t getscore();//��ȡ�÷�
	void setColor(int c);//���ý�����ɫ
	int getColor();//��ȡ������ɫ
	void setSpeed(int c);//��������
	int getSpeed();//��ȡ����
	void setDir(char d);//�����˶�����
	char getDir();//��ȡ�˶�����
};
#endif
