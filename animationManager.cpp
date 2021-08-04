#include "framework.h"
#include "animationManager.h"
#include "image.h"


animationManager::animationManager() {}
animationManager::~animationManager() {}

HRESULT animationManager::init()
{
    return S_OK;
}

void animationManager::release()
{
    deleteAll();
}

void animationManager::update()
{
    iterArrAnimation  iter = _animation.begin();

    for (iter; iter != _animation.end(); ++iter)
    {
        if (!iter->second->isPlay())continue;
        iter->second->frameUpdate(MG_TIME->getElapsedTime() * 1.0f);
    }
}

void animationManager::render()
{

}

void animationManager::addDefAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop)
{
    //�̹��� �� �ִϸ��̼�  �ʱ�ȭ
    Image* img = MG_IMAGE->findImage(imageKeyName);
    animation* ani = new animation;
    ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
    ani->setDefPlayFrame(reverse, loop);
    ani->setFPS(fps);

    //�̹����� �ִϸ��̼��� �ʱ�ȭ ����  �ʿ� �߰��Ѵ�.
    _animation.insert(make_pair(animationKeyName, ani));
}

void animationManager::addAnimation(string animationKeyName, char* imageKeyName, int* playArr, int arrLen, int fps, bool loop)
{
    //�̹��� �� �ִϸ��̼�  �ʱ�ȭ
    Image* img = MG_IMAGE->findImage(imageKeyName);
    animation* ani = new animation;
    ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
    ani->setPlayFrame(playArr, arrLen,loop);
    ani->setFPS(fps);

    //�̹����� �ִϸ��̼��� �ʱ�ȭ ����  �ʿ� �߰��Ѵ�.
    _animation.insert(make_pair(animationKeyName, ani));
}

void animationManager::addAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop)
{
    //�̹��� �� �ִϸ��̼�  �ʱ�ȭ
    Image* img = MG_IMAGE->findImage(imageKeyName);
    animation* ani = new animation;
    ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
    ani->setPlayFrame(start,end,reverse, loop);
    ani->setFPS(fps);

    //�̹����� �ִϸ��̼��� �ʱ�ȭ ����  �ʿ� �߰��Ѵ�.
    _animation.insert(make_pair(animationKeyName, ani));
}

void animationManager::start(string animationKeyName)
{
    iterArrAnimation iter = _animation.find(animationKeyName);
    iter->second->start();
}

void animationManager::stop(string animationKeyName)
{
    iterArrAnimation iter = _animation.find(animationKeyName);
    iter->second->stop();
}

void animationManager::pause(string animationKeyName)
{
    iterArrAnimation iter = _animation.find(animationKeyName);
    iter->second->pause();
}

void animationManager::resume(string animationKeyName)
{
    iterArrAnimation iter = _animation.find(animationKeyName);
    iter->second->resume();
}

animation* animationManager::findAnimation(string animationKeyName)
{
    iterArrAnimation iter = _animation.find(animationKeyName);

    if (iter != _animation.end())
    {
        return iter->second;
    }
    return nullptr;
}

void animationManager::deleteAll()
{
    iterArrAnimation  iter = _animation.begin();

    for (; iter!= _animation.end();)
    {
        if (iter->second != NULL)
        {
            SAFE_DELETE(iter->second);
            iter = _animation.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
}

void animationManager::addDefAnimation(IMAGE animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop)
{
    //�̹��� �� �ִϸ��̼�  �ʱ�ȭ
    Image* img = MG_IMAGE->findImage(imageKeyName);
    animation* ani = new animation;
    ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
    ani->setDefPlayFrame(reverse, loop);
    ani->setFPS(fps);

    //�̹����� �ִϸ��̼��� �ʱ�ȭ ����  �ʿ� �߰��Ѵ�.
    m_anime.insert(make_pair(animationKeyName, ani));
}

void animationManager::addAnimation(IMAGE animationKeyName, char* imageKeyName, int* playArr, int arrLen, int fps, bool loop)
{
    //�̹��� �� �ִϸ��̼�  �ʱ�ȭ
    Image* img = MG_IMAGE->findImage(imageKeyName);
    animation* ani = new animation;
    ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
    ani->setPlayFrame(playArr, arrLen, loop);
    ani->setFPS(fps);

    //�̹����� �ִϸ��̼��� �ʱ�ȭ ����  �ʿ� �߰��Ѵ�.
    m_anime.insert(make_pair(animationKeyName, ani));
}

void animationManager::addAnimation(IMAGE animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop)
{
    //�̹��� �� �ִϸ��̼�  �ʱ�ȭ
    Image* img = MG_IMAGE->findImage(imageKeyName);
    animation* ani = new animation;
    ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
    ani->setPlayFrame(start, end, reverse, loop);
    ani->setFPS(fps);

    //�̹����� �ִϸ��̼��� �ʱ�ȭ ����  �ʿ� �߰��Ѵ�.
    m_anime.insert(make_pair(animationKeyName, ani));
}

void animationManager::start(IMAGE animationKeyName)
{
    animeMapiter iter = m_anime.find(animationKeyName);
    iter->second->start();
}

void animationManager::stop(IMAGE animationKeyName)
{
    animeMapiter iter = m_anime.find(animationKeyName);
    iter->second->stop();
}

void animationManager::pause(IMAGE animationKeyName)
{
    animeMapiter iter = m_anime.find(animationKeyName);
    iter->second->pause();
}

void animationManager::resume(IMAGE animationKeyName)
{
    animeMapiter iter = m_anime.find(animationKeyName);
    iter->second->resume();
}

animation* animationManager::findAnimation(IMAGE animationKeyName)
{
    animeMapiter iter = m_anime.find(animationKeyName);

    if (iter != m_anime.end())
    {
        return iter->second;
    }
    return nullptr;
}