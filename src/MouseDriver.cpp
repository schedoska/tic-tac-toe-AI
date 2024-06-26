#include "MouseDriver.h"

namespace MouseDiverVariables 
{
	bool _isClicked = false;
	bool _LastClickState = false;
}

void MouseDriver::update()
{
	bool actual_state = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	if (!MouseDiverVariables::_LastClickState && actual_state)
	{
		MouseDiverVariables::_isClicked = true;
		MouseDiverVariables::_LastClickState = true;
	}
	else
	{
		MouseDiverVariables::_isClicked = false;
		MouseDiverVariables::_LastClickState = actual_state;
	}
}

bool MouseDriver::isMouseLeftClicked()
{
	return MouseDiverVariables::_isClicked;
}
