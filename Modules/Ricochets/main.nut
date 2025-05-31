local {
	Game,
	Renderer
} = require("HeatedMetal")
local math = require("math")

const RICOCHET_COUNT = 2

const RICOCHET_DEBUG = false

local BulletTable = {}

function DebugDraw() {
	local BulletRemoveQueue = [];

	foreach(ID, Bullet in BulletTable) {
		Renderer.Line(Bullet.Start, Bullet.End, Bullet.BulletColor, 2.0)

		if (Bullet.Timer.HasElapsed(5.0))
			BulletRemoveQueue.append(ID)
	}

	foreach(Bullet in BulletRemoveQueue) {
		delete BulletTable[Bullet]
	}
}

function Bullet(Start, End, Normal, Delta, Entity) {
	local _Color = Color.Random();

	if (RICOCHET_DEBUG) {
		BulletTable[RandomInt(10000)] <- {
			Start = Start,
			End = End,
			BulletColor = _Color,
			Timer = Timer(true)
		}
	}

	//print(Entity)

	local RicochetStart = End + (Normal * 0.1)
	local RicochetDir = (End - Start).Normalize()

	for (local i = 0; i < RICOCHET_COUNT; i++) {
		local Result = Game.Raycast(RicochetStart, RicochetStart + (RicochetDir * 1000.0), 1);

		if (Result.DidHit()) {
			foreach(Hit in Result.Hits()) {

				if (RICOCHET_DEBUG) {
					BulletTable[RandomInt(10000)] <- {
						Start = RicochetStart,
						End = Hit.Origin(),
						BulletColor = _Color,
						Timer = Timer(true)
					}

					Game.CreateDust(Hit.Origin(), 0.2, _Color)
				}

				local Ent = Hit.Entity()
				if (Ent) {
					local Damage = Ent.DamageComponent()
					if (Damage) {
						Damage.SetHealth(math.clamp(Damage.GetHealth() - 5, 0, Damage.GetMaxHealth()))

						return;
					}
				}


				local surfaceNormal = Hit.Normal()

				RicochetStart = Hit.Origin() + (surfaceNormal * 0.1)

				local dotProduct = RicochetDir.Dot(surfaceNormal)
				RicochetDir = RicochetDir - (surfaceNormal * (2.0 * dotProduct))
				RicochetDir = RicochetDir.Normalize()
			}
		}
	}
}

function Shutdown() {
	BulletTable.clear()
}

function Main(WorldID) {
	if (!Game.IsHost()) return;

	print("Ricoshets init")

	if (RICOCHET_DEBUG)
		AddCallback_Update(DebugDraw)

	AddCallback_BulletHit(Bullet)
	AddCallback_Shutdown(Shutdown)
}

Main(0);
//AddCallback_RoundStart(Main)