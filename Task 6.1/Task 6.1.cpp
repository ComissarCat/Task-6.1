#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int pow(int basis, int degree);
int sum_from_range(int start, int end);
void perfect_from_range(int start, int end);
void draw_cart(const char* value, const char* suit);
void enter_cart();
void lucky_number(int number);

int main()
{
    setlocale(LC_ALL, "Russian");    
    
    lucky_number(123321);

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

void draw_cart(const char* value, const char* suit)
{    
    cout << "+-------+\n";
    cout << "|       |\n";
    if (strstr(suit, "spades")) cout << "|s      |\n";
    else if (strstr(suit, "hearts")) cout << "|h      |\n";
    else if (strstr(suit, "diamonds")) cout << "|d      |\n";
    else if (strstr(suit, "crosses")) cout << "|c      |\n";
    cout << "|       |\n";
    if (strstr(value, "jack")) cout << "|   J   |\n";
    else if (strstr(value, "queen")) cout << "|   Q   |\n";
    else if (strstr(value, "king")) cout << "|   K   |\n";
    else if (strstr(value, "ace")) cout << "|   A   |\n";
    else if (strstr(value, "10")) cout << "|  1 0  |\n";
    else cout << "|   " << value << "   |\n";
    cout << "|       |\n";
    if (strstr(suit, "spades")) cout << "|      s|\n";
    else if (strstr(suit, "hearts")) cout << "|      h|\n";
    else if (strstr(suit, "diamonds")) cout << "|      d|\n";
    else if (strstr(suit, "crosses")) cout << "|      c|\n";
    cout << "|       |\n";
    cout << "+-------+\n";
}

void enter_cart()
{
    char value[6], suit[9];

    do
    {
        cout << "Введите значение карты: ";
        gets_s(value);
        _strlwr(value);
    } while (not(strstr(value,"6")) and not(strstr(value, "7")) and not(strstr(value, "8")) and not(strstr(value, "9")) and not(strstr(value, "10"))
        and not(strstr(value, "jack")) and not(strstr(value, "queen")) and not(strstr(value, "king")) and not(strstr(value, "ace")));
    
    do
    {
        cout << "Введите масть: ";
        gets_s(suit);
        _strlwr(suit);
    } while (not(strstr(suit, "spades")) and not(strstr(suit, "hearts")) and not(strstr(suit, "diamonds")) and not(strstr(suit, "crosses")));

    draw_cart(value, suit);
}

void lucky_number(int number)
{
    int first_half = 0, second_half = 0;
    for (int i = 0; i < 3; i++)
    {
        first_half += (number % 10);
        number /= 10;
    }
    for (int i = 0; i < 3; i++)
    {
        second_half += (number % 10);
        number /= 10;
    }
    if (first_half == second_half) cout << "Число счастливое";
    else cout << "Число не счастливое";
}