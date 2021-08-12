#pragma once

enum class LAYER
{
	Unknown = -2,

	MinimapBackground,
	UIMinimapRoom,
	UIMinimapRoad,
	UIMinimapTouch,
	BackGround,

	Building,
	Enemy,
	Player,
	AllinceProjectile,
	EnemyProjectile,
	EffectFrontword,
	Item,
	UI,
	UIButton,
	DummySlot
};

enum class ITEM
{
	ITEM_CONSUMABLE,
	ITEM_TREASURE,
	ITEM_MONEY,
	ITEM_TRINKET_DROP,
	ITEM_TRINKET_EQUIP,

	Torch,
	Food,
	Bandage
};

enum class JOB
{
	Crusader,
	Vestal,
	PlagueDoctor,
	Highwayman
};

enum class DIR 
{
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

	ruins_endhall,
	ruins_mid,
	ruins_bottom,
	ruins_top,

	//IMG-TOWN
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

	estate_activity_log,
	estate_nameplate,
	hero_slot_bg,
	downarrow,
	uparrow,
	sort_rarity,
	unequip_trinkets,
	sort_stress,
	roster_topframe,
	roster_downframe,
	rosterelement_res,
	roster_bggrad,

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
	room_unknown,

	//Hero_roster
	crusader_roster,
	highwayman_roster,
	plague_doctor_roster,
	vestal_roster,

	check,

	//panel
	banner,
	controller,
	hero,
	inventory,
	map,
	map1,
	map2,
	monster,
	scouting,

	treasure,
	trap,
	enemy,
	nothing,

	//Item
	torch,
	food1,
	food2,
	food3,
	food4,
	bandage,
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

	Night_Attack_Prevention,

	Reconnaissance,
	Stress_Down,
	Cure_disease,
	Cure_Death_Door,
	Cure_Hp
};

enum class BATTLETURN
{
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

enum class UNITTYPE 
{
	NONE,
	Hero,
	Enemy
};

enum class RoadObjType 
{
	Empty,
	Trap,
	Tresure,
	Enemy
};