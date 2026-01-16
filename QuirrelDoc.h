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

/// @brief know what you are doing!!!!
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

// Globals

/// @brief Yield (use for while loops)
void Yield();

/// @param MilliSeconds
/// @return did sleep
bool Sleep(uint32 MilliSeconds);

/* KeyNames
0 1 2 3 4 5 6 7 8 9 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
- = , . ; / ` [ \ ] ' F1 F2 F3 F4 F5 F6 F7 F8 F9 F10 F11 F12
Backspace Capslock Ctrl Delete Down End Enter Esc Home Insert
RightAlt LeftAlt RightCtrl LeftCtrl RightMouse LeftMouse
MiddleMouse RightShift LeftShift NumLock Pageup Pagedown
Pause ScrollLock Shift Space Tab Up Mouse4 Mouse5
*/

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

/// @return Heated Metal version string (Ex: 0.1.8)
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
		const string Text;

		/// @brief What color is the text.
		Color Color;

		/// @brief Update text
		void SetText(string Text);
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
		const int32 Min;
		const int32 Max;
	};

	class SliderFloat : Element
	{
		/// @brief Current Value
		const float Value;

		/// @brief Slider Min/Max
		const float Min;
		const float Max;
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

		/// @brief Resize the window.
		void SetSize(Vector2 Size);

		/// @brief Move the window to a position on the screen.
		void SetPosition(Vector2 Position);

		/////////////////////////////////////////////

		/// @brief Background Alpha.
		float Alpha = 1.0;

		/// @brief Current window size.
		const Vector2 Size;

		/// @brief Current window position.
		const Vector2 Position;

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
		/// @brief Update text
		void SetText(string Text);

		/// @brief What are we rendering?
		const string Text;

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

		/// @brief Add a triangle
		OverlayTriangle* Triangle(Vector2 Position1, Vector2 Position2, Vector2 Position3);

		/// @brief Add a Rectangle
		OverlayRectangle* Rectangle(Vector2 Position, Vector2 Size, float Rounding);

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
		string Name();

		/// @brief Get the Components Owned Entity
		/// @return Owner Entity
		Entity* Entity();

		/// @brief Get/Set the components state
		bool GetActive();
		void SetActive(bool Active);
	};

	class DamageComponent : Component
	{
		class DamageData
		{
			/// @brief Set/Get health threshold for low health.
			void SetHealthLow(int32 Health);
			int32 GetHealthLow();
		
			/// @brief Set/Get health threshold for critical health.
			void SetHealthCritical(int32 Health);
			int32 GetHealthCritical();

			/// @brief Set/Get DBNO health amount
			void SetHealthDBNO(int32 Health);
			int32 GetHealthDBNO();
		
			/// @brief Set/Get max health
			void SetHealthMax(int32 Health);
			int32 GetHealthMax();
		
			/// @brief Set/Get how much extra health you can have
			void SetHealthMaxExtra(int32 Health);
			int32 GetHealthMaxExtra();

			// Set/Get how much fall damage to take
			void SetFallDamage(int32 Health);
			int32 GetFallDamage();

			///////////////////////////////
			/// DBNO

			// Set/Get maximum revives (-1 for infinite)
			void SetMaxRevives(int32 Revives);
			int32 GetMaxRevives();
		
			/// @brief Set/Get bleed out time (seconds)
			void SetBleedoutTime(int32 Time);
			int32 GetBleedoutTime();
		
			/// @brief Set/Get bleed out pressure
			void SetBleedoutPressure(float Multiplier);
			float GetBleedoutPressure();
		
			/// @brief Set/Get bleed out speed up
			void SetBleedoutSpeedUp(float Multiplier);
			float GetBleedoutSpeedUp();
		
			/// @brief Set/Get health percentage gain when revived
			void SetRevivedHealth();
			float GetRevivedHealth();

			/// @brief Set/Get health percentage gain when revived via doc stim
			void SetRevivedHealthDoc();
			float GetRevivedHealthDoc();
		
			///////////////////////////////
			/// Lethality (Damage Multipliers)

			/// @brief Set/Get melee damage multiplier
			void SetMeleeDamage(float Multiplier);
			float GetMeleeDamage();

			/// @brief Set/Get explosion damage multiplier
			void SetExplosionDamage(float Multiplier);
			float GetExplosionDamage();

			///////////////////////////////
			/// Toggles

			/// @brief Set/Get if DBNO is enabled
			void SetDBNO(bool Value);
			bool GetDBNO();

			/// @brief Set/Get if extra health stacking is enabled
			void SetExtraHealthStacking();
			void GetExtraHealthStacking();
		};

		/// @brief Set/Get health
		int32 GetHealth();
		void SetHealth(int32 Health);

		/// @brief Get DamageData Instance (Global Settings)
		DamageData *DamageData();
	};

	class WeaponComponent : Component
	{
		/// @brief Returns weapon data name (wip names most of the time)
		string Name();

		/// @brief Returns true if the weapon is reloading
		bool IsReloading();

		/// @brief Set/Get the current clip count
		uint32 GetAmmo();
		void SetAmmo(uint32 Value);

		class DamageWeaponData
		{
			/// @brief Set/Get Health Damage
			uint32 GetDamage();
			void SetDamage(uint32 Damage);

			/// @brief Set/Get Environmental Damage
			uint32 GetDamageEnv();
			void SetDamageEnv(uint32 Damage);
		};

		class AmmoWeaponData
		{
			/// @brief Should the clip remove ammo on firing a shot
			void InfiniteClip(bool Input);

			/// @brief Should the ammo reverse remove ammo on reload
			void InfiniteReserve(bool Input);

			/// @brief Set/Get the RPM
			uint32 GetFireRate();
			void SetFireRate(uint32 RPM);

			/// @brief Set/Get the bullets per shot
			uint32 GetBulletCount();
			void SetBulletCount(uint32 Count);

			/// @brief Set/Get the distance in Meters before the bullet gets ignored
			float GetBulletReach();
			void SetBulletReach(float Range);

			/// @brief Set/Get the Clip Max Capacity
			uint32 GetClipCapacity();
			void SetClipCapacity(uint32 Count);

			/// @brief Set/Get the caliber
			uint32 GetCaliber();
			void SetCaliber(uint32 Caliber);
		};

		class AccuracyWeaponData
		{
			/// @brief Set/Get base accuracy
			float GetBase();
			void SetBase(float Value);

			/// @brief Set/Get Walk accuracy
			float GetWalk();
			void SetWalk(float Value);

			/// @brief Set/Get crouch accuracy
			float GetCrouch();
			void SetCrouch(float Value);

			/// @brief Set/Get prone accuracy
			float GetProne();
			void SetProne(float Value);

			/// @brief Set/Get aim accuracy
			float GetAim();
			void SetAim(float Value);

			/// @brief Set/Get Weapon fire accuracy
			float GetFire();
			void SetFire(float Value);

			/// @brief Set/Get fast recovery (Instant spread recovery)
			bool GetFastRecovery();
			void SetFastRecovery(bool Statement);
		};

		class AnimationWeaponData
		{
			/// @brief Set/Get Weapon draw speed
			float GetDraw();
			void SetDraw(float Value);

			/// @brief Set/Get Weapon holster speed
			float GetHolster();
			void SetHolster(float Value);

			/// @brief Set/Get Weapon aim speed during sprint
			float GetSprintZoomIn();
			void SetSprintZoomIn(float Value);

			/// @brief Set/Get Weapon aim speed
			float GetZoomIn();
			void SetZoomIn(float Value);

			/// @brief Set/Get Weapon de-aim speed
			float GetZoomOut();
			void SetZoomOut(float Value);

			/// @brief Set/Get Weapon manual reload speed
			float GetReloadManual();
			void SetReloadManual(float Value);

			/// @brief Set/Get Weapon automatic reload speed
			float GetReloadAuto();
			void SetReloadAuto(float Value);
		};

		/// @brief Returns the Damage Data instance for the weapon
		DamageWeaponData* GetDamageData();

		/// @brief Returns the Ammo Data instance for the weapon
		AmmoWeaponData* GetAmmoData();

		/// @brief Returns the Accuracy Data instance for the weapon
		AccuracyWeaponData* GetAccuracyData();

		/// @brief Returns the Animation Data instance for the weapon
		AnimationWeaponData* GetAnimationData();
	};

	class PhysicComponent : Component
	{
		/// @brief Set/Get Collision Tag (eCollisionTag)
		uint32 GetCollisionTag();
		void SetCollisionTag(uint32 Tag);
	};

	class SpawnedGadgetComponent : Component
	{
		/// @brief Returns the owner of this gadget
		PlayerController* Owner();

		/// @brief Returns the gadget ObjectID
		objectid GadgetID();
	};

	class Entity : ManagedObject
	{
		/// @brief Get the name of the entity
		string Name();

		/// @brief Check if the entity still exists and is not unloaded
		bool IsValid();

		/// @brief Was the entity created from quirrel?
		bool IsQuirrel();

		/// @brief Is the entity a editor duplicate?
		bool IsEditor();

		/// @brief Is the entity a local?
		bool IsLocal();

		/// @brief Set/Get the entity World Origin
		Vector3 GetOrigin();
		void SetOrigin(Vector3 Origin);

		/// @brief Get the entity World Center Origin
		Vector3 GetCenter();

		/// @brief Set/Get the entity Angles
		Vector3 GetAngles();
		void SetAngles(Vector3 Angles);

		/// @brief Set/Get the entity Scale
		Vector3 GetScale();
		void SetScale(Vector3 Scale);

		/// @brief Set/Get the entity Min/Max
		Vector3 GetMin();
		Vector3 GetMax();

		/// @brief Get the entity Up/Right/Forward vector
		Vector3 GetRight();
		Vector3 GetForward();
		Vector3 GetUp();

		/// @brief Gets the GLOBAL origin of the bone (returns entity origin if not found).
		/// Enum can be found in the core module (eBone).
		/// @param Bone | Index
		Vector3 GetBoneOrigin(uint32 Bone);

		/// @brief Sets an outline of the entity (client side)
		void SetOutline(Color Color);

		/// @brief Get a clone of this entity
		/// @return Duplicated Entity
		Entity* Duplicate();

		/// @brief Get a clone of this entity with a seeded objectid
		/// @return Duplicated Entity
		Entity* DuplicateSeed(uint64 Seed);

		/// @brief Add or Remove the entity from the world
		/// @return Has the entity been Added/Removed
		/// !!!Duplicated entities are entirely removed!!!
		bool AddToWorld();
		bool RemoveFromWorld();

		/// @brief DeActivate/ReActivate all of the components of an entity
		/// Use this to temporarily Disable entities
		bool GetActive();
		void SetActive(bool IsActive);

		/// @brief Hide all visuals
		void SetIsHidden(bool IsHidden);

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
		DamageComponent* DamageComponent();

		/// @brief Returns the Weapon Component if the entity has one
		/// Only returns on host and changes are updated every 5s
		WeaponComponent* WeaponComponent();

		/// @brief Returns the Destruction Component if the entity has one
		/// Disable this to disable destruction
		Component* DestructionComponent();

		/// @brief Returns the Physics Component if the entity has one
		/// Disable this to disable Collision
		PhysicComponent* PhysicComponent();

		/// @brief Returns the Gadget Component if the entity has one
		SpawnedGadgetComponent* GadgetComponent();
	};

	class PlayerController
	{
		/// @brief Returns the name of the player
		string Name();

		/// @details Use eTeam
		/// @brief Returns the Team of the player
		uint32 Team();

		/// @details Use eAlliance
		/// @brief Returns the Alliance of the player
		uint32 Alliance();

		/// @brief Returns the PlayerID of the player
		uint64 PlayerID();

		/// @brief Returns the spectated controller if spectating
		PlayerController* Spectator();

		/// @brief Returns the controller entity
		Entity* Entity();

		/// @brief Returns a forward vector of where the player is looking
		Vector3 Forward();

		/// @brief Sets the players entity origin
		void SetOrigin(Vector3 Origin);
		
		//////////////////////////////////////////////////////////////////////
		
		/// @brief Returns the damage component instance
		DamageComponent* Damage();

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
		WeaponComponent* Weapon();
			
		/// @brief Returns the ObjectID of the weapon being held by the player
		objectid WeaponID();
		
		/// @brief Returns the ItemSlot index of the weapon being held by the player
		ItemSlot WeaponSlot();
	
		/// @brief Applies the currently equipped item with the provided ObjectID
		void ItemSlotApply(ItemSlot Slot, objectid ObjectID);

		/// @brief Removes the currently equipped item
		void ItemSlotRemove(ItemSlot Slot);

		/// @brief Returns the ObjectID of the equipped Primary
		objectid PrimaryID();

		/// @brief Returns the ObjectID of the equipped Secondary
		objectid SecondaryID();

		/// @brief Returns the ObjectID of the equipped Tertiary
		objectid TertiaryID();

		/// @brief Returns the ObjectID of the equipped Primary Gadget
		objectid PrimaryGadgetID();

		/// @brief Returns the ObjectID of the equipped Secondary Gadget
		objectid SecondaryGadgetID();

		/// @brief Returns the ObjectID of the equipped Headgear
		objectid HeadgearID();

		/// @brief Returns the ObjectID of the equipped Uniform
		objectid UniformID();

		/// @brief Returns the ObjectID of the character
		/// enum eCharacter in the core module
		objectid CharacterID();
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
		/// @brief Get the hit origin
		Vector3 Origin();

		/// @brief Get the hit delta
		float Delta();

		/// @brief Get the hit normal
		Vector3 Normal();

		/// @brief Get the entity
		Entity* Entity();

		/// @brief Get the Physic Component
		PhysicComponent* Component();
	};

	class RaycastResult
	{
		/// @brief Did the raycast hit anything?
		bool DidHit();

		/// @brief Get the array of hits
		Array<CastHit> Hits();
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
		/// @brief Get camera Right
		/// @return Returns the right direction vector of the camera as a quaternion.
		Quaternion Right();

		/// @brief Get camera Up
		/// @return Returns the up direction vector of the camera as a quaternion.
		Quaternion Up();

		/// @brief  Get camera Forward
		/// @return Returns the forward direction vector of the camera as a Vector4.
		Vector4 Forward();

		/// @brief Get camera Origin
		/// @return Returns the position of the camera in the world as a Vector4.
		Vector4 Origin();

		/// @brief Get Camera Fov
		/// @return Returns the field of view of the camera as a Vector2.
		Vector2 Fov();
	};

	/// @brief Returns the current view camera instance
	View* GetCamera();

	/////////////////////////////////////////////

	class VolumetricFog
	{
		// Client Side

		/// @brief Get/Set if fog is enabled
		bool IsEnabled();
		void SetIsEnabled(bool IsEnabled);

		/// @brief Get/Set sky lighting influence on fog
		float GetSkyLightingPower();
		void SetSkyLightingPower(float Power);

		/// @brief Get/Set the distance at which fog reaches full intensity
		float GetFullLightingDistance();
		void SetFullLightingDistance(float Distance);

		/// @brief Get/Set fog density
		float GetDensity();
		void SetDensity(float Density);

		/// @brief Get/Set upper height limit of fog
		float GetTop();
		void SetTop(float Top);

		/// @brief Get/Set lower height limit of fog
		float GetBottom();
		void SetBottom(float Bottom);

		/// @brief Get/Set fog direction on X axis
		float GetDirectionX();
		void SetDirectionX(float Dir);

		/// @brief Get/Set fog direction on Z axis
		float GetDirectionZ();
		void SetDirectionZ(float Dir);
	};

	class Skylight
	{
		// Client Side

		/// @brief Get/Set the suns lighting Intensity
		float GetSunIntensity();
		void SetSunIntensity(float Intensity);

		/// @brief Get/Set the skybox Intensity
		float GetSkyboxIntensity();
		void SetSkyboxIntensity(float Intensity);

		/// @brief Get/Set the Sun elevations Min/Max Intensity
		// (Min Controls the elevation Max acts as a hardlimit)
		float GetSunElevationMin();
		void SetSunElevationMin(float Min);

		float GetSunElevationMax();
		void SetSunElevationMax(float Max);

		/// @brief Get/Set the sun Rotation
		float GetSunRotation();
		void SetSunRotation(float Rotation);

		// Get the Fog Settings
		VolumetricFog GetVolumetricFog();
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