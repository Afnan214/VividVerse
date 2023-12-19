#pragma once
#include"PictureImplementation.h"

namespace vv {
	class OpenGLPicture : public PictureImplementation {
	public:
		OpenGLPicture(const std::string& PictureFile);
		OpenGLPicture(std::string&& PictureFile);
		virtual void Bind() override;
		virtual int GetWidth()const override;
		virtual int GetHeight()const override;
		virtual void operator=(const std::string& PictureFile) override;
		~OpenGLPicture();
	private:
		unsigned int mTexture;
		int width;
		int height;
	};
}