#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>


struct User{
    int uid;
    char email[128];
    char name[128];
};








struct User user1 = {1, "e123@cpp.at", "e123"};
struct User user2 = {2, "e124@cpp.at", ""};
struct User user3 = {3, "e1245cpp.at", "e1245"};
struct User user4 = {2, "e125@cpp.at", "e125"};



//struct User users[4] = {user1, user2, user3, user4};















