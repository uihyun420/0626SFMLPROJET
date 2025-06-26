#include "InputMgr.h"
#include <algorithm>

std::list<sf::Keyboard::Key> InputMgr::downKeys;
std::list<sf::Keyboard::Key> InputMgr::heldKeys;
std::list<sf::Keyboard::Key> InputMgr::UpKeys;

void InputMgr::Init()
{

}
void InputMgr::Clear()   // �� ������(while ����)���� ���� ���� �������� DownKeys UpKeys�� ����� �� �����Ӹ� ��ȿ�ϰ� ����
{
	downKeys.clear(); 
	UpKeys.clear();
}

void InputMgr::UpdateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (!Contains(heldKeys, ev.key.code)) // �� ó�� Ű�� ��������
		{
			downKeys.push_back(ev.key.code);
			heldKeys.push_back(ev.key.code);
		}
		break;

	case sf::Event::KeyReleased:
		Remove(heldKeys, ev.key.code);
		UpKeys.push_back(ev.key.code); 
		break;
	}
}



void InputMgr::Update(float dt)
{

}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return Contains(downKeys, key);
}
bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return Contains(UpKeys, key);
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return Contains(heldKeys, key);
}

bool InputMgr::Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)   // key�� ����Ʈ �ȿ� �� �ִ��� �Ǵ�
{
	return std::find(list.begin(), list.end(), key) != list.end(); // ������ end
}

void InputMgr::Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	list.remove(key);
}
