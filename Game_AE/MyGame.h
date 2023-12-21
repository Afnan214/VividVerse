#pragma once
#include"VividVerse.h"

class MyGame : public vv::VividVerseApp<MyGame>
{
public:
	MyGame();
	~MyGame();
	virtual void OnUpdate() override;
	void DrawTaco();
	void MakeTaco();
	void DrawGrape();
	void MakeGrape();
	void checkCollisions();
	void tacoCollision();
	void grapeCollision();
	void toiletCollision();
	void setPositions();
	void DrawNumber();
	void Time();

	void updateEmojiPosition();
	void OnKeyPress(const vv::KeyPressed& e);
	void OnKeyRelease(const vv::KeyReleased& e);
	int getRandom(const int range);
private:
	enum class Direction {up = 0, left= 1, down=2, right=3, topRight=4, topLeft=5, botRight=6, botLeft=7, none=8} mDirection=Direction::none;
	bool isLeftDown = false;
	bool isRightDown = false;
	bool isUpDown = false;
	bool isDownDown = false;
	enum class State {stop, move} mState=State::stop;
	enum class Current {smile=0, normal=1, hungry=2}mCurrent = Current::smile;
	vv::Unit toilet={ "../Assets/Pictures/toilet.png",800,600};
	vv::Unit smile={ "../Assets/Pictures/smile.png", xpos, ypos };
	vv::Unit normal={ "../Assets/Pictures/normal.png", xpos,ypos };
	vv::Unit hungry={ "../Assets/Pictures/hungry.png", xpos, ypos };
	vv::Unit taco = { "../Assets/Pictures/taco.png", getRandom(800),getRandom(600)};
	vv::Unit grape = { "../Assets/Pictures/grape.png",getRandom(800),getRandom(600)};


	std::vector<vv::Unit*> faces = {&smile, &normal, &hungry};
	std::vector<vv::Unit*> tacos = {&taco};
	std::vector<vv::Unit*> grapes = {&grape};
	int CurrentCharacter = 0;

	int eaten = 0;

	bool tacoExists = false;
	bool grapeExists = false;
	bool isTacoEaten = false;
	bool isGrapeEaten = false;

	int mFrameCounter = 0;
	vv::Unit nine = { "../Assets/Pictures/Numbers/nine.png", numPosX,numPosY };
	vv::Unit eight = { "../Assets/Pictures/Numbers/eight.png", numPosX,numPosY };
	vv::Unit seven = { "../Assets/Pictures/Numbers/seven.png", numPosX,numPosY };
	vv::Unit six = { "../Assets/Pictures/Numbers/six.png", numPosX,numPosY };
	vv::Unit five = { "../Assets/Pictures/Numbers/five.png", numPosX,numPosY };
	vv::Unit four = { "../Assets/Pictures/Numbers/four.png", numPosX,numPosY };
	vv::Unit three = { "../Assets/Pictures/Numbers/three.png", numPosX,numPosY };
	vv::Unit two = { "../Assets/Pictures/Numbers/two.png", numPosX,numPosY };
	vv::Unit one = { "../Assets/Pictures/Numbers/one.png", numPosX,numPosY };
	int numPosX = 15;
	int numPosY = 610;
	enum class Numbers {nine, eight, seven, six, five, four, three, two, one}mNumber=Numbers::nine;
	std::vector<vv::Unit*> numbers{&nine, &eight, &seven, &six, &five,&four,&three,&two,&one};
	int numberIndex = 0;
	int timer = 9;

	int width;
	int height;
	int xpos{ 200 };
	int ypos{ 200 };
};
