﻿#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 3; i++) {
        string a;
        cin >> a;
    }

    int N;
    cin >> N;

    int sum = 0;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        while (true)
        {
            string lastRead = "";
            cin >> lastRead;

            if (lastRead == "за") {
                int price;
                cin >> price;
                sum += price;
                count++;
                break;
            }
            else if (lastRead == "по") {
                int price;
                cin >> price;
                cin >> lastRead;
                int amount;
                cin >> amount;
                sum += price * amount;
                count += amount;
                break;
            }
        }
    }

    if (count == 1) {
        cout << " Куплен товар за " << sum << " рублей" << endl;
    }
    else {
        cout << " Куплено " << count << " штук товара за " << sum << " рублей" << endl;
    }

    return 0;
}