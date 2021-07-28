#include "framework.h"
#include "Scene.h"

Scene::Scene() {}
Scene::~Scene() {}

HRESULT Scene::Init()
{
    return S_OK;
}

HRESULT Scene::Init(bool managerInit)
{
    return S_OK;
}

void Scene::Release()
{
}

void Scene::Update()
{
}

void Scene::Render(HDC _hdc)
{
}