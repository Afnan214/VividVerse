#pragma once

#if VV_DEBUG==2
	#define VV_ERROR(x) std::cout<<x<<std::endl;
	#define VV_LOG(x) std::cout<<x<<std::endl;
#elif VV_DEBUG==1
	#define VV_ERROR(x) std::cout<<x<<std::endl;
	#define VV_LOG(x)
#else
	#define VV_ERROR(x)
	#define BV_LOG(x)
#endif

#ifdef VIVIDVERSE_MSCPP
	#ifdef VIVIDVERSE_LIB
		#define VIVIDVERSE_API __declspec(dllexport)
	#else
		#define VIVIDVERSE_API __declspec(dllimport)
	#endif
#else
	#define	VIVIDVERSE_API
#endif

#define VIVIDVERSE_APPLICATION_START(ClassName) \
int main()\
{\
	ClassName::Init();\
	ClassName::RunInterface();\
	return(0);\
}