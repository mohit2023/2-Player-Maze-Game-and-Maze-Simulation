#pragma once

#include "Game.h"

class TimerComponent{
public:
	TimerComponent(int);
	~TimerComponent();
	
	void Update(int);
	void Render();
	int timeRemaining();
private:
	int timeLimit;
	int start;
	int timerValue;
};
