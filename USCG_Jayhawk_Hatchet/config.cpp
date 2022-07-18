class CfgPatches
{
	class USCG_Jayhawk_Rescue
	{
		units[] = {"Helicopter_Medium_Base"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"cba_settings"};
	};
};

class CfgFunctions
{
	class USCG_JayhawkRescue
	{
		class functions
		{
			// Deploy
			class deployHook
			{
				file="\USCG_Jayhawk_Hatchet\functions\fn_deployHook.sqf";
			};
			class deployStretcher
			{
				file="\USCG_Jayhawk_Hatchet\functions\fn_deployStretcher.sqf";
			};
			class deployBasket
			{
				file="\USCG_Jayhawk_Hatchet\functions\fn_deployBasket.sqf";
			};
			// Debug
			class debugStuff
			{
				file="\USCG_Jayhawk_Hatchet\functions\fn_debugStuff.sqf";
			};
			// Retrieve
			class retrieveHookAttachment
			{
				file="\USCG_Jayhawk_Hatchet\functions\fn_retrieveHookAttachment.sqf";
			};
			// Checks
			class hasBasket
			{
				file="\USCG_Jayhawk_Hatchet\functions\fn_hasBasket.sqf";
			};
			class hasStretcher
			{
				file="\USCG_Jayhawk_Hatchet\functions\fn_hasStretcher.sqf";
			};
			// Move
			class moveToCabin
			{
				file="\USCG_Jayhawk_Hatchet\functions\fn_moveToCabin.sqf";
			};
		};
	};
};

#include "cfgUserActions.hpp"

class cfgVehicles 
{
	class B_Heli_Transport_01_F;
	class Helicopter_Medium_Base : B_Heli_Transport_01_F
	{
		class vxf_copilot
		{
			class interaction 
			{
				/*
				*/
				class transferToCabin
				{
					condition = "";
					positionType = "coordinates";
					position[] = {0.0204315,4.4066,-1.16562};
					label = "Move Into Cabin";
					radius = 0.1;
					buttonDown = "player action ['moveToCargo', _vehicle, 1]";
				};
				class setLengthCoPilot
				{
					condition = "hasDeployedHook";
					positionType = "coordinates";
					position[] = {-0.188208,5.01798,-1.09034};
					label = "Set Rope Length";
					radius = 0.2;
					buttonDown = " createDialog 'uscg_RopeMeter' ";
				};
				class readDataCoPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "hasDeployedHook";
					positionType = "coordinates";
					position[] = {-0.154235,5.12919,-1.09263};
					label = "Read Hoist Data";
					radius = 0.2;
					buttonDown = "[player] call uscg_mod_fnc_getDataReadings";
				};
				class transferBasketHelicopter
				{
					condition = "hasDeployedHook";
					positionType = "coordinates";
					position[] = {-0.172121,4.7478,-1.11884};
					label = "Move Hoist Occupants To Helicopter";
					radius = 0.2;
					buttonDown = "[hook] call uscg_mod_fnc_moveInAllOccupants";
				};
				class openDoorCoPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "vxf_vehicle animationPhase ""CoPilot_Door"" < 0.9";
					positionType = "coordinates";
					position[] = {-1.02609,4.86841,-1.13349};
					label = "Open Door";
					radius = 0.2;
					buttonDown = "['copilot_door', vxf_vehicle] call uscg_jayhawk_fnc_openDoor, [vxf_vehicle, [[0], false]] remoteExec [""lockTurret""]";
				};
				class closeDoorCoPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "vxf_vehicle animationPhase ""CoPilot_Door"" > 0.9";
					positionType = "coordinates";
					position[] = {-1.45678,5.27944,-1.13264};
					label = "Close Door";
					radius = 0.2;
					buttonDown = "['copilot_door', vxf_vehicle] call uscg_jayhawk_fnc_closeDoor, [vxf_vehicle, [[0], true]] remoteExec [""lockTurret""]";
				};
				class openDoorPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "vxf_vehicle animationPhase ""Pilot_Door"" < 0.9";
					positionType = "coordinates";
					position[] = {1.04996,4.87261,-1.131};
					label = "Open Door";
					radius = 0.2;
					buttonDown = "['pilot_door', vxf_vehicle] call uscg_jayhawk_fnc_openDoor, [vxf_vehicle, false] remoteExec [""lockDriver""]";
				};
				class closeDoorPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "vxf_vehicle animationPhase ""Pilot_Door"" > 0.9";
					positionType = "coordinates";
					position[] = {1.53369,5.26205,-1.13927};
					label = "Close Door";
					radius = 0.2;
					buttonDown = "['pilot_door', vxf_vehicle] call uscg_jayhawk_fnc_closeDoor, [vxf_vehicle, true] remoteExec [""lockDriver""]";
				};
			};
		};
		class vxf_driver
		{
			class interaction
			{
				class openSideDoorPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "vxf_vehicle animationPhase ""Door_RB"" < 0.1";
					positionType = "coordinates";
					position[] = {0.592812,4.99083,-1.05436};
					label = "Open Side";
					radius = 0.2;
					buttonDown = "[vxf_vehicle, false] call uscg_jayhawk_fnc_sideDoor";
				};
				class closeSideDoorPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "vxf_vehicle animationPhase ""Door_RB"" > 0.1";
					positionType = "coordinates";
					position[] = {0.592812,4.99083,-1.05436};
					label = "Close Side";
					radius = 0.2;
					buttonDown = "[vxf_vehicle, false] call uscg_jayhawk_fnc_sideDoor";
				};
				class transferBasketHelicopter
				{
					condition = "hasDeployedHook";
					positionType = "coordinates";
					position[] = {0.148563,4.74821,-1.11985};
					label = "Move Hoist Occupants To Helicopter";
					radius = 0.2;
					buttonDown = "[hook] call uscg_mod_fnc_moveInAllOccupants";
				};
				class setLengthPilot
				{
					condition = "hasDeployedHook";
					positionType = "coordinates";
					position[] = {0.136798,5.01951,-1.09132};
					label = "Set Rope Length";
					radius = 0.2;
					buttonDown = " createDialog 'uscg_RopeMeter' ";
				};
				class readDataPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "hasDeployedHook";
					positionType = "coordinates";
					position[] = {0.173493,5.12669,-1.08938};
					label = "Read Hoist Data";
					radius = 0.2;
					buttonDown = "[player] call uscg_mod_fnc_getDataReadings";
				};
				class openDoorPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "vxf_vehicle animationPhase ""Pilot_Door"" < 0.9";
					positionType = "coordinates";
					position[] = {1.04996,4.87261,-1.131};
					label = "Open Door";
					radius = 0.2;
					buttonDown = "['pilot_door', vxf_vehicle] call uscg_jayhawk_fnc_openDoor, [vxf_vehicle, false] remoteExec [""lockDriver""]";
				};
				class closeDoorPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "vxf_vehicle animationPhase ""Pilot_Door"" > 0.9";
					positionType = "coordinates";
					position[] = {1.53369,5.26205,-1.13927};
					label = "Close Door";
					radius = 0.2;
					buttonDown = "['pilot_door', vxf_vehicle] call uscg_jayhawk_fnc_closeDoor, [vxf_vehicle, true] remoteExec [""lockDriver""]";
				};
				class openDoorCoPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "vxf_vehicle animationPhase ""CoPilot_Door"" < 0.9";
					positionType = "coordinates";
					position[] = {-1.02609,4.86841,-1.13349};
					label = "Open Door";
					radius = 0.2;
					buttonDown = "['copilot_door', vxf_vehicle] call uscg_jayhawk_fnc_openDoor, [vxf_vehicle, [[0], false]] remoteExec [""lockTurret""]";
				};
				class closeDoorCoPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "vxf_vehicle animationPhase ""CoPilot_Door"" > 0.9";
					positionType = "coordinates";
					position[] = {-1.45678,5.27944,-1.13264};
					label = "Close Door";
					radius = 0.2;
					buttonDown = "['copilot_door', vxf_vehicle] call uscg_jayhawk_fnc_closeDoor, [vxf_vehicle, [[0], true]] remoteExec [""lockTurret""]";
				};
			};
		};
		class vxf_cargo
		{
			class interaction
			{
				class transferToCockpit
				{
					condition = "isNull (vxf_vehicle turretUnit [0])";
					positionType = "coordinates";
					position[] = {0.0204315,4.4066,-1.16562};
					label = "Move Into Cockpit";
					radius = 0.1;
					buttonDown = "player action ['moveToTurret', vxf_vehicle, [0]]";
				};
				class transferToCargo
				{
					condition = "([vxf_vehicle] call uscg_jayhawk_fnc_canCloseDoor == false) && vxf_vehicle doorPhase ""door_RB"" > 0.5 && (vxf_vehicle emptyPositions 'cargo' != 0)";
					positionType = "coordinates";
					position[] = {0.616639,1.20687,-1.36537};
					label = "Move Into Passenger Seat";
					radius = 0.1;
					buttonDown = "player setPos getPos vxf_vehicle, player moveInCargo [vxf_vehicle, 1, true]";
				};
				class transferToGunner
				{
					condition = "([vxf_vehicle] call uscg_jayhawk_fnc_canCloseDoor == true) && vxf_vehicle doorPhase ""door_RB"" > 0.5";
					positionType = "coordinates";
					position[] = {0.884644,2.19265,-1.81217};
					label = "Move Into Door Seat";
					radius = 0.1;
					buttonDown = "player setPos getPos vxf_vehicle, player moveInTurret [vxf_vehicle, [1]]";
				};
				class deployStretcher
				{
					condition = "([vxf_vehicle] call uscg_jayhawkrescue_fnc_hasStretcher == true) && {!hasDeployedHook}";
					positionType = "coordinates";
					position[] = {-0.589604,2.77339,-1.737};
					label = "Deploy Stretcher";
					radius = 0.3;
					buttonDown = "[vxf_vehicle] call uscg_jayhawkrescue_fnc_deployStretcher, vxf_vehicle animate ['stretcher', 1]";
				};
				class deployBasket
				{
					condition = "([vxf_vehicle] call uscg_jayhawkrescue_fnc_hasBasket == true) && {!hasDeployedHook}";
					positionType = "coordinates";
					position[] = {0.525706,2.8762,-1.04493};
					label = "Deploy Basket";
					radius = 0.3;
					buttonDown = "[vxf_vehicle] call uscg_jayhawkrescue_fnc_deployBasket, vxf_vehicle animate ['Basket', 1]";
				};
				class getOutDiver
				{
					condition = "vxf_vehicle doorPhase ""door_RB"" > 0.5";
					positionType = "coordinates";
					position[] = {1.05919,2.73676,-0.616433};
					label = "Jump Into Water";
					radius = 0.2;
					buttonDown = "call mst_fnc_handleEject, player action ['Eject', vxf_vehicle];";
				};
				class Door_RB 
				{
					clickSound="";
					position="door_RB";
					positionType="anim";
					label="Side Door";
					animation="Door_RB";
					interactionCondition="!(vxf_vehicle getCargoIndex player == -1)";
					animStates[] = {0, 1};
					animLabels[] = {"Closed", "Open"};
					animEnd="";
					animStart = "[vxf_vehicle, false] call uscg_jayhawk_fnc_sideDoor";
					radius=0.3;
					animSpeed=1;
				};
				class undeployStretcher
				{
					condition = "hasDeployedStretcher && {vxf_vehicle doorPhase ""door_RB"" > 0.5}";
					positionType = "coordinates";
					position[] = {-0.589604,2.77339,-1.737};
					//position[] = {1.3946,2.03228,0.269152};
					label = "Retrieve Stretcher";
					radius = 0.3;
					buttonDown = "[] call uscg_jayhawkrescue_fnc_retrieveHookAttachment";
				};
				class undeployBasket
				{
					condition = "hasDeployedBasket && {vxf_vehicle doorPhase ""door_RB"" > 0.5}";
					positionType = "coordinates";
					position[] = {0.525706,2.8762,-1.04493};
					//position[] = {1.3946,2.03228,0.269152};
					label = "Retrieve Basket";
					radius = 0.3;
					buttonDown = "[] call uscg_jayhawkrescue_fnc_retrieveHookAttachment";
				};
				class transferToBasket
				{
					condition = "hasDeployedHook && {vxf_vehicle doorPhase ""door_RB"" > 0.5}";
					positionType = "coordinates";
					position[] = {1.08302,2.72844,-0.803451};
					label = "Move Onto Hoist";
					radius = 0.1;
					buttonDown = "[] call mst_fnc_moveIntoBasket";
				};
			};
		};
	};
};
