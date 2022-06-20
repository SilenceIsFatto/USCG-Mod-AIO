class CfgPatches
{
	class USCG_Basket
	{
		units[]={
			"USCG_RescueBasket"
		};
		weapons[]={};
		requiredAddons[]=
		{
			"A3_Boat_F"
		};
		requiredVersion=0.40000001;
	};
};

class cfgVehicles
{
	class EventHandlers;
	class Rubber_duck_base_F;
	class USCG_RescueBasket : Rubber_duck_base_F
	{
		class EventHandlers : EventHandlers
		{
			init = "(_this select 0) lockCargo [0, true]; (_this select 0) lockCargo [1, true]; (_this select 0) lockCargo [2, true]; (_this select 0) lockCargo [3, true]; (_this select 0) lockCargo [4, false]; (_this select 0) lockCargo [5, true];";
		};
		icon = "\USCG_Basket\UI\basket_ca.paa";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		cargoGetInAction[] = {"passenger_flatground_crosslegs_settlein"};
		cargoGetOutAction[] = {"GetOutLow"};
		displayName = "Rescue Basket";
		model = "\USCG_Basket\rescuebasket\rescueBasket";
		transportSoldier = 1;
		cargoAction[] = {"passenger_flatground_crosslegs"};
		armor = 999999;
		animated = 1;
		hiddenSelections[] = {};
		picture = "\USCG_Basket\UI\basket_ca.paa";
		scope = 2;
		faction = "USCG";
		side = 1;
		waterLeakiness = 0.5;
		airCapacity = 99999;
		hasCommander = 0;
		hasDriver = 0;
		hasGunner = 0;
		destrType = "DestructNo";
		ejectDeadDriver = true;			/// use this if you don't have proper dead pose for the driver, it will eject him from boat if he dies
		simulation = "shipx";
		maxSpeed = 75;
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1","SlingLoadCargo2","SlingLoadCargo3","SlingLoadCargo4"};
		class AnimationSources {};
		class HitPoints {};
		class TransportItems {};
		class Exhausts {};
		class RenderTargets {};
	};
};