#pragma once
#include"pch.h"
#include"Utilities.h"

namespace vv {
	class VIVIDVERSE_API PictureImplementation {
	public:
		virtual void Bind() = 0;
		virtual int GetWidth()const = 0;
		virtual int GetHeight()const = 0;
		virtual ~PictureImplementation() {};
		virtual void operator=(const std::string& pictureFile) = 0;

	};
}