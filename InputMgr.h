#pragma once
#include <list>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

class InputMgr  // ������ ������ Ű �Է� ���¸� �����ϱ� ���� ���� ��Ƶ� �Ŵ���
{
private:
	//static std::list<sf::Keyboard::Key> downKeys; // ���� ����
	//static std::list<sf::Keyboard::Key> heldKeys; // ������ ����
	//static std::list<sf::Keyboard::Key> UpKeys;   // ���� ������

	static std::vector<bool> downKeys;
	static std::vector<bool> heldKeys;
	static std::vector<bool> UpKeys;

	// std::list ���� Ű�� �ߺ� ��ϵǴ� �� �����ϰ� ����(remove)�� ��ȯ(foreach)�� ���ϱ� ����

public:
	static void Init(); 
	static void Clear(); // �� ������(while ����)���� ���� ���� �������� DownKeys UpKeys�� ����� �� �����Ӹ� ��ȿ�ϰ� ����

	static void UpdateEvent(const sf::Event& ev);  
	static void Update(float dt); 

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool Contains(const std::vector<bool>& vector, sf::Keyboard::Key key);
	static void Remove( std::vector<bool>& vector, sf::Keyboard::Key key);
};

