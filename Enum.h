#pragma once

enum class LAYER
{
	Unknown = -1,
	BackGround = 0,
	EffectBackground = 2,
	Player = 4,
	Enemy = 8,
	AllinceProjectile = 16,
	EnemyProjectile = 32,
	EffectFrontword = 64,
	Item = 128,
	UI = 256
};

enum class JOB
{
	Crusader,
	Vestal,
	PlagueDoctor,
	Highwayman
};

enum class IMAGE
{
	Vestal_Idle,
	Vestal_Walk,
	Vestal_Combat
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
	ROOM,
	ROAD
};

enum class DUNGEONMAPSTATE 
{
	Road_Empty,
	Road_Enemy,
	Road_Trasure,
	Road_Trap,
	Room_Empty,
	Room_Enemy,
	Room_Trasure,
	Room_Boss
};