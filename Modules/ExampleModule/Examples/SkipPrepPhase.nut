local {
	Game
} = require("HeatedMetal")

local ShouldSkipPrepPhase = false

function Main(WorldID) {
	if (!Game.IsHost() || Game.GetDifficulty() != 0 || !ShouldSkipPrepPhase)
		return

	Sleep(1500)

	Game.SetTimerRemaining(1)

	print("Skipped PrepPhase")
}

AddCallback_RoundStart(Main)

function Command(Args)
{
	ShouldSkipPrepPhase = !ShouldSkipPrepPhase

	if(ShouldSkipPrepPhase)
	{
		print("Prep phase skip | Enabled!")
		return
	}

	print("Prep phase skip | Disabled!")
}

RegisterCommand(Start, "StartSkibidi", "", "Run like hell");

return {

}