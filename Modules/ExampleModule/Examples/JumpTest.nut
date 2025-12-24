let {
	Game,
	Renderer
} = require("HeatedMetal")


local Time = Timer(true)

function Frame() {
	local LocalPlayer = Game.GetLocalPlayer()
	if (LocalPlayer) {

		local Entity = LocalPlayer.Entity()

		if (Entity) {
			if (IsKeyPressed("Space") && Time.HasElapsed(1.0)) {
				local Origin = Entity.GetOrigin()
				Origin.z += 0.5
				Entity.SetOrigin(Origin)
			}
		}
	}
}

AddCallback_Update(Frame)