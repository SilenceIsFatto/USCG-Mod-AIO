mst_fnc_detachStretcher = {
	{
		ropeDestroy _x;
	} forEach ropes hook;
	hasDetachedStretcher = true;
	publicVariable "hasDetachedStretcher";
};

mst_fnc_attachStretcher = {
	_myRope = ropeCreate [hook, [0, 0, 0.05], stretcher_hook, "SlingLoadCargo1", 1, [], ["RopeEnd", [0,0,0]]];
	_myRope = ropeCreate [hook, [0, 0, 0.05], stretcher_hook, "SlingLoadCargo2", 1, [], ["RopeEnd", [0,0,0]]];
	_myRope = ropeCreate [hook, [0, 0, 0.05], stretcher_hook, "SlingLoadCargo3", 1, [], ["RopeEnd", [0,0,0]]];
	_myRope = ropeCreate [hook, [0, 0, 0.05], stretcher_hook, "SlingLoadCargo4", 1, [], ["RopeEnd", [0,0,0]]];
	hasDetachedStretcher = false;
	publicVariable "hasDetachedStretcher";
};