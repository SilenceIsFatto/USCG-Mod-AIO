class CfgPatches
{
	class USCG_Stretcher
	{
		units[] = {"USCG_Stretcher"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Boat_F"};
	};
};

class CfgMovesBasic 
{
	class Actions;
};

//External Ref from CBA XEH:
class CBA_Extended_EventHandlers;

class cfgVehicles 
{
	class Boat_F;
	class B_Boat_Transport_01_F;
	class Rubber_duck_base_F;
	class EventHandlers;
	class USCG_Stretcher: Rubber_duck_base_F
	{
		class EventHandlers : EventHandlers 
		{
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
			init = "(_this select 0) lockCargo [0, true]; (_this select 0) lockCargo [1, true]; (_this select 0) lockCargo [2, true]; (_this select 0) lockCargo [3, true]; (_this select 0) lockCargo [4, false]; (_this select 0) lockCargo [5, true];";
		};
		scope = 2;
		scopeCurator = 2;
		side = 1;
		ace_dragging_canCarry = 1;
		ace_dragging_canDrag = 1;
		ace_dragging_carryDirection = 90;
		ace_dragging_carryPosition[] = {0,1,0};
		ace_dragging_dragDirection = 90;
		ace_dragging_dragPosition[] = {0,1,0};
		faction = "USCG";
		displayName = "Stretcher";
		model = "\USCG_Stretcher\stretcherv3";
		picture = "\USCG_Stretcher\UI\stretcher_ca.paa";
		Icon = "\USCG_Stretcher\UI\stretcher_ca.paa";
		airCapacity = 0;
		hasCommander = 0;
		hasDriver = 0;
		hasGunner = 0;
		cargoAction[] = {"jayhawk_stretcher"}; /// the same of all the crew
		getInAction 		= ""; 		/// how does driver look while getting in
		getOutAction 		= ""; 		/// and out
		cargoGetInAction[] 	= {""}; 	/// and the same for the rest, if the array has fewer members than the count of crew, the last one is used for the rest
		cargoGetOutAction[] = {""}; 	/// that means all use the same in this case
		destrType = "DestructNo";
		transportSoldier = 1; /// number of cargo except driver
		ejectDeadDriver = true;			/// use this if you don't have proper dead pose for the driver, it will eject him from boat if he dies
		simulation = "shipx";
		maxSpeed = 75;
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4", "SlingLoadCargo5"};
	};
};
