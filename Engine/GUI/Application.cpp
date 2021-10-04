#include "Application.h"
#include <cassert>

using namespace GUI;

Application::Application(Graphics::Canvas* CanvasSource):
	Widget(CanvasSource, Graphics::Point(0, 0), Graphics::Point(CanvasSource->Width(), CanvasSource->Height())),
	_Form(nullptr),
	_Current(nullptr)
{
}

void Application::Attach(size_t id, Form* form)
{
	auto ptr = _Forms.find(id);

	assert(ptr == _Forms.end());

	_Forms.emplace(id, form);
}


void Application::Activate(size_t id)
{
	auto ptr = _Forms.find(id);

	assert(ptr != _Forms.end());

	_Form = ptr->second;
}

void Application::Handler(SDL_Event& report)
{
	if (report.type == SDL_KEYDOWN && _Form->Keyboard != nullptr)
	{
		_Form->Keyboard(report.key.keysym.sym);
	}

	if (report.type == SDL_MOUSEMOTION)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		if (_Current != nullptr)
		{
			_Current->State(Widget::Normal);
		}

		_Current = _Form->Contains(Graphics::Point(x, y));

		if (_Current != nullptr)
		{
			_Current->State(Widget::Hover);
		}
	}

	if (report.type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		if (_Current != nullptr)
		{
			_Current->State(Widget::Normal);
		}

		_Current = _Form->Contains(Graphics::Point(x, y));

		if (_Current != nullptr)
		{
			_Current->State(Widget::Down);

			if (_Current->Click != nullptr)
			{
				_Current->Click();
			}
		}
	}
}

void Application::Draw()
{
	assert(_Form != nullptr);

	_Form->Draw();
}