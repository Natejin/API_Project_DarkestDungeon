#include "framework.h"
#include "soundManager.h"

soundManager::soundManager() : m_system(nullptr),m_channel(nullptr), m_sound(nullptr) {}
soundManager::~soundManager() {}

HRESULT soundManager::init()
{
	FMOD::System_Create(&m_system);

	m_system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, 0);

	m_sound = new FMOD::Sound * [TOTALSOUNDBUFFER];
	m_channel =  new FMOD::Channel* [TOTALSOUNDBUFFER];



	memset(m_sound, 0, sizeof(FMOD::Sound*) * (TOTALSOUNDBUFFER));
	memset(m_channel, 0, sizeof(FMOD::Channel*) * (TOTALSOUNDBUFFER));

	SetSound();

	return S_OK;
}

void soundManager::release()
{
	if ((m_channel != nullptr) | (m_sound != nullptr))
	{
		for (int i = 0; i < TOTALSOUNDBUFFER; i++)
		{
			if (m_channel != nullptr)
			{
				if (m_channel[i])m_channel[i]->stop();
			}
			if (m_sound != nullptr)
			{
				if (m_sound[i])m_sound[i]->release();
			}
		}
	}
	SAFE_DELETE(m_channel);
	SAFE_DELETE(m_sound);

	//시스템 닫자
	if (m_system != nullptr)
	{
		m_system->release();
		m_system->close();
	}
}

void soundManager::update()
{
	m_system->update();
}

void soundManager::render()
{

}

void soundManager::addSound(SOUND keyName, string soundName, bool bgm, bool loop)
{
	if (loop)
	{
		if (bgm)//브금
		{
			m_system->createStream(soundName.c_str(), FMOD_LOOP_NORMAL, nullptr, &m_sound[m_totalSounds.size()]);
		}
		else 
		{
			m_system->createSound(soundName.c_str(), FMOD_LOOP_NORMAL, nullptr, &m_sound[m_totalSounds.size()]);
		}
	}
	else
	{
		m_system->createSound(soundName.c_str(), FMOD_DEFAULT, nullptr, &m_sound[m_totalSounds.size()]);
	}
	m_totalSounds.insert(make_pair(keyName, &m_sound[m_totalSounds.size()]));
}


void soundManager::play(SOUND keyName, float volume)
{
	int count = 0;

	arrSoundIter iter = m_totalSounds.begin();
	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_system->playSound(FMOD_CHANNEL_FREE, *iter->second, false, &m_channel[count]);
			m_channel[count]->setVolume(volume);
		}
	}
}

void soundManager::stop(SOUND keyName)
{
	int count = 0;

	arrSoundIter iter = m_totalSounds.begin();
	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_channel[count]->stop();
			break;
		}
	}
}

void soundManager::pause(SOUND keyName)
{
	int count = 0;

	arrSoundIter iter = m_totalSounds.begin();
	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_channel[count]->setPaused(true);
			break;
		}
	}
}

void soundManager::resume(SOUND keyName)
{
	int count = 0;

	arrSoundIter iter = m_totalSounds.begin();
	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_channel[count]->setPaused(false);
			break;
		}
	}
}

bool soundManager::isPlaySound(SOUND keyName)
{
	int count = 0;
	bool isPlay;
	arrSoundIter iter = m_totalSounds.begin();
	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_channel[count]->isPlaying(&isPlay);
			break;
		}
	}
	return  isPlay;
}

bool soundManager::isPauseSound(SOUND keyName)
{
	int count = 0;
	bool isPause;
	arrSoundIter iter = m_totalSounds.begin();
	for (iter; iter != m_totalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			m_channel[count]->getPaused(&isPause);
			break;
		}
	}
	return  isPause;
}

void soundManager::SetSound()
{
	addSound(SOUND::Town, "sound/BGM/Town.wav");
	addSound(SOUND::Combat, "sound/BGM/Combat.wav");

	//Crusader
	addSound(SOUND::Cru_Battleheal, "sound/SoundEffect/Crusader/Cru_Battleheal.wav");
	addSound(SOUND::Cru_holylance, "sound/SoundEffect/Crusader/Cru_holylance.wav");
	addSound(SOUND::Cru_PowerfulAttack, "sound/SoundEffect/Crusader/Cru_PowerfulAttack.wav");
	addSound(SOUND::Cru_PowerfulAttack_miss, "sound/SoundEffect/Crusader/Cru_PowerfulAttack_miss.wav");
	addSound(SOUND::Cru_ScrollAttack, "sound/SoundEffect/Crusader/Cru_ScrollAttack.wav");
	addSound(SOUND::Cru_ScrollAttack_miss, "sound/SoundEffect/Crusader/Cru_ScrollAttack_miss.wav");
	addSound(SOUND::Cru_StressDown, "sound/SoundEffect/Crusader/Cru_StressDown.wav");
	addSound(SOUND::Cru_StressDown_miss, "sound/SoundEffect/Crusader/Cru_StressDown_miss.wav");
	addSound(SOUND::Cru_stunningblow, "sound/SoundEffect/Crusader/Cru_stunningblow.wav");

    //Highwayman
	addSound(SOUND::hwy_backshot, "sound/SoundEffect/Highwayman/hwy_backshot.wav");
	addSound(SOUND::hwy_duelistadvance, "sound/SoundEffect/Highwayman/hwy_duelistadvance.wav");
	addSound(SOUND::hwy_grapeshot, "sound/SoundEffect/Highwayman/hwy_grapeshot.wav");
	addSound(SOUND::hwy_grapeshot_miss, "sound/SoundEffect/Highwayman/hwy_grapeshot_miss.wav");
	addSound(SOUND::hwy_pistolshot, "sound/SoundEffect/Highwayman/hwy_pistolshot.wav");
	addSound(SOUND::hwy_pistolshot_miss, "sound/SoundEffect/Highwayman/hwy_pistolshot_miss.wav");
	addSound(SOUND::hwy_slice, "sound/SoundEffect/Highwayman/hwy_slice.wav");
	addSound(SOUND::hwy_tracking, "sound/SoundEffect/Highwayman/hwy_tracking.wav");
	addSound(SOUND::hwy_tracking_miss, "sound/SoundEffect/Highwayman/hwy_tracking_miss.wav");

	//Plague_doctor
	addSound(SOUND::plg_battlemed, "sound/SoundEffect/Plague_doctor/plg_battlemed.wav");
	addSound(SOUND::plg_battlemed_miss, "sound/SoundEffect/Plague_doctor/plg_battlemed_miss.wav");
	addSound(SOUND::plg_blindinggas, "sound/SoundEffect/Plague_doctor/plg_blindinggas.wav");
	addSound(SOUND::plg_blindinggas_miss, "sound/SoundEffect/Plague_doctor/plg_blindinggas_miss.wav");
	addSound(SOUND::plg_buff, "sound/SoundEffect/Plague_doctor/plg_buff.wav");
	addSound(SOUND::plg_buff_miss, "sound/SoundEffect/Plague_doctor/plg_buff_miss.wav");
	addSound(SOUND::plg_disorientingblast, "sound/SoundEffect/Plague_doctor/plg_disorientingblast.wav");
	addSound(SOUND::plg_disorientingblast_miss, "sound/SoundEffect/Plague_doctor/plg_disorientingblast_miss.wav");
	addSound(SOUND::plg_knife, "sound/SoundEffect/Plague_doctor/plg_knife.wav");
	addSound(SOUND::plg_noxiousblast, "sound/SoundEffect/Plague_doctor/plg_noxiousblast.wav");
	addSound(SOUND::plg_noxiousblast_miss, "sound/SoundEffect/Plague_doctor/plg_noxiousblast_miss.wav");
	addSound(SOUND::plg_plaguegrenade, "sound/SoundEffect/Plague_doctor/plg_plaguegrenade.wav");
	addSound(SOUND::plg_plaguegrenade_miss, "sound/SoundEffect/Plague_doctor/plg_plaguegrenade_miss.wav");

	//Vestal
	addSound(SOUND::vst_dazzlinglight, "sound/SoundEffect/Vestal/vst_dazzlinglight.wav");
	addSound(SOUND::vst_divinegrace, "sound/SoundEffect/Vestal/vst_divinegrace.wav");
	addSound(SOUND::vst_divinegrace_miss, "sound/SoundEffect/Vestal/vst_divinegrace_miss.wav");
	addSound(SOUND::vst_godscom, "sound/SoundEffect/Vestal/vst_godscom.wav");
	addSound(SOUND::vst_godshand, "sound/SoundEffect/Vestal/vst_godshand.wav");
	addSound(SOUND::vst_godshand_miss, "sound/SoundEffect/Vestal/vst_godshand_miss.wav");
	addSound(SOUND::vst_illum, "sound/SoundEffect/Vestal/vst_illum.wav");
	addSound(SOUND::vst_illum_imp, "sound/SoundEffect/Vestal/vst_illum_imp.wav");
	addSound(SOUND::vst_judgement, "sound/SoundEffect/Vestal/vst_judgement.wav");
	addSound(SOUND::vst_macebash, "sound/SoundEffect/Vestal/vst_macebash.wav");

	//Shared
	addSound(SOUND::share_imp_arrow, "sound/SoundEffect/Shared/share_imp_arrow.wav");
	addSound(SOUND::share_imp_axe, "sound/SoundEffect/Shared/share_imp_axe.wav");
	addSound(SOUND::share_imp_explo_big, "sound/SoundEffect/Shared/share_imp_explo_big.wav");
	addSound(SOUND::share_imp_explo_small, "sound/SoundEffect/Shared/share_imp_explo_small.wav");
	addSound(SOUND::share_imp_gas, "sound/SoundEffect/Shared/share_imp_gas.wav");
	addSound(SOUND::share_imp_arrow, "sound/SoundEffect/Shared/share_imp_arrow.wav");
	addSound(SOUND::share_imp_gun, "sound/SoundEffect/Shared/share_imp_gun.wav");
	addSound(SOUND::share_imp_hammer, "sound/SoundEffect/Shared/share_imp_hammer.wav");
	addSound(SOUND::share_imp_knife, "sound/SoundEffect/Shared/share_imp_knife.wav");
	addSound(SOUND::share_imp_magic_light, "sound/SoundEffect/Shared/share_imp_magic_light.wav");
	addSound(SOUND::share_imp_shield, "sound/SoundEffect/Shared/share_imp_shield.wav");
	addSound(SOUND::share_imp_sword, "sound/SoundEffect/Shared/share_imp_sword.wav");

	//UI
	addSound(SOUND::raid_success, "sound/SoundEffect/UI/raid_success.wav");
	addSound(SOUND::ui_dun_buttonroom, "sound/SoundEffect/UI/ui_dun_buttonroom.wav");
	addSound(SOUND::ui_shr_button_click, "sound/SoundEffect/UI/ui_shr_button_click.wav");
	addSound(SOUND::ui_shr_button_click_enemy, "sound/SoundEffect/UI/ui_shr_button_click_enemy.wav");
	addSound(SOUND::ui_town_button_click, "sound/SoundEffect/UI/ui_town_button_click.wav");
	addSound(SOUND::ui_town_button_click_back, "sound/SoundEffect/UI/ui_town_button_click_back.wav");
	addSound(SOUND::ui_town_button_click_locked, "sound/SoundEffect/UI/ui_town_button_click_locked.wav");
	addSound(SOUND::ui_town_button_setoff, "sound/SoundEffect/UI/ui_town_button_setoff.wav");
	addSound(SOUND::ui_town_trinket_close, "sound/SoundEffect/UI/ui_town_trinket_close.wav");
	addSound(SOUND::ui_town_trinket_open, "sound/SoundEffect/UI/ui_town_trinket_open.wav");

	//Narration

	//Good_cri
	addSound(SOUND::vo_narr_good_kill_strong_01, "sound/SoundEffect/Narration/vo_narr_good_kill_strong_01.wav");
	addSound(SOUND::vo_narr_good_kill_strong_02, "sound/SoundEffect/Narration/vo_narr_good_kill_strong_02.wav");
	addSound(SOUND::vo_narr_good_kill_strong_03, "sound/SoundEffect/Narration/vo_narr_good_kill_strong_03.wav");
	//Bad_cri
	addSound(SOUND::vo_narr_bad_crit_01, "sound/SoundEffect/Narration/vo_narr_bad_crit_01.wav");
	addSound(SOUND::vo_narr_bad_crit_02, "sound/SoundEffect/Narration/vo_narr_bad_crit_02.wav");
	addSound(SOUND::vo_narr_bad_crit_03, "sound/SoundEffect/Narration/vo_narr_bad_crit_03.wav");

	//RESIST
	addSound(SOUND::status_buff, "sound/SoundEffect/Shared/status_buff.wav");
	addSound(SOUND::status_guard, "sound/SoundEffect/Shared/status_guard.wav");
	addSound(SOUND::status_marked, "sound/SoundEffect/Shared/status_marked.wav");
	addSound(SOUND::status_marked, "sound/SoundEffect/Shared/status_stun_off.wav");
	addSound(SOUND::status_marked, "sound/SoundEffect/Shared/status_poison.wav");
	addSound(SOUND::status_marked, "sound/SoundEffect/Shared/status_bleed_dot.wav");
	addSound(SOUND::status_marked, "sound/SoundEffect/Shared/status_bleed_onset.wav");

	//
	addSound(SOUND::status_marked, "sound/SoundEffect/Shared/door_open.wav");
	addSound(SOUND::status_marked, "sound/SoundEffect/Shared/EatFood.wav");

	//Footstep
	addSound(SOUND::status_marked, "sound/SoundEffect/Footstep/party_foot_dirt_01.wav");
	addSound(SOUND::status_marked, "sound/SoundEffect/Footstep/party_foot_dirt_02.wav");
	addSound(SOUND::status_marked, "sound/SoundEffect/Footstep/party_foot_dirt_03.wav");
	addSound(SOUND::status_marked, "sound/SoundEffect/Footstep/party_foot_dirt_04.wav");
	addSound(SOUND::status_marked, "sound/SoundEffect/Footstep/party_foot_dirt_05.wav");
	addSound(SOUND::status_marked, "sound/SoundEffect/Footstep/party_foot_dirt_06.wav");
}
