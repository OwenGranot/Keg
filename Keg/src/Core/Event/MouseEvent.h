#pragma once

#include "Event.h"
#include "Core/MouseCodes.h"
#include <utility>

namespace Keg
{
	class MouseEvent : public Event
	{
	public:
		double GetXPosition() { return m_XPosition; }
		double GetYPosition() { return m_YPosition; }

		std::pair<double, double> GetPosition() { return std::make_pair(m_XPosition, m_YPosition ); }

	protected:
		MouseEvent(double x, double y) : m_XPosition(x), m_YPosition(y) {}

		double m_XPosition;
		double m_YPosition;
	};

	class CursorMovedEvent : public MouseEvent
	{
	public:
		CursorMovedEvent(double x, double y) : MouseEvent(x, y) {}
		
		EVENT_STATIC_TYPE("CursorMoved");
	};

	class MousePressedEvent : public MouseEvent
	{
	public:
		MousePressedEvent(double x, double y, MouseCode button) : MouseEvent(x, y), m_Button(button) {}

		MouseCode GetButton() { return m_Button;  }
		
		EVENT_STATIC_TYPE("MousePressed");

	private: 
		MouseCode m_Button;
	};

	class MouseReleasedEvent : public MouseEvent
	{
	public:
		MouseReleasedEvent(double x, double y, MouseCode button) : MouseEvent(x, y), m_Button(button) {}
		MouseCode GetButton() { return m_Button; }

		EVENT_STATIC_TYPE("MouseReleased");

	private:
		MouseCode m_Button;
	};

	class MouseScrolledEvent : public MouseEvent
	{
	public:
		MouseScrolledEvent(double x, double y, double xOff, double yOff) : MouseEvent(x, y), m_XOffset(xOff), m_YOffset(yOff) {}

		double GetXOffset() { return m_XOffset; }
		double GetYOffset() { return m_YOffset; }

		std::pair<double, double> GetOffset() { return std::make_pair(m_XOffset, m_YOffset); }

		EVENT_STATIC_TYPE("MouseScrolled");

	private:
		double m_XOffset;
		double m_YOffset;
	};
	
	class CursorEnteredEvent : public MouseEvent
	{
	public:
		CursorEnteredEvent(double x, double y) : MouseEvent(x, y) {}

		EVENT_STATIC_TYPE("CursorEntered");
	};

	class CursorLeftEvent : public MouseEvent
	{
	public:
		CursorLeftEvent(double x, double y) : MouseEvent(x, y) {}

		EVENT_STATIC_TYPE("CursorLeft");
	};

}