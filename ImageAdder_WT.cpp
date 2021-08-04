#include "framework.h"
#include "ImageAdder_WT.h"

HRESULT ImageAdder_WT::Init()
{

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
	MG_IMAGE->addImage("banner", "images/panel/panel_banner.bmp", 754, 136, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("controller", "images/panel/panel_banner_controller.bmp", 754, 136, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("hero", "images/panel/panel_hero.bmp", 720, 224, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("inventory", "images/panel/panel_inventory.bmp", 720, 360, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("map", "images/panel/panel_map.bmp", 720, 360, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("monster", "images/panel/panel_monster.bmp", 702, 368, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("scouting", "images/panel/scoutingbanner.bmp", 366, 63, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("characterpanerl_bg", "images/panel/characterpanerl_bg.bmp", 240, 101, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("char_edit_focusframe", "images/panel/char_edit_focusframe.bmp", 240, 101, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("characterpanel_frame", "images/panel/characterpanel_frame.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("characterpanel_focusframe", "images/panel/characterpanel_focusframe.bmp", 561, 43, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("next_hero", "images/panel/next_hero.bmp", 80, 49, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("previous_hero", "images/panel/previous_hero.bmp", 80, 49, true, RGB(255, 0, 255));

	//Icon_Map
	MG_IMAGE->addImage("hall_clear", "images/icons_map/hall_clear.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("hall_dark", "images/icons_map/hall_dark.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("hall_dim", "images/icons_map/hall_dim.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("hall_door", "images/icons_map/hall_door.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("indicator", "images/icons_map/indicator.bmp", 51, 48, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("LockedRoom", "images/icons_map/LockedRoom.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("LockedRoom_Blue", "images/icons_map/LockedRoom_Blue.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("LockedRoom_Green", "images/icons_map/LockedRoom_Green.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("LockedRoom_Red", "images/icons_map/LockedRoom_Red.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("LockedRoom_Yellow", "images/icons_map/LockedRoom_Yellow.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_battle", "images/icons_map/marker_battle.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_curio", "images/icons_map/marker_curio.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_hunger", "images/icons_map/marker_hunger.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_obstacle", "images/icons_map/marker_obstacle.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_room_visited", "images/icons_map/marker_room_visited.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_secret", "images/icons_map/marker_secret.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("marker_trap", "images/icons_map/marker_trap.bmp", 24, 24, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("moving_room", "images/icons_map/moving_room.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("PrisonerRoom", "images/icons_map/PrisonerRoom.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_battle", "images/icons_map/room_battle.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_boss", "images/icons_map/room_boss.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_curio", "images/icons_map/room_curio.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_empty", "images/icons_map/room_empty.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_entrance", "images/icons_map/room_entrance.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_treasure", "images/icons_map/room_treasure.bmp", 64, 64, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("room_unknown", "images/icons_map/room_unknown.bmp", 64, 64, true, RGB(255, 0, 255));

	//character ui
	MG_IMAGE->addImage("icon_dismiss", "images/character/icon_dismiss.bmp", 32, 32, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("icon_recolor", "images/character/icon_recolor.bmp", 32, 32, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("icon_rename", "images/character/icon_rename.bmp", 32, 32, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("lockedskill", "images/character/lockedskill.bmp", 72, 72, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("lockquirk", "images/character/lockquirk.bmp", 32, 32, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("quirkreplaced", "images/character/quirkreplaced.bmp", 26, 26, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("selected_ability", "images/character/selected_ability.bmp", 90, 90, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("seriousquirk", "images/character/seriousquirk.bmp", 32, 32, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("singleton_quirk_negative", "images/character/singleton_quirk_negative.bmp", 32, 32, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("singleton_quirk_positive", "images/character/singleton_quirk_positive.bmp", 32, 32, true, RGB(255, 0, 255));
	//Town

	MG_IMAGE->addImage("district", "images/Town/distict.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("district_midground", "images/Town/distict_midground.bmp", 1000, 300, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("ruins", "images/Town/ruins.bmp", 1418, 438, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_ground", "images/Town/town_ground.bmp", 3844, 1672, true, RGB(255, 0, 255));

	// Town_estate
	MG_IMAGE->addImage("town_abbey", "images/Town/estate/town_abbey_1.bmp", 800, 986, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_blacksmith", "images/Town/estate/town_blacksmith_1.bmp", 719, 795, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_camping_trainer", "images/Town/estate/town_camping_trainer_1.bmp", 281, 424, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_graveyard", "images/Town/estate/town_graveyard_1.bmp", 578, 293, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_guild", "images/Town/estate/town_guild_1.bmp", 707, 697, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_nomad_wagon", "images/Town/estate/town_nomad_wagon_1.bmp", 514, 392, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_sanitarium", "images/Town/estate/town_sanitarium_1.bmp", 764, 963, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_stage_coach", "images/Town/estate/town_stage_coach_1.bmp", 509, 362, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_statue", "images/Town/estate/town_statue_1.bmp", 449, 498, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("town_tavern", "images/Town/estate/town_tavern_1.bmp", 824, 814, true, RGB(255, 0, 255));
	//Abbey
	MG_IMAGE->addImage("abbey.character", "images/Town/abbey/abbey.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("abbey.character.bg", "images/Town/abbey/abbey.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	//Blacksmith
	MG_IMAGE->addImage("blacksmith.character", "images/Town/blacksmith/blacksmith.character.bmp", 865, 760, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("blacksmith.character.bg", "images/Town/blacksmith/blacksmith.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("blacksmith.frame", "images/Town/blacksmith/blacksmith.frame.bmp", 1395, 776, true, RGB(255, 0, 255));
	//Camping_trainer
	MG_IMAGE->addImage("camping_trainer.character", "images/Town/camping_trainer/camping_trainer.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("camping_trainer.character.bg", "images/Town/camping_trainer/camping_trainer.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	//Graveyard
	MG_IMAGE->addImage("graveyard.character", "images/Town/graveyard/graveyard.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("graveyard.character", "images/Town/graveyard/graveyard.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	//Gulid
	MG_IMAGE->addImage("guild.character", "images/Town/guild/guild.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("guild.character.bg", "images/Town/guild/guild.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	//Nomad-wagon
	MG_IMAGE->addImage("nomad_wagon.character", "images/Town/nomad_wagon/nomad_wagon.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("nomad_wagon.character.bg", "images/Town/nomad_wagon/nomad_wagon.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("inventory_grid_bg", "images/Town/nomad_wagon/inventory_grid_backgroud.bmp", 684, 360, true, RGB(255, 0, 255));
	//Sanitarium
	MG_IMAGE->addImage("sanitarium.character", "images/Town/sanitarium/sanitarium.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("sanitarium.character.bg", "images/Town/sanitarium/sanitarium.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	//Stage_coach
	MG_IMAGE->addImage("stage_coach.character", "images/Town/stage_coach/stage_coach.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("stage_coach.character.bg", "images/Town/stage_coach/stage_coach.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	//Statue
	MG_IMAGE->addImage("statue.character", "images/Town/statue/statue.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("statue.character.bg", "images/Town/statue/statue.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));
	//Tavern
	MG_IMAGE->addImage("tavern.character", "images/Town/tavern/tavern.character.bmp", 811, 757, true, RGB(255, 0, 255));
	MG_IMAGE->addImage("tavern.character.bg", "images/Town/tavern/tavern.character.bg.bmp", 1395, 776, true, RGB(255, 0, 255));

	return S_OK;
}