/*
*	Author: Silence
*	Description: Retrieves hook, and through predefined event handler takes rope and attachment with
*
*	Arguments:
*
*	Return Value:
*	None
*/


params ["_vehicle"]; // no real point to this

if (vxf_vehicle getVariable "jayhawkHasStretcher") then {
	[vxf_vehicle, ["stretcher", 0]] remoteExec ["animate"];
	[vxf_vehicle, [6, false]] remoteExec ["lockCargo"];
	if !(isNil "stretcherUnit") then {
		stretcherUnit moveInAny vxf_vehicle;
		stretcherUnit moveInCargo [vxf_vehicle, 6];
	};
};

if (vxf_vehicle getVariable "jayhawkHasBasket") then {
	[vxf_vehicle, ["basket", 0]] remoteExec ["animate"];
};

[hook] call uscg_mod_fnc_deleteHook;