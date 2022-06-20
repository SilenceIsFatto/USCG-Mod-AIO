// Don't mind the confusing name, the functions for spawning actual hooks are in fn_helicopterInit.sqf.

_index = lbCurSel 2200;
_hook = lbData [2200, _index];

if ("jayhawk" in typeOf vehicle player) then {

	switch (_hook) do 
	{
		case "USCG_RescueBasket": {[] call uscg_jayhawkrescue_fnc_deployBasket};
	
		case "USCG_Stretcher": {[] call uscg_jayhawkrescue_fnc_deployStretcher};
		
		case "vtx_hook": {[] call uscg_jayhawkrescue_fnc_deployHook};
	};

};