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

if (hasACE) then {
	[_vehicle] call ace_fastroping_fnc_equipFRIES;
};

_vehicle addEventHandler ["GetIn", {
	params ["_vehicle", "_role", "_unit", "_turret"];
	_seat = _vehicle getCargoIndex _unit;
	hint str _seat;
	if (_seat == 6) then {
		stretcherUnit = _unit;
	};
	hint str stretcherUnit;
}];

if (_folded) then {
	//_vehicle lock true;
	
	//_vehicle animateSource ["jayhawk_fold", 1, true];
	
	//_vehicle setVariable ["jayhawkIsFolded", true];
} else {

	_vehicle setVariable ["jayhawkIsFolded", false];
	
	//_vehicle animateSource ["jayhawk_fold", 0, true];

	['pilot_door', _vehicle] call uscg_jayhawk_fnc_closeDoor, [_vehicle, true] remoteExec ["lockDriver"];

	['copilot_door', _vehicle] call uscg_jayhawk_fnc_closeDoor, [_vehicle, [[0], true]] remoteExec ["lockTurret"];

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