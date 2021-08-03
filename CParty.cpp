#include "framework.h"
#include "CParty.h"
#include "CHero.h"
#include "CVestal.h"

CParty::CParty() {}
CParty::~CParty() {}

HRESULT CParty::Init()
{
	return S_OK;
}

HRESULT CParty::Init(int food, int bandage, int torch)
{
	//createParty();

	m_layer = LAYER::Player;

	m_Item_food = food;
	m_Item_bandage = bandage;
	m_Item_Torch = torch;

	m_brightness = 100;

	//torch와 brightness는 다름
	return S_OK;
}

void CParty::Update(float deltaTime, float worldTime)
{

}

void CParty::LateUpdate()
{
}

void CParty::BackRender(HDC _hdc)
{

}

void CParty::Render(HDC _hdc)
{

}

void CParty::FrontRender(HDC _hdc)
{
	showMemberInfo(_hdc);
	showItem(_hdc);
	showDis(_hdc);
}

void CParty::Release()
{
	for (size_t i = 0; i < m_member.size(); i++)
	{
		MG_GMOBJ->RemoveObj(m_member[i]->GetId());
		SAFE_DELETE(m_member[i]);
	}
	m_member.clear();
}

void CParty::SetHero(CHero* member)
{
	if (m_member.size() < maxPartyMember)
	{
		m_member.push_back(member);
	}
}

void CParty::SetCamera() {
	if (m_member.size() > 0)
	{
		MG_CAMERA->SetTarget(m_member[0]);
	}

}

void CParty::SetParty(vector<CHero*> party)
{
	m_member = party;
	for (size_t i = 0; i < m_member.size(); i++)
	{
		MG_GMOBJ->RegisterObj(m_member[i]->GetName(), m_member[i]);
	}
}

CHero* CParty::GetHero(int index)
{
	return index < m_member.size() ? m_member[index] : nullptr;
}
//
//void CParty::createParty()
//{
//	int resist[5] = { 30, 30, 30, 30, 30 };
//
//	//test용
//	//member1 = new Vestal;
//	//member2 = new vestal;
//	//member3 = new vestal;
//	//member4 = new vestal;
//
//	//member1->setPos(4);
//	//member2->setPos(2);
//	//member3->setPos(3);
//	//member4->setPos(1);
//
//	////렌더 순서때문에 이렇게 넣음
//	//MG_GMOBJ->RegisterObj("member4", member4);
//	//MG_GMOBJ->RegisterObj("member3", member3);
//	//MG_GMOBJ->RegisterObj("member2", member2);
//	//MG_GMOBJ->RegisterObj("member1", member1);
//
//	//
//	//m_member.push_back(member1);
//	//m_member.push_back(member2);
//	//m_member.push_back(member3);
//	//m_member.push_back(member4);
//
//	//memberCount0 = false; 
//
//	//왜 이건 안되는지.. 나중에 물어볼 것
//	createVestal("member1", Vector2(210, 360));
//	createVestal("member2", Vector2(230, 360));
//	createVestal("member3", Vector2(250, 360));
//	createVestal("member4", Vector2(270, 360));
//
//
//	//createVestal(member2, "member2");
//	//member2->m_transform->m_pos = Vector2(230, 360);
//
//	//createVestal(member3, "member3");
//	//member3->m_transform->m_pos = Vector2(250, 360);
//
//	//createVestal(member4, "member4");
//	//member4->m_transform->m_pos = Vector2(270, 360);
//
//}

//void CParty::createParty(CHero* mem1, CHero* mem2, CHero* mem3, CHero* mem4)
//{
//
//}

void CParty::SetFormation()
{
	//해당 함수의 의도
	//pos 1과 pos 4인 멤버의 위치가 바뀌었을 경우
	//pos 1이었던 멤버를 벡터에서 pos값으로 호출할 수 있게끔??

	//카메라가 포커스를 맞추는 멤버를 pos 1인 멤버로 설정하고 싶어서

	//멤버의 위치가 변했을 경우 벡터의 순서도 마찬가지로 만드는 것이 타당할 것 같아서

	//근데 시도할수록 이게 과연 필요한게 맞는가에 대해 생각하게 됨

	//m_imember = m_member.begin();
	for (int i = 0; i < m_member.size(); i++)
	{
		//pos값과 vector에 들어가 있는 순서가 다를 경우
		//가르키는 값을 바꿔버리는 것 VS 값 자체를 스왑하는 것
		//pos가 4일 경우 m_member[0]이어야 함
	}
}

void CParty::getFormation(string name)
{

}
//
////이부분 질문하기
//void CParty::createVestal(string name, Vector2 pos)
//{
//	//member1 = new CHero();
//	//int resist[5] = { 30, 30, 30, 30, 30 };
//	//member1->Init(JOB::Vestal, resist, 24, 4, 1, 6, 0, 1, 0, 0);
//	//member1->m_transform->m_pos = Vector2(210, 360);
//	//MG_GMOBJ->RegisterObj(name, member1);
//	//m_member.push_back(member1);
//
//	//================================================
//
//	Vestal* vestal = new Vestal(); //여기서 동적할당하면 안되는 건가?
//
//	int resist[5] = { 30, 30, 30, 30, 30 };
//	//stun, blight, bleed, debuff, move
//
//	vestal->Init(JOB::Vestal, IMAGE::Vestal_Idle, resist, 24, 4, 1, 6, 0, 1, 0, 0);
//	//pos는 임의로 1에 배치, 공격력은 4-9의 중간값으로.
//
//	//member1->m_transform->m_pos = Vector2(210, 360);
//	vestal->m_transform->m_pos = pos;
//	//실질적으로 좌표상 존재하는 위치
//
//	MG_GMOBJ->RegisterObj(name, vestal);
//	m_member.push_back(vestal);
//}
//
//void CParty::createCrusader(CHero* hero, string name)
//{
//	hero = new CHero();
//
//	int resist[5] = { 40, 30, 30, 30, 40 };
//	//stun, blight, bleed, debuff, move
//
//	//hero->Init(JOB::Crusader, IMAGE:: resist, 33, 1, 1, 9, 0, 3, 0, 5);
//	//pos는 임의로 1에 배치, 공격력은 6-12의 중간값으로.
//
//	hero->m_transform->m_pos = Vector2(270, 360);
//	//실질적으로 좌표상 존재하는 위치
//
//	MG_GMOBJ->RegisterObj(name, hero);
//	m_member.push_back(hero);
//}
//
//void CParty::createPlagueDoctor(CHero* hero, string name)
//{
//	hero = new CHero();
//
//	int resist[5] = { 20, 60, 20, 50, 20 };
//	//stun, blight, bleed, debuff, move
//
//	//hero->Init(JOB::PlagueDoctor, resist, 22, 7, 1, 5, 0, 2, 0, 5);
//	//pos는 임의로 1에 배치, 공격력은 6-12의 중간값으로.
//
//	hero->m_transform->m_pos = Vector2(270, 360);
//	//실질적으로 좌표상 존재하는 위치
//
//	MG_GMOBJ->RegisterObj(name, hero);
//	m_member.push_back(hero);
//}
//
//void CParty::createHighwayMan(CHero* hero, string name)
//{
//	hero = new CHero();
//
//	int resist[5] = { 30, 30, 30, 30, 30 };
//	//stun, blight, bleed, debuff, move
//
//	//hero->Init(JOB::Highwayman, resist, 23, 5, 1, 7, 0, 5, 0, 10);
//	//pos는 임의로 1에 배치, 공격력은 6-12의 중간값으로.
//
//	hero->m_transform->m_pos = Vector2(270, 360);
//	//실질적으로 좌표상 존재하는 위치
//
//	MG_GMOBJ->RegisterObj(name, hero);
//	m_member.push_back(hero);
//}

void CParty::FormationMove()
{
	int substraction[3];
	substraction[0] = abs(m_member[0]->m_transform->m_pos.x - m_member[1]->m_transform->m_pos.x);
	substraction[1] = abs(m_member[1]->m_transform->m_pos.x - m_member[2]->m_transform->m_pos.x);
	substraction[2] = abs(m_member[2]->m_transform->m_pos.x - m_member[3]->m_transform->m_pos.x);

	m_member[0]->Move();
	for (size_t i = 0; i < 3; i++)
	{
		if (MG_INPUT->isStayKeyDown(VK_LEFT))
		{
			if (WB_btwHeroes > substraction[i])
			{
				m_member[i + 1]->Move();
				continue;
			}
		}
		if (MG_INPUT->isStayKeyDown(VK_RIGHT))
		{
			if (substraction[i] > WF_btwHeroes)
			{
				m_member[i + 1]->Move();
			}
		}
	}
}


void CParty::setTorch(int torch)
{
	m_Item_Torch = torch;
}

void CParty::setFood(int food)
{
	m_Item_food = food;
}

void CParty::setBandage(int bandage)
{
	m_Item_bandage = bandage;
}

void CParty::setBrightness(int brightness)
{
	m_brightness = brightness;
}


void CParty::decreaseBright_movement()
{
	//추후 횃불의 밝기에 따라 빈도수를 조정하도록 수정
	if (!(m_member[0]->getMoveDis()) == 0 && m_member[0]->getMoveDis() % 300 == 0)
	{
		//10분의 1확률로 스트레스를 받음
		if (MG_RND->getInt(9) == 1)
		{
			m_member[MG_RND->getInt(3)]->setStress(3);
		}
	}
}


void CParty::showMemberInfo(HDC _hdc)
{
	//나중에 스테이더스를 확인하는 용도로 사용할 것

	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 255, 255));

	sprintf_s(str, "Hero1Stress : %d  POS: %d", GetHero(0)->getStress(), GetHero(0)->getPos());
	TextOut(_hdc, WINSIZEX - 200, 10, str, strlen(str));
	sprintf_s(str, "Hero2Stress : %d  POS: %d", GetHero(1)->getStress(), GetHero(1)->getPos());
	TextOut(_hdc, WINSIZEX - 200, 30, str, strlen(str));
	sprintf_s(str, "Hero3Stress : %d  POS: %d", GetHero(2)->getStress(), GetHero(2)->getPos());
	TextOut(_hdc, WINSIZEX - 200, 50, str, strlen(str));
	sprintf_s(str, "Hero4Stress : %d  POS: %d", GetHero(3)->getStress(), GetHero(3)->getPos());
	TextOut(_hdc, WINSIZEX - 200, 70, str, strlen(str));

	for (int i = 0; i < m_member.size(); i++)
	{
		sprintf_s(str, "POS: %d", m_member[i]->getPos());
		TextOut(_hdc, WINSIZEX - 200, 300 + 20 * i, str, strlen(str));
	}



}

void CParty::showItem(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 255, 255));

	sprintf_s(str, "Torch : %d", m_Item_Torch);
	TextOut(_hdc, WINSIZEX - 200, 200, str, strlen(str));
	sprintf_s(str, "Food : %d", m_Item_food);
	TextOut(_hdc, WINSIZEX - 200, 220, str, strlen(str));
	sprintf_s(str, "Bandage : %d", m_Item_bandage);
	TextOut(_hdc, WINSIZEX - 200, 240, str, strlen(str));
}

void CParty::showDis(HDC _hdc)
{
	char str[256];
	string strFrame;
	SetBkMode(_hdc, TRANSPARENT);
	SetTextColor(_hdc, RGB(255, 0, 255));

	sprintf_s(str, "distance : %d", GetHero(0)->getMoveDis());
	TextOut(_hdc, WINSIZEX - 200, 90, str, strlen(str));
	sprintf_s(str, "distance (retreat) : %d", GetHero(0)->getMoveDis_reteat());
	TextOut(_hdc, WINSIZEX - 200, 110, str, strlen(str));
}