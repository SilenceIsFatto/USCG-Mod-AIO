/*
*	Author: Silence
*	Description: deploys stretcher
*
*	Arguments:
*
*	Return Value:
*	None
*/


params ["_vehicle"]; // no real point to this

[vehicle player] call uscg_jayhawkrescue_fnc_deployHook;

stretcher_hook = "USCG_Stretcher" createVehicle position vehicle player;
stretcher_hook setPos (vehicle player modelToWorld [3,2,-1]);

stretcher_hook addItemCargoGlobal ["firstAidKit", 10];
stretcher_hook addItemCargoGlobal ["Medikit", 10];

myRope = ropeCreate [hook, [0, 0, 0.05], stretcher_hook, "SlingLoadCargo1", 1, [], ["RopeEnd", [0,0,0]]];
myRope = ropeCreate [hook, [0, 0, 0.05], stretcher_hook, "SlingLoadCargo2", 1, [], ["RopeEnd", [0,0,0]]];
myRope = ropeCreate [hook, [0, 0, 0.05], stretcher_hook, "SlingLoadCargo3", 1, [], ["RopeEnd", [0,0,0]]];
myRope = ropeCreate [hook, [0, 0, 0.05], stretcher_hook, "SlingLoadCargo4", 1, [], ["RopeEnd", [0,0,0]]];

hasDeployedStretcher = true;
publicVariable "hasDeployedStretcher";
publicVariable "stretcher_hook";

[vehicle player] call mst_fnc_handleRopeDetach;