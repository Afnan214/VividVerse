#include"VividVerse.h"
#include<iostream>
class MyGame : public vv::VividVerseApp<MyGame>
{
public:
	MyGame() {
		SetKeyPressedCallback([this](const vv::KeyPressed& e) {OnKeyPress(e); });
	}
	virtual void OnUpdate() override
	{
		//std::cout << "Beaver running" << std::endl;
		Draw(mUnit);
		
	}
	void OnKeyPress(const vv::KeyPressed& e)
	{
		if (e.GetKeyCode() == VIVIDVERSE_KEY_RIGHT)
			mUnit.UpdateXCoord(50);
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_LEFT)
			mUnit.UpdateXCoord(-50);
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_UP)
			mUnit.UpdateYCoord(50);
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_DOWN)
			mUnit.UpdateYCoord(-50);
	}
private:
	//vv::Picture mPic{ "../Assets/Pictures/test.png" };
	vv::Unit mUnit{ "../Assets/Pictures/test.png", 200, 200 };

	int x{ 100 };
	int y{ 100 };
};

VIVIDVERSE_APPLICATION_START(MyGame);

