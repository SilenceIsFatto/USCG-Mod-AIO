params ["_vehicle"];

_basket = _vehicle getVariable "jayhawkHasBasket";

if (_vehicle animationPhase "basket" != 1) then {
	basketPhase = true;
} else {
	basketPhase = false;
};

basketPhase