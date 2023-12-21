#pragma once
#include"pch.h"
#include"Utilities.h"
#include"PictureImplementation.h"

namespace vv {
	class VIVIDVERSE_API Picture {
	public:
		//Picture();
		Picture(const std::string& PictureFile);
		void Bind();
		int GetWidth() const;
		int GetHeight() const;
		void operator=(const std::string& PictureFile);

	private:
		std::unique_ptr<PictureImplementation> mImplementation;
	};
}