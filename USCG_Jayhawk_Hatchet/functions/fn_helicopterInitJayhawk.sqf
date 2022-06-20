/*

~DEPRECATED~

mst_fnc_deployHelicopterHookJayhawk = {  
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
};

mst_fnc_deployHelicopterStretcherWithHookJayhawk = {
    call mst_fnc_deployHelicopterHookH60;
    stretcher_hook = "MS_Stretcher_V3" createVehicle position player;
    stretcher_hook setPos (vehicle player modelToWorld [3,2,-1]);
    myRope = ropeCreate [hook, [0, 0, 0], stretcher_hook, "SlingLoadCargo1", 1, [], ["RopeEnd", [0,0,0]]];
    myRope = ropeCreate [hook, [0, 0, 0], stretcher_hook, "SlingLoadCargo2", 1, [], ["RopeEnd", [0,0,0]]];
    myRope = ropeCreate [hook, [0, 0, 0], stretcher_hook, "SlingLoadCargo3", 1, [], ["RopeEnd", [0,0,0]]];
    myRope = ropeCreate [hook, [0, 0, 0], stretcher_hook, "SlingLoadCargo4", 1, [], ["RopeEnd", [0,0,0]]];
    hasDeployedStretcher = true;
    publicVariable "hasDeployedStretcher";
    publicVariable "stretcher_hook";
    [vehicle player] call mst_fnc_handleRopeDetach;
};

*/