/*
*	Author: Silence
*	Description: Lord help me
*
*	Arguments:
*	0: _vehicle		<OBJECT> - Vehicle you want to run on
*	Return Value:
*	<BOOL> - false/true
*/

// # isn't being used

params ["_vehicle"];

_allTurrets = allturrets [_vehicle, true];
_allTurrets deleteAt 0;
_allTurrets = count _allTurrets;
hint str _allTurrets;
	
if ( _allTurrets != 0 && ([_vehicle] call uscg_jayhawk_fnc_canCloseDoor) ) then {
	player action ["moveToCargo", _vehicle, 1];
};