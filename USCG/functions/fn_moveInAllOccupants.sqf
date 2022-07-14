params ["_vehicle"];

{
	_x setPos getPos vxf_vehicle;
	_x moveInCargo [vxf_vehicle, 1, true];
	_x assignAsCargo vxf_vehicle;
} forEach crew _vehicle;
titleText ["Crew Of Hook Is Secure!","PLAIN DOWN"];

if (hasDeployedStretcher) then {
	{
		_x setPos getPos vxf_vehicle;
		_x moveInCargo [vxf_vehicle, 1, true];
		_x assignAsCargo vxf_vehicle;
	} forEach crew stretcher_hook;
	titleText ["Crew Of Hook Is Secure!","PLAIN DOWN"];
};

if (hasDeployedBasket) then {
	{
		_x setPos getPos vxf_vehicle;
		_x moveInCargo [vxf_vehicle, 1, true];
		_x assignAsCargo vxf_vehicle;
	} forEach crew basket_hook;
	titleText ["Crew Of Hook Is Secure!","PLAIN DOWN"];
};