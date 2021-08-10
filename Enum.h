#pragma once

enum class LAYER
{
	Unknown = -2,

	MinimapBackground = 0,
	Minimap = 1,
	BackGround = 2,
	Building = 3,
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

	Ruins_room1,
	Ruins_room2,
	Ruins_room3,
	Ruins_room4,
	Ruins_room5,
	Ruins_room6,
	Ruins_room7,
	Ruins_room8,
	Ruins_room9,

	abbey_bg,
	abbey_char,

	blacksmith_bg,
	blacksmith_char,

	camping_trainer_bg,
	camping_trainer_char,

	graveyard_bg,
	graveyard_char,

	guild_bg,
	guild_char,

	nomad_wagon_bg,
	nomad_wagon_char,

	sanitarium_bg,
	sanitarium_char,

	stage_coach_bg,
	stage_coach_char,

	statue_bg,
	statue_char,

	tavern_bg,
	tavern_char,


	ruins_endhall,
	ruins_mid,

	ruins_bottom,
	ruins_top,

	//IMG_PLAYABLECHARACTER
	crusader,
	highwayman,
	plague_doctor,
	vestal,

	//Minimap Button
	hall_clear,			
	hall_dark,			
	hall_dim,			
	hall_door,			
	indicator,			
	LockedRoom,			
	LockedRoom_Blue,	
	LockedRoom_Green,	
	LockedRoom_Red,		
	LockedRoom_Yellow,	
	marker_battle,		
	marker_curio,		
	marker_hunger,		
	marker_obstacle,	
	marker_room_visited,
	marker_secret,		
	marker_trap,		
	moving_room,		
	PrisonerRoom,		
	room_battle,		
	room_boss,			
	room_curio,			
	room_empty,			
	room_entrance,		
	room_treasure,		
	room_unknown
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