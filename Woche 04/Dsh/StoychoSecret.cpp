#include <iostream>
#include <cstring>
#pragma warning (disable : 4996)

class Secret
{
private:
	char* taskCondition = nullptr;

	char* password = nullptr;

	size_t failedLogs = 0;

public:
	Secret() = delete;

	Secret(const char* _taskCondition, const char* _password);

	~Secret();

	const char* getTask() const;

	void setPassword(const char* newPassword, const char* oldPassword);

	void setTask(const char* newTask, const char* password);

	size_t getLoginFails() const;
};

Secret::Secret(const char * _taskCondition, const char * _password) 
{
	if (_taskCondition && _password)
	{
		taskCondition = new char[strlen(_taskCondition) + 1]{};
		strcpy(taskCondition, _taskCondition);

		password = new char[strlen(_password) + 1]{};
		strcpy(password, _password);
	}
}

Secret::~Secret()
{
	delete[] taskCondition;
	delete[] password;
}

const char * Secret::getTask() const
{
	return taskCondition;
}

void Secret::setPassword(const char * newPassword, const char * oldPassword)
{
	if (!newPassword || !oldPassword)
		return;

	if (strcmp(oldPassword, password) == 0)
	{
		delete[] password;

		password = new char[strlen(newPassword) + 1]{};

		strcpy(password, newPassword);
	}
	else
	{
		failedLogs++;
	}
}

void Secret::setTask(const char * newTask, const char * _password)
{
	if (!newTask || !_password)
		return;

	if (strcmp(_password, password) == 0)
	{
		delete[] taskCondition;

		taskCondition = new char[strlen(newTask) + 1]{};

		strcpy(taskCondition, newTask);
	}
	else
	{
		failedLogs++;
	}
}

size_t Secret::getLoginFails() const
{
	return failedLogs;
}

int main()
{
	Secret secret("OOP the best, ama na taratanci","itswednesday");

	secret.setPassword("omgbe", "nadali");

	secret.setTask("ne se povatrqm nali?", "nadali");

	std::cout << secret.getLoginFails();

	return 0;
}

