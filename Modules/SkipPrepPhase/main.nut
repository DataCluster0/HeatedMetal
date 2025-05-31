local {
	Game
} = require("HeatedMetal")

function Main(WorldID) {
	if (!Game.IsHost() || Game.GetDifficulty() != 0)
		return

	Sleep(1500)

	Game.SetTimerRemaining(1)

	print("Skipped PrepPhase")
}

function SkipPrepPhase() {
	AddCallback_RoundStart(Main)
}

SkipPrepPhase();