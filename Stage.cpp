#include"Stage.h"
#include"General.h"
#include"ActionField.h"
#include"ScaffoldMaker.h"

Stage::Stage(int _stageNum)
	:stageNum(_stageNum),scroll(0)
{
	SetFontSize(15);
}

void Stage::Update() {
	static CActionField field(stageNum);
	static CScaffoldMaker maker;
	
	DrawBack(field.RightEdge());
	if (stageNum == TUTORIAL) {

	}
	else {
		if (!field.MenuOpening()) {
			maker.Update();
		}
		else {
			maker.OnlyDraw();
		}
		field.Update(scroll);
		if (field.MeGotCoin()) {
			maker.AddCoin();
		}
		if (!field.MenuOpening()) {
			Scroll();
			if (maker.DrawFinished()) {
				field.Make(maker.DrawnSpotX(), maker.DrawnSpotY(), maker.DrawnType(), scroll);
			}
		}
	}
	
}

///////////////private関数////////////////////////
void Stage::Scroll() {
	static CMouse mouse;
	static float a;
	a += mouse.Wheel(1) * 50.0;
	if (a>50) {
		scroll += 50;
		a = 0;
	}
	else if (a<-50) {
		scroll -= 50;
		a = 0;
	}
	if (scroll<0) {
		scroll = 0;
	}
}

void Stage::DrawBack(int rightEdge) {
	static int backGraph = LoadGraph("noseResource/main_back.png");
	DrawGraph(0, 0, backGraph, true);
	///////////ぐりっど////////////////////////
	for (int i = 0; i <= rightEdge * 50; i += 50) {
		DrawLine(i - scroll, 0, i - scroll, WINDOW_HEIGHT, BLUE);
	}
	for (int j = 0; j < WINDOW_HEIGHT; j += 50) {
		DrawLine(0, j, WINDOW_WIDTH, j, BLUE);
	}
	//////////////////////////////////////////
}