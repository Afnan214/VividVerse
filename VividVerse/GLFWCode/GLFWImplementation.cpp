#include "pch.h"
#include "GLFWImplementation.h"
namespace vv
{
	GLFWImplementation::GLFWImplementation()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
	void GLFWImplementation::Create(const std::string& name, int width, int height)
	{
		mWindow = glfwCreateWindow(width, height, "Game_AE", NULL, NULL);
		if (mWindow == NULL)
		{
			std::cout << "failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(mWindow);

		glfwSetWindowUserPointer(mWindow, &mCallbacks);

		glfwSetWindowPosCallback(mWindow, [](GLFWwindow* window, int xpos, int ypos) {
			Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
			callbacks->setWindowPos(xpos, ypos);
			});

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int keycode, int scancode, int action, int mods) {
			if (action == GLFW_REPEAT)
			{
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyRepeated e{ keycode };
				callbacks->keyRepeatedFunc(e);
			}
			else if (action == GLFW_PRESS)
			{
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyPressed e{ keycode };
				callbacks->keyPressedFunc(e);
			}
			else if (action == GLFW_RELEASE)
			{
				Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };

				KeyReleased e{ keycode };
				callbacks->keyReleasedFunc(e);
			}
			});
		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
			Callbacks* callbacks{ (Callbacks*)glfwGetWindowUserPointer(window) };
			callbacks->windowCloseFunc();
			});
	}
	int GLFWImplementation::GetHeight() const
	{
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}
	int GLFWImplementation::GetWidth() const
	{
		int width{ 0 }, height{ 0 };
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}
	void GLFWImplementation::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}
	void GLFWImplementation::PollEvents()
	{
		glfwPollEvents();
	}
	void GLFWImplementation::SetKeyPressedCallback(std::function<void(const KeyPressed&)>& callbackFunc)
	{
		mCallbacks.keyPressedFunc = callbackFunc;
	}
	void GLFWImplementation::SetKeyReleasedCallback(std::function<void(const KeyReleased&)>& callbackFunc)
	{
		mCallbacks.keyReleasedFunc = callbackFunc;
	}
	void GLFWImplementation::SetKeyRepeatedCallback(std::function<void(const KeyRepeated&)>& callbackFunc)
	{
		mCallbacks.keyRepeatedFunc = callbackFunc;
	}
	void GLFWImplementation::SetWindowPosCallback(std::function<void(int& xpos, int& ypos )>& callbackFunc)
	{
		mCallbacks.setWindowPos = callbackFunc;
	}
	void GLFWImplementation::SetWindowCloseCallback(std::function<void()>& callbackFunc)
	{
		mCallbacks.windowCloseFunc = callbackFunc;
	}
}