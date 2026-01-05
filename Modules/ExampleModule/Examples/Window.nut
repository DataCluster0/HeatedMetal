let {
	Game,
	Renderer
} = require("HeatedMetal")


local Window = Renderer.CreateWindow("Quirrel Window", Vector2(400.0, 400.0));
{
	Window.Text("Hello World!");

	Window.SeperatorText("Sliders")

	{
		Window.SliderFloat("Window Alpha", 1.0, 0.0, 1.0, function(NewValue) {
			Window.Alpha = NewValue;
		})

		Window.SliderInt("Slider Int", 5, 0, 10, function(NewValue) {})

		Window.SliderFloat("Window Float", 1.0, 0.0, 10.0, function(NewValue) {})
	}


	Window.SeperatorText("Same Line")

	{
		Window.Button("Button1", function() {})
		Window.SameLine()
		Window.Button("Button2", function() {})
	}


	{
		local Seperator = Window.SeperatorText("Colored Seperator")
		local Text = Window.Text("Colored Text");

		local NewColor = Color(0.0, 1, 0.0, 1.0);

		Text.Color = NewColor;
		Seperator.Color = NewColor;
	}

	/////////////////////////////////////////

	Window.SeperatorText("Buttons")

	{
		Window.Button("Print Text", function() {
			print("Hello from button!");
		});

		local BigButton = Window.Button("Big Button!", function() {});
		BigButton.Size = Vector2(380.0, 40.0)

	}


	Window.SeperatorText("Element Properties")

	{
		local HideMeText = Window.Text("Hide Me Text!");
		Window.Button("Hide Text", function() {
			HideMeText.Active = !HideMeText.Active
		});
	}


	Window.SeperatorText("Buttons")

	{
		local ToggleState = false
		local Toggle1 = Window.Toggle("Toggle", ToggleState, function(NewValue) {
			ToggleState = NewValue;
		})

		Window.Toggle("Disable Toggle", false, function(NewValue) {
			Toggle1.Disabled = NewValue;
		})
	}

	Window.SeperatorText("Error Handling")

	{
		Window.Toggle("Invalid arg size", false, function() {})

		Window.Button("Runtime Error", function() {
			Game.GetEntity(0x0).Name()
		});
	}

	/////////////////////////////////////////

	Window.SeperatorText("Trees")

	{
		local Tree1 = Window.Tree("Tree 1", true);
		{
			Tree1.Text("Tree 2");
			{
				local SubTree1 = Tree1.Tree("SubTree 1", true);
				SubTree1.Text("Sub Tree 1");
			}
		}
	}

}

function Command(Args) {
	Window.Active = !Window.Active;
}

RegisterCommand(Command, "TestWindow", "", "Enable a quirrel made window!");

return {

}