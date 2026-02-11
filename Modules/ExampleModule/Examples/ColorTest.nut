local {
	Renderer,
	Game
} = require("HeatedMetal")

//local test = require("temp/test.nut")

local math = require("math")

local LineThickness = 1.0

local AnimationDuration = 4.0 // seconds
local HalfAnimationDuration = AnimationDuration / 2.0
local AnimationProgress = 0.0

local AnimationTimer = Timer(true)
local ColorTimer = Timer(true)
local Radius = 10.0
local ColorTime = 0.1

local Enabled = false

function Frame() {
	if(!Enabled)
		return;

	local LocalPlayer = Game.GetLocalPlayer()

	if (!LocalPlayer)
		return;

	local Entity = LocalPlayer.Entity

	if (!Entity)
		return;

	local Color_ = Color.Rainbow(1.0)

	local Origin = Entity.Origin
	local EndOrigin = Origin + (LocalPlayer.Forward * 20.0)
	local Angles = Vector3(0, 0, 0)

	local elapsedTime = AnimationTimer.ElapsedTime()
	AnimationProgress = elapsedTime / AnimationDuration

	if (AnimationProgress > 1.0) {
		AnimationProgress = AnimationProgress - math.floor(AnimationProgress)
		AnimationTimer.Reset()
	}

	// Move
	local progressFactor;

	if (AnimationProgress < 0.5)
		progressFactor = AnimationProgress * 2.0;
	else
		progressFactor = (1.0 - AnimationProgress) * 2.0;

	local Position = Origin + (EndOrigin - Origin) * progressFactor

	Renderer.Text("Funny Text", EndOrigin, Color_)
	Renderer.Line(Origin, EndOrigin, Color_, LineThickness)

	Renderer.Sphere(Position, Vector3(0, 0, 0), Radius, 10, Color_, LineThickness)

	if (ColorTimer.HasElapsed(ColorTime))
		Game.CreateDust(Position, Radius, Color_)
}

AddCallback_Update(Frame);

function Command(Args) {
	Enabled = !Enabled;
}

RegisterCommand(Command, "TestColor", "", "Color Test");

return {}