#include "framework.h"
#include "imageManager.h"

imageManager::imageManager() {}
imageManager::~imageManager() {}

HRESULT imageManager::init()
{
	////���⿡ ��� �̹����� �־�ΰ� ���
	//MG_IMAGE->addImage("���ȭ��", "images/���.bmp", WORLDSIZEX, WORLDSIZEY, true, RGB(255, 0, 255));
	//MG_IMAGE->addImage("ī�޶�", "images/ī�޶�.bmp", WINSIZEX / 10, WINSIZEY / 10, true, RGB(255, 0, 255));
	//MG_IMAGE->addImage("�̴ϸ�", "images/���.bmp", WINSIZEX * 2 / 10, WINSIZEY / 10, true, RGB(255, 0, 255));

	////Darkest dungeon
	//MG_IMAGE->addFrameImage("�ϸ�", "images/�ϸ�.bmp", 960, 200, 10, 2, true, RGB(255, 0, 255));

	//Hero
	MG_IMAGE->addFrameImage(IMAGE::Vestal_Idle, "images/Heroes/Vestal_Idle_Frame.bmp", 2400, 300, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Crusader_Idle, "images/Heroes/Crusader_Idle_Frame.bmp", 2400, 295, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Crusader_Walk, "images/Heroes/Crusader_Walk_Frame.bmp", 2400, 287, 12, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage(IMAGE::Crusader_Combat, "images/Heroes/Crusader_Combat_Frame.bmp", 2400, 350, 12, 1, true, RGB(255, 0, 255));

	MG_IMAGE->addImage(IMAGE::crusader_roster, "images/Heroes/crusader_portrait_roster.bmp", 85, 85,true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::highwayman_roster, "images/Heroes/highwayman_portrait_roster.bmp", 85, 85,true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::vestal_roster, "images/Heroes/vestal_portrait_roster.bmp", 85, 85,true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::plague_doctor_roster, "images/Heroes/plague_doctor_portrait_roster.bmp", 85, 85,true, RGB(255, 0, 255));

	//Enemy
	MG_IMAGE->addFrameImage(IMAGE::Skeleton_Defender, "images/Enemys/Enemy_SkeletonDefender_Combat_Frame.bmp", 2400, 256, 12, 1, true, RGB(255, 0, 255));
	//quick
	MG_IMAGE->addImage("quick", "images/quick.bmp", 32, 32, true, RGB(255, 0, 255));

	//resistance
	MG_IMAGE->addImage("bleed", "images/resistance/skill_attribute_bleed.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("buff", "images/resistance/skill_attribute_buff.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("debuff", "images/resistance/skill_attribute_debuff.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("diseade", "images/resistance/skill_attribute_disease.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("gaurd", "images/resistance/skill_attribute_guard.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("heal", "images/resistance/skill_attribute_heal.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("move", "images/resistance/skill_attribute_move.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("poison", "images/resistance/skill_attribute_poison.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("stress", "images/resistance/skill_attribute_stress.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("stun", "images/resistance/skill_attribute_stun.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("tag", "images/resistance/skill_attribute_tag.bmp", 24, 24, true, RGB(255, 0, 255));

	//panel
	MG_IMAGE->addImage(IMAGE::banner, "images/panel/panel_banner.bmp", 685, 123, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::controller, "images/panel/panel_banner_controller.bmp", 754, 136, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::hero, "images/panel/panel_hero.bmp", 655, 203, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::inventory, "images/panel/panel_inventory.bmp", 630, 325, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::map, "images/panel/panel_map.bmp", 630, 325, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::map1, "images/panel/panel_map1.bmp", 630, 325, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::map2, "images/panel/panel_map2.bmp", 630, 325, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::monster, "images/panel/panel_monster.bmp", 702, 368, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::scouting, "images/panel/scoutingbanner.bmp", 366, 63, true, RGB(255, 0, 255));

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
	MG_IMAGE->addImage(IMAGE::room_entrance, "images/icons_map/room_entrance.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::room_treasure, "images/icons_map/room_treasure.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::room_unknown, "images/icons_map/room_unknown.bmp", 64, 64, true, RGB(255, 0, 255));


	//========================================================
	//ruins-map
	//���� �� ���
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
	//�ӽ� �̹���
	//ĳ����
	MG_IMAGE->addFrameImage(IMAGE::Vestal_Idle, "images/mem11.bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("crusader", "images/test/mem11.bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("highwayMan", "images/test/mem11.bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("plagueDoctor", "images/test/mem11.bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));

	//����
	MG_IMAGE->addFrameImage("mon1", "images/test/mon11.bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("mon2", "images/test/mon11.bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("mon3", "images/test/mon11.bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));
	MG_IMAGE->addFrameImage("mon4", "images/test/mon11.bmp", 400, 700, 1, 1, true, RGB(255, 0, 255));

	//���
	MG_IMAGE->addFrameImage("bg", "images/test/temporary bg.bmp", WORLDSIZEX, WORLDSIZEY, 1, 1, true, RGB(255, 0, 255));
	
	MG_IMAGE->addImage("testItem", "images/dungeonUI/item_testImg.bmp", 1050-982, 135, false, RGB(255, 0, 255));

	//Town
	MG_IMAGE->addImage("district", "images/Town/district.bmp", 1395+550 , 776+100+200, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("district_midground", "images/Town/district_midground.bmp", 1000 + 920, 300+400, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_ruins", "images/Town/ruins.bmp", 1418+502, 438+500, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_ground", "images/Town/town_ground.bmp", 3844 / 3 +700, 1672 / 2+100+100, true, RGB(255, 0, 255));

	// Town_estate
	MG_IMAGE->addImage("town_abbey", "images/Town/estate/town_abbey_1.bmp", 800 / 2 , 986 / 2 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_blacksmith", "images/Town/estate/town_blacksmith_1.bmp", 719 / 2, 795 / 2 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_camping_trainer", "images/Town/estate/town_camping_trainer_1.bmp", 281, 424/2, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_graveyard", "images/Town/estate/town_graveyard_1.bmp", 578/2, 293/2, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_guild", "images/Town/estate/town_guild_1.bmp", 707 / 2, 697 / 2, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_nomad_wagon", "images/Town/estate/town_nomad_wagon_1.bmp", 514 / 2-50 , 392 / 2-50 , true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_sanitarium", "images/Town/estate/town_sanitarium_1.bmp", 764 / 2 , 963 / 2, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_stage_coach", "images/Town/estate/town_stage_coach_1.bmp", 509/2, 362/2, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_statue", "images/Town/estate/town_statue_1.bmp", 449/2, 498/2, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_tavern", "images/Town/estate/town_tavern_1.bmp", 824 /2, 814 /2, true, RGB(255, 0, 255));
	//Abbey
	MG_IMAGE->addImage(IMAGE::abbey_char, "images/Town/abbey/abbey.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::abbey_bg, "images/Town/abbey/abbey.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	
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
	//Stage_coach
	MG_IMAGE->addImage(IMAGE::stage_coach_char, "images/Town/stage_coach/stage_coach.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::stage_coach_bg, "images/Town/stage_coach/stage_coach.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	//Statue
	MG_IMAGE->addImage(IMAGE::statue_char, "images/Town/statue/statue.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::statue_bg, "images/Town/statue/statue.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	//Tavern
	MG_IMAGE->addImage(IMAGE::tavern_char, "images/Town/tavern/tavern.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage(IMAGE::tavern_bg, "images/Town/tavern/tavern.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	
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

	MG_IMAGE->addImage("treasure", "images/test/treasure.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("trap", "images/test/trap.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("enemy", "images/test/enemyPoint.bmp", 100, 100, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("nothing", "images/test/nothing.bmp", 100, 100, false, RGB(255, 0, 255));

	//����� ������
	MG_IMAGE->addImage("crusader_portrait", "images/icons_heroes/crusader_portrait_roster.bmp", 70, 70, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill1", "images/icons_heroes/crusader.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill2", "images/icons_heroes/crusader.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill3", "images/icons_heroes/crusader.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill4", "images/icons_heroes/crusader.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill5", "images/icons_heroes/crusader.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill6", "images/icons_heroes/crusader.ability.six.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("crusader_skill7", "images/icons_heroes/crusader.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("highwayman_portrait", "images/icons_heroes/highwayman_portrait_roster.bmp", 70, 70, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill1", "images/icons_heroes/highwayman.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill2", "images/icons_heroes/highwayman.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill3", "images/icons_heroes/highwayman.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill4", "images/icons_heroes/highwayman.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill5", "images/icons_heroes/highwayman.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill6", "images/icons_heroes/highwayman.ability.six.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("highwayman_skill7", "images/icons_heroes/highwayman.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));
	
	MG_IMAGE->addImage("plague_doctor_portrait", "images/icons_heroes/plague_doctor_portrait_roster.bmp", 70, 70, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill1", "images/icons_heroes/plague_doctor.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill2", "images/icons_heroes/plague_doctor.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill3", "images/icons_heroes/plague_doctor.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill4", "images/icons_heroes/plague_doctor.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill5", "images/icons_heroes/plague_doctor.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill6", "images/icons_heroes/plague_doctor.ability.six.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("plagueDoctor_skill7", "images/icons_heroes/plague_doctor.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("vestal_portrait", "images/icons_heroes/vestal_portrait_roster.bmp", 70, 70, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill1", "images/icons_heroes/vestal.ability.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill2", "images/icons_heroes/vestal.ability.two.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill3", "images/icons_heroes/vestal.ability.three.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill4", "images/icons_heroes/vestal.ability.four.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill5", "images/icons_heroes/vestal.ability.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill6", "images/icons_heroes/vestal.ability.six.five.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_skill7", "images/icons_heroes/vestal.ability.seven.bmp", 65, 65, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("ability_move", "images/icons_heroes/ability_move.bmp", 65, 65, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("ability_pass", "images/icons_heroes/ability_pass.bmp", 20, 65, false, RGB(255, 0, 255));

	MG_IMAGE->addImage("vestal_armor", "images/icons_equip_Vestal/eqp_armour_0.bmp", 68, 132, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("vestal_weapon", "images/icons_equip_Vestal/eqp_weapon_0.bmp", 68, 132, false, RGB(255, 0, 255));
	
	//UIovelay
	MG_IMAGE->addImage("selected1", "images/dungeonUI/selected_1.bmp", 175, 120, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("selected2", "images/dungeonUI/selected_2.bmp", 236, 206, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("target1", "images/dungeonUI/target_2.bmp", 246, 206, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("target2", "images/dungeonUI/target_3.bmp", 328, 206, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("target3", "images/dungeonUI/target_4.bmp", 436, 206, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("target_h_1", "images/dungeonUI/target_h_2.bmp", 236, 206, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("target_h_2", "images/dungeonUI/target_h_3.bmp", 331, 206, true, RGB(255, 0, 255));

	MG_IMAGE->addImage("HP_full", "images/dungeonUI/health_pip_full.bmp", 100, 10, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("HP_empty", "images/dungeonUI/health_pip_empty.bmp", 100, 10, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("STRS_full", "images/dungeonUI/stress_pip_full.bmp", 9, 10, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("STRS_empty", "images/dungeonUI/stress_pip_empty.bmp", 9, 10, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("STRS_over", "images/dungeonUI/stress_pip_full_overstressed.bmp", 9, 10, true, RGB(255, 0, 255));

	MG_IMAGE->addImage("memberRect", "images/test/memberRect.bmp", 70, 135, false, RGB(255, 0, 255));


	//item
	MG_IMAGE->addImage("torch", "images/item/inv_supply+torch.bmp", 70, 135, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("food1", "images/item/inv_provision+_0.bmp", 70, 135, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("food2", "images/item/inv_provision+_1.bmp", 70, 135, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("food3", "images/item/inv_provision+_2.bmp", 70, 135, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("food4", "images/item/inv_provision+_3.bmp", 70, 135, false, RGB(255, 0, 255));
	MG_IMAGE->addImage("bandage", "images/item/inv_supply+bandage.bmp", 70, 135, false, RGB(255, 0, 255));

	//check
	MG_IMAGE->addImage(IMAGE::check, "images/menucheck.bmp", 32, 32, false, RGB(255, 0, 255));

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