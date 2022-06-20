/*
*	Author: Silence
*	Description: Initialises the jayhawk when it is spawned
*
*	Arguments:
*	0: _vehicle			<OBJECT> - Vehicle you want to run on
*	1: _basket			<BOOL> - true/false
*	2: _stretcher		<BOOL> - true/false
*	Return Value:
*	None
*/


params ["_vehicle", "_basket", "_stretcher", "_folded"];

if (_folded) then {
	_vehicle lock true;
	
	_vehicle animateSource ["jayhawk_fold", 1, true];
	
	_vehicle setVariable ["jayhawkIsFolded", true];
} else {
	_vehicle setVariable ["jayhawkIsFolded", false];
	
	_vehicle animateSource ["jayhawk_fold", 0, true];

	['pilot_door', _vehicle] call uscg_jayhawk_fnc_openDoor, [_vehicle, false] remoteExec ["lockDriver"];

	['copilot_door', _vehicle] call uscg_jayhawk_fnc_openDoor, [_vehicle, [[0], false]] remoteExec ["lockTurret"];

	_handle = [_vehicle] spawn {
		params ["_vehicle"];
		
		for "_i" from 0 to 7 do {
			[_vehicle, [_i, true]] remoteExec ["lockCargo"];
			sleep 0.1;
		};
		
	};

	if (_basket) then {
		_vehicle setVariable ["jayhawkHasBasket", true];
	} else {
		_vehicle setVariable ["jayhawkHasBasket", false];
		[_vehicle, ['basket', 1]] remoteExec ["animate"];
	};

	if (_stretcher) then {
		_vehicle setVariable ["jayhawkHasStretcher", true];
	} else {
		_vehicle setVariable ["jayhawkHasStretcher", false];
		[_vehicle, ['stretcher', 1]] remoteExec ["animate"];
	};

};