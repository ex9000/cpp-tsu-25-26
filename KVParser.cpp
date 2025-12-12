#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <map>
#include <string>
#include <string_view>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Didn't pass a file path" << endl;
        return 0;
    }

    string path = string(argv[1]);

    ifstream file(path, ios::app);

    if (!path.ends_with(".ucl"s))
    {
        cout << "The file isn't .ucl (reading it anyway)" << endl;
    }

    if (!file)
    {
        cout << "Error opening the file (somehow)" << endl;
        return 0;
    }

    map<string, long long int> kvs;

    string line;

    while (std::getline(file, line)) {

        // Remove spaces
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

        // Comment handling
        if (line[0] == '#') {
            continue;
        }

        // Output the text from the file
        int splitter = line.find('=');

        if (splitter == std::string::npos) {
            cout << "Encountered an unparseable line: \"" << line << "\", skipping it" << endl;
            continue;
        }

        auto key = line.substr(0, splitter);
        auto value_str = line.substr(splitter + 1, line.length() - splitter - 2);

        auto value = atoi(value_str.c_str());

        // cout << key << " and " << value << endl;

        kvs[key] = value;
    }

    file.close();

    cout << "Enter new key-value pairs divided by hyphens (write 'end' to finish):" << endl;

    while (std::getline(cin, line)) {

        if (line == "end")
            break;

        // Output the text from the file
        int splitter = line.find('-');

        if (splitter == std::string::npos) {
            cout << "The given line is unparseable, skipping it" << endl;
            continue;
        }

        auto key = line.substr(0, splitter);
        auto value = atoi(line.substr(splitter + 1, line.length()).c_str());

        // cout << key << " and " << value << endl;

        kvs[key] = value;
    }

    cout << "Rewriting the file" << endl;
    std::filesystem::remove(path);
    ofstream newfile(path, ios::app);

    for (const auto& [key, value] : kvs) {
        newfile << key << " = " << value << ";" << endl;
    }
    newfile.close();
}