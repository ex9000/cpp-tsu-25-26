#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

std::map<std::string, std::string> data;
std::vector<std::string> keyOrder;

int read_local_config(std::fstream& file) {
    std::string line;
    int finded = 0;
    while (getline(file, line) && finded == 0) {
        int value_op = line.find('=');
        std::string key_finded = line.substr(0, value_op);
        std::string val_finded = line.substr(value_op + 1);
        data[key_finded] = val_finded;
        keyOrder.push_back(key_finded);
    }
    file.close();
    return 0;
};

void save_local_config(const std::string& filename) {
    std::ofstream file(filename);

    for (int i = 0; i < keyOrder.size(); i++) {
        std::string key = keyOrder[i];
        std::string value = data[key];
        file << key << "=" << value << "\n";
    }

    file.close();
}

int main(int argc, char* argv[]) {
    std::string filename;
    if (argc >= 2) {
        filename = argv[1];
    }
    else {
        filename = "file.ini";
    }

    std::fstream myFile(filename);
    std::string line;

    read_local_config(myFile);
    std::string str1;
    std::string str2;

    while (std::cin >> str1) {
        std::cin >> str2;
        if (data.contains(str1)) {
            data[str1] = str2;
        }
        else {
            keyOrder.push_back(str1);
            data[str1] = str2;
        }
        save_local_config(filename);
    }
    return 0;

}
