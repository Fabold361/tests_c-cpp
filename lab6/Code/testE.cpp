#include <cassert>
#include <cmath>
#include <cstddef>
#include <string>
#include <vector>

struct User
{
  unsigned int uid;
  std::string email;
  std::string name;
};

std::vector<bool> validate(std::vector<User> users)
{
  std::vector<bool> output;

  for (size_t i = 0; i < users.size(); i++)
  {
    unsigned int invalid_email = 1; // true -> email is not valid
    size_t j = 0;                   // j muss pro Nutzer neu starten

    while (users[i].email[j] != '\0')
    {
      if (users[i].email[j] == '@')
        invalid_email = 0;
      j++;
    }

    bool unique_uid = true;
    for (size_t k = 0; k < users.size(); k++)
    {
      if (k != i && users[k].uid == users[i].uid)
      {
        unique_uid = false;
        break;
      }
    }

    if (unique_uid && users[i].name[0] != '\0' && invalid_email == 0)
      output.push_back(true);
    else
      output.push_back(false);
  }
  return output;
}

int main()
{
  std::vector<User> users = {
      {1, "e123@cpp.at", "e123"},  // valid
      {2, "e124@cpp.at", ""},      // empty name
      {3, "e1245cpp.at", "e1245"}, // invalid email
      {2, "e125@cpp.at", "e125"}   // duplicate uid
  };
  auto res = validate(users);
  std::vector<bool> expected = {true, false, false, false};
  assert(res == expected);
  return 0;
}
