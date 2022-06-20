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

[hook] call uscg_mod_fnc_deleteHook;

[vxf_vehicle, ["Door_RB", 0]] remoteExec ["animateDoor"];
[vxf_vehicle, ["stretcher", 0]] remoteExec ["animate"];
[vxf_vehicle, ["basket", 0]] remoteExec ["animate"];

for "_i" from 1 to 6 do {
	[vxf_vehicle, [_i, true]] remoteExec ["lockCargo"];
};