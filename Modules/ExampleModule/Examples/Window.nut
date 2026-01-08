let {
	Game,
	Renderer
} = require("HeatedMetal")


local Window = Renderer.CreateWindow("Quirrel Window", Vector2(600.0, 400.0));

function CreateLayout() {
	local Tab = Window.Tab("Layout")


	Tab.SeperatorText("Sliders")

	{

		Tab.SliderInt("Slider Int", 5, 0, 10, function(NewValue) {})
		Tab.SliderFloat("Slider Float", 1.0, 0.0, 10.0, function(NewValue) {})
	}

	////////////////////////////////////////////

	Tab.SeperatorText("Same Line")

	{
		Tab.Button("Button1", function() {})
		Tab.SameLine()
		Tab.Button("Button2", function() {})
	}


	{
		local Seperator = Tab.SeperatorText("Colors")
		local Text = Tab.Text("Colored Text");

		local NewColor = Color(0.0, 1, 0.0, 1.0);

		Text.Color = NewColor;
		Seperator.Color = NewColor;
	}

	/////////////////////////////////////////

	Tab.SeperatorText("Buttons")

	{
		Tab.Button("Print Text", function() {
			print("Hello from button!");
		});

		Tab.Selectable("Print Text", function() {
			print("Hello from selectable!");
		});

		local BigButton = Tab.Button("Big Button!", function() {});
		BigButton.Size = Vector2(380.0, 40.0)

	}

	////////////////////////////////////////////

	Tab.SeperatorText("Element Properties")

	{
		local HideMeText = Tab.Text("Hide Me Text!");
		Tab.Button("Hide Text", function() {
			HideMeText.Active = !HideMeText.Active
		});
	}

	////////////////////////////////////////////

	Tab.SeperatorText("Buttons")

	{
		local ToggleState = false
		local Toggle1 = Tab.Toggle("Toggle", ToggleState, function(NewValue) {
			ToggleState = NewValue;
		})

		Tab.Toggle("Disable Toggle", false, function(NewValue) {
			Toggle1.Disabled = NewValue;
		})
	}

	////////////////////////////////////////////

	/////////////////////////////////////////

	Tab.SeperatorText("Trees")

	{
		local Tree1 = Tab.Tree("Tree 1", true);
		{
			Tree1.Text("Tree 2");
			{
				local SubTree1 = Tree1.Tree("SubTree 1", true);
				SubTree1.Text("Sub Tree 1");
			}
		}
	}
}

function CreateErrors()
{
	local Tab = Window.Tab("Errors")

	Tab.SeperatorText("Error Handling")

	{
		Tab.Toggle("Invalid arg size", false, function() {})

		Tab.Button("Runtime Error", function() {
			Game.GetEntity(0x0).Name()
		});
	}

}


function CreateProperties() {
	local Tab = Window.Tab("Properties")

	local TextPos = Tab.Text("Position : X " + Window.Position.x + " Y " + Window.Position.y);
	local TextSize = Tab.Text("Size : X " + Window.Size.x + " Y " + Window.Size.y);

	Tab.Button("Update Text", function() {
		TextPos.SetText("Position : X " + Window.Position.x + " Y " + Window.Position.y);
		TextSize.SetText("Size : X " + Window.Size.x + " Y " + Window.Size.y);
	});

	Tab.Seperator();

	Tab.SliderFloat("Alpha", 1.0, 0.0, 1.0, function(NewValue) {
		Window.Alpha = NewValue;
	})

	Tab.Button("Move to center", function() {
		Window.SetPosition((Renderer.DisplaySize() - Window.Size) * 0.5);
	});

	Tab.Button("Half the size", function() {
		Window.SetSize(Window.Size * 0.5);
	});
}

function CreateFlags() {
	local Tab = Window.Tab("Flags")

	Tab.SeperatorText("Window")

	Tab.Toggle("Block Input", true, function(NewValue) {
		Window.BlockInput = NewValue;
	});

	Tab.Toggle("No TitleBar", false, function(NewValue) {
		Window.NoTitleBar = NewValue;
	});

	Tab.Toggle("No ScrollBar", false, function(NewValue) {
		Window.NoScrollBar = NewValue;
	});


	Tab.Toggle("Auto Resize", false, function(NewValue) {
		Window.AutoResize = NewValue;
	});



	Tab.SeperatorText("User Actions")


	Tab.Toggle("No Resize", false, function(NewValue) {
		Window.NoResize = NewValue;
	});

	Tab.Toggle("No Move", false, function(NewValue) {
		Window.NoMove = NewValue;
	});

	Tab.Toggle("No Collapse", false, function(NewValue) {
		Window.NoCollapse = NewValue;
	});
}


CreateLayout();
CreateErrors();
CreateProperties();
CreateFlags();


function Command(Args) {
	Window.Active = !Window.Active;
}

RegisterCommand(Command, "TestWindow", "", "Enable a quirrel made window!");

return {

}