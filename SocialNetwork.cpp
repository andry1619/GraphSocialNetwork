#include "SocialNetwork.h"
#include <memory>
#include <iostream>

SocialNetwork::Human::Human() : id(-1) {}

SocialNetwork::Human::Human(const std::string _name, int _id) : name(_name), id(_id) {}

SocialNetwork::Human& SocialNetwork::Human::operator=(const Human& other) {
    name = other.name;
    id = other.id;
    return *this;
}
SocialNetwork::Human::Human(const Human& other) {
    name = other.name;
    id = other.id;
}

bool SocialNetwork::Human::operator==(const Human& other) {
    return other.id == this->id;
}

SocialNetwork::SocialNetwork() {
    for (int i = 0; i < SIZE; i++) {
        busyids.push_back(false);
        for (int j = 0; j < SIZE; j++)
            friend_matrix[i][j] = 0;
    }   
}
void SocialNetwork::addnewMan(const std::string name) {
    Human man = findManByName(name);
    if (man.id >= 0)
        return;
    
    for (int i = 0; i < SIZE; i++) {
        if (busyids[i] == false) {
            busyids[i] = true;
            people.push_back(Human(name, i));
            return;
        }
    }   
}

void SocialNetwork::delMan(const std::string name) {
    Human man = findManByName(name);
    if (man.id < 0)
        return;
    busyids[man.id] = false;
    int index = -1;
    for (size_t i = 0; i < people.size(); i++) {
        if (man == people[i]) index = i;
    }
    for (int i = 0; i < people.size(); i++) {
        friend_matrix[i][man.id] = 0;
        friend_matrix[man.id][i] = 0;
    }
    people.erase(people.begin() + index);
}

void SocialNetwork::addFriendship(const std::string name_1, const std::string name_2) {
    Human m1 = findManByName(name_1);
    Human m2 = findManByName(name_2);
    if (m1.id < 0 || m2.id < 0)
        return;
    friend_matrix[m1.id][m2.id] = 1;
    friend_matrix[m2.id][m1.id] = 1;
}

void SocialNetwork::showThreeHandshakes() {
    int wavesLevels[SIZE];
    for (int i = 0; i < SIZE; i++) {
        wavesLevels[i] = -1;
    }
    wavesLevels[0] = 0;

    std::vector<int> queue;
    queue.push_back(0);

    while (queue.size()) {
        int currentManIndex = queue[0];
        queue.erase(queue.begin() + 0);
        for (int i = 0; i < people.size(); i++)
            if (are_friends(people[currentManIndex], people[i]) &&
                wavesLevels[i] == -1)
            {
                wavesLevels[i] = wavesLevels[currentManIndex] + 1;
                queue.push_back(i);
            }
    }

    for (int i = 0; i < people.size(); i++) {
        for (int j = i + 1; j < people.size(); j++) {
            if (abs(wavesLevels[i] - wavesLevels[j]) <= 3) {
                std::cout << people[i].name << " " << people[j].name << std::endl;
            }
        }
    }
}


bool SocialNetwork::are_friends(const Human& m1, const Human& m2) {
    return friend_matrix[m1.id][m2.id] == 1;
}

bool SocialNetwork::man_exists_with_id(int man_id) {
    for (int i = 0; i < people.size(); i++)
        if (people[i].id == man_id)
            return true;
    return false;
}

SocialNetwork::Human SocialNetwork::findManByName(const std::string name) {
    for (int i = 0; i < people.size(); i++)
        if (name == people[i].name)
            return people[i];
    return Human();
}
