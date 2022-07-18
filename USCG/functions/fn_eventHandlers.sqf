/*
mst_fnc_addUSCGEH = {
	params ["_AI"];
	_AI addEventHandler ["GetInMan", {
		params ["_unit", "_role", "_vehicle", "_turret"];
		if (typeOf _vehicle == "USCG_Stretcher") then {
			[_unit, "USCG_anim_stretcher"] remoteExec ["switchMove"];
		};
	}];
};

{
	[_x] call mst_fnc_addUSCGEH;
} forEach allUnits;

addMissionEventHandler ["GroupCreated", {
	params ["_group"];
	[_group] spawn
    {
        params ["_group"];
        sleep 1;
        {
            [_x] call mst_fnc_addUSCGEH;
        } foreach units _group;
    };
}];

*/

uscg_fnc_handleRopeDetach = {
	params ["_heli"];
	_heli addEventHandler ["RopeBreak",{
		params ["_object1", "_rope", "_object2"];
		{
			ropeDestroy _x;
		} forEach ropes _heli;
		deleteVehicle hook;
		hasDeployedHook = false;
		publicVariable "hasDeployedHook";
		hookDeployed = false;
		publicVariable "hookDeployed";
		_heli animateSource ['hook', 0]; // unhide hook
		if (hasDeployedStretcher) then {
			deleteVehicle stretcher_hook;
			hasDeployedStretcher = false;
			publicVariable "hasDeployedStretcher";
		};
		if (hasDeployedBasket) then {
			deleteVehicle basket_hook;
			hasDeployedBasket = false;
			publicVariable "hasDeployedBasket";
		};
	}];
};

mst_fnc_handleEject = {
	player addEventHandler ["GetOutMan", { 
		params ["_unit", "_role", "_vehicle", "_turret"];
		[_unit, "GetOutHeli_Light_01bench"] remoteExec ["switchMove"];
		_unit removeEventHandler ["GetOutMan", _thisEventHandler];
		[_unit] spawn {sleep 1.2,
			params ["_unit"];
			[_unit, "AswmPercMstpSnonWnonDnon"] remoteExec ["switchMove"];
		};
	}];
};