#pragma once
#include"singleton.h"
#include"inc/fmod.hpp"
#pragma comment(lib,"lib/fmodex_vc.lib")

#define EXTRACHANNELBUFFER 5
#define SOUNDBUFFER 100
#define TOTALSOUNDBUFFER SOUNDBUFFER+EXTRACHANNELBUFFER

class soundManager : public Singleton<soundManager>
{
private:
	typedef map<SOUND, FMOD::Sound**>arrSounds;
	typedef map<SOUND, FMOD::Sound**>::iterator arrSoundIter;


	FMOD::System* m_system;
	FMOD::Sound** m_sound;
	FMOD::Channel** m_channel;

	arrSounds m_totalSounds;

public:
	soundManager();
	~soundManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void addSound(SOUND keyName, string soundName, bool bgm = FALSE, bool loop = FALSE);
	void play(SOUND keyName, float volume = 1.0f);
	void stop(SOUND keyName);
	void pause(SOUND keyName);
	void resume(SOUND keyName);

	//플레이 중이냐
	bool isPlaySound(SOUND keyName);
	//일시 정지 중이냐
	bool isPauseSound(SOUND keyName);

};