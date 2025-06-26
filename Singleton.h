#pragma once

template <typename T>
class Singleton
{
protected:
	Singleton() = default; // 아무일도 안하는 기본 생성자 추가와 동일
	virtual ~Singleton() = default; // 상속 받을것이기 때문에 가상 소멸자로 해야함
	
	Singleton(const Singleton&) = delete; // 매개변수에 자기 클래스의 레퍼런스를 받으면 복사 생성자 , 사용하지 않기 위해서 delete 왜냐면 싱글톤이기 때문에
	Singleton& operator=(const Singleton&) = delete;
	

public:

	static T& Instance()
	{
		static T instance; // static 지역 변수 static 키워드를 붙이면, 이 변수는 함수가 끝나도 파괴되지 않고 값을 유지합니다.

		                   //스코프(scope)는 “함수 내부”로 제한되지만, 저장 기간(storage duration)은 프로그램 전체입니다.
		return instance; 
	}

};
