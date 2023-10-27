#include"pch.h"
#include "VividVerseApp.h"

namespace vv
{
	template<typename T>
	VividVerseApp<T>::VividVerseApp()
	{
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
		mWindow.Create("Game AE", 1000, 800);
		while (mShouldContinue) {
			OnUpdate();

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}

	}
	template<typename T>
	void VividVerseApp<T>::OnUpdate()
	{
	}
}