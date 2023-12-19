#include "pch.h"
#include "Picture.h"
#include "GLFWCode/OpenGLPicture.h"

vv::Picture::Picture(const std::string& PictureFile)
{
#ifdef VIVIDVERSE_MSCPP
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(PictureFile)};
#elif VIVIDVERSE_APPLE
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(PictureFile) };
#elif VIVIDVERSE_LINUX
	mImplementation = std::unique_ptr<PictureImplementation>{ new OpenGLPicture(PictureFile) };
#endif
}

void vv::Picture::Bind()
{
	mImplementation->Bind();
}

int vv::Picture::GetWidth()const
{
	return mImplementation->GetWidth();
	/*return 0;*/
}

int vv::Picture::GetHeight()const
{
	return mImplementation->GetHeight();
	//return 0;
}

void vv::Picture::operator=(const std::string& PictureFile)
{
	mImplementation->operator=(PictureFile);
}
