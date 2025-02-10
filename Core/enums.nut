global enum eGamestate
{
	Splash, // 0 Splash Screen
	ShutDown, // 1
	MainMenu, // 2 Main Menu
	CustomGame, // 3 Custom Games
	LoadingPreGame, // 4 Loading pre-game
	SelectMenu, // 5 Select Menu
	Loading, // 6 Loading
	InGame, // 7 In-Game
}

global enum eTeam
{
	A,
	B,
	Count,
	Invalid
}

global enum eMap
{
	Neighborhood = 0x431BA741C3,
	House = 0x37625C3900,
	Oregon = 0x35F2901CF4,
	Hereford = 0x2A3A99CB,
	ClubHouse = 0x31E6DF85,
	Plane = 0x9B858528,
	Yacht = 0x6961015C,
	Consulate = 0x9B858E7A,
	Bank = 0x9B858706,
	Kanal = 0x570932C9,
	Chalet = 0x3C7E4A5A5D,
	Barlett = 0xA0C50B9A,
	Kafe = 0x522587EA,
	Border = 0xCE4BB240,
	Favela = 0x77B43597E,
	Skyscraper = 0x8AF15096F,
	Coastline = 0x9CCC3D997,
	ThemePark = 0x2E8679C826,
	Tower = 0xC7C6E5654,
	Villa = 0x14839B2B18,
	HerefordRework = 0x1DCA7A2258,
	Fortress = 0x1D61EAFB8F,
	Outback = 0x2296804EC5,
	Menu = 0x9B2C8DC1,
}

global enum eTimeOfDay
{
	Default = 0xA45F6E8E,
	Day_Default = 0xA45F7850,
	Night_Default = 0xA45F7851,

	SmokeMode = 0x637399FB,

	Day = 0x19438604,
	Night = 0x19438605,
	Halloween = 0x2450CDB74D,
}

global enum eCaliber {
	Invalid_Caliber = 0x0,       // Invalid Caliber (Should result in a default caliber)
	Blowtorch = 0x7CFE9C27,      // Mavericks Blowtorch
	DP27 = 0x8616E1E0,           // Tachanka's DP27
	DP27_Turret = 0x033BC036,    // Tachanka's DP27 (Stationary Turret)
	Kali_Sniper = 0xDB87EF30,    // Kali's Sniper Rifle CRX300 / Golden Gun
	Skeletonkey = 0x487C2569,    // Buck's Skeleton Key
	Generic_Pistol = 0x0D67F306, // Normal Pistol
	Generic_Rifle = 0xE6589B1F,  // Normal Rifle
	Generic_Smg = 0x617A0088,    // Normal SMG
};

global enum eExplosion
{
	NitroCell,
	Smoke,
	Flash,
	Dazzler,
	ConcussionMine,
	ClusterCharge,
	Shumika,
	EMP,

	ExplosionBelt,
};

global enum NotificationType
{
	Info,
	Warning,
	Error,
	Success
};

return {

}