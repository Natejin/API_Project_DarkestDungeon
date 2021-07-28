#pragma once

enum class LAYER
{

	BackGround = 0,
	EffectBackground = 2,
	Player = 4,
	Enemy = 8,
	AllinceProjectile = 16,
	EnemyProjectile = 32,
	EffectFrontword = 64,
	Item = 128,
	UI = 512

};

enum class JOB
{
	Crusader,
	Vestal,
	PlagueDoctor,
	Highwayman
};