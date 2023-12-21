#include "MyGame.h"

MyGame::MyGame()
{
	
		SetKeyPressedCallback([this](const vv::KeyPressed& e) {OnKeyPress(e); });
		SetKeyReleasedCallback([this](const vv::KeyReleased& e) {OnKeyRelease(e); });
		width = getWidth();
		height = getHeight();
	
}

MyGame::~MyGame()
{
	for (auto taco : tacos)
	{
		delete taco;
	}
	for (auto grape : grapes)
	{
		delete grape;
	}
}

void MyGame::OnUpdate()
{
	Draw(*faces[CurrentCharacter]);
	DrawNumber();
	DrawGrape();
	DrawTaco();
	Draw(toilet);
	checkCollisions();
	updateEmojiPosition();
	setPositions();
	Time();
	mFrameCounter++;
}

void MyGame::DrawTaco()
{
	if (!tacoExists)
	{
		MakeTaco();
	}
	else if (tacoExists and !isTacoEaten)
	{
		Draw(*tacos[eaten]);
	}
	
	
}

void MyGame::MakeTaco()
{
	vv::Unit *taco = new vv::Unit { "../Assets/Pictures/taco.png", getRandom(800),getRandom(600)};
	tacos.push_back(taco);
	tacoExists = true;
}


void MyGame::DrawGrape()
{
	if (!grapeExists)
	{
		MakeGrape();
	}
	else if (grapes.size() > 0 and !isGrapeEaten)
	{
		Draw(*grapes[eaten]);
	}
}

void MyGame::MakeGrape()
{
	vv::Unit* grape = new vv::Unit{ "../Assets/Pictures/grape.png",getRandom(800),getRandom(600) };
	grapes.push_back(grape);
	grapeExists = true;
}

void MyGame::checkCollisions()
{
	if (tacoExists)
	{
		tacoCollision();
	}
	if (grapeExists) {
		grapeCollision();
	}
	toiletCollision();
}

void MyGame::tacoCollision()
{
	if (vv::UnitsOverlap(*faces[CurrentCharacter], *tacos[eaten]))
	{
		if (!isTacoEaten)
		{
			if (isGrapeEaten) {
				CurrentCharacter = 2;
			}
			else {
				CurrentCharacter = 1;
			}
			isTacoEaten = true;
		}

	}
}

void MyGame::grapeCollision()
{
	if (vv::UnitsOverlap(*faces[CurrentCharacter], *grapes[eaten]))
	{
		if (!isGrapeEaten)
		{
			if (isTacoEaten) {
				CurrentCharacter = 2;
			}
			else {
				CurrentCharacter = 1;
			}
			isGrapeEaten = true;
		}
	}
}

void MyGame::toiletCollision()
{
	if (vv::UnitsOverlap(*faces[CurrentCharacter], toilet))
	{
		if (isGrapeEaten && isTacoEaten)
		{
			std::cout << "reset" << std::endl;
			grapeExists = false;
			tacoExists = false;
			isGrapeEaten = false;
			isTacoEaten = false;
			CurrentCharacter = 0;
			MakeGrape();
			MakeTaco();
			eaten++;
		}
		
	}
}

void MyGame::setPositions()
{
	for (auto face : faces)
	{
		face->SetCoords(xpos, ypos);
	}
}

void MyGame::DrawNumber()
{
	if (numberIndex < numbers.size())
	{
		Draw(*numbers[numberIndex]);
	}
	else
	{
		Draw(*numbers[numberIndex-1]);
		numberIndex = 0;
	}
}

void MyGame::Time()
{
	if (numberIndex < numbers.size()) {
		if (mFrameCounter % 60 == 0) {
			timer--;
			numberIndex++;
		}
	}

}

void MyGame::updateEmojiPosition()
{
	switch (mState)
	{
	case MyGame::State::move:
		switch (mDirection)
		{
		case MyGame::Direction::up:

			faces[CurrentCharacter]->UpdateYCoord(10);
			ypos += 10;
			break;
		case MyGame::Direction::left:
			faces[CurrentCharacter]->UpdateXCoord(-10);
			xpos -= 10;
			break;
		case MyGame::Direction::down:
			faces[CurrentCharacter]->UpdateYCoord(-10);
			ypos -= 10;
			break;
		case MyGame::Direction::right:
			faces[CurrentCharacter]->UpdateXCoord(10);
			xpos += 10;
			break;
		case MyGame::Direction::topLeft:
			faces[CurrentCharacter]->UpdateYCoord(10);
			faces[CurrentCharacter]->UpdateXCoord(-10);
			xpos -= 10;
			ypos += 10;
			break;
		case MyGame::Direction::topRight:
			faces[CurrentCharacter]->UpdateXCoord(10);
			faces[CurrentCharacter]->UpdateYCoord(10);
			xpos += 10;
			ypos += 10;
			break;
		case MyGame::Direction::botLeft:
			faces[CurrentCharacter]->UpdateYCoord(-10);
			faces[CurrentCharacter]->UpdateXCoord(-10);
			xpos -= 10;
			ypos -= 10;
			break;
		case MyGame::Direction::botRight:
			faces[CurrentCharacter]->UpdateXCoord(10);
			faces[CurrentCharacter]->UpdateYCoord(-10);
			xpos += 10;
			ypos -= 10;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void MyGame::OnKeyPress(const vv::KeyPressed& e)
{
	mState = State::move;
	if (mDirection == Direction::none) {
		if (e.GetKeyCode() == VIVIDVERSE_KEY_RIGHT)
		{
			mDirection = Direction::right;
			isRightDown = true;
		}
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_LEFT)
		{
			mDirection = Direction::left;
			isLeftDown = true;
		}

		else if (e.GetKeyCode() == VIVIDVERSE_KEY_UP)
		{
			mDirection = Direction::up;
			isUpDown = true;
		}

		else if (e.GetKeyCode() == VIVIDVERSE_KEY_DOWN)
		{
			mDirection = Direction::down;
			isDownDown = true;
		}
	}
	else if (isUpDown)
	{
		if (e.GetKeyCode() == VIVIDVERSE_KEY_RIGHT)
		{
			mDirection = Direction::topRight;
			isRightDown = true;
		}
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_LEFT)
		{
			mDirection = Direction::topLeft;
			isLeftDown = true;

		}
	}
	else if (isDownDown)
	{
		if (e.GetKeyCode() == VIVIDVERSE_KEY_RIGHT)
		{
			mDirection = Direction::botRight;
			isRightDown = true;
		}
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_LEFT)
		{
			mDirection = Direction::botLeft;
			isLeftDown = true;
		}
	}
	else if (isRightDown)
	{
		if (e.GetKeyCode() == VIVIDVERSE_KEY_UP)
		{
			mDirection = Direction::topRight;
			isUpDown = true;
		}
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_DOWN)
		{
			mDirection = Direction::botRight;
			isDownDown = true;
		}
	}
	else if (isLeftDown)
	{
		if (e.GetKeyCode() == VIVIDVERSE_KEY_UP)
		{
			mDirection = Direction::topLeft;
			isUpDown = true;
		}
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_DOWN)
		{
			mDirection = Direction::botLeft;
			isDownDown = true;
		}
	}
}

void MyGame::OnKeyRelease(const vv::KeyReleased& e)
{

	if (mDirection == Direction::topRight) {
		if (e.GetKeyCode() == VIVIDVERSE_KEY_RIGHT)
		{
			mDirection = Direction::up;
			isRightDown = false;
		}

		else if (e.GetKeyCode() == VIVIDVERSE_KEY_UP)
		{
			mDirection = Direction::right;
			isUpDown = false;
		}
	}
	else if (mDirection == Direction::topLeft)
	{
		if (e.GetKeyCode() == VIVIDVERSE_KEY_LEFT)
		{
			mDirection = Direction::up;
			isLeftDown = false;
		}
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_UP)
		{
			mDirection = Direction::left;
			isUpDown = false;
		}
	}
	else if (mDirection == Direction::botRight)
	{
		if (e.GetKeyCode() == VIVIDVERSE_KEY_DOWN)
		{
			mDirection = Direction::right;
			isDownDown = false;
		}
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_RIGHT)
		{
			mDirection = Direction::down;
			isRightDown = false;
		}
	}
	else if (mDirection == Direction::botLeft)
	{
		if (e.GetKeyCode() == VIVIDVERSE_KEY_LEFT)
		{
			mDirection = Direction::down;
			isLeftDown = false;
		}
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_DOWN)
		{
			mDirection = Direction::left;
			isDownDown = false;
		}
	}
	else
	{
		mState = State::stop;
		if (e.GetKeyCode() == VIVIDVERSE_KEY_RIGHT)
		{
			mDirection = Direction::none;
			isRightDown = false;
		}
		else if (e.GetKeyCode() == VIVIDVERSE_KEY_LEFT)
		{
			mDirection = Direction::none;
			isLeftDown = false;
		}

		else if (e.GetKeyCode() == VIVIDVERSE_KEY_UP)
		{
			mDirection = Direction::none;
			isUpDown = false;
		}

		else if (e.GetKeyCode() == VIVIDVERSE_KEY_DOWN)
		{
			mDirection = Direction::none;
			isDownDown = false;
		}
	}
}

int MyGame::getRandom(const int range)
{
	int random = std::rand() % (range+1);
//	std::cout << random<<std::endl;
	return random;
}
