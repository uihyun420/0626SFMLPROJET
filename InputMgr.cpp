#include "InputMgr.h"
#include <algorithm>

std::vector<bool> InputMgr::downKeys(sf::Keyboard::KeyCount);
std::vector<bool> InputMgr::heldKeys(sf::Keyboard::KeyCount);
std::vector<bool> InputMgr::UpKeys(sf::Keyboard::KeyCount);

void InputMgr::Init()
{
	downKeys.resize(101);
	UpKeys.resize(101);
}
void InputMgr::Clear()   // 매 프레임(while 루프)시작 직후 이전 프레임의 DownKeys UpKeys를 비워서 한 프레임만 유효하게 만듬
{
	downKeys.clear(); 
	UpKeys.clear();
}

void InputMgr::UpdateEvent(const sf::Event& ev) // sf::Event란 SFML이 윈도우 시스템에서 받은 마우스 움직임, 키보드 입력, 윈도우 닫기 등의 모든 사건을 표현하는 구조체
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed: 
		if (!Contains(heldKeys, ev.key.code)) //이미 heldKeys 에 없던 키라면 -> 지금 막 눌린 것으로 간주 
		{
			downKeys[ev.key.code] = true;
			heldKeys[ev.key.code] = true;
		}
		break;

	case sf::Event::KeyReleased:

		heldKeys[ev.key.code] = false;
		UpKeys[ev.key.code] = true;
		break;
	}
}



void InputMgr::Update(float dt) // 프레임 중간 갱신 // 현재는 비어 있지만… 나중에 “키를 누르고 있는 시간 누적” 같은 로직이나, “버튼 홀드 중일 때 이벤트 반복” 같은 기능을 넣을 수 있는 자리입니다.
{

}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key) // 그 프레임에 방금 눌렀는가? 
{
	return Contains(downKeys, key); // 해당 리스트에 키가 있는지 확인
}
bool InputMgr::GetKeyUp(sf::Keyboard::Key key) // 그 프레임에 방금 떼였는가? 
{
	return Contains(UpKeys, key);
}

bool InputMgr::GetKey(sf::Keyboard::Key key) // 지금 누르고 있는 중인가? 
{
	return Contains(heldKeys, key);
}

bool InputMgr::Contains(const std::vector<bool>& vector, sf::Keyboard::Key key)   // key가 리스트 안에 들어가 있는지 판단
{
	return vector[key]; //std::find(vector.begin(), vector.end(), key) != vector.end(); // std::find를 써서 “해당 리스트에 key가 있으면 true”를 반환합니다.
}

void InputMgr::Remove(std::vector<bool>& vector, sf::Keyboard::Key key)
{
	vector[key] = false;// std::vector::remove 로 리스트에서 key를 모두 지웁니다.
}
