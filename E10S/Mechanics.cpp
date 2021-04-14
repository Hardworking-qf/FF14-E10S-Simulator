#include "Mechanics.h"
extern Player player;
extern Boss boss;

void (*DrawMechanics)(void);
// ǰ��
Rect FrontBack() {
	srand(clock());
	boss.ATK_DIRE = rand() % 2*2;
	boss.FACE_DIRE = rand() % 4;
	boss.SHADOW_DIRE = rand() % 4;
	DrawMechanics = []() {
		DrawShadow(Vector2Df{ .5,.5 }, boss.SHADOW_DIRE, true);
		DrawBoss(boss.FACE_DIRE, boss.ATK_DIRE);
	};
	return Rect{ {},{} };
}

// ���ҵ�
Rect LeftRight() {
	srand(clock());
	boss.ATK_DIRE = rand() % 2 * 2+1;
	boss.FACE_DIRE = rand() % 4;
	boss.SHADOW_DIRE = rand() % 4;
	DrawMechanics = []() {
		DrawShadow(Vector2Df{ .5,.5 }, boss.SHADOW_DIRE, true);
		DrawBoss(boss.FACE_DIRE, boss.ATK_DIRE);
	};
	return Rect{ {},{} };
}

// ��Ӱ��
Rect PlaceShadow() {
	srand(clock());
	boss.ATK_DIRE = rand() % 2 * 2 + 1;
	boss.FACE_DIRE = rand() % 4;
	player.SHADOW_DIRE = rand() % 4;
	DrawMechanics = []() {
		DrawShadow(player.pos, player.SHADOW_DIRE);
		DrawBoss(boss.FACE_DIRE, boss.ATK_DIRE);
	};
	return Rect{ {},{} };
}