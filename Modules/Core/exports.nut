local {
	Game
} = require("HeatedMetal")

// Jank Team Win Helper
function TeamWin(Team) {
	if (!Game.IsHost()) return false

	foreach(Player in Game.GetPlayerList()) {

		if (Team == Player.Team())
			continue

		local Entity = Player.Entity()
		if (Entity) {
			// Player ent always contains a damage component
			Entity.DamageComponent().SetHealth(0)
		}
	}

	return true
}

// Player to DamageComponent Helper
function GetHealth(Player) {
	if (!Player) return null;

	local Entity = Player.Entity();
	if (!Entity) return null;

	return Entity.DamageComponent();
}

return {
	TeamWin,
	GetHealth
}