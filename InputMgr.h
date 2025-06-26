#pragma once
#include <list>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

class InputMgr  // 프레임 단위로 키 입력 상태를 관리하기 위해 따로 모아둔 매니저
{
private:
	static std::list<sf::Keyboard::Key> downKeys; // 지금 눌림
	static std::list<sf::Keyboard::Key> heldKeys; // 누르고 있음
	static std::list<sf::Keyboard::Key> UpKeys;   // 지금 떼어짐

	// std::list 같은 키가 중복 등록되는 걸 방지하고 삭제(remove)나 순환(foreach)이 편리하기 때문

public:
	static void Init(); 
	static void Clear(); // 매 프레임(while 루프)시작 직후 이전 프레임의 DownKeys UpKeys를 비워서 한 프레임만 유효하게 만듬

	static void UpdateEvent(const sf::Event& ev); 
	static void Update(float dt); 

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	static bool Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);
	static void Remove( std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);
};

