#pragma once
#include"Utilities.h"
#include"GameWindow.h"
namespace vv {
	template<typename T>
	class  VividVerseApp {
	public:

		static void Init();

		static void RunInterface();
		void Run();
		virtual void OnUpdate();

		friend typename T;
	private:
		VividVerseApp();
		inline static VividVerseApp* sInstance{ nullptr };
		GameWindow mWindow;
		bool mShouldContinue{ true };
	};

}
#include"VividVerseApp.cpp"