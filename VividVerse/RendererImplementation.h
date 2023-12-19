#pragma once
#pragma once
#include"pch.h"
#include "Utilities.h"
#include"Picture.h"
namespace vv {
	class VIVIDVERSE_API RendererImplementation {
	public:
		virtual void Init() = 0;
		virtual void Draw(int x, int y, Picture& pic) = 0;
		virtual void Clear() = 0;
		virtual ~RendererImplementation() {};
	};
}