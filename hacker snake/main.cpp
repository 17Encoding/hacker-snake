#include "main.h"

//������
int main() {
	initgraph(COL * 10, ROW * 10 + 20);

	//����ѭ��
	while (1) {
		arrow[0].setX(250), arrow[0].setY(280);
		Display::start(arrow,num);
		Option::init(wall, snake, food, num);

		//��Ϸѭ��
		while (1) {
			t2 = GetTickCount();
			//������Ϸ����
			Option::DrawMap(wall, snake, food, num);

			//�����̰��µ�ʱ�򣬸ı��ߵ�ǰ������
			if (_kbhit()) {
				if (!Option::ChangeDir(num))break;
			}

			//���ﵽʱ���������Զ���ǰ
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