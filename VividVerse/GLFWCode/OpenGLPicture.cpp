#include "pch.h"
#include "OpenGLPicture.h"
#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include"stb_image.h"
vv::OpenGLPicture::OpenGLPicture(const std::string& PictureFile)
{
	//Textures
	/*std::string pictureString{ ReadWholeFile(picFile) };*/
	const char* pictureSource = PictureFile.c_str();
	VV_LOG(pictureSource);

	glGenTextures(1, &mTexture);
	glBindTexture(GL_TEXTURE_2D, mTexture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	/*int width, height, nrChannels;*/
	int nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load( pictureSource, &width, &height, &nrChannels, 0);
 	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

	}
	else
	{
		VV_ERROR("Failed to load a picture from the file!!!")
	}

	//this->height = height;
	//this->width = width;
	//this->nrChannels = nrChannels;
	stbi_image_free(data);
}

vv::OpenGLPicture::OpenGLPicture(std::string&& PictureFile)
{
	const char* pictureSource = PictureFile.c_str();
	//VV_LOG(pictureSource);
	glGenTextures(1, &mTexture);
	//glBindTexture(GL_TEXTURE_2D, mTexture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	/*int width, height, nrChannels;*/
	int nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(pictureSource, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		VV_ERROR("Failed to load a picture from the file!!!")
	}
;
	stbi_image_free(data);
}

void vv::OpenGLPicture::Bind()
{
	
	glBindTexture(GL_TEXTURE_2D, mTexture);
	
	//glUseProgram(mTexture);
}

int vv::OpenGLPicture::GetWidth()const 
{
	return width;
}

int vv::OpenGLPicture::GetHeight()const
{
	return height;
}

void vv::OpenGLPicture::operator=(const std::string& PictureFile)
{
	//Textures
	/*std::string pictureString{ ReadWholeFile(picFile) };*/
	const char* pictureSource = PictureFile.c_str();

	glGenTextures(1, &mTexture);
	glBindTexture(GL_TEXTURE_2D, mTexture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	/*int width, height, nrChannels;*/
	int nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(pictureSource, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		VV_ERROR("Failed to load a picture from the file!!!")
	}
	//this->height = height;
	//this->width = width;
	//this->nrChannels = nrChannels;
	stbi_image_free(data);
}

vv::OpenGLPicture::~OpenGLPicture()
{
	glDeleteTextures(1, &mTexture);
}
//std::string vv::OpenGLPicture::ReadWholeFile(const std::string& fileName)
//{
//	std::ifstream inputFile{ fileName };
//
//	std::string result;
//	std::string nextLine;
//
//	while (inputFile)
//	{
//		std::getline(inputFile, nextLine);
//		if (!inputFile)
//			break;
//		result += nextLine;
//		result += "\n";
//	}
//
//	return result;
//}
//
//std::string vv::OpenGLPicture::ReadWholeFile(std::string&& fileName)
//{
//	std::ifstream inputFile{ move(fileName) };
//
//	std::string result;
//	std::string nextLine;
//
//	while (inputFile)
//	{
//		std::getline(inputFile, nextLine);
//		if (!inputFile)
//			break;
//		result += nextLine;
//		result += "\n";
//	}
//
//	return result;
//}
