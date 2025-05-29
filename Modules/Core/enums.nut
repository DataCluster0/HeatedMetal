global enum eNotifType
{
	Info,
	Warning,
	Error,
	Success
};

global enum eGamestate
{
	Splash,          // 0 Splash Screen
	ShutDown,		 // 1 Shutdown
	MainMenu,        // 2 Main Menu
	CustomGame,      // 3 Custom Games
	LoadingPreGame,  // 4 Loading pre-game
	SelectMenu,      // 5 Select Menu
	Loading,         // 6 Loading
	InGame,          // 7 In-Game
}

global enum eTeam
{
	A,
	B,
	Spectator,
	Invalid
}

global enum eAlliance
{
	Neutral,
	Rainbow,
	Terrorist,
	TeamA,
	TeamB,
	NA,
	TeamMax,
};

global enum eItemSlot
{
	Primary,
	Secondary,
	Tertiary,

	PrimaryGadget,
	SecondaryGadget,
	Character // Causes bugs use with caution
};

global enum eExplosion
{
	NitroCell,
	Impact,
	Smoke,
	Gas,
	Flash,
	Dazzler,
	ConcussionMine,
	ConcussionGrenade,
	ContactGrenade,
	ClusterCharge,
	Shumika,
	Volcan,
	EMP,
	Airjab,
	AirjabOld,
	LVExplosiveLance,
	ExplosionBelt
};

global enum eDamageType
{
	Bullet,
	Melee,
	Explosive,
	Falling,
	Regeneration,
	Unknown,
	Debris,
	ThrownObject,
	BledOut,
	Gas,
	ThermalExplosion,
	MeleeGadget,
	BarbedWire,
	Electric,
	Reinforcement,
	FragExplosion,
	Paralyzed,
	EMP,
	BreakAll,
	CleanUp,
	InterrogateKill,
	MeleeFinisher,
	Toxic,
	ToxicExplosion,
	Pneumatic,
	BodyContact,
	ContactExplosion,
	Flash,
	ParasiteSpike,
	Laser,
	Concussion,
	BlowTorch,
	TaserShield,
	ReverseFriendlyFire,
	SelfDestroyed,
	AreaControl,
	Fire,
	BreachKick,
	BreakWall
}

global enum eEntityEffect
{
	NotAffected,
	Flashed,
	Smoked,
	Gased,
	InBarbedWire,
	GrenadeProximity,
	Electrocuted,
	Concussioned,
	SonicBurstAffected,
	InNetTrap,
	Deafened,
	StunnedByNetTrap,
	Boosted,
	Hunt,
	Disrupted,
	Caltropped,
	Attracted,
	LeaderBuff,
	Rooted,
	PreBoost,
	RootingAreaPreWarning,
	Bloodlust,
	LogicBomb,
	Meleed,
	LogicBombCameraFX,
	LogicBombStopUsingCamera,
	FullBoost,
	CaltropDOT,
	TagDeviceWarning,
	TagDeviceScanning,
	AudioAlarmAffected,
	EpiShot,
	HighlightedWithOutline,
	TagDeviceRevealed,
	LaserAffected,
	TaserShieldEnter,
	TaserShieldExit,
	BlowTorchSlowdown,
	UsingTaserShield,
	Stealth,
	PushBack,
	NeuropathyDistance,
	LogicBombExit,
	LogicBombExitByDuration,
	SmartGlasses,
	CameraInvisibility,
	CameraGlitch,
	CameraGlitchOutro,
	SilentStep,
	CameraInvisibilityObservationToolFeedback,
	CameraInvisibilityOutro,
	FireDOT,
	SmokeOpacityReduction,
	Value_53,
	Dash,
	WeakConcussion,
	ClimbHatch,
	ControllableDecoy,
	ControllableDecoyDeploy,
	ControllingControllableDecoy,
	JammerWarning
	BreakWall_DEPRECATED,
	PostDash,
	PostClimbHatch,
	LowFrequencySound,
	LowFrequencySoundOutro,
	ControllableDecoyDeployFailed,
	PostControllingControllableDecoy,
	WaterBreachSplash,
	LaserDOT,
};

global enum eMap
{
	Neighborhood   = 0x431BA741C3,
	House          = 0x37625C3900,
	Oregon         = 0x35F2901CF4,
	Hereford       = 0x2A3A99CB,
	ClubHouse      = 0x31E6DF85,
	Plane          = 0x9B858528,
	Yacht          = 0x6961015C,
	Consulate      = 0x9B858E7A,
	Bank           = 0x9B858706,
	Kanal          = 0x570932C9,
	Chalet         = 0x3C7E4A5A5D,
	Barlett        = 0xA0C50B9A,
	Kafe           = 0x522587EA,
	Border         = 0xCE4BB240,
	Favela         = 0x77B43597E,
	Skyscraper     = 0x8AF15096F,
	Coastline      = 0x9CCC3D997,
	ThemePark      = 0x2E8679C826,
	Tower          = 0xC7C6E5654,
	Villa          = 0x14839B2B18,
	HerefordRework = 0x1DCA7A2258,
	Fortress       = 0x1D61EAFB8F,
	Outback        = 0x2296804EC5,
	Menu           = 0x9B2C8DC1,
}

global enum eTimeOfDay
{
	Default       = 0xA45F6E8E,
	SmokeMode     = 0x637399FB,

	Day_Default   = 0xA45F7850,
	Day           = 0x19438604,

	Night_Default = 0xA45F7851,
	Night         = 0x19438605,
}

global enum eCaliber
{
	None,

	// Bullet
	Bullet_SuperLow = 0xD67F306,
	Bullet_Low = 0x617A0088,
	Bullet_Mid = 0xE6589B1F,
	Bullet_High = 0x95773E2,
	Bullet_SuperHigh = 0x33BC036,
	Bullet_MaxPower = 0xC5F80148,

	Bullet_BOSG = 0x5E9182B4,
	Bullet_CSRX300 = 0xDB87EF30,
	Bullet_DMR = 0x7887498A,
	Bullet_DP27 = 0x8616E1E0,

	// Shell
	Shell_Low = 0x4E56EB23,
	Shell_Mid = 0xC97470B4,
	Shell_High = 0x487C2569,

	// Gadget
	Gadget_BarrageTurret = 0x6B541DED,
	Gadget_BlowTorch = 0x7CFE9C27,
};

global enum eCharacter
{
	LESION     = 0x37802D16BA,
	KAPKAN     = 0x37802D16B9,
	KAID       = 0x37802D16B8,
	JAGER      = 0x37802D16B7,
	JACKAL     = 0x37802D16B6,
	IQ         = 0x37802D16B5,
	HIBANA     = 0x37802D16B4,
	GRIDLOCK   = 0x37802D16B3,
	GLAZ       = 0x37802D16B1,
	FUZE       = 0x37802D16B0,
	FROST      = 0x37802D16AF,
	FINKA      = 0x37802D16AE,
	ELA        = 0x37802D16AD,
	ZERO       = 0x40705E6CA7,
	ECHO       = 0x37802D16AC,
	DOKKAEBI   = 0x37802D16AB,
	DOC        = 0x37802D16AA,
	CLASH      = 0x37802D16A9,
	CAVEIRA    = 0x37802D16A8,
	CASTLE     = 0x37802D16A7,
	CAPITAO    = 0x37802D16A6,
	BUCK       = 0x37802D16A5,
	BLITZ      = 0x37802D16A4,
	BLACKBEARD = 0x37802D16A3,
	BANDIT     = 0x37802D16A2,
	ASH        = 0x37802D16A1,
	AMARU      = 0x37802D16A0,
	ALIBI      = 0x37802D169F,
	WAMAI      = 0x37802D169D,
	ACE        = 0x3D42207D45,
	MELUSI     = 0x3D42207D30,
	GOYO       = 0x37802D16B2,
	IANA       = 0x3B075FB191,
	ORYX       = 0x3B075FFCB4,
	MOZZIE     = 0x37802D16C0,
	MONTAGNE   = 0x37802D16BF,
	MIRA       = 0x37802D16BE,
	MAVERICK   = 0x37802D16BD,
	ZOFIA      = 0x37802D16DA,
	YING       = 0x37802D16D9,
	WARDEN     = 0x37802D16D8,
	KALI       = 0x37802D169C,
	VIGIL      = 0x37802D16D7,
	VALKYRIE   = 0x37802D16D6,
	TWITCH     = 0x37802D16D5,
	THERMITE   = 0x37802D16D4,
	THATCHER   = 0x37802D16D3,
	TACHANKA   = 0x37802D16D2,
	SMOKE      = 0x37802D16D1,
	SLEDGE     = 0x37802D16D0,
	ROOK       = 0x37802D16CF,
	MUTE       = 0x37802D16C1,
	MAESTRO    = 0x37802D16BC,
	LION       = 0x37802D16BB,
	NOMAD      = 0x37802D16C2,
	NOKK       = 0x37802D16C3,
	PULSE      = 0x37802D16C4,

	RECRUITATK = 0x45AC0BAA36,
	RECRUITDEF = 0x45AC0BAA4B,

	// HM Operators

	// ATK
	DEADEYE    = 0x95AC10BA36,
	BAPHOMET   = 0x95AC10CA36,
	XRAY       = 0x95AC10FA36,
	CHAOS      = 0x95AC112A36

	// DEF
	SPECTER    = 0x95AC10AA4B,
	JADE       = 0x87803246BE,
	MIRAGE     = 0x95AC10EA4B,
	MONARCH    = 0x95AC110A4B,
	RAZOR      = 0x95AC111A4B,
}

global enum eBone
{
	Reference,
	CameraNode,
	GroundNode,

	Root,
	Head,
	Neck,
	Hips,
	Spine,
	Spine1,
	Spine2,


	LeftLeg,
	LeftFoot,
	LeftShoulder,
	LeftArm,
	LeftHand,
	LeftForearm,
	LeftAss,

	RightLeg,
	RightFoot,
	RightShoulder,
	RightArm,
	RightHand,
	RightForearm,
	RightAss,
}

return {
}