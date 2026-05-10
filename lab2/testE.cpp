#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using Sequence = std::vector<int>;
using Compare = std::function<bool(int, int)>;

bool compare_equal(const Sequence &data_1, const Sequence &data_2, Compare func)
{
    if (data_1.size() != data_2.size())
    {
        return false;
    }

    for (size_t i = 0; i < data_1.size(); i++)
    {
        if (!func(data_1[i], data_2[i]))
        {
            return false;
        }
    }

    return true;
}

bool compare_exact(int a, int b)
{
    return a == b;
}

bool compare_tolerance(int a, int b)
{
    return std::abs(a - b) <= 1;
}

void print_sequence(const Sequence &data, const char *label)
{
    printf("%s", label);
    for (size_t i = 0; i < data.size(); i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    Sequence data_1 = {1, 2, 3};
    Sequence data_2 = {1, 2, 3};
    Sequence data_3 = {1, 3, 4};
    Sequence data_4 = {1, 2};

    print_sequence(data_1, "Sequ 1: ");
    print_sequence(data_2, "Sequ 2: ");
    print_sequence(data_3, "Sequ 3: ");
    print_sequence(data_4, "Sequ 4: ");
    printf("\n");

    printf("Exact comparison (Sequence 1 / Sequence 2): %d\n", compare_equal(data_1, data_2, compare_exact));
    printf("Exact comparison (Sequence 1 / Sequence 3): %d\n", compare_equal(data_1, data_3, compare_exact));
    printf("Tolerance comparison (Sequence 1 / Sequence 3): %d\n", compare_equal(data_1, data_3, compare_tolerance));
    printf("Length comparison (Sequence 1 / Sequence 4): %d\n", compare_equal(data_1, data_4, compare_exact));

    return 0;
}
