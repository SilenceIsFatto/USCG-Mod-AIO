/*
*	Author: Silence
*	Description: Checks if side door can be opened/closed
*
*	Arguments:
*	0: _vehicle		<OBJECT> - Vehicle you want to run on
*	Return Value:
*	<BOOL> - false/true
*/

params ["_vehicle"];

[_vehicle] spawn {
	params ["_vehicle"];
	{
		_index = _vehicle getCargoIndex _x;
		if (_index == 0) then {
			//hint "Can Not Close";	
			result = false;
		} else {
			//hint "Can Close";
			result = true;
		};
	} forEach crew _vehicle;
	uiSleep 0.1;
};

result