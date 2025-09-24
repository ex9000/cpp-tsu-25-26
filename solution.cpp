#include <iostream>
#include <string>

using namespace std;

int main()
{
    int result_sum = 0;
    int result_count = 0;
    int n;
    string slovo;

    cin >> slovo >> slovo >> slovo >> n;

    while (n != 0) {
        int cost, count;

        cin >> slovo;
        if (slovo == "за") {
            cin >> cost;
            result_sum += cost;
            result_count++;
            n--;
        }

        if (slovo == "по") {
            cin >> cost >> slovo >> count;
            result_sum += count * cost;
            result_count += count;
            n--;
        }
    }

    if (result_count == 1) {
        cout << "Куплен товар за " << result_sum << " рублей" << endl;
    }
    else {
        cout << "Куплено " << result_count << " штук товара за " << result_sum << " рублей" << endl;
    }
    return 0;
}
