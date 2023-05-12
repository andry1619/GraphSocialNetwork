#include "SocialNetwork.h"

int main(char* ar[], int count)
{
    SocialNetwork sn;

    sn.addnewMan("Oleg");
    sn.addnewMan("Nikita");
    sn.addnewMan("Nastya");
    sn.addnewMan("Vika");
    sn.addnewMan("Jenya");

    sn.delMan("Vika");
    sn.addnewMan("Vanya");

    sn.addFriendship("Oleg", "Nikita");
    sn.addFriendship("Nikita", "Nastya");
    sn.addFriendship("Nastya", "Vanya");
    sn.addFriendship("Vanya", "Jenya");

    sn.showThreeHandshakes();

    return 0;
}