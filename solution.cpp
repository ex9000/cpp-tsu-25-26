#include <iostream>

int main()
{
    for (int i = 0; i < 3; i++) {
        std::string a;
        std::cin >> a;
    }

    int N;
    std::cin >> N;

    int sum = 0;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        while (true)
        {
            std::string lastRead = "";
            std::cin >> lastRead;

            if (lastRead == "за") {
                int price;
                std::cin >> price;
                sum += price;
                count++;
                break;
            }
            else if (lastRead == "по") {
                int price;
                std::cin >> price;
                std::cin >> lastRead;
                int amount;
                std::cin >> amount;
                sum += price * amount;
                count += amount;
                break;
            }
        }
    }

    if (count == 1) {
        std::cout << "Куплен товар за " << sum << " рублей" << std::endl;
    }
    else {
        std::cout << "Куплено " << count << " штук товара за " << sum << " рублей" << std::endl;
    }

    return 0;
}