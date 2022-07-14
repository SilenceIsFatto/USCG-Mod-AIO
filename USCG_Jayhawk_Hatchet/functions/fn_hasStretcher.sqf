/*
*	Author: Silence
*	Description: Checks if stretcher is in vehicle or not
*
*	Arguments:
*	0: _vehicle		<OBJECT> - Vehicle you want to run on
*	Return Value:
*	<BOOL> - false/true
*/

params ["_vehicle"];

_stretcher = _vehicle getVariable "jayhawkHasStretcher";

if (_vehicle animationPhase "stretcher" != 1) then {
	stretcherPhase = true;
} else {
	stretcherPhase = false;
};

stretcherPhase