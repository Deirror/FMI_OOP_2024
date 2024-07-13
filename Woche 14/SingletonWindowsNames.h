#pragma once
#include <vector>
#include <string>

//Design Pattern : Singleton
class SingletonWindowsNames
{
public:
	static SingletonWindowsNames& getInstance()
	{
		static SingletonWindowsNames instance;
		return instance;
	}

	int find(const std::string& name) const
	{
		for (int i = 0; i < winNames.size(); i++)
		{
			if (name == winNames[i])
				return i;
		}

		return -1;
	}

	void push_winName(const std::string& winName)
	{
		if (find(winName) == -1)
		{
			winNames.push_back(winName);
		}
		else
		{
			throw std::exception("Already contains win name!");
		}
	}

	void pop_winName(const std::string& winName)
	{
		int index = find(winName);

		if(index == -1)
			throw std::exception("Doesn't contain win name!");

		std::string& str = winNames.at(winNames.size() - 1);

		winNames.at(index) = str;

		winNames.pop_back();
	}

private:
	SingletonWindowsNames() = default;
	~SingletonWindowsNames() = default;

	std::vector<std::string> winNames;
};

