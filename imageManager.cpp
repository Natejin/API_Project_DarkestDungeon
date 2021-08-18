#include "framework.h"
#include "imageManager.h"

imageManager::imageManager() {}
imageManager::~imageManager() {}

HRESULT imageManager::init()
{
	//Hero
	MG_IMAGE->addFrameImage(IMAGE::Vestal_Idle, "images/Heroes/vestal/Vestal_Idle_Frame.bmp", 2400, 270, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Vestal_Walk, "images/Heroes/vestal/Vestal_Walking_Frame.bmp", 2400, 270, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Vestal_Combat, "images/Heroes/vestal/Vestal_Combat_Frame.bmp", 2400, 270, 12, 1, true, RGB(255, 0, 255));
	
	MG_IMAGE->addFrameImage(IMAGE::Crusader_Idle, "images/Heroes/crusader/Crusader_Idle_Frame.bmp", 2400, 295, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Crusader_Walk, "images/Heroes/crusader/Crusader_Walk_Frame.bmp", 2400, 287, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Crusader_Combat, "images/Heroes/crusader/Crusader_Combat_Frame.bmp", 2400, 350, 12, 1, true, RGB(255, 0, 255));
	
	MG_IMAGE->addFrameImage(IMAGE::Plague_Idle, "images/Heroes/plague_doctor/plague_doctor_Idle_Frame2.bmp", 2400, 380, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Plague_Walk, "images/Heroes/plague_doctor/plague_doctor_walking_Frame.bmp", 2400, 280, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Plague_Combat, "images/Heroes/plague_doctor/plague_doctor_Combat_Frame.bmp", 2400, 285, 12, 1, true, RGB(255, 0, 255));

	MG_IMAGE->addFrameImage(IMAGE::Highwayman_Idle, "images/Heroes/highwayman/highwayMan_Idle_Frame.bmp", 2400, 280, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Highwayman_Walk, "images/Heroes/highwayman/highwayMan_Walking_Frame.bmp", 2400, 280, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Highwayman_Combat, "images/Heroes/highwayman/highwayMan_combat_Frame.bmp", 2400, 285, 12, 1, true, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::Crusader_banner, "images/Heroes/crusader/crusader_banner.bmp", 529, 975, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_charge, "images/Heroes/crusader/crusader_charge.bmp", 838, 465, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_defend, "images/Heroes/crusader/crusader_defend.bmp", 341, 650, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_investigate, "images/Heroes/crusader/crusader_investigate.bmp", 413, 569, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_scroll, "images/Heroes/crusader/crusader_scroll.bmp", 466, 611, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_sword, "images/Heroes/crusader/crusader_sword.bmp", 619, 580, true, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::Highwayman_defend, "images/Heroes/highwayman/highwayman_defend.bmp", 336, 563, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Highwayman_hipshot, "images/Heroes/highwayman/highwayman_hipshot.bmp", 397, 542, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Highwayman_investigate, "images/Heroes/highwayman/highwayman_investigate.bmp", 384, 585, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Highwayman_lunge, "images/Heroes/highwayman/highwayman_lunge.bmp", 625, 470, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Highwayman_pistol, "images/Heroes/highwayman/highwayman_pistol.bmp", 634, 600, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Highwayman_slice, "images/Heroes/highwayman/highwayman_slice.bmp", 577, 535, true, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::Plague_doctor_blast, "images/Heroes/plague_doctor/plague_doctor_blast.bmp", 451, 537, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Plague_doctor_buff, "images/Heroes/plague_doctor/plague_doctor_buff.bmp", 394, 566, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Plague_doctor_dagger, "images/Heroes/plague_doctor/plague_doctor_dagger.bmp", 446, 626, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Plague_doctor_defend, "images/Heroes/plague_doctor/plague_doctor_defend.bmp", 420, 525, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Plague_doctor_grenade, "images/Heroes/plague_doctor/plague_doctor_grenade.bmp", 597, 574, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Plague_doctor_investigate, "images/Heroes/plague_doctor/plague_doctor_investigate.bmp", 415, 548, true, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::Vestal_defend, "images/Heroes/vestal/vestal_defend.bmp", 371, 559, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_heal, "images/Heroes/vestal/vestal_heal.bmp", 339, 618, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_investigate, "images/Heroes/vestal/vestal_investigate.bmp", 375, 555, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_lectionary, "images/Heroes/vestal/vestal_lectionary.bmp", 390, 728, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_mace, "images/Heroes/vestal/vestal_mace.bmp", 625, 539, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_miracle, "images/Heroes/vestal/vestal_miracle.bmp", 357, 753, true, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::crusader_roster, "images/Heroes/crusader_portrait_roster.bmp", 85, 85,true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::highwayman_roster, "images/Heroes/highwayman_portrait_roster.bmp", 85, 85,true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::vestal_roster, "images/Heroes/vestal_portrait_roster.bmp", 85, 85,true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::plague_doctor_roster, "images/Heroes/plague_doctor_portrait_roster.bmp", 85, 85,true, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::crusader_header, "images/Heroes/crusader_head.bmp", 605,100,true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::highwayman_header, "images/Heroes/highwayman_head.bmp", 605,100,true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::vestal_header, "images/Heroes/vestal_head.bmp", 605,100,true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::plague_doctor_header, "images/Heroes/plague_doctor_head.bmp", 605,100,true, RGB(255, 0, 255));

	//Comabt_Skill
	MG_IMAGE->addImage(IMAGE::Crusader_portrait, "images/icons_heroes/crusader_portrait_roster.bmp", 70, 70, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_Skill_Smite, "images/icons_heroes/crusader.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_Skill_ZealousAccusation, "images/icons_heroes/crusader.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_Skill_StunningBlow, "images/icons_heroes/crusader.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_Skill_BulwarkofFaith, "images/icons_heroes/crusader.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_Skill_BattleHeal, "images/icons_heroes/crusader.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_Skill_HolyLance, "images/icons_heroes/crusader.ability.six.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_Skill_InspiringCry, "images/icons_heroes/crusader.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("highwayman_portrait", "images/icons_heroes/highwayman_portrait_roster.bmp", 70, 70, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill1", "images/icons_heroes/highwayman.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill2", "images/icons_heroes/highwayman.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Highwayman_Skill_PointBlankShot, "images/icons_heroes/highwayman.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Highwayman_Skill_GrapeshotBlast, "images/icons_heroes/highwayman.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill5", "images/icons_heroes/highwayman.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Highwayman_Skill_Duelists_Advance, "images/icons_heroes/highwayman.ability.six.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Highwayman_Skill_OpenVein, "images/icons_heroes/highwayman.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("plague_doctor_portrait", "images/icons_heroes/plague_doctor_portrait_roster.bmp", 70, 70, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Plague_doctor_Skill_NoxiousBlast, "images/icons_heroes/plague_doctor.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Plague_doctor_Skill_PlagueGrenade, "images/icons_heroes/plague_doctor.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Plague_doctor_Skill_Incision, "images/icons_heroes/plague_doctor.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Plague_doctor_Skill_BattleFiled_Medicine, "images/icons_heroes/plague_doctor.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill3", "images/icons_heroes/plague_doctor.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill6", "images/icons_heroes/plague_doctor.ability.six.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill7", "images/icons_heroes/plague_doctor.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));
	
	MG_IMAGE->addImage(IMAGE::Vestal_portrait, "images/icons_heroes/vestal_portrait_roster.bmp", 70, 70, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_Skill_Judgement, "images/icons_heroes/vestal.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_Skill_MaceBash, "images/icons_heroes/vestal.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_Skill_DazzlingLight, "images/icons_heroes/vestal.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_Skill_DivineGrace, "images/icons_heroes/vestal.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_Skill_DivineComfort, "images/icons_heroes/vestal.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	//MG_IMAGE->addImage(IMAGE::Vestal_Skill_Illumination , "images/icons_heroes/vestal.ability.six.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_Skill_HandofLight, "images/icons_heroes/vestal.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));

	//Enemy_frame
	MG_IMAGE->addFrameImage(IMAGE::Enemy_SkeletonDefender_Idle, "images/Enemys/Enemy_SkeletonDefender_Combat_Frame.bmp", 2400, 256, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::skeleton_courtier_combat, "images/Enemys/Skeleton_courtier_Combat_Frame.bmp", 2400, 250, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::skeleton_common_combat, "images/Enemys/Skeleton_common_combat_Frame.bmp", 2400, 260, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::necromancer_combat, "images/Enemys/Boss_necromenser_Frame.bmp", 9600, 550, 24, 1, true, RGB(255, 0, 255));
	
	//skeleton_defender
	MG_IMAGE->addImage(IMAGE::Enemy_SkeletonDefender_Attack, "images/Enemys/skeleton_defender_axe.bmp", 710, 580, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Enemy_SkeletonDefender_Defender, "images/Enemys/skeleton_defender_defend.bmp", 499, 621, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Enemy_SkeletonDefender_Shield, "images/Enemys/skeleton_defender_shield.bmp", 650, 623, true, RGB(255, 0, 255));
	
	//skeleton_courtier
	MG_IMAGE->addImage(IMAGE::skeleton_courtier_attack, "images/Enemys/skeleton_courtier_attack.bmp", 550, 491, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::skeleton_courtier_attack_goblet, "images/Enemys/skeleton_courtier_attack_goblet.bmp", 458, 520, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::skeleton_courtier_defend, "images/Enemys/skeleton_courtier_defend.bmp", 332, 526, true, RGB(255, 0, 255));
	
	//skeleton_common
	MG_IMAGE->addImage(IMAGE::skeleton_common_attack, "images/Enemys/skeleton_common_attack.bmp", 575, 548, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::skeleton_common_defend, "images/Enemys/skeleton_common_defend.bmp", 342, 508, true, RGB(255, 0, 255));
	
	//Monster_dead
	MG_IMAGE->addFrameImage(IMAGE::skeleton_defender_dead, "images/Enemys/skeleton_defender_dead.bmp", 130, 100, true, 1, 1, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::skeleton_courtier_dead, "images/Enemys/skeleton_courtier_dead.bmp", 130, 100, true, 1, 1, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::skeleton_common_dead, "images/Enemys/skeleton_common_dead.bmp", 130, 100, true, 1, 1, RGB(255, 0, 255));
	
	//BOSS
	MG_IMAGE->addImage(IMAGE::necromancer_attack, "images/Enemys/necromancer_attack.bmp", 1188, 882, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::necromancer_defend, "images/Enemys/necromancer_defend.bmp", 589, 888, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::necromancer_retreat, "images/Enemys/necromancer_retreat.bmp", 615, 1168, true, RGB(255, 0, 255));

	//quit
	MG_IMAGE->addImage("quick", "images/quick.bmp", 32, 32, true, RGB(255, 0, 255));

	//resistance
	MG_IMAGE->addImage(IMAGE::bleed, "images/resistance/skill_attribute_bleed.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::buff, "images/resistance/skill_attribute_buff.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::debuff, "images/resistance/skill_attribute_debuff.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::diseade, "images/resistance/skill_attribute_disease.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::gaurd, "images/resistance/skill_attribute_guard.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::heal, "images/resistance/skill_attribute_heal.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::move, "images/resistance/skill_attribute_move.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::poison, "images/resistance/skill_attribute_poison.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::stress, "images/resistance/skill_attribute_stress.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::stun, "images/resistance/skill_attribute_stun.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::tag, "images/resistance/skill_attribute_tag.bmp", 24, 24, true, RGB(255, 0, 255));

	//panel
	MG_IMAGE->addImage(IMAGE::banner, "images/panel/panel_banner.bmp", 685, 123, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::controller, "images/panel/panel_banner_controller.bmp", 754, 136, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::hero, "images/panel/panel_hero.bmp", 655, 203, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::inventory, "images/panel/panel_inventory.bmp", 630, 325, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::map, "images/panel/panel_map.bmp", 630, 325, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::map1, "images/panel/panel_map1.bmp", 630, 325, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::map2, "images/panel/panel_map2.bmp", 630, 325, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::monster, "images/panel/panel_monster.bmp", 630, 325, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::scouting, "images/panel/scoutingbanner.bmp", 366, 63, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::characterpanel_bg, "images/panel/characterpanel_bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::characterpanel, "images/panel/characterpanel.bmp", 1395,776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Backdrop_treatment, "images/panel/quirk_treatment_backdrop.bmp", 420,250, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Backdrop_disease, "images/panel/disease_treatment_backdrop.bmp", 420,250, true, RGB(255, 0, 255));
	
	//Icon_Map
	MG_IMAGE->addImage(IMAGE::hall_clear, "images/icons_map/hall_clear.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::hall_dark, "images/icons_map/hall_dark.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::hall_dim, "images/icons_map/hall_dim.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::hall_door, "images/icons_map/hall_door.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::indicator, "images/icons_map/indicator.bmp", 51, 48, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::LockedRoom, "images/icons_map/LockedRoom.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::LockedRoom_Blue, "images/icons_map/LockedRoom_Blue.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::LockedRoom_Green, "images/icons_map/LockedRoom_Green.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::LockedRoom_Red, "images/icons_map/LockedRoom_Red.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::LockedRoom_Yellow, "images/icons_map/LockedRoom_Yellow.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::marker_battle, "images/icons_map/marker_battle.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::marker_curio, "images/icons_map/marker_curio.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::marker_hunger, "images/icons_map/marker_hunger.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::marker_obstacle, "images/icons_map/marker_obstacle.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::marker_room_visited, "images/icons_map/marker_room_visited.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::marker_secret, "images/icons_map/marker_secret.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::marker_trap, "images/icons_map/marker_trap.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::moving_room, "images/icons_map/moving_room.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::PrisonerRoom, "images/icons_map/PrisonerRoom.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::room_battle, "images/icons_map/room_battle.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::room_boss, "images/icons_map/room_boss.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::room_curio, "images/icons_map/room_curio.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::room_empty, "images/icons_map/room_empty.bmp", 64, 64, true, RGB(255, 0, 255));
	//MG_IMAGE->addImage(IMAGE::room_entrance, "images/icons_map/room_entrance.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::room_treasure, "images/icons_map/room_treasure.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::room_unknown, "images/icons_map/room_unknown.bmp", 64, 64, true, RGB(255, 0, 255));


	//========================================================
	//ruins-map
	MG_IMAGE->addImage("ruins_bg", "images/ruins/crypts_corridor_bg.bmp", 720, 720, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("ruins_wall0", "images/ruins/crypts_corridor_door_basic.bmp", 720, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall1", "images/ruins/crypts_corridor_wall_00.bmp", 720, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall3", "images/ruins/crypts_corridor_wall_02.bmp", 720, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall4", "images/ruins/crypts_corridor_wall_03.bmp", 720, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall7", "images/ruins/crypts_corridor_wall_06.bmp", 720, 720, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("ruins_wall2", "images/ruins/transperant/crypts_corridor_wall_01.bmp", 720, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall5", "images/ruins/transperant/crypts.corridor_wall_04.bmp", 720, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_wall6", "images/ruins/transperant/crypts_corridor_wall_05.bmp", 720, 720, true, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::Ruins_room1, "images/ruins/crypts_room_wall_empty.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Ruins_room2, "images/ruins/crypts_room_wall_library.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Ruins_room3, "images/ruins/crypts_room_wall_entrance.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Ruins_room4, "images/ruins/crypts_room_wall_drain.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Ruins_room5, "images/ruins/crypts_room_wall_barrels.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Ruins_room6, "images/ruins/crypts_room_wall_arch.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Ruins_room7, "images/ruins/crypts_room_wall_altar.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Ruins_room8, "images/ruins/crypts_entrance_room_wall.bmp", 1920, 720, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Ruins_room9, "images/ruins/crypts_room_wall_torture.bmp", 1920, 720, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("ruins_endhall", "images/ruins/transperant/crypts_endhall_01.bmp", 720, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_mid", "images/ruins/transperant/crypts_corridor_mid.bmp", 720, 720, true, RGB(255, 0, 255));

	MG_IMAGE->addImage("ruins_bottom", "images/ruins/transperant/crypts_foreground_bottom_01.bmp", 720, 101, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins_top", "images/ruins/transperant/crypts_foreground_top_01.bmp", 720, 330, true, RGB(255, 0, 255));


	//========================================================
	//Town
	MG_IMAGE->addImage("district", "images/Town/district.bmp", 1395+550 , 776+100+200, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("district_midground", "images/Town/district_midground.bmp", 1000 + 920, 300+400, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_ruins", "images/Town/ruins.bmp", 1418+502, 438+500, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_ground", "images/Town/town_ground.bmp", 3844 / 3 +700, 1672 / 2+100+100, true, RGB(255, 0, 255));

	// Town_estate
	MG_IMAGE->addImage("town_abbey", "images/Town/estate/town_abbey_1.bmp", 800, 986, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_blacksmith", "images/Town/estate/town_blacksmith_1.bmp", 719, 795, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_camping_trainer", "images/Town/estate/town_camping_trainer_1.bmp", 424, 281, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_graveyard", "images/Town/estate/town_graveyard_1.bmp", 578, 293, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_guild", "images/Town/estate/town_guild_1.bmp", 707, 697, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_nomad_wagon", "images/Town/estate/town_nomad_wagon_1.bmp", 514, 392, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_sanitarium", "images/Town/estate/town_sanitarium_1.bmp", 764, 963, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_stage_coach", "images/Town/estate/town_stage_coach_1.bmp", 509, 362, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_statue", "images/Town/estate/town_statue_1.bmp", 449, 498, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_tavern", "images/Town/estate/town_tavern_1.bmp", 824, 814, true, RGB(255, 0, 255));
	
	//Abbey
	MG_IMAGE->addImage(IMAGE::abbey_char, "images/Town/abbey/abbey.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::abbey_bg, "images/Town/abbey/abbey.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::abbey_flagellation, "images/Town/abbey/abbey_flagellation.bmp", 72, 72, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::abbey_meditation, "images/Town/abbey/abbey_meditation.bmp", 72, 72, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::abbey_pray, "images/Town/abbey/abbey_pray.bmp", 72, 72, true, RGB(255, 0, 255));

	//Blacksmith
	MG_IMAGE->addImage(IMAGE::blacksmith_char, "images/Town/blacksmith/blacksmith.character.bmp", 865, 760, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::blacksmith_bg, "images/Town/blacksmith/blacksmith.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("blacksmith.frame", "images/Town/blacksmith/blacksmith.frame.bmp", 1395, 776, true, RGB(255, 0, 255));
	
	//Camping_trainer
	MG_IMAGE->addImage(IMAGE::camping_trainer_char, "images/Town/camping_trainer/camping_trainer.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camping_trainer_bg, "images/Town/camping_trainer/camping_trainer.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	
	//Graveyard
	MG_IMAGE->addImage(IMAGE::graveyard_char, "images/Town/graveyard/graveyard.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::graveyard_bg, "images/Town/graveyard/graveyard.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	
	//Gulid
	MG_IMAGE->addImage(IMAGE::guild_char, "images/Town/guild/guild.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::guild_bg, "images/Town/guild/guild.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	
	//Nomad-wagon
	MG_IMAGE->addImage(IMAGE::nomad_wagon_char, "images/Town/nomad_wagon/nomad_wagon.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::nomad_wagon_bg, "images/Town/nomad_wagon/nomad_wagon.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("inventory_grid_bg", "images/Town/nomad_wagon/inventory_grid_backgroud.bmp", 684, 360, true, RGB(255, 0, 255));
	
	//Sanitarium
	MG_IMAGE->addImage(IMAGE::sanitarium_char, "images/Town/sanitarium/sanitarium.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::sanitarium_bg, "images/Town/sanitarium/sanitarium.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::sanitarium_disease_quirk_cost, "images/Town/sanitarium/sanitarium_disease_quirk_cost.bmp", 72, 72, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::sanitarium_cost, "images/Town/sanitarium/sanitarium_cost.bmp", 72, 72, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::sanitarium_room, "images/Town/sanitarium/sanitarium_room.bmp", 72, 72, true, RGB(255, 0, 255));
	
	//Stage_coach
	MG_IMAGE->addImage(IMAGE::stage_coach_char, "images/Town/stage_coach/stage_coach.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::stage_coach_bg, "images/Town/stage_coach/stage_coach.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	
	//Statue
	MG_IMAGE->addImage(IMAGE::statue_char, "images/Town/statue/statue.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::statue_bg, "images/Town/statue/statue.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	
	//Tavern
	MG_IMAGE->addImage(IMAGE::tavern_char, "images/Town/tavern/tavern.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::tavern_bg, "images/Town/tavern/tavern.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::tavern_bar, "images/Town/tavern/tavern_bar.bmp", 72, 72, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::tavern_brothel, "images/Town/tavern/tavern_brothel.bmp", 72, 72, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::tavern_gambling, "images/Town/tavern/tavern_gambling.bmp", 72, 72, true, RGB(255, 0, 255));

	//TownUI
	MG_IMAGE->addImage(IMAGE::estate_activity_log, "images/Town_UI/estate_activity_log_button.bmp",103,103 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::estate_nameplate, "images/Town_UI/estate_nameplate.bmp",893,281 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::hero_slot_bg, "images/Town_UI/hero_slot_bg.bmp",85,85 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::downarrow, "images/Town_UI/realm_inventory_downarrow.bmp",62,49 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::uparrow, "images/Town_UI/realm_inventory_uparrow.bmp",62,49 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::sort_rarity, "images/Town_UI/realm_inventory_sort_rarity.bmp",32,32 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::unequip_trinkets, "images/Town_UI/realm_inventory_unequip_trinkets.bmp",32,32 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::sort_stress, "images/Town_UI/roster_sort_stress.bmp",32,32 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::roster_topframe, "images/Town_UI/roster_topframe.bmp",383,60 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::roster_downframe, "images/Town_UI/roster_bottomframe.bmp", 383, 60, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::rosterelement_res, "images/Town_UI/rosterelement_res1.bmp", 395-20, 104, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::roster_bggrad, "images/Town_UI/roster_bggrad.bmp", 373, 1080/2, true, RGB(255, 0, 255));

	MG_IMAGE->addImage("panel_bg", "images/panel/panel_bg.bmp", 1920, 1080, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("panel_bg2", "images/panel/panel_bg2.bmp", 344, 319, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("torchFrontBar", "images/dungeonUI/torch_.bmp", 900, 200, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("torchBackBar", "images/dungeonUI/torch_lightBar.bmp", 890, 30, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("torchBackBar2", "images/dungeonUI/torch_lightBar2.bmp", 422, 30, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("torchBackBar3", "images/dungeonUI/torch_lightBar2.bmp", 422, 30, true, RGB(255, 0, 255));

	MG_IMAGE->addImage("button", "images/dungeonUI/button_.bmp", 100, 100, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("button2", "images/dungeonUI/button_.bmp", 100, 100, false, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::treasure, "images/test/treasure.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::trap, "images/test/trap.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::NONE, "images/test/enemyPoint.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::nothing, "images/test/nothing.bmp", 100, 100, false, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::obj_crate1, "images/dungeonOBJ/Crate1.bmp", 248, 140, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_crate2, "images/dungeonOBJ/Crate2.bmp", 248, 155, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_pack1, "images/dungeonOBJ/Discarded_Pack1.bmp", 240, 188, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_pack1, "images/dungeonOBJ/Discarded_Pack2.bmp", 240, 188, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_altar1, "images/dungeonOBJ/Eldritch_Altar1.bmp", 245, 480, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_altar2, "images/dungeonOBJ/Eldritch_Altar2.bmp", 245, 480, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_sack1, "images/dungeonOBJ/Sack1.bmp", 450, 320, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_sack2, "images/dungeonOBJ/Sack2.bmp", 450, 320, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_books1, "images/dungeonOBJ/Stack_of_Books1.bmp", 135, 125, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_books2, "images/dungeonOBJ/Stack_of_Books2.bmp", 135, 125, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_treasure1, "images/dungeonOBJ/treasure1.bmp", 275, 210, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_treasure2, "images/dungeonOBJ/treasure2.bmp", 275, 220, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_strongBox1, "images/dungeonOBJ/Unlocked_Strongbox1.bmp", 390, 474, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_strongBox2, "images/dungeonOBJ/Unlocked_Strongbox2.bmp", 400, 474, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_trap1, "images/dungeonOBJ/spikes_front.bmp", 300, 60, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_trap2, "images/dungeonOBJ/spikes_front2.bmp", 300, 220, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::obj_trap3, "images/dungeonOBJ/spikes_back.bmp", 310, 70, true, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::eve_byHand, "images/dungeonOBJ/byhand.bmp", 124, 69, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::eve_eat, "images/dungeonOBJ/eat.bmp", 124, 69, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::eve_pass, "images/dungeonOBJ/pass.bmp", 124, 69, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::eve_startve, "images/dungeonOBJ/starve.bmp", 124, 69, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::eve_scroll_loot, "images/dungeonOBJ/event_scroll_loot.bmp", 456, 475, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::eve_scroll_side, "images/dungeonOBJ/event_scroll_sidebar.bmp", 456, 400, true, RGB(255, 0, 255));

	//skill
	MG_IMAGE->addImage(IMAGE::SelectedSkill, "images/character/selected_ability.bmp", 90, 90, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Ability_Move, "images/icons_heroes/ability_move.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Ability_Pass, "images/icons_heroes/ability_pass.bmp", 20, 65, false, RGB(255, 0, 255));
	
	//Common
	MG_IMAGE->addImage(IMAGE::camp_skill_bandage, "images/Camp_Common/camp_skill_bandage.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_encourage, "images/Camp_Common/camp_skill_encourage.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_pep_talk, "images/Camp_Common/camp_skill_pep_talk.bmp", 72, 72, false, RGB(255, 0, 255));
	
	//Crusader
	MG_IMAGE->addImage(IMAGE::camp_skill_stand_tall, "images/Camp_Crusader/camp_skill_stand_tall.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_unshakeable_leader, "images/Camp_Crusader/camp_skill_unshakeable_leader.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_zealous_speech, "images/Camp_Crusader/camp_skill_zealous_speech.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_zealous_vigil, "images/Camp_Crusader/camp_skill_zealous_vigil.bmp", 72, 72, false, RGB(255, 0, 255));
	
	//Highwayman
	MG_IMAGE->addImage(IMAGE::camp_skill_clean_guns, "images/Camp_Highwayman/camp_skill_clean_guns.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_gallows_humor, "images/Camp_Highwayman/camp_skill_gallows_humor.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_perimeter_alarms, "images/Camp_Highwayman/camp_skill_perimeter_alarms.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_uncatchable, "images/Camp_Highwayman/camp_skill_uncatchable.bmp", 72, 72, false, RGB(255, 0, 255));
	
	//Plague_Doctor
	MG_IMAGE->addImage(IMAGE::camp_skill_experimental_vapours, "images/Camp_Plague_doctor/camp_skill_experimental_vapours.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_leeches, "images/Camp_Plague_doctor/camp_skill_leeches.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_preventative_medicine, "images/Camp_Plague_doctor/camp_skill_preventative_medicine.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_self_medicate, "images/Camp_Plague_doctor/camp_skill_self_medicate.bmp", 72, 72, false, RGB(255, 0, 255));
	
	//Vestal
	MG_IMAGE->addImage(IMAGE::camp_skill_bless, "images/Camp_Vestal/camp_skill_bless.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_chant, "images/Camp_Vestal/camp_skill_chant.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_pray, "images/Camp_Vestal/camp_skill_pray.bmp", 72, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::camp_skill_sanctuary, "images/Camp_Vestal/camp_skill_sanctuary.bmp", 72, 72, false, RGB(255, 0, 255));

	//Weapon&Armor
	MG_IMAGE->addImage(IMAGE::Vestal_Armor_0, "images/icons_equip_Vestal/eqp_armour_0.bmp", 68, 132, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Vestal_Weapon_0, "images/icons_equip_Vestal/eqp_weapon_0.bmp", 68, 132, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_Armor_0, "images/icons_equip_Crusader/eqp_armour_0.bmp", 68, 132, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Crusader_Weapon_0, "images/icons_equip_Crusader/eqp_weapon_0.bmp", 68, 132, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Plague_Armor_0, "images/icons_equip_Plague_doctor/eqp_armour_0.bmp", 68, 132, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Plague_Weapon_0, "images/icons_equip_Plague_doctor/eqp_weapon_0.bmp", 68, 132, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Highway_Armor_0, "images/icons_equip_Highwayman/eqp_armour_0.bmp", 68, 132, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Highway_Weapon_0, "images/icons_equip_Highwayman/eqp_weapon_0.bmp", 68, 132, false, RGB(255, 0, 255));

	//UIovelay
	MG_IMAGE->addImage("HP_full", "images/dungeonUI/health_pip_full.bmp", 10, 10, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("HP_empty", "images/dungeonUI/health_pip_empty.bmp", 10, 10, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("STRS_full", "images/dungeonUI/stress_pip_full.bmp", 9, 10, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("STRS_empty", "images/dungeonUI/stress_pip_empty.bmp", 9, 10, true, RGB(255, 0, 255));
	//MG_IMAGE->addImage("STRS_over", "images/dungeonUI/stress_pip_full_overstressed.bmp", 9, 10, true, RGB(255, 0, 255));

	MG_IMAGE->addImage("memberRect", "images/test/memberRect.bmp", 70, 135, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::panel_monster_Black, "images/dungeonUI/panel_monster_indicator_invalid_Black.bmp", 147, 76, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::panel_monster_Red, "images/dungeonUI/panel_monster_indicator_valid_Red.bmp", 147, 76, true, RGB(255, 0, 255));
	
	MG_IMAGE->addImage(IMAGE::Target_Monster1, "images/dungeonUI/target_1.bmp", 175, 206, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Target_Monster2, "images/dungeonUI/target_2.bmp", 246, 206, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Target_Monster3, "images/dungeonUI/target_3.bmp", 328, 206, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Target_Monster4, "images/dungeonUI/target_4.bmp", 436, 206, true, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::Target_Selected1, "images/dungeonUI/selected_1.bmp", 175, 120, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Target_Selected2, "images/dungeonUI/selected_2.bmp", 236, 206, true, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::Target_Heal1, "images/dungeonUI/target_h_1.bmp", 236, 206, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Target_Heal2, "images/dungeonUI/target_h_2.bmp", 236, 206, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Target_Heal3, "images/dungeonUI/target_h_3.bmp", 331, 206, true, RGB(255, 0, 255));

	//item
	MG_IMAGE->addImage(IMAGE::torch	, "images/item/inv_supply+torch.bmp", 70, 135, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::food1	, "images/item/inv_provision+_0.bmp", 70, 135, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::food2	, "images/item/inv_provision+_1.bmp", 70, 135, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::food3	, "images/item/inv_provision+_2.bmp", 70, 135, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::food4	, "images/item/inv_provision+_3.bmp", 70, 135, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::bandage, "images/item/inv_supply+bandage.bmp", 70, 135, false, RGB(255, 0, 255));

	//check
	MG_IMAGE->addImage(IMAGE::check, "images/menucheck.bmp", 32, 32, false, RGB(255, 0, 255));
	
	//potionbutton
	MG_IMAGE->addImage(IMAGE::PositionButton_enable, "images/position_enable.bmp", 64, 64, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::PositionButton_unable, "images/position_unable.bmp", 64, 64, false, RGB(255, 0, 255));
	//MG_IMAGE->addImage(IMAGE::PositionButton_enable_red, "images/position_unable_red.bmp", 64, 64, false, RGB(255, 0, 255));
	
	//pont
	MG_IMAGE->addImage(IMAGE::Quirk, "images/Quirk.bmp", 80, 40, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::OriginStatus, "images/OriginStatus.bmp", 144, 34, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Equip, "images/Equip.bmp", 61, 30, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::CombatSkill, "images/CombatSkill.bmp", 145, 33, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::CampingSkill, "images/CampingSkill.bmp", 145, 33, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Resistance, "images/Resistance.bmp", 105, 30, false, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::Disease, "images/Disease.bmp", 60, 36, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("border_line", "images/Town/border_line.bmp", 1920, 1080, true, RGB(255, 0, 255));

	//embarkBt
	MG_IMAGE->addImage("embark", "images/Town_UI/embarkBt.bmp", 250, 72, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("embark_dungeon", "images/Town_UI/dungeonBt.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("partySlot", "images/Town_UI/partySlot.bmp", 100, 100, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("partySlot_", "images/selDungeon/embark_party.background.bmp", 412, 113, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("heroSlot1", "images/selDungeon/hero_slot.backgroundhightlight.bmp", 85, 85, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("heroSlot2", "images/selDungeon/hero_slot.background.bmp", 85, 85, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("heroSlot3", "images/selDungeon/hero_slot.positive_frame.bmp", 85, 85, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("selQuestBg", "images/selDungeon/quest_select_selected.bmp", 192, 192, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("selDungeonBg", "images/selDungeon/quest_select.background.bmp", 1920, 1080, true, RGB(255, 0, 255));
	
	//Battle_Scene
	MG_IMAGE->addImage(IMAGE::BattleBG_darkest_dungeon_1, "images/BattleScene/darkest_dungeon_1.bmp", 2320, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::BattleBG_darkest_dungeon_2, "images/BattleScene/darkest_dungeon_2.bmp", 2320, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::BattleBG_darkestdungeon_wall1, "images/BattleScene/darkestdungeon_wall1.bmp", 2320, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::BattleBG_darkestdungeon_wall2, "images/BattleScene/darkestdungeon_wall2.bmp", 2320, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::BattleBG_town_invasion, "images/BattleScene/town_invasion.bmp", 2320, 720, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::BattleBG_trinket_retention, "images/BattleScene/trinket_retention.bmp", 2320, 720, true, RGB(255, 0, 255));
	
	//Number
	MG_IMAGE->addFrameImage(IMAGE::NumberBlack, "images/Number/NumberBlack.bmp", 340, 49,10,1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::NumberGreen, "images/Number/NumberGreen.bmp", 340, 49, 10, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::NumberRed, "images/Number/NumberRed.bmp", 340, 49, 10, 1, true, RGB(255, 0, 255));

	return S_OK;

}

void imageManager::release()
{
	deleteAll();
}

Image* imageManager::addImage(string strKey, const int width, const int height)
{
	Image* img = findImage(strKey);
	if (img)return img;

	img = new Image;

	//�̹����� �ʱ�ȭ���� ������
	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ��߰��Ѵ�.
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addImage(string strKey, const char* fileName, const int width, const int height, bool trans, COLORREF transColor)
{
	//�߰��Ϸ��� Ű������ �̹��� �����ϴ��� Ȯ��
	Image* img = findImage(strKey);
	//�߰��Ϸ��� �̹����� �̹� ������ ����
	if (img)return img;

	img = new Image;

	//�̹����� �ʱ�ȭ���� ������
	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ��߰��Ѵ�.
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addImage(string strKey, const char* fileName, const float x, const float y, const int const width, const int height, bool trans, COLORREF transColor)
{
	//�߰��Ϸ��� Ű������ �̹��� �����ϴ��� Ȯ��
	Image* img = findImage(strKey);
	//�߰��Ϸ��� �̹����� �̹� ������ ����
	if (img)return img;

	img = new Image;

	//�̹����� �ʱ�ȭ���� ������
	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ��߰��Ѵ�.
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addFrameImage(string strKey, const char* fileName, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//�߰��Ϸ��� Ű������ �̹��� �����ϴ��� Ȯ��
	Image* img = findImage(strKey);
	//�߰��Ϸ��� �̹����� �̹� ������ ����
	if (img)return img;

	img = new Image;

	//�̹����� �ʱ�ȭ���� ������
	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ��߰��Ѵ�.
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addFrameImage(string strKey, const char* fileName, const float x, const float y, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//�߰��Ϸ��� Ű������ �̹��� �����ϴ��� Ȯ��
	Image* img = findImage(strKey);
	//�߰��Ϸ��� �̹����� �̹� ������ ����
	if (img)return img;

	img = new Image;

	//�̹����� �ʱ�ȭ���� ������
	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ��߰��Ѵ�.
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::findImage(string strKey)
{
	//�ش�Ű �˻�
	mapImageListIter key = _mImageList.find(strKey);

	//Ű�� ã����
	if (key != _mImageList.end())
	{
		return key->second;
	}
	return NULL;
}

bool imageManager::deleteImage(string strKey)
{
	mapImageListIter key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);
		return true;
	}
	return false;
}

bool imageManager::deleteAll()
{
	//�� ��ü�� ���鼭 �����Ѵ�.
	mapImageListIter iter = _mImageList.begin();

	for (iter; iter != _mImageList.end();)
	{
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else ++iter;
	}
	_mImageList.clear();
	return true;
}





void imageManager::render(string strKey, HDC hdc)
{
	//�̹����� ã�� �� ����
	Image* img = findImage(strKey);
	if (img) img->render(hdc);
}

void imageManager::render(string strKey, HDC hdc, const int destX, const int destY)
{
	Image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(string strKey, HDC hdc, const int destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourHeight)
{
	Image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void imageManager::frameRender(string strKey, HDC hdc, const int destX, const int destY)
{
	Image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY);
}

void imageManager::frameRender(string strKey, HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY)
{
	Image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}

void imageManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea,int offSetX, int offSetY)
{
	Image* img = findImage(strKey);
	if (img) img->loopRender(hdc, drawArea, offSetX, offSetY);
}

void imageManager::loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha)
{
	Image* img = findImage(strKey);
	if (img) img->loopAlphaRender(hdc, drawArea, offSetX, offSetY, alpha);
}






//
//
Image* imageManager::addImage(IMAGE strKey, const int width, const int height)
{
	Image* img = findImage(strKey);
	if (img)return img;

	img = new Image;

	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	m_ImageMap.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addImage(IMAGE strKey, const char* fileName, const int width, const int height, bool trans, COLORREF transColor)
{
	Image* img = findImage(strKey);
	if (img)return img;

	img = new Image;
	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		strKey;
		assert(false);
		return NULL;
	}

	m_ImageMap.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addImage(IMAGE strKey, const char* fileName, const float x, const float y, const int const width, const int height, bool trans, COLORREF transColor)
{
	//�߰��Ϸ��� Ű������ �̹��� �����ϴ��� Ȯ��
	Image* img = findImage(strKey);
	//�߰��Ϸ��� �̹����� �̹� ������ ����
	if (img)return img;

	img = new Image;

	//�̹����� �ʱ�ȭ���� ������
	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ��߰��Ѵ�.
	m_ImageMap.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addFrameImage(IMAGE strKey, const char* fileName, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//�߰��Ϸ��� Ű������ �̹��� �����ϴ��� Ȯ��
	Image* img = findImage(strKey);
	//�߰��Ϸ��� �̹����� �̹� ������ ����
	if (img)return img;

	img = new Image;

	//�̹����� �ʱ�ȭ���� ������
	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ��߰��Ѵ�.
	m_ImageMap.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::addFrameImage(IMAGE strKey, const char* fileName, const float x, const float y, const int width, const int height, const int frameX, const int frameY, bool trans, COLORREF transColor)
{
	//�߰��Ϸ��� Ű������ �̹��� �����ϴ��� Ȯ��
	Image* img = findImage(strKey);
	//�߰��Ϸ��� �̹����� �̹� ������ ����
	if (img)return img;

	img = new Image;

	//�̹����� �ʱ�ȭ���� ������
	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	//������ �̹����� ������ ���� �̹��� ��Ͽ��߰��Ѵ�.
	m_ImageMap.insert(make_pair(strKey, img));

	return img;
}

Image* imageManager::findImage(IMAGE strKey)
{
	//�ش�Ű �˻�
	mapImageIter key = m_ImageMap.find(strKey);

	//Ű�� ã����
	if (key != m_ImageMap.end())
	{
		return key->second;
	}
	return NULL;
}

bool imageManager::deleteImage(IMAGE strKey)
{
	mapImageIter key = m_ImageMap.find(strKey);

	if (key != m_ImageMap.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		m_ImageMap.erase(key);
		return true;
	}
	return false;
}



void imageManager::render(IMAGE strKey, HDC hdc)
{
	//�̹����� ã�� �� ����
	Image* img = findImage(strKey);
	if (img) img->render(hdc);
}

void imageManager::render(IMAGE strKey, HDC hdc, const int destX, const int destY)
{
	Image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(IMAGE strKey, HDC hdc, const int destX, const int destY, const int sourX, const int sourY, const int sourWidth, const int sourHeight)
{
	Image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void imageManager::frameRender(IMAGE strKey, HDC hdc, const int destX, const int destY)
{
	Image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY);
}

void imageManager::frameRender(IMAGE strKey, HDC hdc, const int destX, const int destY, const int currentFrameX, const int currentFrameY)
{
	Image* img = findImage(strKey);
	if (img) img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}

void imageManager::loopRender(IMAGE strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY)
{
	Image* img = findImage(strKey);
	if (img) img->loopRender(hdc, drawArea, offSetX, offSetY);
}

void imageManager::loopAlphaRender(IMAGE strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY, BYTE alpha)
{
	Image* img = findImage(strKey);
	if (img) img->loopAlphaRender(hdc, drawArea, offSetX, offSetY, alpha);
}