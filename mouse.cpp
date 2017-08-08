#include"mouse.h"

CMouse::CMouse()
:x(0),y(0),
tempX(0),tempY(0)
{
	SetRange(0,0,0,0);
}

CMouse::CMouse(int _x1,int _y1,int _x2,int _y2)
	:CMouse()
{
	SetRange(_x1, _y1, _x2, _y2);
}

void CMouse::SetRange(int _x1,int _y1,int _x2,int _y2){
	rangeX1 = _x1;
	rangeY1 = _y1;
	rangeX2 = _x2;
	rangeY2 = _y2;
}

bool CMouse::RightReleased(){
	static bool flag=false;
	if( flag==false && GetMouseInput() &(MOUSE_INPUT_RIGHT != 0) ){
		flag = true;
	}
	if( flag == true && !(GetMouseInput() &(MOUSE_INPUT_RIGHT != 0) ) ){
		flag = false;
		return true;
	}

	return false;
}
bool CMouse::LeftReleased(){
	static bool flag = false;

	if(flag == false && GetMouseInput()&(MOUSE_INPUT_LEFT != 0) ){
		flag = true;
	}
	if(flag==true && !(GetMouseInput()&(MOUSE_INPUT_LEFT != 0)) ){
		flag = false;
		return true;
	}
	return false;
}

void CMouse::SetTemp(){
	GetMousePoint(&x,&y);
	static bool flag = false;
	if( Insided() ){
		if(flag == false ){//押されてないとき
			if( GetMouseInput()&(MOUSE_INPUT_LEFT != 0) ){
				flag =true;
			}
			tempX=x;
			tempY=y;
		}else{
			if( !(GetMouseInput() &(MOUSE_INPUT_LEFT!=0) ) ){
				flag =false;
			}
		}
	}

}

int CMouse::ChangeX(){
	GetMousePoint(&x,&y);
	return x-tempX;
}
int CMouse::ChangeY(){
	GetMousePoint(&x,&y);
	return y-tempY;
}

bool CMouse::LeftPushing(){	
	if (GetMouseInput()&(MOUSE_INPUT_LEFT != 0)) {
		return true;
	}
	return false;
}

bool CMouse::Insided(){
	GetMousePoint(&x,&y);
	if(rangeX1 < x && x < rangeX2 && rangeY1 < y &&  y < rangeY2){
		return true;
	}
	return false;
}