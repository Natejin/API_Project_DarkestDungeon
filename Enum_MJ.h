#pragma once

enum class IMG_DUNGEON
{
	//==============================
	//dungeon
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

	ruins_endhall,
	ruins_mid,

	ruins_bottom,
	ruins_top,


	//==============================
	//playableCharacter
	hero_vestal_idle,
	hero_vestal_walking,
	hero_vestal_combat,

	hero_crusader_idle,
	hero_crusader_walking,
	hero_crusader_combat,

	hero_highwayman_idle,
	hero_highwayman_walking,
	hero_highwayman_combat,

	hero_plague_doctor_idle,
	hero_plague_doctor_walking,
	hero_plague_doctor_combat,


	//==============================
	//UI
	//skill_attribute
	attribute_bleed,
	attribute_buff,
	attribute_debuff,
	attribute_disease, //우선보류
	attribute_guard,
	attribute_heal,
	attribute_move,
	attribute_poison,
	attribute_stress,
	attribute_stun,
	attribute_tag, //marked가 더 낫지 않나

	//panel
	panel_banner,
	panel_banner_controller,
	panel_hero,
	panel_inventory,
	panel_map,
	panel_monster,
	panel_scoutingbanner,

	//dungeonUI
	dungeonUI_hall_clear,
	dungeonUI_hall_dark,
	dungeonUI_hall_dim,
	dungeonUI_hall_door,
	dungeonUI_indicator,
	dungeonUI_LockedRoom,
	dungeonUI_LockedRoom_Blue,
	dungeonUI_LockedRoom_Green,
	dungeonUI_LockedRoom_Red,
	dungeonUI_LockedRoom_Yellow,
	dungeonUI_marker_battle,
	dungeonUI_marker_curio,
	dungeonUI_marker_hunger,
	dungeonUI_marker_obstacle,
	dungeonUI_marker_room_visited,
	dungeonUI_marker_secret,
	dungeonUI_marker_trap,
	dungeonUI_moving_room,
	dungeonUI_PrisonerRoom,
	dungeonUI_room_battle,
	dungeonUI_room_boss,
	dungeonUI_room_curio, 
	dungeonUI_room_empty, 
	dungeonUI_room_entrance,
	dungeonUI_room_treasure,
	dungeonUI_room_unknown,

	//==============================
	//enemy
	skeleton_defender_combat,
	skeleton_coutier_combat,
	skeleton_militia_combat,
	skeleton_common_combat,
	skeleton_captain_combat,
	skeleton_bearer_combat,
	skeleton_arbalist_combat,
	skeleton_spear_combat


	//==============================
	//item



	//==============================
	//town
	


};

enum class PLAYABLECHARACTER
{
	hero_crusader,
	hero_highwayman,
	hero_plague_doctor,
	hero_vestal
};

enum class ENEMY
{
	skeleton_defender,
	skeleton_coutier,
	skeleton_militia,
	skeleton_common,
	skeleton_captain,
	skeleton_bearer,
	skeleton_arbalist,
	skeleton_spear
};

enum class CONSUMABLEITEM
{
	Item_food,
	Item_bandage,
	Item_Torch
};

enum class TRINKET
{
	Trinket_dungeonDrop,
	Trinket_shopPurchase
};

enum class TOWN
{
	//일단 필요하다고 생각한 것들만 나열
	Town_wholeView,
	Town_abbey,
	Town_blackSmith,
	Town_stageCoach,
	Town_tavern,
	Town_embark
	
	//아래의 각종 설정창들이나 인벤토리는 어디에?
	//Town_inventory
};