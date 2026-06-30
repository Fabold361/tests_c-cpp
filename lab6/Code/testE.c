#include <assert.h>
#include <stddef.h>
#include <string.h>

#define NUM_USERS 4

typedef struct
{
  unsigned int uid;
  const char *email;
  const char *name;
} User;

void validate(const User *users, size_t n, int *output)
{
  for (size_t i = 0; i < n; i++)
  {
    int invalid_email = 1; // 1 -> email is not valid
    size_t j = 0;

    while (users[i].email[j] != '\0')
    {
      if (users[i].email[j] == '@')
        invalid_email = 0;
      j++;
    }

    int unique_uid = 1;
    for (size_t k = 0; k < n; k++)
    {
      if (k != i && users[k].uid == users[i].uid)
      {
        unique_uid = 0;
        break;
      }
    }

    if (unique_uid && users[i].name[0] != '\0' && invalid_email == 0)
      output[i] = 1;
    else
      output[i] = 0;
  }
}

int main()
{
  User users[NUM_USERS] = {
      {1, "e123@cpp.at", "e123"},  // valid
      {2, "e124@cpp.at", ""},      // empty name
      {3, "e1245cpp.at", "e1245"}, // invalid email
      {2, "e125@cpp.at", "e125"}   // duplicate uid
  };

  int res[NUM_USERS];
  validate(users, NUM_USERS, res);

  int expected[NUM_USERS] = {1, 0, 0, 0};
  assert(memcmp(res, expected, sizeof(expected)) == 0);

  return 0;
}
