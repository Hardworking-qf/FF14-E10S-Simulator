#pragma once
#include "Mouse.h"
#include <GL/glut.h>
#include <vector>
using namespace std;
typedef void (*ButtonCallback)();

struct Button {
	int x;// x����
	int y;// y����
	int w;// ��ť��
	int h;// ��ť��
	char* text;// ����
	void* font;// ����
	ButtonCallback callbackFunction;// �ص�����
	bool isPressed;// �Ƿ񱻰���
	bool isHighlighted;// �Ƿ�߹⣨�����ͣ�ڰ�ť�ϣ�
};

// �ж�(x,y)�Ƿ��ڰ�ťb��
bool isPosInBtn(Button* b, int x, int y);

// ��ť����
void ButtonPress(Button* b, int x, int y);
void ButtonsPress(int x, int y);

// ��ť�ɿ�
void ButtonRelease(Button* b, int x, int y);
void ButtonsRelease(int x, int y);

// ��ť��ͣ
void ButtonPassive(Button* b, int x, int y);
void ButtonsPassive(int x, int y);

// ����
void addText(void* font, char* text, int x, int y);

// ��ť����
void ButtonDraw(Button* b);
void ButtonsDraw();