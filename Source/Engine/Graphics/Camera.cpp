#include "Camera.h"

using namespace Graphics;

Camera::Camera(Graphics::Point pos, Graphics::Point size):
	_Pos(pos),
	_Size(size)
{
}

size_t Camera::PosX()
{
	return _Pos.PosX();
}

size_t Camera::PosY()
{
	return _Pos.PosY();
}

size_t Camera::Width()
{
	return _Size.PosX();
}

size_t Camera::Height()
{
	return _Size.PosY();
}

void Camera::PosX(size_t value)
{
	_Pos.PosX(value);
}

void Camera::PosY(size_t value)
{
	_Pos.PosY(value);
}

void Camera::Width(size_t value)
{
	_Size.PosX(value);
}

void Camera::Height(size_t value)
{
	_Size.PosY(value);
}