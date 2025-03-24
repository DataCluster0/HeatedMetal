local {
	Game
} = require("HeatedMetal");

local math = require("math");

local ElevatorSpeed = 0.8;
local FloorTime = 6.0;

local CurrentFloor = 0;
local MovingUp = true;
local FloorHeights = [-2.409, 1.968, 7.972]; // Exact floor heights
local TargetHeight = FloorHeights[CurrentFloor];

local Parts = [];
local RemoveList = [
	0x105B46CE90, // Hatch

	0x1301DC8564,
	0x14C1B95A2F,
	0x14C1B95E4F,
	0x16774FEA55,
	0x14C1B95E4D,
	0x14C1B95E28,
	0x15C8FC55F5,
	0x15543BC457,
	0x15C8FCD845,
];

local PartList = [
	0x1301DCD665, // Floor (added first)
	0x1301DCD5F7, // A
	0x1301DCD64B, // C
	//0x105B46CE90, // Hatch
	//0xFBF9BD161, // CubeMap
	0x15B549312E, // OmniLight 1
	0x15B5493131, // OmniLight 2
]

function AddParts(List) {
	foreach(ObjectID in List) {
		let Ent = Game.GetEntity(ObjectID);

		if (Ent) {
			let Data = {
				Entity = Ent.Duplicate(),
				Origin = Ent.GetOrigin()
				Delta = Vector3(0, 0, 0)
			};

			Parts.append(Data);
		}
	}
}

function ResetElevator() {
	foreach(Part in Parts) {
		let Ent = Part.Entity;
		if (Ent) {
			Ent.RemoveFromWorld() // Delete
		}
	}

	CurrentFloor = 0;
	MovingUp = true;
	TargetHeight = FloorHeights[0];
}

function ManageList(ObjectIDS, Remove) {
	foreach(ObjectID in ObjectIDS) {
		let Ent = Game.GetEntity(ObjectID);

		if (Ent) {
			if (Remove)
				Ent.RemoveFromWorld();
			else
				Ent.AddToWorld();
		}
	}
}

function MoveElevator(deltaTime) {
	local floorEntity = Parts[0].Entity;
	local currentOrigin = floorEntity.GetOrigin();
	local currentHeight = currentOrigin.z;

	local targetOrigin = Vector3(currentOrigin.x, currentOrigin.y, TargetHeight);
	local direction = targetOrigin - Vector3(currentOrigin.x, currentOrigin.y, currentHeight);
	local distanceToTarget = direction.Length();

	local threshold = 0.01; // Threshold for snapping

	if (distanceToTarget < threshold) {
		currentHeight = TargetHeight;
	} else {
		local speed = ElevatorSpeed * deltaTime;
		speed = math.min(speed, 1.2);

		local movement = direction.Normalize() * speed;
		currentHeight += movement.z;
	}

	local newFloorOrigin = currentOrigin;
	newFloorOrigin.z = currentHeight;
	floorEntity.SetOrigin(newFloorOrigin);

	foreach(part in Parts) {
		local partEntity = part.Entity;
		if (!partEntity)
			continue;

		local partOrigin = partEntity.GetOrigin();
		partOrigin.z = part.Delta.z + newFloorOrigin.z;
		partEntity.SetOrigin(partOrigin);
	}

	return math.abs(TargetHeight - newFloorOrigin.z) < threshold;
}

local m_Timer = Timer(false);
local stopTimer = Timer(false);
local lastTime = 0;

function Tick() {
	local deltaTime = m_Timer.ElapsedTime() - lastTime;
	lastTime += deltaTime; // Update lastTime

	if (MoveElevator(deltaTime)) {
		if (stopTimer.HasElapsed(FloorTime)) {
			CurrentFloor += MovingUp ? 1 : -1;

			// Switch direction if at the top or bottom floor
			if (CurrentFloor >= FloorHeights.len() - 1 || CurrentFloor <= 0) {
				MovingUp = !MovingUp;
			}

			TargetHeight = FloorHeights[CurrentFloor];
		}
	} else stopTimer.Reset()
}

function Exit() {
	ResetElevator()

	ManageList(RemoveList, false);
	ManageList(PartList, false);

	Parts.clear();
}

function RoundStart(WorldID) {
	if (!Game.IsHost() || WorldID != eMap.Tower) // Tower
		return;

	Exit()

	AddParts(PartList)

	if (Parts.len() <= 0) return;

	foreach(i, value in Parts) {
		if (i <= 0) continue;

		value.Delta = Parts[i].Origin - Parts[0].Origin;
	}

	ManageList(RemoveList, true);
	ManageList(PartList, true);

	// Move up hidden floor
	local FloorBase = Game.GetEntity(0x118517D59E);
	if (FloorBase)
		FloorBase.SetOrigin(Vector3(0.0, 0.0, 0.2)); // Set the initial height based on the first floor



	m_Timer.Start();
	stopTimer.Start();

	AddCallback_Update(Tick)
	AddCallback_Shutdown(Exit)

	print("Elevator Init");
}

function Main() {
	AddCallback_RoundStart(RoundStart)
}

Main();