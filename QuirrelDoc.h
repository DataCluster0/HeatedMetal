//////////////////////////////////////////////
// QUIRREL DEFINITIONS
/////////////////////////////////////////////

/////////////////////////////////////////////
// Language Documentation : https://quirrel.io/doc/reference/language.html
/////////////////////////////////////////////

/////////////////////////////////////////////
// VS Code Extensions
/////////////////////////////////////////////
// https://marketplace.visualstudio.com/items?itemName=marcinbar.vscode-squirrel
// https://marketplace.visualstudio.com/items?itemName=mepsoid.vscode-s-quirrel
/////////////////////////////////////////////

// Stop VS Code from complaining (this is purely for nicer viewing of the file)

typedef const char* string;

typedef signed char int8;
typedef short int16;
typedef int int32;
typedef long long int64;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef unsigned long long objectid;

typedef function;
typedef table;

template <typename Type>
struct Array
{
};

// forward
typedef class PlayerController;
typedef class Entity;

//////////////////////////////////////////////
// Math Classes
/////////////////////////////////////////////

class Vector2
{
	float x, y;

	Vector2(float x, float y);

	float Length();
	float LengthSq();
	Vector2 Normalize();
	float Dot(Vector2 Other);
};

class Vector3
{
	float x, y, z;

	Vector3(float x, float y, float z);
	Vector4 ToVec4();
	Quaternion ToQuat();

	float Length();
	float LengthSq();
	Vector3 Normalize();
	Vector3 Round(float Precision);
	float Dot(Vector3 Other);
	Vector3 Cross(Vector3 Other);
	float Distance(Vector3 Other);
};

class Vector4
{
	float x, y, z, w;

	Vector4(float x, float y, float z, float w);
	Vector3 ToVec3();
	Quaternion ToQuat();

	float Length();
	float LengthSq();
	Vector4 Normalize();
	float Dot(Vector4 Other);
	Vector4 Cross(Vector4 Other);
	float Distance(Vector4 Other);
};

class Quaternion
{
	float x, y, z, w;

	Quaternion(float x, float y, float z, float w);
	Vector3 ToVec3();
	Vector4 ToVec4();

	Vector3 Rotate(Vector3 Input);
	Quaternion Conjugate();
	Quaternion Inverse();
	Quaternion Normalize();
};

class Color
{
	float R, G, B, A;

	Color(float R, float G, float B, float A);

	/// @brief 255 RGB -> 1.0 RGB
	static Color RGB(float R, float G, float B, float A);

	/// @brief Returns the inverted color values
	Color Invert();

	Color Fade(Color To, float Factor);

	/// @brief Returns a Random Color (from current time)
	static Color Random();

	/// @brief Returns a Random Color with a provided seed
	static Color RandomS(uint32 Seed);

	/// @brief Returns a Rainbow Color with a provided speed
	static Color Rainbow(float Speed);
};

//////////////////////////////////////////////
// Utility Classes
/////////////////////////////////////////////

/// @brief Uses a seconds | 1.0 = Second or | 0.5 = Half a second
class Timer
{
	/// @brief Creates a timer
	/// @param StartNow should the timer start counting from creation time?
	Timer(bool StartNow);

	/// @brief Starts the timer.
	void Start();

	/// @brief Resets the timer.
	void Reset();

	/// @brief Gets the elapsed time in seconds.
	float ElapsedTime();

	/// @brief Checks if a specified duration has elapsed. (Resets timer if true)
	bool HasElapsed(float time);
};

/// @brief You should know how to use this otherwise don't
class Pointer
{
	/// @brief Read/Write a boolean value.
	bool GetBool(uint64 offset);
	void SetBool(uint64 offset, bool value);

	/// @brief Read/Write an Int8.
	int8 GetInt8(uint64 offset);
	void SetInt8(uint64 offset, int8 value);

	/// @brief Read/Write a Uint8.
	uint8 GetUint8(uint64 offset);
	void SetUint8(uint64 offset, uint8 value);

	/// @brief Read/Write an Int16.
	int16 GetInt16(uint64 offset);
	void SetInt16(uint64 offset, int16 value);

	/// @brief Read/Write a Uint16.
	uint16 GetUint16(uint64 offset);
	void SetUint16(uint64 offset, uint16 value);

	/// @brief Read/Write an Int32.
	int32 GetInt32(uint64 offset);
	void SetInt32(uint64 offset, int32 value);

	/// @brief Read/Write a Uint32.
	uint32 GetUint32(uint64 offset);
	void SetUint32(uint64 offset, uint32 value);

	/// @brief Read/Write an Int64.
	int64 GetInt64(uint64 offset);
	void SetInt64(uint64 offset, int64 value);

	/// @brief Read/Write a Uint64.
	uint64 GetUint64(uint64 offset);
	void SetUint64(uint64 offset, uint64 value);

	/// @brief Read/Write a Float.
	float GetFloat(uint64 offset);
	void SetFloat(uint64 offset, float value);

	/// @brief Read/Write a Double.
	double GetDouble(uint64 offset);
	void SetDouble(uint64 offset, double value);

	/// @brief Read/Write a Vector2.
	Vector2 GetVector2(uint64 offset);
	void SetVector2(uint64 offset, Vector2 value);

	/// @brief Read/Write a Vector3.
	Vector3 GetVector3(uint64 offset);
	void SetVector3(uint64 offset, Vector3 value);

	/// @brief Read/Write a Vector4.
	Vector4 GetVector4(uint64 offset);
	void SetVector4(uint64 offset, Vector4 value);

	/// @brief Read/Write a Quaternion.
	Quaternion GetQuat(uint64 offset);
	void SetQuat(uint64 offset, Quaternion value);

	/// @brief Read a pointer.
	Pointer* Read(uint64 offset);
};

//////////////////////////////////////////////
// Modules, Classes, Functions
/////////////////////////////////////////////

/* KeyNames
0 1 2 3 4 5 6 7 8 9 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
- = , . ; / ` [ \ ] ' F1 F2 F3 F4 F5 F6 F7 F8 F9 F10 F11 F12
Backspace Capslock Ctrl Delete Down End Enter Esc Home Insert
RightAlt LeftAlt RightCtrl LeftCtrl RightMouse LeftMouse
MiddleMouse RightShift LeftShift NumLock Pageup Pagedown
Pause ScrollLock Shift Space Tab Up Mouse4 Mouse5
*/

/// @param MilliSeconds
/// @return did sleep
bool Sleep(uint32 MilliSeconds);

/// @brief Check if the key is was pressed.
/// @return Was the key pressed
bool IsKeyPressed(string KeyName);

/// @brief Check if the key is currently not being held.
/// @return Is the key not being held.
bool IsKeyUp(string KeyName);

/// @brief Check if the key is currently being held.
/// @return Is the key being held.
bool IsKeyDown(string KeyName);

/// @brief Registers a keybind
bool RegisterKeybind(string KeyName, function Callback);

/// @brief Registers a console command
/// @param Array<String> | Arguments
bool RegisterCommand(function Callback, string Name, string Arguments, string Description);

/// @return Heated Metal version string (Ex: 0.4.0)
string HMVersion();

/// @return Heated Metal version numbers.
uint32 HMMajor();
uint32 HMMinor();
uint32 HMPatch();
uint32 HMRevision();
uint32 HMRevisionPatch();

/////////////////////////////////////////////
// Modules

/// @return Is the module currently loaded?
bool IsModuleLoaded(string ModuleName);

/// @return Returns the defined 'Version' of a module
uint32 GetModuleVersion(string ModuleName);

/// @return Returns the defined 'VersionString' of a module
string GetModuleVersionString(string ModuleName);

/////////////////////////////////////////////

/// @brief Returns the current engine time. (Time from game start)
float EngineTime();

/// @brief Returns the current delta time.
float DeltaTime();

/// @brief Returns a random float from 0.f to {Max}.
float RandomFloat(float Max);

/// @brief Returns a random float from {Min} to {Max}.
float RandomFloatRange(float Min, float Max);

/// @brief Returns a random int from 0 to {Max}.
int64 RandomInt(int64 Max);

/// @brief Returns a random int from {Min} to {Max}.
int64 RandomIntRange(int64 Min, int64 Max);

/////////////////////////////////////////////
// Network

/// @brief Sends a table over the network (see AddCallback_NetworkTable)
/// @param string           | Table name for callback
/// @param table            | Table | Accepted Values : bool, int, float, string
/// @param PlayerController | Server only option (only sends the table to that player)
void SendNetworkTable(string Name, table Table, PlayerController Receiver /*Server Optional*/);

//////////////////////////////////////////////
// Renderer class
/////////////////////////////////////////////

class Renderer // SDK Native
{
	/// @brief Returns the current display size as a Vector2.
	Vector2 DisplaySize();

	/// @brief Returns the current mouse display coordinates.
	Vector2 MousePos();

	/// @brief Returns direction vector from the specified screen coordinates
	Vector3 ScreenToWorld(Vector2 Screen);

	/// @brief Calculates alpha value based on distance.
	float DistanceToAlpha(float Distance, float MaxDistance, float MinAlpha = 25.0, float MaxAlpha = 255.0);

	/////////////////////////////////////////////
	// 3D

	/// @brief Draws a 3D text at the specified origin.
	bool Text(string Text, Vector3 Origin, Color Color);

	/// @brief Draws a 3D text at the specified origin.
	bool TextScaled(string Text, Vector3 Origin, float FontSize, Color Color);

	/// @brief Draws a 3D line from start to end with specified thickness.
	bool Line(Vector3 StartOrigin, Vector3 EndOrigin, Color Color, float Thickness);

	/// @brief Draws a 3D triangle.
	bool Triangle(Vector3 Origin, Vector3 Point1, Vector3 Point2, Vector3 Point3, Vector3 Point, Color Color, float Thickness);

	/// @brief Draws a 3D rectangle.
	bool Rectangle(Vector3 Origin, Vector3 Angles, float Width, float Height, Color Color, float Thickness);

	/// @brief Draws a 3D circle.
	bool Circle(Vector3 Origin, Vector3 Angles, float Radius, int NumSegments, Color Color, float Thickness);

	/// @brief Draws a 3D cylinder.
	bool Cylinder(Vector3 Origin, Vector3 Angles, float Radius, float Height, int NumSegments, Color Color, float Thickness);

	/// @brief Draws a 3D Sphere.
	bool Sphere(Vector3 Origin, Vector3 Angles, float Radius, int NumSegments, Color Color, float Thickness);

	/// @brief Draws a 3D cube.
	bool Cube(Vector3 Origin, Vector3 Angles, float Size, Color Color, float Thickness);

	/////////////////////////////////////////////
	/// Window Elements

	class Element
	{
		/// @brief Is this element being drawn?
		bool Active;

		/// @brief Is this element disabled?
		bool Disabled;
	};

	class ElementText : Element
	{
		/// @brief Current text.
		string Text;

		/// @brief What color is the text.
		Color Color;
	};

	class Button : Element
	{
		/// @brief How big is the button?
		Vector2 Size;
	};

	class SliderInt : Element
	{
		/// @brief Current Value
		const int32 Value;

		/// @brief Slider Min/Max
		int32 Min;
		int32 Max;
	};

	class SliderFloat : Element
	{
		/// @brief Current Value
		const float Value;

		/// @brief Slider Min/Max
		float Min;
		float Max;
	};

	class Gui : Element
	{
		/// @brief Adds a tree node
		Gui* Tree(string Name, bool OpenByDefault);

		/// @brief Adds text
		ElementText* Text(string Text);

		/// @brief Adds a separator
		Element* SameLine();

		/// @brief Adds a separator
		Element* Separator();

		/// @brief Adds a text separator
		ElementText* SeparatorText(string Text);

		/// @brief Adds a button
		Button* Button(string Name, function Callback);

		/// @brief Adds a selectable
		Element* Selectable(string Name, function Callback);

		/// @brief Adds a toggle
		/// @param bool | Changed Value
		Element* Toggle(string Name, bool InitialValue, function Callback);

		/// @brief Adds an int slider
		/// @param int32 | Changed Value
		SliderInt* SliderInt(string Name, int32 InitialValue, int32 Min, int32 Max, function Callback);

		/// @brief Adds an float slider
		/// @param float | Changed Value
		SliderFloat* SliderFloat(string Name, float InitialValue, float Min, float Max, function Callback);
	};

	class Window : Gui
	{
		/// @brief Create a tab element.
		Gui* Tab(string Name);

		/////////////////////////////////////////////

		/// @brief Background Alpha.
		float Alpha = 1.0;

		/// @brief Current window size.
		Vector2 Size;

		/// @brief Current window position.
		Vector2 Position;

		/////////////////////////////////////////////

		/// @brief Should the window block input to the game?
		bool BlockInput = true;

		/// @brief Should the window auto resize?
		bool AutoResize;

		/// @brief Disable the title bar.
		bool NoTitleBar;

		/// @brief Disable the window from having a scroll bar
		bool NoScrollBar;

		/////////////////////////////////////////////

		/// @details User Action
		/// @brief Disable the window from being resized.
		bool NoResize;

		/// @details User Action
		/// @brief Disable the window from being moved.
		bool NoMove;

		/// @details User Action
		/// @brief Disable the window from being collapsed.
		bool NoCollapse;
	};

	/////////////////////////////////////////////
	/// Overlay Elements

	class ElementOverlay : Element
	{
		/// @brief Is the Element filled?
		bool Filled;

		/// @brief Is the Element outlined?
		bool Outlined;

		/// @brief Is the Element centered?
		bool Centered;

		/// @brief Does the Element have a border?
		bool Bordered;

		/// @brief Element Thickness
		float Thickness = 1.0;

		/// @brief Element Color
		Color Color;
	};

	class OverlayText : ElementOverlay
	{	
		/// @brief What are we rendering?
		string Text;

		/// @brief How is the text?
		float Scale = 1.0;

		/// @brief Where is the text being drawn at?
		Vector2 Position;
	};

	class OverlayLine : ElementOverlay
	{
		/// @brief Where does the line start at?
		Vector2 Start;

		/// @brief Where does the line end?
		Vector2 End;
	};

	class OverlayCircle : ElementOverlay
	{
		/// @brief Where are we drawing the circle at?
		Vector2 Position;

		/// @brief How big is the circle?
		float Radius = 1.0;

		/// @brief How many segments does the circle have?
		int Segments = 0;
	};

	class OverlayTriangle : ElementOverlay
	{
		/// @brief Where are we drawing the triangle edges at?
		Vector2 Position1;
		Vector2 Position2;
		Vector2 Position3;
	};

	class OverlayRectangle : ElementOverlay
	{
		/// @brief Where are we drawing the Rectangle?
		Vector2 Position;

		/// @brief How big is the Rectangle?
		Vector2 Size;

		/// @brief How rounded are the edges?
		float Rounding = 0.0;
	};

	class OverlayQuad : ElementOverlay
	{
		/// @brief Where are we drawing the Quad edges at?
		Vector2 Position1;
		Vector2 Position2;
		Vector2 Position3;
		Vector2 Position4;
	};

	class Overlay : Element
	{
		/// @brief Add text.
		OverlayText* Text(string Text, Vector2 Position);

		/// @brief Add a line.
		OverlayLine* Line(Vector2 Start, Vector2 End);

		/// @brief Add a circle.
		OverlayCircle* Circle(Vector2 Position, float Radius, int Segments);

		/// @brief Add a Rectangle
		OverlayRectangle* Rectangle(Vector2 Position, Vector2 Size, float Rounding);

		/// @brief Add a triangle
		OverlayTriangle* Triangle(Vector2 Position1, Vector2 Position2, Vector2 Position3);

		/// @brief Add a Quad
		OverlayQuad* Quad(Vector2 Position1, Vector2 Position2, Vector2 Position3, Vector2 Position4);
	};

	/////////////////////////////////////////////

	/// @brief Creates a window instance.
	/// Use Window.Active = true to enable the window.
	/// @param string  | Window Name
	/// @param Vector2 | Window Size
	Window* CreateWindow(string Name, Vector2 Size);

	/// @brief Creates a overlay instance.
	/// Use Overlay.Active = true to enable the overlay.
	Overlay* CreateOverlay();
};

/////////////////////////////////////////////
// Game class
/////////////////////////////////////////////

class Game // Native
{
	// Only Derived
	class ManagedObject
	{
		objectid ObjectID;
	};

	class Component : ManagedObject
	{
		/// @brief Returns the component name
		const string Name;

		/// @brief Owner Entity
		const Entity* Entity;

		/// @brief component state
		bool Active;
	};

	class DamageComponent : Component
	{
		class DamageData
		{
			/// @brief Health threshold for low health.
			int32 HealthLow;
		
			/// @brief Health threshold for critical health.
			int32 HealthCritical;

			/// @brief DBNO health amount
			int32 HealthDBNO;
		
			/// @brief Max health
			int32 HealthMax;
		
			/// @brief How much extra health you can have
			int32 HealthMaxExtra;

			// How much fall damage to take
			int32 FallDamage;

			///////////////////////////////
			/// DBNO

			// Maximum revives (-1 for infinite)
			int32 MaxRevives;
		
			/// @brief Bleed out time (seconds)
			int32 BleedoutTime;
		
			/// @brief Bleed out pressure
			float BleedoutPressure;
		
			/// @brief Bleed out speed up
			float BleedoutSpeedUp;
		
			/// @brief Health percentage gain when revived
			float RevivedHealth;

			/// @brief Health percentage gain when revived via doc stim
			float RevivedHealthDoc;
		
			///////////////////////////////
			/// Lethality (Damage Multipliers)

			/// @brief Melee damage multiplier
			float MeleeDamage;

			/// @brief Explosion damage multiplier
			float ExplosionDamage;

			///////////////////////////////
			/// Toggles

			/// @brief if DBNO is enabled
			bool DBNO;

			/// @brief if extra health stacking is enabled
			bool ExtraHealthStacking;
		};

		/// @brief Current health
		int32 Health;

		/// @brief DamageData Instance (Global Settings)
		const DamageData *DamageData;
	};

	class WeaponComponent : Component
	{
		/// @brief Weapon data name (wip names most of the time)
		const string Name;

		/// @brief Is the weapon reloading?
		const bool IsReloading;

		/// @brief Current clip count
		//uint32 Ammo;

		/// @brief Current weapon rpm (how many bullets per second are we firing)
		const float RPM;

		class DamageWeaponData
		{
			/// @brief How much damage will the bullet deal to entities with a damage component?
			uint32 Damage;

			/// @brief How much damage to the environment will the bullet deal (Example: 0 the bullet will passthrough a single glass panel)
			uint32 DamageEnv;
		};

		class AmmoWeaponData
		{
			/// @brief Should the clip remove ammo on firing a shot
			bool InfiniteClip;

			/// @brief Should the ammo reverse remove ammo on reload
			bool InfiniteReserve;

			/// @brief How fast will the weapon fire?
			uint32 FireRate;

			/// @brief How many bullet will the gun fire at once?
			uint32 BulletCount;

			/// @brief At what distance will the bullets be ignored?
			float BulletReach;

			/// @brief How much ammo does the clip have?
			uint32 ClipCapacity;

			/// @brief What kind of damage to walls does the bullet do? (eCaliberID)
			uint32 Caliber;
		};

		class AccuracyWeaponData
		{
			/// @brief Base accuracy
			float Base;

			/// @brief Walk accuracy
			float Walk;

			/// @brief Crouch accuracy
			float Crouch;

			/// @brief Prone accuracy
			float Prone;

			/// @brief Aim accuracy
			float Aim;

			/// @brief Fire accuracy
			float Fire;

			/// @brief Fast recovery (Instant spread recovery)
			bool FastRecovery;
		};

		class AnimationWeaponData
		{
			/// @brief Weapon draw speed
			float Draw;

			/// @brief Weapon holster speed
			float Holster;

			/// @brief Weapon aim speed during sprint
			float SprintZoomIn;

			/// @brief Weapon aim speed
			float ZoomIn;

			/// @brief Weapon de-aim speed
			float ZoomOut;

			/// @brief Weapon manual reload speed
			float ReloadManual;

			/// @brief Weapon automatic reload speed
			float ReloadAuto;
		};

		/// @brief Returns the Damage Data instance for the weapon
		const DamageWeaponData* DamageData;

		/// @brief Returns the Ammo Data instance for the weapon
		const AmmoWeaponData* AmmoData;

		/// @brief Returns the Accuracy Data instance for the weapon
		const AccuracyWeaponData* AccuracyData;

		/// @brief Returns the Animation Data instance for the weapon
		const AnimationWeaponData* AnimationData;
	};

	class PhysicComponent : Component
	{
		/// @brief What collision tag does this physic component use? (eCollisionTag)
		uint32 CollisionTag;
	};

	class SpawnedGadgetComponent : Component
	{
		/// @brief Owner of this gadget
		const PlayerController* Owner;

		/// @brief Gadget ObjectID
		const objectid GadgetID;
	};

	class Entity : ManagedObject
	{
		/// @brief Get the name of the entity
		const string Name;

		/// @brief Check if the entity still exists and is not unloaded
		const bool IsValid;

		/// @brief Was the entity created from quirrel?
		const bool IsQuirrel;

		/// @brief Is the entity a editor duplicate?
		const bool IsEditor;

		/// @brief Is the entity a local?
		const bool IsLocal;

		/// @brief DeActivate/ReActivate all of the components of an entity
		/// Use this to temporarily Disable entities
		bool Active;

		/// @brief Hide all visuals
		void SetIsHidden(bool IsHidden);

		////////////////////////////////////////////////

		/// @brief World Center Origin
		const Vector3 Center;

		/// @brief World Origin
		Vector3 Origin;

		/// @brief Angles
		Vector3 Angles;

		/// @brief Scale
		Vector3 Scale;

		////////////////////////////////////////////////

		/// @brief entity Min/Max
		const Vector3 Min;
		const Vector3 Max;

		/// @brief entity Up/Right/Forward vector
		const Vector3 Right;
		const Vector3 Forward;
		const Vector3 Up;

		/// @brief Gets the GLOBAL origin of the bone (returns entity origin if not found).
		/// Enum can be found in the core module (eBone).
		/// @param Bone | Index
		Vector3 GetBoneOrigin(uint32 Bone);

		////////////////////////////////////////////////

		/// @brief Sets an outline of the entity (client side)
		void SetOutline(Color Color);

		////////////////////////////////////////////////

		/// @brief Get a clone of this entity
		/// @return Duplicated Entity
		Entity* Duplicate();

		/// @brief Get a clone of this entity with a seeded objectid
		/// @return Duplicated Entity
		Entity* DuplicateSeed(uint64 Seed);

		/// @brief Get a clone of this entity as an editor entity
		/// @return Duplicated Editor Entity (Saved in world file)
		Entity* DuplicateEditor();


		/// @brief Add or Remove the entity from the world
		/// @return Has the entity been Added/Removed
		/// !!!Duplicated entities are entirely removed!!!
		bool AddToWorld();
		bool RemoveFromWorld();

		////////////////////////////////////////////////

		/// @brief Victim takes damage by amount and type (attribution).
		void GiveDamage(int32 Amount, uint32 DamageType, objectid VictimID /*Entity*/);

		/// @brief Take damage by amount and type.
		void TakeDamage(int32 Amount, uint32 DamageType);

		////////////////////////////////////////////////

		/// @brief Will make each client sync the entities component data (Host Only)
		void SyncComponents();

		/// @brief Does the entity have this component?
		bool HasComponent(string Name);

		/// @brief Get all components
		Array<Component*> GetComponents();

		/// @brief Get all components that have a matching name (Case sensitive)
		Array<Component*> GetComponentsByName(string Name);

		/// @brief Get a component by index
		/// @return Returns null if the index is invalid
		Component* GetComponentByIndex(uint32 Index);

		////////////////////////////////////////////////

		/// @brief Returns the Damage Component if the entity has one
		const DamageComponent* DamageComponent;

		/// @brief Returns the Weapon Component if the entity has one
		/// Only returns on host and changes are updated every 5s
		const WeaponComponent* WeaponComponent;

		/// @brief Returns the Destruction Component if the entity has one
		/// Disable this to disable destruction
		const Component* DestructionComponent;

		/// @brief Returns the Physics Component if the entity has one
		/// Disable this to disable Collision
		const PhysicComponent* PhysicComponent;

		/// @brief Returns the Gadget Component if the entity has one
		const SpawnedGadgetComponent* GadgetComponent;
	};

	class PlayerController
	{
		/// @brief Name of the player
		const string Name;

		/// @details Use eTeam
		/// @brief Team of the player
		const uint32 Team;

		/// @details Use eAlliance
		/// @brief Alliance of the player
		const uint32 Alliance;

		/// @brief PlayerID of the player
		const uint64 PlayerID;

		/// @brief Spectated player if spectating
		const PlayerController* Spectator;

		/// @brief Controlled entity
		const Entity* Entity;

		/// @brief Forward vector of where the player is looking
		const Vector3 Forward;

		/// @brief Velocity vector of where the entity is going
		const Vector3 Velocity;

		/// @brief Mobility ( 100 baseline ) how fast is the base speed? (Resets after item swap)
		uint32 Mobility;

		/// @brief Sets the players entity origin
		void SetOrigin(Vector3 Origin);
		
		//////////////////////////////////////////////////////////////////////
		
		/// @brief Returns the damage component instance
		const DamageComponent* DamageComponent;

		//////////////////////////////////////////////////////////////////////
		
		/// @brief Defined as eItemSlot in core module
		enum ItemSlot
		{
			Primary,
			Secondary,
			Tertiary,

			PrimaryGadget,
			SecondaryGadget,

			Character // Causes bugs use with caution
		};
		
		/// @brief Returns the current instance of the weapon being held by the player
		const WeaponComponent* Weapon;

		//////////////////////////////////////////////////////////////////////

		/// @brief Applies the currently equipped item with the provided ObjectID
		void ItemSlotApply(ItemSlot Slot, objectid ObjectID);

		/// @brief Removes the currently equipped item
		void ItemSlotRemove(ItemSlot Slot);

		//////////////////////////////////////////////////////////////////////

		/// @brief Returns the ItemSlot index of the weapon being held by the player
		const ItemSlot WeaponSlot;

		/// @brief Returns the ObjectID of the weapon being held by the player
		const objectid WeaponID;
		
		/// @brief Returns the ObjectID of the equipped Primary
		const objectid PrimaryID;

		/// @brief Returns the ObjectID of the equipped Secondary
		const objectid SecondaryID;

		/// @brief Returns the ObjectID of the equipped Tertiary
		const objectid TertiaryID;

		/// @brief Returns the ObjectID of the equipped Primary Gadget
		const objectid PrimaryGadgetID;

		/// @brief Returns the ObjectID of the equipped Secondary Gadget
		const objectid SecondaryGadgetID;

		/// @brief Returns the ObjectID of the equipped Headgear
		const objectid HeadgearID;

		/// @brief Returns the ObjectID of the equipped Uniform
		const objectid UniformID;

		/// @brief Returns the ObjectID of the character
		/// enum eCharacter in the core module
		const objectid CharacterID;
	};

	//////////////////////////////////////////////
	// Controller & Entity Functions
	/////////////////////////////////////////////

	/// @brief Get the local Player instance
	PlayerController* GetLocalPlayer();

	/// @brief Get the local view Player instance
	/// (if the local Player is spectating an other Player this will return the spectated Player)
	PlayerController* GetViewPlayer();

	/// @brief Get Player instance by PlayerID
	PlayerController* GetPlayerByID(uint64 PlayerID);

	/// @brief Returns an array of Player instances
	Array<PlayerController*> GetPlayerList();

	/// @brief Returns an array of AI Entity instances
	Array<Entity*> GetAIList();

	/////////////////////////////////////////////

	/// @brief Returns existing duplicates of an entity
	/// @param ObjectID | Master ObjectID
	Array<Entity*> GetDuplicatedEntities(objectid ObjectID);

	/// @brief Returns static entity list
	Array<Entity*> GetEntityList();

	/// @brief Returns static entity list of all entities that contain that component
	/// @param String | Component Name (Case Sensitive)
	Array<Entity*> GetEntityListByComponent(string Name);

	/// @brief Returns local entity list in objectid form (use GetEntity)
	Array<objectid> GetEntityListLocal();

	/// @brief Get Entity if an instance exists
	/// @return Returns an Entity instance of an Object
	Entity* GetEntity(objectid ObjectID);

	/// @brief Create an Entity from addons
	/// @return Returns a duplicated entity
	Entity* CreateEntityAddon(objectid ObjectID);

	/////////////////////////////////////////////

	/// @brief Get Object pointer if exists
	/// @return Returns a Pointer instance of an Object
	Pointer* GetObject(objectid ObjectID);

	//////////////////////////////////////////////
	// Game State Functions
	/////////////////////////////////////////////

	/// @return Are we the host?
	bool IsHost();

	/// @return Is the current host config in ThirdPerson?
	bool IsThirdPerson();

	/// @return Is the current host config in RTS?
	bool IsRTS();

	/// @return Is the current player in the editor?
	bool IsEditor();

	/// @return Is the current player in the context menu?
	bool IsContext();

	/// @return Is the in-game UI disabled?
	bool IsUIDisabled();

	/// @brief Set the in-game ui disabled state.
	void SetIsUIDisabled(bool IsDisabled);

	/// @return Is the UI disabled by the user? (ToggleHideUI)
	bool IsUIDisabledUser();

	/////////////////////////////////////////////

	/// @brief Is a custom map currently loaded?
	bool IsCustomMap();

	/// @brief Returns the currently loaded custom map name (World MetaData must be set)
	/// @return string | Map Name
	string GetCustomMap();

	/// @brief Returns the ObjectID of the current World
	uint64 GetWorld();

	/// @brief Returns the ObjectID of the current GameMode
	uint64 GetGameMode();

	/// @brief Returns the ObjectID of the current Time Of Day layer
	uint64 GetTimeOfDay();

	/// @brief Returns the ObjectID of the current AI Difficulty layer
	uint64 GetDifficulty();

	/// @return Returns the current game state
	uint32 GetGameState();

	//////////////////////////////////////////////
	// Game Time Functions
	/////////////////////////////////////////////

	/// @return Is the Phase Timer Paused
	bool IsTimerPaused();

	/// @brief Pause/Unpause the Phase Timer
	void SetTimerPaused(bool IsPaused);

	/// @brief Set/Get the phase timers time
	void SetTimerRemaining(int32 TimeInSeconds);
	float GetTimerRemaining();

	//////////////////////////////////////////////
	// Game Round Functions
	/////////////////////////////////////////////
	// (eAlliance)

	/// @brief Force wins the current round for that Allience
	void SetRoundWin(uint32 Alliance);

	/// @brief Set/Get the current match round wins
	void SetRoundWinCount(uint32 Alliance, uint32 Count);
	uint32 GetRoundWinCount(uint32 Alliance);

	//////////////////////////////////////////////
	// Game Utility Functions
	/////////////////////////////////////////////

	/// @brief Adds a In-Game notification (Kill feed)
	/// @param Text       | Notification Text
	/// @param Color 	  | What color the notification is going to be. (eTeamColor)
	/// @param Replicate  | Should we send this to clients. (Server optional | Default : false)
	/// @param Receiver   | Who Receives the notification if empty and Replicate is true will replicate to everyone. (Server optional)
	void AddNotification(string Text, uint32 Color, bool Replicate /*optional*/, PlayerController Receiver /*optional*/);

	/// @brief Creates a dust particle at a certain location
	/// Has a hard limit of 100 (will conflict with Dust Painting)
	void CreateDust(Vector3 Origin, float Radius, Color Color);

	/// @brief Use eExplosion from the core module
	enum eExplosion : uint32
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

	/// @brief Creates an explosion at the specified origin
	/// Effects have a hard limit for some time
	/// Maximum of 50 calls per 5 seconds
	/// @param Origin      | Explosion Origin
	/// @param Type		   | Explosion Type
	/// @param Owner       | Who takes the credit (Optional)
	void CreateExplosion(Vector3 Origin, eExplosion Type, PlayerController Owner /*optional*/);

	class CastHit
	{
		/// @brief Hit origin
		const Vector3 Origin;

		/// @brief Hit delta
		const float Delta;

		/// @brief Hit normal
		const Vector3 Normal;

		/// @brief Entity
		const Entity* Entity;

		/// @brief  Physic Component
		const PhysicComponent* Component;
	};

	class RaycastResult
	{
		/// @brief Did the raycast hit anything?
		const bool DidHit;

		/// @brief Get the array of hits
		const Array<CastHit> Hits;
	};

	/// @brief Fires a raycast from and to the specified origin coordinates (Uses projectile filtering)
	/// @param Start       | Start Origin
	/// @param End		   | End Origin
	/// @param Count       | How many surfaces does it go trough
	RaycastResult Raycast(Vector3 Start, Vector3 End, uint8 Count);

	/// @brief Uses character gravity filtering instead of projectile filtering.
	RaycastResult RaycastCharacter(Vector3 Start, Vector3 End, uint8 Count);

	//////////////////////////////////////////////
	// Camera & Skylight
	/////////////////////////////////////////////

	class View
	{
		/// @brief Camera Right
		/// @return Returns the right direction vector of the camera as a quaternion.
		const Quaternion Right;

		/// @brief Camera Up
		const Quaternion Up;

		/// @brief Camera Forward
		const Vector4 Forward;

		/// @brief Camera Origin
		const Vector4 Origin;

		/// @brief Camera Fov
		const Vector2 Fov;
	};

	/// @brief Returns the current view camera instance
	View* GetCamera();

	/////////////////////////////////////////////

	class VolumetricFog
	{
		// Client Side

		/// @brief Is the fog enabled?
		bool IsEnabled;

		/// @brief Sky lighting influence on fog
		float SkyLightingPower;

		/// @brief The distance at which fog reaches full intensity
		float FullLightingDistance;

		/// @brief Fog density
		float Density;

		/// @brief Upper height limit of fog
		float Top;

		/// @brief Lower height limit of fog
		float Bottom;

		/// @brief Fog direction on X axis
		float DirectionX;

		/// @brief Fog direction on Z axis
		float DirectionZ;
	};

	class Skylight
	{
		/// @brief Suns lighting Intensity
		float SunIntensity;

		/// @brief Skybox Intensity
		float SkyboxIntensity;

		/// @brief Sun elevations Min/Max Intensity
		// (Min Controls the elevation Max acts as a hardlimit)
		float SunElevationMin;
		float SunElevationMax;

		/// @brief Sun Rotation
		float GetSunRotation;

		// Get the Fog Settings
		const VolumetricFog VolumetricFog;
	};

	/// @brief Returns the current skylight instance
	Skylight* GetSkylight();

	/////////////////////////////////////////////
};

/////////////////////////////////////////////
// CALLBACKS
/////////////////////////////////////////////

// !! RoundStart is kept across world reloads. !!
// !! Every other Callback is cleared. !!

/// @details Not Threaded !
/// @brief Called when the user requests the modules to be shutdown.
void AddCallback_Shutdown(function Func);

/// @details Not Threaded !
/// @brief Called every game tick.
void AddCallback_Update(function Func);

/// @brief Called at Round Start
/// @param ObjectID | WorldID (eMap in core module)
void AddCallback_RoundStart(function Func);

/// @brief Called at Round End
void AddCallback_RoundEnd(function Func);

/// @brief Called when a bullet hits the ground
/// @param Vector3 | Start
/// @param Vector3 | End
/// @param Vector3 | Normal
/// @param float   | Delta
/// @param Entity  | Hit Entity
void AddCallback_BulletHit(function Func);

/// @brief Called when damage is caused
/// @param DamageComponent   | Hit Damage Component
/// @param uint32            | Taken Damage
/// @param uint32            | Damage Type (eDamageType)
/// @param PlayerController  | Attacker
/// @param PlayerController  | Victim
void AddCallback_Damage(function Func);

/// @brief Called when an entity effect is caused
/// @param Entity   | Instigator
/// @param Entity   | Source
/// @param uint32   | Effect Type (eEntityEffect)
void AddCallback_EntityEffect(function Func);

/////////////////////////////////////////////
// NETWORK CALLBACKS
/////////////////////////////////////////////

/// @brief Called when a server or client sends a network table (see SendNetworkTable)
/// @param string             | Table Name
/// @param table              | Table
/// @param PlayerController   | Sender (null if sent from server)
void AddCallback_NetworkTable(function Func);

/////////////////////////////////////////////
// WEAPON CALLBACKS
/////////////////////////////////////////////
/// @param WeaponComponent | Weapon

/// @brief Weapon has zoomed in
void AddCallback_WeaponZoomIn(function Func);

/// @brief Weapon has zoomed out
void AddCallback_WeaponZoomOut(function Func);

/// @brief Weapon started firing
void AddCallback_WeaponFire(function Func);

/// @brief Weapon stopped firing
void AddCallback_WeaponFireStop(function Func);

/////////////////////////////////////////////
// PLAYER CONTROLLER CALLBACKS
/////////////////////////////////////////////
/// @param PlayerController | Player

/// @brief Called on Controller Death.
void AddCallback_PlayerDeath(function Func);

/// @brief Called on Controller Spawn/Respawn
void AddCallback_PlayerSpawn(function Func);

/// @brief Toggle Callbacks
void AddCallback_LeanRight(function Func);
void AddCallback_LeanLeft(function Func);
void AddCallback_Crouch(function Func);
void AddCallback_Prone(function Func);

void AddCallback_Melee(function Func);
void AddCallback_Interact(function Func);
void AddCallback_AccessDrone(function Func);

/// @brief Called when a player does a yellow ping
/// @param PlayerController  | Instigator
/// @param Vector3           | World Position
void AddCallback_Ping(function Func);

/////////////////////////////////////////////
// GADGET CALLBACKS
/////////////////////////////////////////////

/// @brief Called when a Gadget is spawned
/// @param PlayerController  | Instigator
/// @param Entity            | Gadget
/// @param ObjectID          | Gadget ObjectID
void AddCallback_GadgetSpawned(function Func);

/// @brief Called when a Gadget is picked up
/// @param PlayerController  | Instigator
/// @param Entity            | Gadget
/// @param ObjectID          | Gadget ObjectID
void AddCallback_GadgetPickup(function Func);

/// @brief Called when a Gadget has stuck to a wall
/// @param PlayerController  | Instigator
/// @param Entity            | Gadget
/// @param ObjectID          | Gadget ObjectID
void AddCallback_GadgetStickied(function Func);

/// @brief Called when a Gadget has blown up
/// @param PlayerController  | Instigator
/// @param Entity            | Gadget
/// @param ObjectID          | Gadget ObjectID
void AddCallback_GadgetDetonated(function Func);

/////////////////////////////////////////////
// CHARACTER CALLBACKS
/////////////////////////////////////////////

/// @brief Called when a Character has started to fall
/// @param PlayerController  | Instigator
void AddCallback_CharacterFalling(function Func);

/// @brief Called when a Character has landed
/// @param PlayerController  | Instigator
void AddCallback_CharacterLanding(function Func);

/////////////////////////////////////////////
// GAMEMODE CALLBACKS
/////////////////////////////////////////////

/// @brief Called when a Defuser is deployed
/// @param PlayerController  | Instigator
/// @param uint32            | Alliance (eAlliance)
/// @param Entity            | Bomb
void AddCallback_DefuserDeployed(function Func);

/// @brief Called when a Defuser is sabotaged
/// @param PlayerController  | Instigator
/// @param uint32            | Alliance (eAlliance)
void AddCallback_DefuserSabotaged(function Func);

/// @brief Called when a Defuser finishes defusing
/// @param PlayerController  | Instigator
/// @param uint32            | Alliance (eAlliance)
/// @param Entity            | Bomb
void AddCallback_DefuserSucceeded(function Func);

/// @brief Called when a Player Drops/Picks up a Defuser
/// @param PlayerController  | Instigator
void AddCallback_DefuserDropped(function Func);
void AddCallback_DefuserPickedUp(function Func);