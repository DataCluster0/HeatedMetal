local {
	Renderer,
	Game
} = require("HeatedMetal")

local math = require("math")

local EntityTable = {};

local MasterEntity = 0x1E600B8D1C7C7F0;

function Action(ent, data) {
	if (!ent)
		return

	data.Rotation += 5.0
	if (data.Rotation >= 360.0) data.Rotation = 0.0
	ent.SetAngles(Vector3(0, 0, data.Rotation))

	if (!data.Target)
		return

	local dmg = data.Target.DamageComponent()
	if (!dmg || dmg.GetHealth() <= 0) {
		EntityTable.rawdelete(ent)
		ent.RemoveFromWorld()
		return
	}

	local srcPos = ent.GetOrigin()
	local tgtPos = data.Target.GetOrigin()
	local delta = tgtPos - srcPos

	if (delta.Length() > 0.0) {
		local dir = delta.Normalize()
		// use MoveSpeed to control chase speed
		local newPos = srcPos + dir * data.MoveSpeed


		if (srcPos.Distance(tgtPos) >= 4.0)
			ent.SetOrigin(newPos)
	}
}

function BulletHit(start, end, normal, delta, entity) {
	if (!(entity in EntityTable))
		return

	local d = EntityTable[entity]
	d.Health = math.Clamp(d.Health - 10, 0, d.MaxHealth)

	if (d.Health > 0)
		Game.CreateDust(end, 0.2, Color.RGB(255, 0, 0, 255))
	else {
		EntityTable.rawdelete(entity)
		Game.CreateDust(end, 2, Color.RGB(255, 0, 0, 255))
		entity.RemoveFromWorld()
	}
}

function RespawnObjects() {
	local father = Game.GetEntity(MasterEntity)
	if (!father)
		return

	local players = Game.GetPlayerList()
	local radius = 100.0

	for (local i = 0; i < players.len(); ++i) {
		local plyEnt = players[i].Entity()
		local dmg = plyEnt.DamageComponent()
		if (!dmg || dmg.GetHealth() <= 0)
			continue

		local pos = plyEnt.GetOrigin()
		local count = 50

		for (local n = 0; n < count; ++n) {
			local angle = (2 * math.PI / count) * n
			local offsetX = math.cos(angle) * radius
			local offsetZ = math.sin(angle) * radius

			local toilet = father.Duplicate()
			toilet.SetOrigin(Vector3(pos.x + offsetX, pos.y + offsetZ, pos.z))

			//local destr = toilet.DestructionComponent()
			//if (destr) destr.SetActive(false)

			local health = RandomIntRange(100, 200)
			EntityTable[toilet] <- {
				Target = plyEnt,
				Rotation = RandomFloatRange(0, 360),
				MoveSpeed = 0.05,
				DamageTimer = Timer(true),
				Health = health,
				MaxHealth = health
			}
		}
	}
}

function EngineFrame() {

	if (EntityTable.len() <= 0) {
		RespawnObjects()
	}

	foreach(Ent, data in EntityTable) {
		Action(Ent, data);
	}
}

function Shutdown() {

	foreach(Ent, data in EntityTable) {
		if (Ent)
			Ent.RemoveFromWorld();
	}

	EntityTable.clear()

	print("ObjectCircle exit")
}

function Main() {
	if (!Game.IsHost()) // House
		return;

	//Sleep(4000.0)

	RespawnObjects()

	AddCallback_Update(EngineFrame)
	//AddCallback_BulletHit(BulletHit)
	AddCallback_Shutdown(Shutdown)

	print("ObjectCircle Init")
}

function start(strarray) {
	Main()
}

RegisterCommand(start, "TestObjectCircle", "", "");

return {

}