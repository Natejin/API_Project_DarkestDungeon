#pragma once

enum class LAYER
{
	Unknown = -1,
	BackGround = 0,
	Building = 2,
	Player = 4,
	Enemy = 8,
	AllinceProjectile = 16,
	EnemyProjectile = 32,
	EffectFrontword = 64,
	Item = 128,
	UI = 256,
	UIButton = 512
};

enum class JOB
{
	Crusader,
	Vestal,
	PlagueDoctor,
	Highwayman
};

enum class DIR {
	Left,
	Up,
	Right,
	Down

};

enum class IMAGE
{	
	//Hero
	Vestal_Idle,
	Vestal_Walk,
	Vestal_Combat,
	Crusader_Idle,
	Crusader_Walk,
	Crusader_Combat,
	//Enemy
	Skeleton_Defender,

	//IMG_DUNGEON
	ruins_bg,

	ruins_wall0,
	ruins_wall2,
	ruins_wall3,
	ruins_wall6,
	ruins_wall_basic,

	ruins_wall1,
	ruins_wall4,
	ruins_wall5,

	ruins_room1,
	ruins_room2,
	ruins_room3,
	ruins_room4,
	ruins_room5,
	ruins_room6,
	ruins_room7,
	ruins_room8,
	ruins_room9,

	abbey_bg,
	abbey_char,

	ruins_endhall,
	ruins_mid,

	ruins_bottom,
	ruins_top,

	//IMG_PLAYABLECHARACTER
	crusader,
	highwayman,
	plague_doctor,
	vestal
};

enum class RACE 
{
	Human,
	Undying,
	Worm
};

enum class Resistance
{
	Stun,
	Blight,
	Bleed,
	Debuff,
	Move,
	Death_Door
};

enum class Combat_Skill
{

};

enum class Camping_Skill
{	
	//야습방지
	Night_Attack_Prevention,
	//정찰 강화
	Reconnaissance,
	Stress_Down,
	Cure_disease,
	Cure_Death_Door,
	Cure_Hp
};

enum class BATTLETURN
{	
	//야습방지
	EnemyTurn,
	PlayerTurn
};

enum class DUNGEONSTATE 
{
	NONE,
	ROOM,
	ROAD
};

enum class DUNGEONMODE
{
	NONE,
	BATTLE,
	WALK
};

enum class COLLIDERTYPE 
{
	BOX,
	CIRCLE,
	PIXEL
};


enum class ANIMATIONTYPE
{
	Stop,
	Play,
	Pause

};



enum class DUNGEONMAPSTATE 
{
	NONE,
	Road_Empty,
	Road_Enemy,
	Road_Trasure,
	Road_Trap,
	Room_Empty,
	Room_Enemy,
	Room_Trasure,
	Room_Boss,
};

enum class SCENETYPE
{
	Test,
	Dungeon,
	Dungeon2,
	Town
};

enum class UNITTYPE {
	NONE,
	Hero,
	Enemy

};