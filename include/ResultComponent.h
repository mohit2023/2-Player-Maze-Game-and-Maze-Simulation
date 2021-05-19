#pragma once

#include "Game.h"

class ResultComponent{
public:
	ResultComponent(vector<vector<vector<int>>>&);
	~ResultComponent();
	
	void Render();
private:
	int score1;
	int score2;
	int winner;
};
