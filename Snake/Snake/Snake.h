#pragma once
class Snake
{
public:
	int width; //������ ����
	int height; //������ ����
	int tailX[100], tailY[100]; //� �������� ��������� ������ ������
	int nTail; //������ ������ ������
	//�����������, �������� ��������� �������� ������
	Snake()
	{
		width = 20;
		height = 15;
		nTail = 0;
	}
};
