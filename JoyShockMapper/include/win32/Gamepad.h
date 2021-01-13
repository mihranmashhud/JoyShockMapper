#pragma once

#include "JoyShockMapper.h"


struct _VIGEM_TARGET_T;

class Gamepad
{
public:
	using TargetUpdate = function<void(void*)>;

	class Update
	{
	public:
		Update(Gamepad &gamepad);
		~Update();

		void setButton(ButtonID btn, bool pressed);
		void setLeftStick(float x, float y);
		void setRightStick(float x, float y);
		void setLeftTrigger(float);
		void setRightTrigger(float);
		void send();
	private:
		unique_ptr<XINPUT_GAMEPAD> _state;
		TargetUpdate _targetUpdate;
	};

	Gamepad();
	virtual ~Gamepad();

	bool isInitialized(std::string *errorMsg = nullptr);

	TargetUpdate getUpdater();

private:
	std::string _errorMsg;
	_VIGEM_TARGET_T *_gamepad;
};