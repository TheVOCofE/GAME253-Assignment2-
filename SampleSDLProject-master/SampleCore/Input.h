#pragma once

#include "System.h"
namespace core {
	class Input : public System
	{
		bool quitRequested;
		bool m_leftPressed = false;
		bool m_rightPressed = false;
		bool m_downPressed = false;
		bool m_upPressed = false;
		bool m_1Pressed = false;
	public:
		Input();
		~Input();

		bool Init() override;
		void Update() override;
		void Draw() const override;
		bool Shutdown() override;
		inline bool IsLeftPressed() const { return m_leftPressed;  }
		inline bool IsUpPressed() const { return m_upPressed; }
		inline bool IsDownPressed() const { return m_downPressed; }
		inline bool IsRightPressed() const { return m_rightPressed; }
		inline bool Is1Pressed() const { return m_1Pressed; }
		System* make_system(SystemType type);

		inline bool QuitRequested() const { return quitRequested; }
	};
}
