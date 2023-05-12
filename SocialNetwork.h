#pragma once
#include <string>
#include <vector>

class SocialNetwork
{
public:
	struct Human { // ����� ��������
		Human();
		Human(const std::string _name, int _id);
		Human& operator=(const Human& other);
		Human(const Human& other);

		bool operator==(const Human& other);

		std::string name; // ���

		friend class SocialNetwork;

	private:
		int id; // ���������� id

	};
	SocialNetwork();
	// ���������� ������ �������� � ����
	void addnewMan(const std::string name);
	// �������� �������� �� ����
	void delMan(const std::string name);
	// ��������� ������ ����� ����� ������
	void addFriendship(const std::string name_1, const std::string name_2);
	// �������� ������ ���
	void showThreeHandshakes();

private: // �������
	// �������� ��������?
	bool are_friends(const Human& m1, const Human& m2);
	// ���� �� ������� � man_id
	bool man_exists_with_id(int man_id);
	// ����� �� �����
	Human findManByName(const std::string name);
private: // ����
	static const int SIZE = 10;
	int friend_matrix[SIZE][SIZE]; // ������� ������
	std::vector<Human> people; // ������ ����� ������ ����
	std::vector<bool> busyids; // ������� id
};

