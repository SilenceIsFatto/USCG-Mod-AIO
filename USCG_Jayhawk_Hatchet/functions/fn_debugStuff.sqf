/*
*	Author: Silence
*	Description: Debug code, draws an icon around every hatchet framework action
*
*	Arguments:
*	0: _vehicle 		<OBJECT> - Vehicle you want to run this on
*	1: _vxf		<STRING> - ["vxf_copilot", "vxf_driver", "vxf_cargo"]
*	Return Value:
*	None
*/


params ["_vehicle", "_vxf"];

_allInteractionPoints = (configFile >> "cfgVehicles" >> typeOf _vehicle >> _vxf >> "interaction") call BIS_fnc_getCfgSubClasses;
hint str _allInteractionPoints;
positions = [];
names = [];

{
	_allPositions = (getArray(configFile >> "cfgVehicles" >> typeOf _vehicle >> _vxf >> "interaction" >> _x >> "position"));
	_allNames = (getText(configFile >> "cfgVehicles" >> typeOf _vehicle >> _vxf >> "interaction" >> _x >> "label"));
	positions append [_allPositions];
	names append [_allNames];
} forEach _allInteractionPoints;

hint str positions;

canDraw = true;

switch (_vxf) do 
{
	case "vxf_driver" : 
	{
		_drawIcon_Pilot = addMissionEventHandler ["Draw3D",{
			if (vehicle player != player && canDraw) then {
				{
					_name = (names select _forEachIndex);
					if ("Door" in _name) then {} else {
						drawIcon3D [
						  "a3\ui_f\data\Map\Markers\Military\dot_ca.paa",
						  [0,1,0,1],
						  vehicle player modelToWorldVisual (positions select _forEachIndex),
						  2.5,2.5,0,
						  _name
						];
					};
				} forEach positions;
			};
		}];
	};
	
	case "vxf_copilot" : 
	{
		_drawIcon_CoPilot = addMissionEventHandler ["Draw3D",{
			if (vehicle player != player && canDraw) then {
				{
					_name = (names select _forEachIndex);
					if ("Door" in _name) then {} else {
						drawIcon3D [
						  "a3\ui_f\data\Map\Markers\Military\dot_ca.paa",
						  [1,0,0,1],
						  vehicle player modelToWorldVisual (positions select _forEachIndex),
						  2.5,2.5,0,
						  _name
						];
					};
				} forEach positions;
			};
		}];
	};
	
	case "vxf_cargo":
	{
		_drawIcon_Cargo = addMissionEventHandler ["Draw3D",{
			if (vehicle player != player && canDraw) then {
				{
					_name = (names select _forEachIndex);
					if ("Side" in _name) then {} else {
						drawIcon3D [
						  "a3\ui_f\data\Map\Markers\Military\dot_ca.paa",
						  [0,0,1,1],
						  vehicle player modelToWorldVisual (positions select _forEachIndex),
						  2.5,2.5,0,
						  _name
						];
					};
				} forEach positions;
			};
		}];
	};
};