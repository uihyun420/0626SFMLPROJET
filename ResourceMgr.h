#pragma once
#include "Singleton.h"
#include <string>
#include <unordered_map>  // map , u-map ���� �����̳� ���ø� ���ڸ� 2�� ���� �տ� �ִ� ���ø� ���ڸ� Key �ڿ��� value ������ �����ϰ� ���� ���� value 
						// ���� �����̳ʴ� Ž���� Ưȭ�Ǿ����� Ž�� ������ u-map�� �� ���� ��ġ�� �ڵ������� �ȵ�

#include <vector>


// Ŭ���� ���ø��� Ŭ������ �Ǳ� ���ؼ��� ���ø� ���ڰ� �ʿ�

template <typename T> // �ؽ���, ��Ʈ, ���� �Ŵ����� ������� ���
class ResourceMgr : public Singleton<ResourceMgr<T>> // �̱����� ����� ���� T 
{
	friend Singleton<ResourceMgr<T>>;

protected:

	ResourceMgr() = default;
	virtual ~ResourceMgr()
	{
		for (auto piar : resources)
		{
			delete piar.second;
		}
		resources.clear();
	}


	ResourceMgr(const ResourceMgr&) = delete;
	ResourceMgr* operator=(const ResourceMgr&) = delete;


	std::unordered_map<std::string, T*> resources; // ���ø� ���� 2�� Key, value

	static T Empty;

public:
	// ���� �ε� ���ε� ���� �⺻���� ��� 
	bool load(const std::vector<std::string>& vec)
	{
		for (auto str : vec) // ���� : ����
		{
			load(str);
		}
		return false;
	}

	bool load(const std::string& vec) // ���۷����� ������ �ٸ� ������ ���ο� ������ ���簡 �Ǵ� ���̾ �ʹ� �����Ͱ� �޸𸮿� �������� �׷��Ƿ� ���������� �ٷ� ������ �� �ֵ���
	{
		auto it = resources.find(vec);
		if (it != resources.end()) 
		{
			return false; // �̹� �ε� �Ǿ� ������
		}

		T* res = new T();
		bool success = res->loadFromFile(vec);
		if (!success)
		{
			return false;
		}
		resources.insert({ vec, res}); // key, value ������ �Է�
		
	}



	bool Unload(const std::vector<std::string>& str) 
	{
		for (auto vector : str)
		{
			auto it = resources.find(vector);
			if (it == resources.end()) // ��ã����
			{
				return false;
			}

			delete it->second; // new ����Ʈ 
			resources.erase(it); // �����̳ʿ��� ���°�
			return true; // ���������ϱ� Ʈ�� 
		}

	}


	bool Unload(const std::string& vector)
	{
		auto it = resources.find(vector);
		if (it == resources.end()) // ��ã����
		{
			return false;
		}

		delete it->second; // new ����Ʈ 
		resources.erase(it); // �����̳ʿ��� ���°�
		return true; // ���������ϱ� Ʈ�� 
	}






	T& Get(const std::string& id) // T�� ���۷����� ��ȯ��, ���� ��θ� ����(key)
	{
		auto it = resources.find(id); // �Ű������� T�� �ѱ�
		if (it == resources.end()) // �ȵ� ������ 
		{
			return Empty;
		}

		return *(it->second);
	}


};
template <typename T>
T ResourceMgr<T>::Empty; 