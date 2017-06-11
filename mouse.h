#pragma once

#include"Dxlib.h"
#include "General.h"

class CMouse{
public:
	CMouse(int _x1,int _y1,int _x2,int _y2);//�R���X�g���N�^�Ŕ͈͂̎w����s��

	void SetRange(int _x1,int _y1,int _x2,int _y2);//�͈͂̎w��

	bool LeftReleased();
	bool RightReleased();

	void SetTemp();

	int GetChangeX();//SetTemp�Őݒ肵�����W����̕ψʂ̂w������Ԃ�
	int GetChangeY();//SetTemp�Őݒ肵�����W����̕ψʂ̂x������Ԃ�
	bool GetFlag();

private:
	bool Insided();

	bool flag;
	bool rightFlag;

	int x,y;

	int tempX,tempY;

	int rangeX1,rangeX2,rangeY1,rangeY2;

};