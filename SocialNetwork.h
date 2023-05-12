#pragma once
#include <string>
#include <vector>

class SocialNetwork
{
public:
	struct Human { // класс человека
		Human();
		Human(const std::string _name, int _id);
		Human& operator=(const Human& other);
		Human(const Human& other);

		bool operator==(const Human& other);

		std::string name; // им€

		friend class SocialNetwork;

	private:
		int id; // внутренний id

	};
	SocialNetwork();
	// добавление нового человека в сеть
	void addnewMan(const std::string name);
	// удаление человека из сети
	void delMan(const std::string name);
	// установка дружбы между двум€ людьми
	void addFriendship(const std::string name_1, const std::string name_2);
	// алгоритм поиска пар
	void showThreeHandshakes();

private: // функции
	// €вл€ютс€ друзь€ми?
	bool are_friends(const Human& m1, const Human& m2);
	// есть ли человек с man_id
	bool man_exists_with_id(int man_id);
	// поиск по имени
	Human findManByName(const std::string name);
private: // пол€
	static const int SIZE = 10;
	int friend_matrix[SIZE][SIZE]; // матрица дружбы
	std::vector<Human> people; // список людей внутри сети
	std::vector<bool> busyids; // зан€тые id
};

