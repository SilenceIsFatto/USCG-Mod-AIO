/*
*	Author: Silence
*	Description: deploys basket
*
*	Arguments:
*
*	Return Value:
*	None
*/


params ["_vehicle"]; // no real point to this

[vehicle player] call uscg_jayhawkrescue_fnc_deployHook;

basket_hook = "USCG_RescueBasket" createVehicle position vehicle player;
basket_hook setPos (vehicle player modelToWorld [3,2,-3]);

basket_hook addItemCargoGlobal ["firstAidKit", 10];
basket_hook addItemCargoGlobal ["Medikit", 10];

myRope = ropeCreate [hook, [0, 0, 0.05], basket_hook, "SlingLoadCargo1", 1, [], ["RopeEnd", [0,0,0]]];
myRope = ropeCreate [hook, [0, 0, 0.05], basket_hook, "SlingLoadCargo2", 1, [], ["RopeEnd", [0,0,0]]];
myRope = ropeCreate [hook, [0, 0, 0.05], basket_hook, "SlingLoadCargo3", 1, [], ["RopeEnd", [0,0,0]]];
myRope = ropeCreate [hook, [0, 0, 0.05], basket_hook, "SlingLoadCargo4", 1, [], ["RopeEnd", [0,0,0]]];

hasDeployedBasket = true;
publicVariable "hasDeployedBasket";
publicVariable "basket_hook";

[vehicle player] call mst_fnc_handleRopeDetach;