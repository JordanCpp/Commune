#include "Texture2D.h"
#include "../Formats/StbImage.h"

using namespace Arc::Graphics;

Texture2D::Texture2D(const std::string& path):
	_Id(0),
	_Width(0),
	_Height(0),
	_Channels(0),
	_Image(nullptr)
{
	_Image = StbImage::stbi_load(path.c_str(), &_Width, &_Height, &_Channels, 0);
	GL::glGenTextures(1, &_Id);

	GL::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	GL::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	GL::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	GL::glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	GL::glTexImage2D(GL_TEXTURE_2D, 0, 3, _Width, _Height, 0, GL_RGB, GL_UNSIGNED_BYTE, _Image);
}

Texture2D::~Texture2D()
{
	StbImage::stbi_image_free(_Image);
	GL::glDeleteTextures(1, &_Id);
}