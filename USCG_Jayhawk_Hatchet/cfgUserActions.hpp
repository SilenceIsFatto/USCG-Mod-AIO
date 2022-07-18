class CfgUserActions
{
	class USCG_Pilot_Buttons // This class name is used for internal representation and also for the inputAction command.
	{
		displayName = "Toggle Pilot Button Help";
		tooltip = "";
		onActivate = "[vehicle player, 'vxf_driver'] call uscg_jayhawkrescue_fnc_debugStuff";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class USCG_Cargo_Buttons // This class name is used for internal representation and also for the inputAction command.
	{
		displayName = "Toggle Cabin Button Help";
		tooltip = "";
		onActivate = "[vehicle player, 'vxf_cargo'] call uscg_jayhawkrescue_fnc_debugStuff";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class USCG_Copilot_Buttons // This class name is used for internal representation and also for the inputAction command.
	{
		displayName = "Toggle Copilot Button Help";
		tooltip = "";
		onActivate = "[vehicle player, 'vxf_copilot'] call uscg_jayhawkrescue_fnc_debugStuff";
		onDeactivate = "";
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class USCG_No_Buttons // This class name is used for internal representation and also for the inputAction command.
	{
		displayName = "Toggle Button HUD";
		tooltip = "";
		onActivate = "canDraw = false";
		onDeactivate = "";
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
};

class UserActionGroups
{
	class USCG_Keybinds // Unique classname of your category.
	{
		name = "US Coastguard - Semper Paratus"; // Display name of your category.
		isAddon = 1;
		group[] = {
			"USCG_Pilot_Buttons",
			"USCG_Cargo_Buttons",
			"USCG_Copilot_Buttons",
			"USCG_No_Buttons"
		};
	};
};