/*
*	Author: Silence
*	Description: Checks if basket is in vehicle or not
*
*	Arguments:
*	0: _vehicle		<OBJECT> - Vehicle you want to run on
*	Return Value:
*	<BOOL> - false/true
*/

params ["_vehicle"];

_basket = _vehicle getVariable "jayhawkHasBasket";

if (_vehicle animationPhase "basket" != 1) then {
	basketPhase = true;
} else {
	basketPhase = false;
};

basketPhase