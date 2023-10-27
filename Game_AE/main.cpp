#include"VividVerse.h"
#include<iostream>
class MyGame : public vv::VividVerseApp<MyGame>
{
public:
	virtual void OnUpdate() override
	{
		std::cout << "Beaver running" << std::endl;
	}
};

VIVIDVERSE_APPLICATION_START(MyGame);

