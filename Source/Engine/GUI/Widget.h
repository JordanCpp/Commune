#ifndef _Engine_GUI_Widget_h_
#define _Engine_GUI_Widget_h_

#include "../Graphics/Canvas.h"
#include <vector>
#include <functional>

namespace GUI
{
	class Widget
	{
	public:
		enum
		{
			Normal,
			Hover,
			Down
		};
		Widget(Graphics::Canvas* canvas, Graphics::Point pos, Graphics::Point size);
		virtual ~Widget();
		void On();
		void Off();
		bool Visible();
		virtual void Draw() = 0;
		std::function<void(Graphics::Point pos)> Click;
		std::function<void(size_t key)> Keyboard;
		Graphics::Canvas* View();
		size_t State();
		void State(size_t value);
		Widget* Parent();
		void Parent(Widget* source);
		std::vector<Widget*>& Widgets();
		Graphics::Rect& Area();
		Widget* Contains(Graphics::Point pos);
		void Attach(Widget* source);
	private:
		bool _Visible;
		size_t _State;
		Widget* _Parent;
		Graphics::Canvas* _Canvas;
		std::vector<Widget*> _Widgets;
		Graphics::Rect _Area;
	};
}

#endif