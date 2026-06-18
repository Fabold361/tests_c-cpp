#include <cassert>
#include <cmath>
#include <cstddef>
#include <string>
#include <vector>

struct User {
 unsigned int uid;
 std::string email;
 std::string name;
};

std::vector<bool> validate(std::vector<User> users){
    std::vector<bool> output;

    unsigned int invalid_email = 1;     //true -> email in not valid
    size_t j = 0;

    for (size_t i = 0; i < users.size(); i++){
        while (users[i].email[j] != '\0') {
            if (users[i].email[j] == '@') invalid_email = 0;
            j++;
        }
        if ((users[i].uid == i+1) && users[i].name[0] != '\0' && invalid_email == 0) output.push_back(true);    //only checking seqential (autogengen uid) and not duplicate uid, system relies onstacking uid 
        else output.push_back(false);
        invalid_email = 1;
        j = 0;
    }
    return output;
}

int main() {
 std::vector<User> users = {
 {1, "e123@cpp.at", "e123"}, // valid
 {2, "e124@cpp.at", ""}, // empty name
 {3, "e1245cpp.at", "e1245"}, // invalid email
 {2, "e125@cpp.at", "e125"} // duplicate uid
 };
 auto res = validate(users);
 std::vector<bool> expected = {true, false, false, false};
 assert(res == expected);
 return 0;
}