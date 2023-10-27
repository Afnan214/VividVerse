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
		while (mShouldContinue) {
			OnUpdate();
		}
	}
	template<typename T>
	void VividVerseApp<T>::OnUpdate()
	{
	}
}