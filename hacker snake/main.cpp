#include "main.h"

//主程序
int main() {
	initgraph(COL * 10, ROW * 10 + 20);

	//程序循环
	while (1) {
		arrow[0].setX(250), arrow[0].setY(280);
		Display::start(arrow,num);
		Option::init(wall, snake, food, num);

		//游戏循环
		while (1) {
			t2 = GetTickCount();
			//绘制游戏界面
			Option::DrawMap(wall, snake, food, num);

			//当键盘按下的时候，改变蛇的前进方向
			if (_kbhit()) {
				if (!Option::ChangeDir(num))break;
			}

			//若达到时间间隔，则自动向前
			if (t2 - t1 > num.getSpeed()) {
				if (!Option::move(wall, snake, food, num))break;
				t1 = t2;
			}
		}
		Display::end(num);
	}
	closegraph();
	return 0;
}