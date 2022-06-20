params ["_vehicle"];

_stretcher = _vehicle getVariable "jayhawkHasStretcher";

if (_vehicle animationPhase "stretcher" != 1) then {
	stretcherPhase = true;
} else {
	stretcherPhase = false;
};

stretcherPhase