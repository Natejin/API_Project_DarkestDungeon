#include "framework.h"
#include "minimap.h"

minimap::minimap()
{
}

minimap::~minimap()
{
}

HRESULT minimap::init()
{



	m_rockman = MG_IMAGE->findImage("록맨");
	m_rockman->setX(WINSIZEX / 2);
	m_rockman->setY(WINSIZEY / 2);
	mini_rc = RectMakeCenter(100 + m_rockman->getX() / 10 - m_camera / 10, 50 + m_rockman->getY() / 10, 10, 10);
	m_index = 0;
	m_count = 0;
	m_camera = 0;
	isLeft = false;
	return S_OK;
}

void minimap::release()
{
}

void minimap::update()
{
	if (MG_INPUT->isStayKeyDown(VK_LEFT) && m_rockman->getX() > 0)
	{
		isLeft = true;

		if (m_rockman->getX() >= WINSIZEX / 2)
		{
			m_rockman->setX(m_rockman->getX() - PLAYERSPEED);
		}
		else if (m_camera < 0)
		{
			m_camera += CAMERASPEED;
		}
		else {
			m_rockman->setX(m_rockman->getX() - PLAYERSPEED);
		}
	}
	if (MG_INPUT->isStayKeyDown(VK_RIGHT) && m_rockman->getX() + 80 < WINSIZEX)
	{
		isLeft = false;

		if (m_rockman->getX() <= WINSIZEX / 2)
		{
			m_rockman->setX(m_rockman->getX() + PLAYERSPEED);
		}
		else if (m_camera > -WINSIZEX)
		{
			m_camera -= CAMERASPEED;
		}
		else {
			m_rockman->setX(m_rockman->getX() + PLAYERSPEED);
		}
	}
	if (isLeft)
	{
		m_count++;
		m_rockman->setFrameY(1);

		if (m_count % 5 == 0)
		{
			m_count = 0;
			m_index--;
			if (m_index < m_rockman->getMaxFrameY())
			{
				m_index = 9;
			}
			m_rockman->setFrameX(m_index);
		}
	}
	else {
		m_count++;
		m_rockman->setFrameY(0);

		if (m_count % 5 == 0)
		{
			m_count = 0;
			m_index++;
			if (m_index >= m_rockman->getMaxFrameX())
			{
				m_index = 0;
			}
			m_rockman->setFrameX(m_index);
		}
	}
	mini_rc = RectMakeCenter(100 + m_rockman->getX() / 10 - m_camera / 10, 50 + m_rockman->getY() / 10, 10, 10);
}

void minimap::render()
{
	MG_IMAGE->render("배경화면", getMemDC(), m_camera, 0);
	MG_IMAGE->render("미니맵", getMemDC(), 100, 50);
	MG_IMAGE->frameRender("록맨", getMemDC(), m_rockman->getX(), m_rockman->getY(), m_rockman->getFrameX(), m_rockman->getFrameY());

	Rectangle(getMemDC(), mini_rc.left, mini_rc.top, mini_rc.right, mini_rc.bottom);

	MG_IMAGE->render("카메라", getMemDC(), 100 - m_camera / 10, 50);



}
