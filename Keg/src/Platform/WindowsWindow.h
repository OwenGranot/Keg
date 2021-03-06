#pragma once
#include "Window.h"
#include <GLFW/glfw3.h>

namespace Keg
{
	class WindowsWindow : public Window
	{
	public:

		WindowsWindow(const char* title = "Keg Engine", int width = 1280, int height = 720);
		// Initialization & Destruction
		virtual void Init() override;
		virtual ~WindowsWindow() override;
		virtual void Shutdown() const override;

		// Runtime handeling
		virtual void SetEventCallback(const EventCallbackFn& cb) override;
		virtual void SwapBuffers() const override;
		virtual void PollEvents() const override;
		virtual bool HasWindow() const override;
		virtual void OnUpdate() const override;
		virtual void* GetProcAddress() override;

		inline virtual int GetWidth() { return m_Data.width; }
		inline virtual int GetHeight() { return m_Data.height; }
		inline virtual double GetTime() { return glfwGetTime(); }
		virtual void SetCursorVisibility(bool& mode);
		virtual void SetWindowIcon(const char* path);

		GLFWwindow* GetWindow() { return m_Window; }
		void* GetNativeWindow() { return m_Window; }


	private:
		// This WindowData will be passed as a GLFW user pointer (for context saving)
		struct WindowData
		{
			const char* title;
			int width;
			int height;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
		GLFWwindow* m_Window;
	};
}