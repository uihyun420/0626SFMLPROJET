#include "InputMgr.h"
#include <algorithm>

std::list<sf::Keyboard::Key> InputMgr::downKeys;
std::list<sf::Keyboard::Key> InputMgr::heldKeys;
std::list<sf::Keyboard::Key> InputMgr::UpKeys;

void InputMgr::Init()
{

}
void InputMgr::Clear()   // 매 프레임(while 루프)시작 직후 이전 프레임의 DownKeys UpKeys를 비워서 한 프레임만 유효하게 만듬
{
	downKeys.clear(); 
	UpKeys.clear();
}

void InputMgr::UpdateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (!Contains(heldKeys, ev.key.code)) // 맨 처음 키가 눌린순간
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

bool InputMgr::Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)   // key가 리스트 안에 들어가 있는지 판단
{
	return std::find(list.begin(), list.end(), key) != list.end(); // 없으면 end
}

void InputMgr::Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	list.remove(key);
}
