#include "pch.h"
#include "Renderer.h"
#include"GLFWCode/OpenGLRenderer.h"
vv::Renderer::Renderer()
{
#ifdef VIVIDVERSE_MSCPP
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif VIVIDVERSE_APPLE
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif VIVIDVERSE_LINUX
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
}
//#include "GLFWCode/"
void vv::Renderer::Init()
{
	mImplementation->Init();
}

void vv::Renderer::Draw(int x, int y, Picture& pic)
{
	mImplementation->Draw(x, y, pic);
}

void vv::Renderer::Clear()
{
	mImplementation->Clear();
};
