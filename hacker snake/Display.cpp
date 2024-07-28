#include "Display.h"
#include <easyx.h>
#include <conio.h>

void Display::start(Cube arrow[4],Number &num) {
	while (1) {
		BeginBatchDraw();//开始绘制
		settextcolor(num.getColor());
		settextstyle(65, 25, _T("黑体"));
		cleardevice();//清屏
		outtextxy(230, 80, "HACKER");
		outtextxy(240, 145, "SNAKE");
		settextstyle(25, 0, _T("黑体"));
		outtextxy(280, 280, "PLAY");
		outtextxy(285, 340, "SET");
		outtextxy(280, 400, "EXIT");
		settextstyle(14, 0, _T("黑体"));
		switch (num.getSpeed()) {
		case 50:
			outtextxy(500, 450, "DIFFICULTY:HARD");
			break;
		case 100:
			outtextxy(500, 450, "DIFFICULTY:NORMAL");
			break;
		case 150:
			outtextxy(500, 450, "DIFFICULTY:EASY");
			break;
		}
		settextstyle(25, 0, _T("黑体"));
		outtextxy(arrow[0].getX(), arrow[0].getY(), "->");//绘制箭头
		EndBatchDraw();//结束绘制
		if (!chose1(arrow,num))return;//获取玩家选择
	}
}

bool Display::chose1(Cube arrow[4],Number &num) {
	switch (_getch()) {
	case 'S':
	case 's':
	case 80:
		if (arrow[0].getX() == 250 && arrow[0].getY() == 280)
			arrow[0].setX(255), arrow[0].setY(340);
		else if (arrow[0].getX() == 255 && arrow[0].getY() == 340)
			arrow[0].setX(250), arrow[0].setY(400);
		break;
	case 'W':
	case 'w':
	case 72:
		if (arrow[0].getX() == 250 && arrow[0].getY() == 400)
			arrow[0].setX(255), arrow[0].setY(340);
		else if (arrow[0].getX() == 255 && arrow[0].getY() == 340)
			arrow[0].setX(250), arrow[0].setY(280);
		break;
	case 13:
		if (arrow[0].getX() == 250 && arrow[0].getY() == 280)
			return false;
		else if (arrow[0].getX() == 255 && arrow[0].getY() == 340) {
			arrow[1].setX(260), arrow[1].setY(100);
			set(arrow,num);
		}
		else if (arrow[0].getX() == 250 && arrow[0].getY() == 400) {
			int n;
			n = MessageBox(GetHWnd(), "Do you want to exit?", "hacker snake", MB_OKCANCEL);
			if (n == IDOK)
				exit(0);
			else if (n == IDCANCEL);
		}
		break;
	case 27:
		int n;
		n = MessageBox(GetHWnd(), "Do you want to exit?", "hacker snake", MB_OKCANCEL);
		if (n == IDOK)
			exit(0);
		else if (n == IDCANCEL)
			break;
	default:break;
	}
	return true;
}

void Display::set(Cube arrow[4], Number& num) {
	while (1) {
		BeginBatchDraw();
		cleardevice();
		settextcolor(num.getColor());
		settextstyle(25, 0, _T("黑体"));
		outtextxy(285, 100, "COLOR");
		outtextxy(270, 200, "DIFFICULTY");
		outtextxy(285, 300, "RETURN");
		settextstyle(14, 0, _T("黑体"));
		switch (num.getSpeed()) {
		case 50:
			outtextxy(500, 450, "DIFFICULTY:HARD");
			break;
		case 100:
			outtextxy(500, 450, "DIFFICULTY:NORMAL");
			break;
		case 150:
			outtextxy(500, 450, "DIFFICULTY:EASY");
			break;
		}
		settextstyle(25, 0, _T("黑体"));
		outtextxy(arrow[1].getX(), arrow[1].getY(), "->");
		EndBatchDraw();
		if (!chose2(arrow,num))return;
	}
}

bool Display::chose2(Cube arrow[4], Number& num) {
	switch (_getch()) {
	case 'S':
	case 's':
	case 80:
		if (arrow[1].getX() == 260 && arrow[1].getY() == 100)
			arrow[1].setX(245), arrow[1].setY(200);
		else if (arrow[1].getX() == 245 && arrow[1].getY() == 200)
			arrow[1].setX(260), arrow[1].setY(300);
		break;
	case 'W':
	case 'w':
	case 72:
		if (arrow[1].getX() == 260 && arrow[1].getY() == 300)
			arrow[1].setX(245), arrow[1].setY(200);
		else if (arrow[1].getX() == 245 && arrow[1].getY() == 200)
			arrow[1].setX(260), arrow[1].setY(100);
		break;
	case 13:
		if (arrow[1].getX() == 260 && arrow[1].getY() == 100) {
			arrow[2].setX(270), arrow[2].setY(80);
			colorband(arrow,num);
		}
		else if (arrow[1].getX() == 245 && arrow[1].getY() == 200) {
			arrow[3].setX(260), arrow[3].setY(100);
			difficultyband(arrow,num);
		}
		else if (arrow[1].getX() == 260 && arrow[1].getY() == 300)
			return false;
		break;
	case 27:
		return false;
	default:break;
	}
	return true;
}

void Display::colorband(Cube arrow[4], Number& num) {
	while (1) {
		BeginBatchDraw();
		cleardevice();
		settextcolor(num.getColor());
		settextstyle(25, 0, _T("黑体"));
		outtextxy(295, 80, "RED");
		outtextxy(290, 150, "BLUE");
		outtextxy(285, 220, "GREEN");
		outtextxy(280, 290, "YELLOW");
		outtextxy(285, 360, "RETURN");
		settextstyle(14, 0, _T("黑体"));
		switch (num.getSpeed()) {
		case 50:
			outtextxy(500, 450, "DIFFICULTY:HARD");
			break;
		case 100:
			outtextxy(500, 450, "DIFFICULTY:NORMAL");
			break;
		case 150:
			outtextxy(500, 450, "DIFFICULTY:EASY");
			break;
		}
		settextstyle(25, 0, _T("黑体"));
		outtextxy(arrow[2].getX(), arrow[2].getY(), "->");
		EndBatchDraw();
		if (!chose3(arrow,num))return;
	}
}

bool Display::chose3(Cube arrow[4], Number& num) {
	switch (_getch()) {
	case 'S':
	case 's':
	case 80:
		if (arrow[2].getX() == 270 && arrow[2].getY() == 80)
			arrow[2].setX(265), arrow[2].setY(150);
		else if (arrow[2].getX() == 265 && arrow[2].getY() == 150)
			arrow[2].setX(260), arrow[2].setY(220);
		else if (arrow[2].getX() == 260 && arrow[2].getY() == 220)
			arrow[2].setX(250), arrow[2].setY(290);
		else if (arrow[2].getX() == 250 && arrow[2].getY() == 290)
			arrow[2].setX(260), arrow[2].setY(360);
		break;
	case 'W':
	case 'w':
	case 72:
		if (arrow[2].getX() == 260 && arrow[2].getY() == 360)
			arrow[2].setX(250), arrow[2].setY(290);
		else if (arrow[2].getX() == 250 && arrow[2].getY() == 290)
			arrow[2].setX(260), arrow[2].setY(220);
		else if (arrow[2].getX() == 260 && arrow[2].getY() == 220)
			arrow[2].setX(265), arrow[2].setY(150);
		else if (arrow[2].getX() == 265 && arrow[2].getY() == 150)
			arrow[2].setX(270), arrow[2].setY(80);
		break;
	case 13:
		if (arrow[2].getX() == 270 && arrow[2].getY() == 80)
			num.setColor(RGB(255, 0, 0));
		else if (arrow[2].getX() == 265 && arrow[2].getY() == 150)
			num.setColor(RGB(0, 255, 255));
		else if (arrow[2].getX() == 260 && arrow[2].getY() == 220)
			num.setColor(RGB(0, 255, 0));
		else if (arrow[2].getX() == 250 && arrow[2].getY() == 290)
			num.setColor(RGB(255, 255, 0));
		else if (arrow[2].getX() == 260 && arrow[2].getY() == 360)
			return false;
		break;
	case 27:
		return false;
	default:break;
	}
	return true;
}

void Display::difficultyband(Cube arrow[4], Number& num) {
	while (1) {
		BeginBatchDraw();
		cleardevice();
		settextcolor(num.getColor());
		settextstyle(25, 0, _T("黑体"));
		outtextxy(290, 100, "EASY");
		outtextxy(280, 170, "NORMAL");
		outtextxy(290, 240, "HARD");
		outtextxy(285, 310, "RETURN");
		settextstyle(14, 0, _T("黑体"));
		switch (num.getSpeed()) {
		case 50:
			outtextxy(500, 450, "DIFFICULTY:HARD");
			break;
		case 100:
			outtextxy(500, 450, "DIFFICULTY:NORMAL");
			break;
		case 150:
			outtextxy(500, 450, "DIFFICULTY:EASY");
			break;
		}
		settextstyle(25, 0, _T("黑体"));
		outtextxy(arrow[3].getX(), arrow[3].getY(), "->");
		EndBatchDraw();
		if (!chose4(arrow,num))return;
	}
}

bool Display::chose4(Cube arrow[4], Number& num) {
	switch (_getch()) {
	case 'S':
	case 's':
	case 80:
		if (arrow[3].getX() == 260 && arrow[3].getY() == 100)
			arrow[3].setX(255), arrow[3].setY(170);
		else if (arrow[3].getX() == 255 && arrow[3].getY() == 170)
			arrow[3].setX(260), arrow[3].setY(240);
		else if (arrow[3].getX() == 260 && arrow[3].getY() == 240)
			arrow[3].setX(260), arrow[3].setY(310);
		break;
	case 'W':
	case 'w':
	case 72:
		if (arrow[3].getX() == 260 && arrow[3].getY() == 310)
			arrow[3].setX(260), arrow[3].setY(240);
		else if (arrow[3].getX() == 260 && arrow[3].getY() == 240)
			arrow[3].setX(255), arrow[3].setY(170);
		else if (arrow[3].getX() == 255 && arrow[3].getY() == 170)
			arrow[3].setX(260), arrow[3].setY(100);
		break;
	case 13:
		if (arrow[3].getX() == 260 && arrow[3].getY() == 100)
			num.setSpeed(150);
		else if (arrow[3].getX() == 255 && arrow[3].getY() == 170)
			num.setSpeed(100);
		else if (arrow[3].getX() == 260 && arrow[3].getY() == 240)
			num.setSpeed(50);
		else if (arrow[3].getX() == 260 && arrow[3].getY() == 310)
			return false;
		break;
	case 27:
		return false;
	default:break;
	}
	return true;
}

void Display::end(Number& num) {
	while (1) {
		BeginBatchDraw();
		cleardevice();
		settextcolor(num.getColor());
		settextstyle(65, 25, _T("黑体"));
		outtextxy(200, 200, "GAME OVER");
		EndBatchDraw();
		switch (_getch()) {
		case 13:
		case 32:
		case 27:return;
		default:break;
		}
	}
}
