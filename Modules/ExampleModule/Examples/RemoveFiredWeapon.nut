local {
	Renderer,
	Game
} = require("HeatedMetal")


function FireWeapon(WeaponComponent) {
	local Ent = WeaponComponent.Entity()
	if (Ent)
		Ent.RemoveFromWorld()
}

AddCallback_WeaponFire(FireWeapon)