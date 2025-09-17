#include <iostream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    int pos = line.rfind(' ');
    int n = std::stoi(line.substr(pos + 1));

    int total_sum = 0;
    int total_k = 0;

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);

        int k = 1;
        int p = 0;
        std::size_t pos_za = line.find(" за ");
        std::size_t pos_po = line.find(" по ");

        if (pos_za != std::string::npos) {
            std::size_t start = pos_za + 4;
            std::string num = line.substr(start);
            p = std::stoi(num);
        } else if (pos_po != std::string::npos) {
            std::size_t start_p = pos_po + 4;
            std::string num_p = line.substr(start_p);
            p = std::stoi(num_p);

            std::size_t colon = line.find(':', start_p);
            std::size_t start_k = colon + 2; // после ": "
            std::string num_k = line.substr(start_k);
            k = std::stoi(num_k);
        }

        total_sum += k * p;
        total_k += k;
    }

    if (total_k == 1) {
        std::cout << "Куплен товар за " << total_sum << " рублей" << std::endl;
    } else {
        std::cout << "Куплено " << total_k << " штук товара за " << total_sum << " рублей" << std::endl;
    }

    return 0;
}
