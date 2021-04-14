#include "Base.h"

int winw = 1080, winh = 600;
Boss boss;
Player player{ { 0.5,0.5 } };

void DrawPlatform() {
	glColor3d(0.67, 0.67, 0.67);
	DrawRect(Vector2Df{ 0,0 }, Vector2Df{ 1,1 });
}

void DrawBoss(int FACE_DIRE, int ATK_DIRE) {
	float r = 0.05;
	int RED_DIRE = (FACE_DIRE + ATK_DIRE) % 4;
	float red_deg = RED_DIRE * PI / 2,
		faceNegdeg = FACE_DIRE * PI / 2 + PI;
	float quad = PI / 4;
	glColor3f(ATK_DIRE==FRONT ? 1 : 0, 0, 0);
	DrawFan(Vector2Df{
		FACE_DIRE == EAST ? 1.0F : FACE_DIRE == WEST ? -1.0F : 0.0F,
		FACE_DIRE == NORTH ? 1.0F : FACE_DIRE == SOUTH ? -1.0F : 0.0F
		}*r * 1.2 + Vector2Df{ .5,.5 },
		r, faceNegdeg - quad, faceNegdeg + quad, 1);
	glColor3f(1, 0, 0);
	DrawFan(Vector2Df{ .5,.5 }, r, red_deg - quad, red_deg + quad);
	glColor3f(0, 0, 0);
	DrawFan(Vector2Df{ .5,.5 }, r, red_deg + quad, red_deg - quad + 2 * PI);
	glColor3d(0.67, 0.67, 0.67);
	DrawFan(Vector2Df{ .5,.5 }, r*.8, 0,2*PI);
	
}
void DrawPlayer() {
	glColor3f(0, 1, 0);
	DrawFan(player.pos, 0.02, 0, 2 * PI);

}
void DrawShadow(Vector2Df pos, int DIRE, bool large) {
	float d = large ? .2 : .05;
	float deg15 = PI / 12;
	float shadowDeg = DIRE * PI / 2;
	glColor3f(.3, .3, .3);
	DrawFan(pos, d * 2, shadowDeg - deg15, shadowDeg + deg15, 1);
}
