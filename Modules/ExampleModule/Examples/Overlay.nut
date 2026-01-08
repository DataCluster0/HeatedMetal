local {
	Game,
	Renderer
} = require("HeatedMetal")

local math = require("math")

local DisplaySize = Renderer.DisplaySize();
local DisplayCenter = DisplaySize * 0.5


local Overlay = Renderer.CreateOverlay();

// Draw across the screen
local Centerline = Overlay.Line(Vector2(0, 0), DisplaySize)
Centerline.Thickness = 10.0
/////////////////////////////////////////////

// Crosshair
Overlay.Line(DisplayCenter - Vector2(15.0, 0), DisplayCenter + Vector2(15.0, 0));
Overlay.Line(DisplayCenter - Vector2(0, 15.0), DisplayCenter + Vector2(0, 15.0));

/////////////////////////////////////////////

local Text = Overlay.Text("Overlay Text", DisplayCenter);
Text.Outlined = true
/////////////////////////////////////////////

local BarPos = Vector2(10, DisplaySize.y - 50);
local HealthBar = Overlay.Rectangle(BarPos, Vector2(200.0, 25.0), 5.0);

/////////////////////////////////////////////

local Triangle = Overlay.Triangle(
	DisplayCenter + Vector2(0, -80),
	DisplayCenter + Vector2(-15, -60),
	DisplayCenter + Vector2(15, -60)
);

Triangle.Filled = true;
Triangle.Color = Color(1.0, 0.0, 0.0, 1.0);

/////////////////////////////////////////////

local Box = Overlay.Rectangle(Vector2(DisplaySize.x - 150.0, 10.0), Vector2(140.0, 80.0), 3.0);
Box.Filled = false;

///////////////////////////////////////////// Moving Circle

local Time = 0.0;

local Circle = Overlay.Circle(DisplayCenter, 40.0, 32);

function Update() {
	Time += DeltaTime();

	// Move circle across screen
	local Offset = math.sin(Time) * (DisplaySize.x * 0.4);
	Circle.Position = Vector2(DisplayCenter.x + Offset, DisplayCenter.y);
}

AddCallback_Update(Update)

/////////////////////////////////////////////


function Command(Args) {
	Overlay.Active = !Overlay.Active;
}

RegisterCommand(Command, "TestOverlay", "", "Enable a quirrel made overlay!");

return {

}