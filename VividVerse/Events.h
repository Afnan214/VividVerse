#pragma once
#include"Utilities.h"
namespace vv
{
	class VIVIDVERSE_API KeyPressed
	{
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class VIVIDVERSE_API KeyReleased
	{
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};
	class VIVIDVERSE_API WindowClosed {

	};
}