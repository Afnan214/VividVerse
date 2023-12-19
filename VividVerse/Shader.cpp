#include"pch.h"
#include"Shader.h"
#include"GLFWCode/OpenGLShader.h"
namespace vv {
	Shader::Shader(const std::string& vertexSFile, const std::string& framentSFFile)
	{
#ifdef VIVIDVERSE_MSCPP
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, framentSFFile)};
#elif VIVIDVERSE_APPLE
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, framentSFFile) };
#elif VIVIDVERSE_LINUX
		mImplementation = std::unique_ptr<ShaderImplementation>{ new OpenGLShader(vertexSFile, framentSFFile) };
#endif
	}

	void Shader::Bind()
	{
		mImplementation->Bind();
	}

	void Shader::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(move(uniformName), val1, val2);
	}

	void Shader::SetUniform2Ints(std::string&& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(move(uniformName), val1, val2);
	}

}