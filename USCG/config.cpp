class CfgPatches
{
	class USCG
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Characters_F", "cba_settings"};
	};
};

class cfgFactionClasses 
{ 
    class USCG
    { 
        displayName = "USCG"; 
        priority = 3;
        side = 1; // Opfor = 0, Blufor = 1, Indep = 2. 
        icon = "\USCG\USCG_Image.paa";
    };  
};

class CfgFunctions
{
	class USCG_mod
	{
		class functions
		{
			// core
			class helicopterInit
			{
				file="\USCG\functions\fn_helicopterInit.sqf";
				postInit=1;
			};
			class eventHandlers 
			{
				file="\USCG\functions\fn_eventHandlers.sqf";
				postInit=1;
			};
			class commonFunctions
			{
				file="\USCG\functions\fn_commonFunctions.sqf";
				postInit=1;
			};
			// dialog/ace
			class handleDialog
			{
				file="\USCG\functions\fn_handleDialog.sqf";
				postInit=1;
			};
			class spawnHookSelection
			{
				file="\USCG\functions\fn_spawnHookSelection.sqf";
				postInit=1;
			};
			class aceInit
			{
				file="\USCG\functions\fn_aceInit.sqf";
				postInit=1;
			};
			// misc
			class setRopeLength
			{
				file="\USCG\functions\fn_setRopeLength.sqf";
				postInit=0;
			};
			class moveInAllOccupants
			{
				file="\USCG\functions\fn_moveInAllOccupants.sqf";
				postInit=0;
			};
			class getDataReadings
			{
				file="\USCG\functions\fn_getDataReadings.sqf";
				postInit=0;
			};
			// delete
			class deleteHook
			{
				file="\USCG\functions\fn_deleteHook.sqf";
				postInit=0;
			};
			class getRopeLength
			{
				file="\USCG\functions\fn_getRopeLength.sqf";
				postInit=0;
			};
			
		};
	};
};

#include "\USCG\dialogs\defines.hpp"
#include "\USCG\dialogs\dialogs.hpp"

class cfgVehicles 
{
	class Heli_Transport_01_base_F;
	class vtx_H60_base : Heli_Transport_01_base_F 
	{
		class vxf_copilot
		{
			class interaction 
			{
				class readDataCoPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "hookDeployed";
					positionType = "coordinates";
					position[] = {-0.730867,5.09079,-0.491695};
					label = "Read Hoist Data";
					radius = 0.2;
					buttonDown = "[player] call uscg_mod_fnc_getDataReadings";
				};
				class transferBasketHelicopter
				{
					condition = "ropeLength (ropes vxf_vehicle select 0) <= 3";
					positionType = "coordinates";
					position[] = {-0.0472,4.88146,-0.613526};
					label = "Move Hoist Crew - Helicopter";
					radius = 0.1;
					buttonDown = "[hook] call uscg_mod_fnc_moveInAllOccupants";
				};
			};
		};
		class vxf_driver
		{
			class interaction
			{
				class transferBasketHelicopter
				{
					condition = "ropeLength (ropes vxf_vehicle select 0) <= 3";
					positionType = "coordinates";
					position[] = {-0.0472,4.88146,-0.613526};
					label = "Move Hoist Crew - Helicopter";
					radius = 0.1;
					buttonDown = "[hook] call uscg_mod_fnc_moveInAllOccupants";
				};
				class setLengthPilot
				{
					condition = "hookDeployed";
					positionType = "coordinates";
					position[] = {0.719166,5.09165,-0.493864};
					label = "Set Rope Length";
					radius = 0.2;
					buttonDown = " createDialog 'uscg_RopeMeter' ";
				};
				class readDataPilot
				{
					clickSound = "vxf_Switch_Sound";
					condition = "hookDeployed";
					positionType = "coordinates";
					position[] = {0.720362,5.1483,-0.357264};
					label = "Read Rescue Hoist Data";
					radius = 0.2;
					buttonDown = "[player] call uscg_mod_fnc_getDataReadings";
				};
			};
		};
		class vxf_cargo
		{
			class interaction
			{
				class deployHook
				{
					condition = "!hookDeployed";
					positionType = "coordinates";
					position[] = {1.3946,2.03228,0.269152};
					label = "Deploy Hoist";
					radius = 0.3;
					buttonDown = "[] call mst_fnc_deployHelicopterHookH60";
				};
				class getOutDiver
				{
					condition = "";
					positionType = "coordinates";
					position[] = {-1.08656,1.74033,-1.22008};
					label = "Jump Into Water";
					radius = 0.3;
					buttonDown = "[] call mst_fnc_handleEject, player action ['Eject', vehicle player];";
				};
				class undeployHook
				{
					condition = "hookDeployed";
					positionType = "coordinates";
					position[] = {1.43148,2.02815,0.46699};
					//position[] = {1.3946,2.03228,0.269152};
					label = "Retrieve Hoist";
					radius = 0.3;
					buttonDown = "[hook] call uscg_mod_fnc_deleteHook && vehicle player animateSource ['hoist_hook_hide', 0];";
				};
				class changeRopeLength
				{
					condition = "hookDeployed";
					positionType = "coordinates";
					position[] = {1.04544,2.62412,-0.248061};
					label = "Set Rope Length (WIP, may only work for pilot)";
					radius = 0.1;
					buttonDown = " createDialog 'uscg_RopeMeter' ";
				};
				class transferToBasket
				{
					condition = "ropeLength (ropes vehicle player select 0) <= 3";
					positionType = "coordinates";
					position[] = {1.66, 1.585,-0.3};
					label = "Move Onto Hoist";
					radius = 0.1;
					buttonDown = "[] call mst_fnc_moveIntoBasket";
				};
				class pickRescueEquipment
				{
					clickSound = "vxf_Switch_Sound";
					condition = "!hookDeployed";
					positionType = "coordinates";
					position[] = {1.04227,2.76631,-0.246649};
					label = "Choose Rescue Equipment";
					radius = 0.1;
					buttonDown = "[] call mst_fnc_spawnHookSelectionMenu";
				};
			};
		};
	};
};
