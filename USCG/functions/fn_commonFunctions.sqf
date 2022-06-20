// Variables (Defaults)
hasDeployedBasket = false;
hasDeployedStretcher = false;
hasDeployedHook = false;
hasDetachedStretcher = false;

_fnc_makeCarrayble = { 
    params ["_object"]; 
	[_object, true, [0,1.5,0.5], 0 ] call ace_dragging_fnc_setDraggable;
	[_object, true, [0,1.5,0.5], 0] call ace_dragging_fnc_setCarryable;
};
["USCG_Stretcher", "init", _fnc_makeCarrayble, true, [], true] call CBA_fnc_addClassEventHandler; 

_allowedHooks =
[
	"USCG_RescueBasket", 
	"USCG_Stretcher",
	"vtx_hook"
];

mst_fnc_spawnHookSelectionMenu = {
	createDialog "uscg_hookSelection";
	[] call USCG_mod_fnc_handleDialog;
};

mst_fnc_moveIntoBasket = {
	uscgheli = vehicle player;
	player moveInAny hook;
};

mst_fnc_moveToHelicopter = {
	player moveInAny uscgheli;
};