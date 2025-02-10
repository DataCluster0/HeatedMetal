require("enums.nut")
local CoreImpl = require("exports.nut")
local Globals = getconsttable();

function RegisterModuleImpl(Name, Table) {
	Globals[Name] <- Table;

	function Remove() {
		if (Name in Globals)
			delete Globals[Name]
	}

	AddCallback_Shutdown(Remove)
}

function Init() {
	Globals["RegisterModule"] <- RegisterModuleImpl

	function Remove() {
		delete Globals["RegisterModule"]
	}

	AddCallback_Shutdown(Remove)
}

Init()

RegisterModuleImpl("Core", CoreImpl)

// Use RegisterModule(Name, Table) to register functions this helper is globaly defined

// Use Core to access these functions
// Example : Core.TeamWin(eTeam.A)