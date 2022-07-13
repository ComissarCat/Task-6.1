#include <iostream>
using namespace std;

int pow(int basis, int degree);
int sum_from_range(int start, int end);
void perfect_from_range(int start, int end);
void draw_cart(char suit, char value);
void lucky_number(int number);

int main()
{
    setlocale(LC_ALL, "Russian");

    perfect_from_range(1, 500);

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

void perfect_from_range(int start, int end)
{
    for (int i = start; i <= end; i++)
    {        
        int sum_of_dividers = 0;        
        for (int j = 1; j <= i; j++)
        {
            if (not(i % j)) sum_of_dividers += j;
        }
        if ((sum_of_dividers - i) == i) cout << i << "\t";
    }
}