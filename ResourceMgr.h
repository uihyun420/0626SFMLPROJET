#pragma once
#include "Singleton.h"
#include <string>
#include <unordered_map>  // map , u-map 연관 컨테이너 템플릿 인자를 2개 받음 앞에 있는 템플릿 인자를 Key 뒤에를 value 실제로 저장하고 싶은 값은 value 
						// 연관 컨테이너는 탐색에 특화되어있음 탐색 성능은 u-map이 더 좋음 그치만 자동정렬이 안됨

#include <vector>


// 클래스 템플릿이 클래스가 되기 위해서는 템플릿 인자가 필요

template <typename T> // 텍스쳐, 폰트, 사운드 매니져로 만드려고 사용
class ResourceMgr : public Singleton<ResourceMgr<T>> // 싱글턴이 사용할 인자 T 
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


	std::unordered_map<std::string, T*> resources; // 템플릿 인자 2개 Key, value

	static T Empty;

public:
	// 파일 로드 업로드 가장 기본적인 기능 
	bool load(const std::vector<std::string>& vec)
	{
		for (auto str : vec) // 원소 : 범위
		{
			load(str);
		}
		return false;
	}

	bool load(const std::string& vec) // 레퍼런스가 없으면 다른 공간에 새로운 변수로 복사가 되는 것이어서 너무 데이터가 메모리에 많아진다 그러므로 참조형으로 바로 접근할 수 있도록
	{
		auto it = resources.find(vec);
		if (it != resources.end()) 
		{
			return false; // 이미 로드 되어 있으니
		}

		T* res = new T();
		bool success = res->loadFromFile(vec);
		if (!success)
		{
			return false;
		}
		resources.insert({ vec, res}); // key, value 쌍으로 입력
		
	}



	bool Unload(const std::vector<std::string>& str) 
	{
		for (auto vector : str)
		{
			auto it = resources.find(vector);
			if (it == resources.end()) // 못찾으면
			{
				return false;
			}

			delete it->second; // new 딜리트 
			resources.erase(it); // 컨테이너에서 빼는것
			return true; // 삭제했으니까 트루 
		}

	}


	bool Unload(const std::string& vector)
	{
		auto it = resources.find(vector);
		if (it == resources.end()) // 못찾으면
		{
			return false;
		}

		delete it->second; // new 딜리트 
		resources.erase(it); // 컨테이너에서 빼는것
		return true; // 삭제했으니까 트루 
	}






	T& Get(const std::string& id) // T의 레퍼런스로 반환형, 파일 경로를 받음(key)
	{
		auto it = resources.find(id); // 매개변수로 T를 넘김
		if (it == resources.end()) // 안들어가 있으면 
		{
			return Empty;
		}

		return *(it->second);
	}


};
template <typename T>
T ResourceMgr<T>::Empty; 