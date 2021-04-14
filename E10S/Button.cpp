#include "Button.h"
#include "Mouse.h"
vector<Button*> buttons;// ��ť����
extern Mouse mouse;
// �ж�(x,y)�Ƿ��ڰ�ťb��
bool isPosInBtn(Button* b, int x, int y) {
	if (!b) return false;
	return x > b->x &&
		x < b->x + b->w &&
		y > b->y &&
		y < b->y + b->h;
}

// ��ť����
void ButtonPress(Button* b, int x, int y) {
	if (!b) return;
	if (isPosInBtn(b, x, y))b->isPressed = true;
}

void ButtonsPress(int x, int y) {
	for (Button* b : buttons)ButtonPress(b, x, y);
}

// ��ť�ɿ�
void ButtonRelease(Button* b, int x, int y) {
	if (!b) return;
	if (isPosInBtn(b, mouse.xpress, mouse.ypress) &&
		isPosInBtn(b, x, y)) {// ��ʼ��ͽ����㶼Ҫ�ڰ�ť��
		if (b->callbackFunction) {// �ص��������� �����ص�����
			b->callbackFunction();
		}
	}
	b->isPressed = false;
}

void ButtonsRelease(int x, int y) {
	for (Button* b : buttons)ButtonRelease(b, x, y);
}

// ��ť��ͣ
void ButtonPassive(Button* b, int x, int y) {
	if (!b)return;
	if (isPosInBtn(b, x, y)) {
		if (!b->isHighlighted) {
			b->isHighlighted = true;
			glutPostRedisplay();
		}
	}
	else if (b->isHighlighted) {
		b->isHighlighted = false;
		glutPostRedisplay();
	}
}

void ButtonsPassive(int x, int y) {
	for (Button* b : buttons)ButtonPassive(b, x, y);
}

// ����
void addText(void* font, char* text, int x, int y) {
	glRasterPos2i(x, y);

	while (*text != '\0') {
		glutBitmapCharacter(font, *text);
		++text;
	}
}

// ��ť����
void ButtonDraw(Button* b) {
	if (!b)return;

	// ��ť������ɫ
	if (b->isHighlighted) glColor3f(0.7f, 0.7f, 0.8f);
	else glColor3f(0.6f, 0.6f, 0.6f);

	// ��ť����
	glBegin(GL_QUADS); {
		glVertex2i(b->x, b->y);
		glVertex2i(b->x, b->y + b->h);
		glVertex2i(b->x + b->w, b->y + b->h);
		glVertex2i(b->x + b->w, b->y);
	} glEnd();

	// ����
	glLineWidth(3);

	// ���ϱ���
	if (b->isPressed) glColor3f(0.4f, 0.4f, 0.4f);//���µ���ɫ
	else glColor3f(0.8f, 0.8f, 0.8f);//�ͷŵ���ɫ 

	glBegin(GL_LINE_STRIP); {
		glVertex2i(b->x + b->w, b->y);
		glVertex2i(b->x, b->y);
		glVertex2i(b->x, b->y + b->h);
	}glEnd();

	// �ҡ��±���
	if (b->isPressed) glColor3f(0.8f, 0.8f, 0.8f);
	else glColor3f(0.4f, 0.4f, 0.4f);

	glBegin(GL_LINE_STRIP); {
		glVertex2i(b->x, b->y + b->h);
		glVertex2i(b->x + b->w, b->y + b->h);
		glVertex2i(b->x + b->w, b->y);
	}glEnd();

	glLineWidth(1);

	// ������������
	int textx = b->x + (b->w - glutBitmapLength(b->font, (const unsigned char*)b->text)) / 2;
	int texty = b->y + (b->h + 10) / 2;

	// ��ť����ʱ������Ч��
	if (b->isPressed) {
		textx += 2;
		texty += 2;
	}

	//�߹�ʱ������Ч��
	if (b->isHighlighted) {
		glColor3f(0, 0, 0);
		addText(b->font, b->text, textx, texty);
		textx--;
		texty--;
	}

	glColor3f(1, 1, 1);
	addText(b->font, b->text, textx, texty);
}

void ButtonsDraw() {
	for (Button* b : buttons)ButtonDraw(b);
}