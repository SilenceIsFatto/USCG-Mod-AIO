class Attributes {
	class ace_fastroping_equipFRIES {
		condition = "objectVehicle";
		control = "Checkbox";
		defaultValue = "(false)";
		displayName = "Remove FRIES from helicopter (ACE Only)";
		expression = "if !(_value) then {[_this] call ace_fastroping_fnc_unequipFRIES}";
		property = "ace_fastroping_equipFRIES";
		tooltip = "Removes a Fast Rope Insertion Extraction System";
		typeName = "BOOL";
	};
	class uscg_jayhawk_sideDoorOpen {
		condition = "objectVehicle";
		control = "Checkbox";
		defaultValue = "(false)";
		displayName = "Open Side Door";
		expression = "if (_value) then {[_this] call uscg_jayhawk_sideDoor}";
		property = "uscg_jayhawk_sideDoorOpen";
		tooltip = "Opens/Closes The Side Door On Mission Start";
		typeName = "BOOL";
	};	
	class uscg_jayhawk_removeStretcher {
		condition = "objectVehicle";
		control = "Checkbox";
		defaultValue = "(false)";
		displayName = "Remove Stretcher";
		expression = "if (_value) then {[_this, ['stretcher', 1]] remoteExec ['animate'], _vehicle setVariable ['jayhawkHasStretcher', false]} else {[_this, ['stretcher', 0]] remoteExec ['animate'], _vehicle setVariable ['jayhawkHasStretcher', true]}";
		property = "uscg_jayhawk_stretcher";
		tooltip = "Removes Stretcher And Actions";
		typeName = "BOOL";
	};
	class uscg_jayhawk_removeBasket {
		condition = "objectVehicle";
		control = "Checkbox";
		defaultValue = "(false)";
		displayName = "Remove Basket";
		expression = "if (_value) then {[_this, ['basket', 1]] remoteExec ['animate'], _vehicle setVariable ['jayhawkHasBasket', false]} else {[_this, ['basket', 0]] remoteExec ['animate'], _vehicle setVariable ['jayhawkHasBasket', true]}";
		property = "uscg_jayhawk_basket";
		tooltip = "Removes Basket And Actions";
		typeName = "BOOL";
	};
}; // Attributes