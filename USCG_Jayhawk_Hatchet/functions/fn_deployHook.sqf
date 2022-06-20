/*
*	Author: Silence
*	Description: Deploys hook
*
*	Arguments:
*
*	Return Value:
*	None
*/


params ["_vehicle"]; // no real point to this

hook = "vtx_hook" createVehicle position player;  
hook setPos (vehicle player modelToWorld [3,2,-1]);

_rope = ropeCreate [vehicle player, "rope", hook, [0,0,0.2], 3];  

hasDeployedHook = true;  
publicVariable "hasDeployedHook";  
vehicle player animateSource ['ems', 1]; 
[vehicle player] call mst_fnc_handleRopeDetach;  

hookDeployed = true;  
publicVariable "hookDeployed"; 
publicVariable "hook";  