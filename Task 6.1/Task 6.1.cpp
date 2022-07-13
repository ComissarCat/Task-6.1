#include <iostream>
using namespace std;

int pow(int basis, int degree);
int sum_from_range(int start, int end);
int perfect_from_range(int start, int end);
void draw_cart(char suit, char value);
void lucky_number(int number);

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << sum_from_range(1, 5);

    return 0;
}

int pow(int basis, int degree)
{
    int result = basis;
    for (int i = 1; i < degree; i++)
    {
        result *= basis;
    }
    return result;
}

int sum_from_range(int start, int end)
{
    int result = 0;
    for (int i = start; i <= end; i++)
    {
        result += i;
    }
    return result;
}