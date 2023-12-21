#pragma once
#include "../WindowImplementation.h"
#include "GLFW/glfw3.h"

namespace vv
{
	class GLFWImplementation :public WindowImplementation
	{
	public:
		GLFWImplementation();

		void Create(const std::string& name, int width, int height) override;
		int GetHeight() const override;
		int GetWidth() const override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
		virtual void SetKeyPressedCallback(std::function<void(const KeyPressed&)>& callbackFunc) override;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleased&)>& callbackFunc) override;
		virtual void SetKeyRepeatedCallback(std::function<void(const KeyRepeated&)>& callbackFunc) override;
		virtual void SetWindowPosCallback(std::function<void(int& xpos, int &ypos)>& callbackFunc) override;
		virtual void SetWindowCloseCallback(std::function<void()>& callbackFunc)override;
	private:
		struct Callbacks
		{
			std::function<void(const KeyPressed&)> keyPressedFunc{ [](const KeyPressed&) {} };
			std::function<void(const KeyReleased&)> keyReleasedFunc{ [](const KeyReleased&) {} };
			std::function<void(const KeyRepeated&)> keyRepeatedFunc{ [](const KeyRepeated&) {} };
			std::function<void(int& xpos, int&ypos)> setWindowPos{ [](int& xpos, int& ypos) {} };
			std::function<void()> windowCloseFunc{ []() {} };
		}mCallbacks;
		int xPos;
		int yPos;
		GLFWwindow* mWindow;
	};
}