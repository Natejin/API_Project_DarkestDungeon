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
	UIIndicator,
	UIMotion,
	DummySlot
};

enum class SKILLTARGET
{
	Enemy,
	Enemies,
	Self,
	Ally,
	Allies
};

enum class EFFECTTYPE
{
	NONE,
	Stun,
	PROT,
	Blind,
	Poison,
	Bleed,
	Heal
};

enum class TRINKET {
	NONE,
	Item1,
	Item2,
	Item3,
	Item4,

};

enum class SKILLIMAGETYPE {
	Attack,
	Charge,
	Defend,
	Buff,
	Debuff,

};

enum class SKILL
{
	//HERO
	//Crusader
	Crusader_Combat_Smite,
	Crusader_Combat_ZealousAccusation,
	Crusader_Combat_StunningBlow,
	Crusader_BuffAllie_BulwarkofFaith,
	Crusader_Heal_BattleHeal,
	Crusader_Combat_HolyLance,
	//Vestal
	Vestal_Combat_MaceBash,
	Vestal_Combat_Judgement,
	Vestal_Combat_DazzlingLight,
	Vestal_Heal_DivineGrace,
	Vestal_Heal_DivineComfort,
	Vestal_Combat_Illumination,
	Vestal_Combat_HandofLight,
	//Plague_doctor
	Plague_doctor_NoxiousBlast,
	Plague_doctor_PlagueGrenade,
	Plague_doctor_Incision,
	Plague_doctor_BattleFiled_Medicine,
	//Highwayman
	Highwayman_PointBlankShot,
	Highwayman_GrapeshotBlast,
	Highwayman_Duelists_Advance,
	Highwayman_OpenVein,


	//ENEMY
	BoneDefender_Combat_1,
	BoneCommon_Combat_1,
	BoneCourtier_Combat_1,
	BoneCourtier_Combat_2_goblet,
	Necromancer_Combat_1,
	Necromancer_Combat_2_back,


};
enum class Camp_Skill
{
	
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

enum class SOUND {
	//BGM
	Town,
	Combat,
	Ruins_dark,
	Ruins_base,

	//Crusader
	Cru_Battleheal,
	Cru_holylance,
	Cru_PowerfulAttack,
	Cru_PowerfulAttack_miss,
	Cru_ScrollAttack,
	Cru_ScrollAttack_miss,
	Cru_StressDown,
	Cru_StressDown_miss,
	Cru_stunningblow,
	//Highwayman
	hwy_backshot,
	hwy_duelistadvance,
	hwy_grapeshot,
	hwy_grapeshot_miss,
	hwy_pistolshot,
	hwy_pistolshot_miss,
	hwy_slice,
	hwy_tracking,
	hwy_tracking_miss,
	//Plague_doctor
	plg_battlemed,
	plg_battlemed_miss,
	plg_blindinggas,
	plg_blindinggas_miss,
	plg_buff,
	plg_buff_miss,
	plg_disorientingblast,
	plg_disorientingblast_miss,
	plg_knife,
	plg_noxiousblast,
	plg_noxiousblast_miss,
	plg_plaguegrenade,
	plg_plaguegrenade_miss,
	//Vestal
	vst_dazzlinglight,
	vst_divinegrace,
	vst_divinegrace_miss,
	vst_godscom,
	vst_godshand,
	vst_godshand_miss,
	vst_illum,
	vst_illum_imp,
	vst_judgement,
	vst_macebash,
	//Shared
	share_imp_arrow,
	share_imp_axe,
	share_imp_explo_big,
	share_imp_explo_small,
	share_imp_gas,
	share_imp_gun,
	share_imp_hammer,
	share_imp_knife,
	share_imp_magic_light,
	share_imp_shield,
	share_imp_sword,
	share_imp_slime,
	//UI
	raid_success,
	ui_dun_buttonroom,
	ui_shr_button_click,
	ui_shr_button_click_enemy,
	ui_town_button_click,
	ui_town_button_click_back,
	ui_town_button_click_locked,
	ui_town_button_setoff,
	ui_town_trinket_close,
	ui_town_trinket_open,
	//Narration
 
	//Good_cri
	vo_narr_good_kill_strong_01,
	vo_narr_good_kill_strong_02,
	vo_narr_good_kill_strong_03,
	//Bad_cri
	vo_narr_bad_crit_01,
	vo_narr_bad_crit_02,
	vo_narr_bad_crit_03,
	//RESIST
	status_buff,
	status_guard,
	status_marked,
	status_stun_off,
	status_poison,
	status_bleed_dot,
	status_bleed_onset,
	//
	door_open,
	EatFood,
	//Footstep
	party_foot_dirt_01,
	party_foot_dirt_02,
	party_foot_dirt_03,
	party_foot_dirt_04,
	party_foot_dirt_05,
	party_foot_dirt_06


};

enum class IMAGE
{
	NONE,

	//Enemy Motion
	Enemy_SkeletonDefender_Idle,
	Enemy_SkeletonDefender_Attack,
	Enemy_SkeletonDefender_Defender,
	Enemy_SkeletonDefender_Shield,
	//skeleton_courtier
	skeleton_courtier_combat,
	skeleton_courtier_attack,
	skeleton_courtier_attack_goblet,
	skeleton_courtier_defend,
	//skeleton_common
	skeleton_common_combat,
	skeleton_common_attack,
	skeleton_common_defend,
	//BOSS
	necromancer_combat,
	necromancer_attack,
	necromancer_defend,
	necromancer_retreat,
	//Monster_dead
	skeleton_defender_dead,
	skeleton_courtier_dead,
	skeleton_common_dead,
	

	//UI
	panel_monster_Red,
	panel_monster_Black,

	Target_Selected1,
	Target_Selected2,
	Target_Selected3,

	Target_Monster1,
	Target_Monster2,
	Target_Monster3,
	Target_Monster4,

	Target_Heal1,
	Target_Heal2,
	Target_Heal3,

	//WeaponArmor
	Vestal_Armor_0 ,
	Vestal_Weapon_0,
	Crusader_Armor_0 ,
	Crusader_Weapon_0,
	Plague_Armor_0,
	Plague_Weapon_0,
	Highway_Armor_0,
	Highway_Weapon_0,
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
	abbey_flagellation,
	abbey_meditation,
	abbey_pray,
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
	characterpanel_bg,
	characterpanel,
	crusader_header,
	highwayman_header,
	plague_doctor_header,
	vestal_header,
	treasure,
	trap,
	nothing,

	//dungeonOBJ
	obj_crate1,
	obj_crate2,
	obj_pack1,
	obj_pack2,
	obj_altar1,
	obj_altar2,
	obj_sack1,
	obj_sack2,
	obj_books1,
	obj_books2,
	obj_treasure1,
	obj_treasure2,
	obj_strongBox1,
	obj_strongBox2,
	obj_trap1,
	obj_trap2,
	obj_trap3,

	//dungeonEvent
	eve_byHand,
	eve_eat,
	eve_pass,
	eve_startve,
	eve_scroll_loot,
	eve_scroll_side,

	//Item
	torch,
	food1,
	food2,
	food3,
	food4,
	bandage,

	//portrit
	Crusader_portrait,
	Vestal_portrait,

	//Skill
	SelectedSkill,

	Ability_Move,
	Ability_Pass,
	// 
	//crusader
	Crusader_Skill_Smite,
	Crusader_Skill_ZealousAccusation,
	Crusader_Skill_StunningBlow,
	Crusader_Skill_BulwarkofFaith,
	Crusader_Skill_BattleHeal,
	Crusader_Skill_HolyLance,
	Crusader_Skill_InspiringCry,

	//vestal
	Vestal_Skill_MaceBash,
	Vestal_Skill_Judgement,
	Vestal_Skill_DazzlingLight,
	Vestal_Skill_DivineGrace,
	Vestal_Skill_DivineComfort,
	Vestal_Skill_Illumination,
	Vestal_Skill_HandofLight,
	//Plagued_doctor
	Plague_doctor_Skill_NoxiousBlast,
	Plague_doctor_Skill_PlagueGrenade,
	Plague_doctor_Skill_Incision,
	Plague_doctor_Skill_BattleFiled_Medicine,
	//Highwayman
	Highwayman_Skill_PointBlankShot,
	Highwayman_Skill_GrapeshotBlast,
	Highwayman_Skill_Duelists_Advance,
	Highwayman_Skill_OpenVein,

	//HeroMotion_Crusader
	Crusader_Idle,
	Crusader_Walk,
	Crusader_Combat,

	Crusader_banner,
	Crusader_charge,
	Crusader_defend,
	Crusader_investigate,
	Crusader_scroll,
	Crusader_sword,
	
	//Highwayman
	Highwayman_Idle,
	Highwayman_Walk,
	Highwayman_Combat,

	Highwayman_defend,
	Highwayman_hipshot,
	Highwayman_investigate,
	Highwayman_lunge,
	Highwayman_pistol,
	Highwayman_slice,

	//Plague_doctor
	Plague_Idle,
	Plague_Walk,
	Plague_Combat,
	Plague_doctor_blast,
	Plague_doctor_buff,
	Plague_doctor_dagger,
	Plague_doctor_defend,
	Plague_doctor_grenade,
	Plague_doctor_investigate,

    //Vestal
	Vestal_Idle,
	Vestal_Walk,
	Vestal_Combat,

	Vestal_defend,
	Vestal_heal,
	Vestal_investigate,
	Vestal_lectionary,
	Vestal_mace,
	Vestal_miracle,
	//Backdrop
	Backdrop_treatment,
	Backdrop_disease,
	//button
	PositionButton_enable,
	PositionButton_unable,
	//PositionButton_enable_red,
	Quirk,
	OriginStatus,
	Equip,
	CombatSkill,
	CampingSkill,
	Resistance,
	Disease,
	//resist
	bleed,
	buff,
	debuff,
	diseade,
	gaurd,
	heal,
	move,
	poison,
	stress,
	stun,
	tag,

	//Camp_Skill
	
	//Common
	camp_skill_bandage,
	camp_skill_encourage,
	camp_skill_pep_talk,
	//Crusader
	camp_skill_stand_tall,
	camp_skill_unshakeable_leader,
	camp_skill_zealous_speech,
	camp_skill_zealous_vigil,
	//Highwayman
	camp_skill_clean_guns,
	camp_skill_gallows_humor,
	camp_skill_perimeter_alarms,
	camp_skill_uncatchable,
	//Plague_Doctor
	camp_skill_experimental_vapours,
	camp_skill_leeches,
	camp_skill_preventative_medicine,
	camp_skill_self_medicate,
	//Vestal
	camp_skill_bless,
	camp_skill_chant,
	camp_skill_pray,
	camp_skill_sanctuary,
	//Battle_Scene
	BattleBG_darkest_dungeon_1,
	BattleBG_darkest_dungeon_2,
	BattleBG_darkestdungeon_wall1,
	BattleBG_darkestdungeon_wall2,
	BattleBG_town_invasion,
	BattleBG_trinket_retention
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
	Treasure,
	Enemy,
	Boss
};

enum class ENEMYTYPE {
	BoneDefender,
	BoneCommon,
	BoneCourtier,
	Necromancer,

};

enum class  HeroListBtType
{
	ownHero,
	coach
};
