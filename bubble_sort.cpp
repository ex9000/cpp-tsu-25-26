using namespace std;

struct Index {long long int index; double value; };

void bubble_sort(Index lst[], long long int n) {
    for (long long int i = 0; i < n - 1; ++i) {
        for (long long int j = 0; j < n - i - 1; ++j) {
            if (lst[j].value > lst[j + 1].value) {
                Index nw = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = nw;
            }
        }
    }
}
