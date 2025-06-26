#pragma once

template <typename T>
class Singleton
{
protected:
	Singleton() = default; // �ƹ��ϵ� ���ϴ� �⺻ ������ �߰��� ����
	virtual ~Singleton() = default; // ��� �������̱� ������ ���� �Ҹ��ڷ� �ؾ���
	
	Singleton(const Singleton&) = delete; // �Ű������� �ڱ� Ŭ������ ���۷����� ������ ���� ������ , ������� �ʱ� ���ؼ� delete �ֳĸ� �̱����̱� ������
	Singleton& operator=(const Singleton&) = delete;
	

public:

	static T& Instance()
	{
		static T instance; // static ���� ���� static Ű���带 ���̸�, �� ������ �Լ��� ������ �ı����� �ʰ� ���� �����մϴ�.

		                   //������(scope)�� ���Լ� ���Ρ��� ���ѵ�����, ���� �Ⱓ(storage duration)�� ���α׷� ��ü�Դϴ�.
		return instance; 
	}

};
