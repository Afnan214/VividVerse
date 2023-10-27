#pragma once
#include"Utilities.h"

namespace vv {
	template<typename T>
	class VIVIDVERSE_API VividVerseApp {
	public:

		static void Init();

		static void RunInterface();
		void Run();
		virtual void OnUpdate();

		friend typename T;
	private:
		VividVerseApp();
		inline static VividVerseApp* sInstance{ nullptr };
		bool mShouldContinue{ true };
	};

}
#include"VividVerseApp.cpp"