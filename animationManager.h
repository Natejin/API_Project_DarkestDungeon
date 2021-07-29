#pragma once
#include"singleton.h"
#include "animation.h"
#include "Enum.h"

class animationManager : public  Singleton<animationManager>
{
private:
	typedef map<string, animation*> arrAnimation;
	typedef map<string, animation*>::iterator iterArrAnimation;

	arrAnimation _animation;

	typedef map<IMAGE, animation*> animeMap;
	typedef map<IMAGE, animation*>::iterator animeMapiter;

	animeMap m_anime;
public:

	animationManager();
	~animationManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//처음부터  끝까지
	void addDefAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse = false, bool loop = false);

	void addAnimation(string animationKeyName, char* imageKeyName, int* playArr, int arrLen, int fps, bool loop = false);
	void addAnimation(string animationKeyName, char* imageKeyName,int start, int end, int fps, bool reverse = false, bool loop = false);


	void start(string animationKeyName);
	void stop(string animationKeyName);
	void pause(string animationKeyName);
	void resume(string animationKeyName);

	//찾아라
	animation* findAnimation(string animationKeyName);

	void deleteAll();


	void addDefAnimation(IMAGE animationKeyName, char* imageKeyName, int fps, bool reverse = false, bool loop = false);

	void addAnimation(IMAGE animationKeyName, char* imageKeyName, int* playArr, int arrLen, int fps, bool loop = false);
	void addAnimation(IMAGE animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse = false, bool loop = false);


	void start(IMAGE animationKeyName);
	void stop(IMAGE animationKeyName);
	void pause(IMAGE animationKeyName);
	void resume(IMAGE animationKeyName);

	//찾아라
	animation* findAnimation(IMAGE animationKeyName);
};