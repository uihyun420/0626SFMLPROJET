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
void InputMgr::Clear()   // �� ������(while ����)���� ���� ���� �������� DownKeys UpKeys�� ����� �� �����Ӹ� ��ȿ�ϰ� ����
{
	downKeys.clear(); 
	UpKeys.clear();
}

void InputMgr::UpdateEvent(const sf::Event& ev) // sf::Event�� SFML�� ������ �ý��ۿ��� ���� ���콺 ������, Ű���� �Է�, ������ �ݱ� ���� ��� ����� ǥ���ϴ� ����ü
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed: 
		if (!Contains(heldKeys, ev.key.code)) //�̹� heldKeys �� ���� Ű��� -> ���� �� ���� ������ ���� 
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



void InputMgr::Update(float dt) // ������ �߰� ���� // ����� ��� �������� ���߿� ��Ű�� ������ �ִ� �ð� ������ ���� �����̳�, ����ư Ȧ�� ���� �� �̺�Ʈ �ݺ��� ���� ����� ���� �� �ִ� �ڸ��Դϴ�.
{

}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key) // �� �����ӿ� ��� �����°�? 
{
	return Contains(downKeys, key); // �ش� ����Ʈ�� Ű�� �ִ��� Ȯ��
}
bool InputMgr::GetKeyUp(sf::Keyboard::Key key) // �� �����ӿ� ��� �����°�? 
{
	return Contains(UpKeys, key);
}

bool InputMgr::GetKey(sf::Keyboard::Key key) // ���� ������ �ִ� ���ΰ�? 
{
	return Contains(heldKeys, key);
}

bool InputMgr::Contains(const std::vector<bool>& vector, sf::Keyboard::Key key)   // key�� ����Ʈ �ȿ� �� �ִ��� �Ǵ�
{
	return vector[key]; //std::find(vector.begin(), vector.end(), key) != vector.end(); // std::find�� �Ἥ ���ش� ����Ʈ�� key�� ������ true���� ��ȯ�մϴ�.
}

void InputMgr::Remove(std::vector<bool>& vector, sf::Keyboard::Key key)
{
	vector[key] = false;// std::vector::remove �� ����Ʈ���� key�� ��� ����ϴ�.
}
