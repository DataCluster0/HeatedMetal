//////////////////////////////////////////////
// QUERREL DEFINITIONS
/////////////////////////////////////////////

/////////////////////////////////////////////
// Language Documentation : https://quirrel.io/doc/reference/language.html
/////////////////////////////////////////////

/////////////////////////////////////////////
// VS Code Extentions
/////////////////////////////////////////////
// https://marketplace.visualstudio.com/items?itemName=marcinbar.vscode-squirrel
// https://marketplace.visualstudio.com/items?itemName=mepsoid.vscode-s-quirrel
/////////////////////////////////////////////

// Stop VS Code from complaining (this is purely for nicer viewing of the file)
typedef string;

typedef int8;
typedef int16;
typedef int32;
typedef int64;

typedef uint8;
typedef uint16;
typedef uint32;
typedef uint64;
typedef quirrelfunc;

template <typename Type>
struct Array
{
};

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

class Timer
{
	Timer(bool StartNow);

	/// @brief Starts the timer.
	void Start();

	/// @brief Resets the timer.
	void Reset();

	/// @brief Gets the elapsed time in seconds.
	float ElapsedTime();

	/// @brief Checks if a specified duration has elapsed.
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

/// @brief Check if the key is currently pressed
/// @return Was the key pressed
bool IsKeyPressed(string KeyName);

/* KeyNames
0 1 2 3 4 5 6 7 8 9 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
- = , . ; / ` [ \ ] ' F1 F2 F3 F4 F5 F6 F7 F8 F9 F10 F11 F12
Backspace Capslock Ctrl Delete Down End Enter Esc Home Insert
RightAlt LeftAlt RightCtrl LeftCtrl RightMouse LeftMouse
MiddleMouse RightShift LeftShift NumLock Pageup Pagedown
Pause ScrollLock Shift Space Tab Up XButton1 XButton2
*/

/// @brief Returns the current delta time
float DeltaTime();

/// @brief Returns a random float from 0.f to {Max}
float RandomFloat(float Max);

/// @brief Returns a random float from {Min} to {Max}
float RandomFloatRange(float Min, float Max);

/// @brief Returns a random int from 0 to {Max}
int64 RandomInt(int64 Max);

/// @brief Returns a random int from {Min} to {Max}
int64 RandomIntRange(int64 Min, int64 Max);

/////////////////////////////////////////////
// CALLBACKS
/////////////////////////////////////////////
// !! RoundStart is kept across world reloads. !!
// !! Every other Callback is cleared. !!

/// @brief Calls when the user requests the modules to be shutdown
void AddCallback_Shutdown();

/// @brief Calls every game tick
void AddCallback_Update();

/// @brief Weapon Callbacks
/// @param WeaponComponent | Weapon
void AddCallback_WeaponZoomIn();   // Weapon has zoomed in
void AddCallback_WeaponZoomOut();  // Weapon has zoomed out
void AddCallback_WeaponFire();	   // Weapon started firing
void AddCallback_WeaponFireStop(); // Weapon stopped firing

/// @brief Called when a player uses a melee
/// @param PlayerController | Player
void AddCallback_Melee();

/// @brief Called when a bullet hits the ground
/// @param Vector3 | Start
/// @param Vector3 | End
/// @param Vector3 | Type_Normal
/// @param float   | Delta
/// @param Entity  | HitEntity
void AddCallback_BulletHit();

/// @brief Calls at Round Startreturns the current WorldID check core enums.nut for the ids
/// @param ObjectID | WorldID
void AddCallback_RoundStart();

/////////////////////////////////////////////

class Renderer // SDK Native
{
	/// @brief Returns the current display size as a Vector2.
	Vector2 GetDisplaySize();

	/// @brief Draws a 3D text at the specified origin.
	bool Text(Vector3 Origin, string Text, Color Color);

	/// @briefDraws a 3D line from start to end with specified thickness.
	bool Line(Vector3 StartOrigin, Vector3 EndOrigin, Color Color, float Thickness = 1.0);

	/// @brief Draws a 3D rectangle.
	bool Rectangle(Vector3 Origin, Vector3 Angles, float Width, float Height, Color Color, float Thickness = 1.0);

	/// @briefDraws a 3D circle.
	bool Circle(Vector3 Origin, Vector3 Angles, float Radius, int NumSegments, Color Color, float Thickness = 1.0);

	/// @brief Draws a 3D cylinder.
	bool Cylinder(Vector3 Origin, Vector3 Angles, float Radius, float Height, int NumSegments, Color Color, float Thickness = 1.0);

	/// @brief Draws a 3D Sphere.
	bool Sphere(Vector3 Origin, Vector3 Angles, float Radius, int NumSegments, Color Color, float Thickness = 1.0);

	/// @brief Draws a 3D cube.
	bool Cube(Vector3 Origin, Vector3 Angles, float Size, Color Color, float Thickness = 1.0);

	/// @brief Calculates alpha value based on distance.
	float DistanceToAlpha(float Distance, float MaxDistance, float MinAlpha = 25.0, float MaxAlpha = 255.0);
};

// vs code forward
class Entity;

class Game // Native
{
	// Only Derived
	class ManagedObject
	{
		uint64 ObjectID;
	};

	class Component : ManagedObject
	{
		/// @brief Get the Components Owned Entity
		/// @return Owner Entity
		Entity* Entity();

		/// @brief Get/Set the components state
		bool GetActive();
		void SetActive(bool Active);
	};

	class DamageComponent : Component
	{
		/// @brief Set/Get health
		int32 GetHealth();
		void SetHealth(int32 Health);

		/// @brief Set/Get Max health
		int32 GetMaxHealth();
		void SetMaxHealth(uint32 MaxHealth);

		/// @brief Set/Get Max health
		int32 GetFallDamage();
		void SetFallDamage(int32 FallDamage);
	};

	class WeaponComponent : Component
	{
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

		class DamageWeaponData
		{
			/// @brief Set/Get Health Damage
			uint32 GetDamage();
			void SetDamage(uint32 Damage);

			/// @brief Set/Get Environmental Damage
			uint32 GetDamageEnv();
			void SetDamageEnv(uint32 Damage);
		};

		class AccuracyWeaponData
		{
			/// @brief Set/Get Base Accuracy
			float GetBase();
			void SetBase(float Value);

			/// @brief Set/Get Walk Accuracy
			float GetWalk();
			void SetWalk(float Value);

			/// @brief Set/Get Crouch Accuracy
			float GetCrouch();
			void SetCrouch(float Value);

			/// @brief Set/Get Prone Accuracy
			float GetProne();
			void SetProne(float Value);

			/// @brief Set/Get Aim Accuracy
			float GetAim();
			void SetAim(float Value);

			/// @brief Set/Get Weapon Fire Accuracy
			float GetFire();
			void SetFire(float Value);

			/// @brief Set/Get Fast Recovery (Accuracy recovers really fast)
			bool GetFastRecovery();
			void SetFastRecovery(bool Statement);
		};

		/// @brief Returns the Ammo Data instance for the weapon
		AmmoWeaponData* GetAmmoData();

		/// @brief Returns the Damage Data instance for the weapon
		DamageWeaponData* GetDamageData();

		/// @brief Returns the Accuracy Datainstance for the weapon
		AccuracyWeaponData* GetAccuracyData();

		/// @brief Set/Get the current clip count
		uint32 GetAmmo();
		void SetAmmo(uint32 Value);

		/// @brief Returns true if the weapon is reloading
		bool IsReloading();
	};

	class Entity : ManagedObject
	{
		/// @brief Get the name of the entity
		string Name();

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

		/// @brief Gets the entity Up/Right/Forward vector
		Vector3 GetRight();
		Vector3 GetForward();
		Vector3 GetUp();

		/// @brief Sets an outline of the entity (client side)
		void SetOutline(Color Color);

		/// @brief Get a clone of this entity
		/// @return Duplicated Entity
		Entity* Duplicate();

		/// @brief Add or Remove the entity from the world
		/// @return Has the entity been Added/Removed
		/// !!!Duplicated entities are entirely removed!!!
		bool AddToWorld();
		bool RemoveFromWorld();

		/// @brief DeActivate/ReActivate all of the components of an entity
		/// Use this to temporarily Disable entities

		bool IsActive();
		void SetIsActive(bool IsActive);

		/// @brief Returns the Damage Component if the entity has one
		DamageComponent* DamageComponent();

		/// @brief Returns the Weapon Component if the entity has one
		WeaponComponent* WeaponComponent();

		/// @brief Returns the Destruction Component if the entity has one
		/// Disable this to disable destruction
		Component* DestructionComponent();
	};

	class VolumetricFog
	{
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

	class PlayerController
	{
		/// @brief Returns the controller entity
		Entity* Entity();

		/// @brief Use eTeam from the core module
		enum Team : uint8
		{
			A,
			B,
			Count,
			Invalid
		};

		/// @brief Returns the controller team
		Team Team();

		/// @brief Returns the current instance of a weapon being held by the controller
		WeaponComponent* Weapon();

		/// @brief Returns the damage component instance
		DamageComponent* Damage();

		/// @brief Returns the ObjectID of the equipped primary
		uint64 PrimaryID();

		/// @brief Returns the ObjectID of the equipped secondary
		uint64 SecondaryID();

		/// @brief Returns the ObjectID of the character
		/// enum eCharacter in the core module 
		uint64 CharacterID();
	};

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

	class CastHit
	{
		/// @brief Get the hit origin
		Vector3 Origin();

		/// @brief Get the hit delta
		float Delta();

		/// @brief Get the hit normal
		Vector3 Type_Normal();

		/// @brief Get the entity if one was hit
		Entity* Entity();

		/// @brief Get the collision component if one was hit
		Component* Component();
	};

	class RaycastResult
	{
		/// @brief Did the raycast hit anything?
		bool DidHit();

		/// @brief Get the array of hits
		Array<CastHit> Hits();
	};

	///////////////////////////////////////////// Time

	/// @return Is the Phase Timer Paused
	bool IsTimerPaused();

	/// @brief Pause/Unpause the Phase Timer
	void SetTimerPaused(bool IsPaused);

	/// @brief Set/Get the phase timers time
	void SetTimerRemaining(int32 TimeInSeconds);
	float GetTimerRemaining();

	///////////////////////////////////////////// Utilities

	/// @brief Creates a dust particle at a certain location
	/// Has a hard limit of 100 (will conflict with paintball mode and dust painting)
	void CreateDust(Vector3 Origin, float Radius, Color Color);

	/// @brief Use eExplosionType from the core module
	enum ExplosionType : uint32
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

	/// @brief Creates an explosion at the specified origin
	/// Effects have a hard limit for some time
	/// Maximum of 50 calls per 5 seconds
	void CreateExplosion(Vector3 Origin, ExplosionType Type);

	/// @brief Fires a raycast from and to the specified origin coordinates
	/// @param Start       | Start Origin
	/// @param End		   | End Origin
	/// @param Penetration | Max bullet penetration / how many casts will be done
	RaycastResult Raycast(Vector3 Start, Vector3 End, uint8 Penetration);

	/////////////////////////////////////////////

	/// @return Are we the host?
	bool IsHost();

	/// @brief Get the local PlayerController instance
	PlayerController* GetLocalPlayer();

	/// @brief Returns an array of PlayerController instances
	Array<PlayerController*> GetPlayerList();

	/// @brief Returns the current skylight instance
	Skylight* GetSkylight();

	/// @brief Returns the current view camera instance
	View* GetCamera();

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

	/////////////////////////////////////////////

	/// @brief Get Entity if an instance exists
	/// @return Returns an Entity instance of an Object
	Entity* GetEntity(uint64 ObjectID);

	/// @brief Create an Entity from external preloads
	/// @return Returns a duplicated entity
	Entity* CreateExternalEntity(uint64 ObjectID);

	/// @brief Get Object pointer if exists
	/// @return Returns a Pointer instance of an Object
	Pointer* GetObject(uint64 ObjectID);

	/////////////////////////////////////////////
};
