#include"pch.h"
#include "VividVerseApp.h"
#include"Utilities.h"
//#include"../glad/include/glad/glad.h"
//#include"../glfw/include/GLFW/glfw3.h"
//#include"../stbi/stb_image.h"
#include"VividVerse.h"
#include"Shader.h"
#include"Picture.h"
#include"Renderer.h"

namespace vv
{
	template<typename T>
	VividVerseApp<T>::VividVerseApp()
	{
		mWindow.Create("Game AE", 2000, 1000);
		mRenderer.Init();
		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
	}
	template<typename T>
	void VividVerseApp<T>::Init()
	{
		if (sInstance == nullptr) {
			sInstance = new T;
		}
	}
	template<typename T>
	void VividVerseApp<T>::RunInterface()
	{
		sInstance->Run();
	}
	template<typename T>
	void VividVerseApp<T>::Run()
	{
		
		
		vv::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };

		//vv::Picture pic{ "../Assets/Pictures/test.png" };
		mNextFrameTime = std::chrono::steady_clock::now();

		while (mShouldContinue) {
			
			mRenderer.Clear();


			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());
			
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
		


	}
	template<typename T>
	void VividVerseApp<T>::OnUpdate()
	{
	}

	template<typename T>
	void VividVerseApp<T>::Draw(int x, int y, Picture& pic)
	{
		sInstance->mRenderer.Draw(x, y, pic);
	}
	template<typename T>
	void VividVerseApp<T>::Draw(Unit& item)
	{
		sInstance->mRenderer.Draw(item.mXPosition, item.mYPosition, item.mImage);
	}
	template<typename T>
	void VividVerseApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mWindow.SetKeyPressedCallback(callbackFunc);
	}
	template<typename T>
	void VividVerseApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}
	template<typename T>
	void VividVerseApp<T>::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		mWindow.SetWindowCloseCallback(callbackFunc);
	}
	template<typename T>
	void VividVerseApp<T>::DefaultWindowCloseHandler() {
		mShouldContinue = false;
	}

}
	