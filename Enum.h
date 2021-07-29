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

enum class RACE {
	Human,
	Undying,
	Worm

};
