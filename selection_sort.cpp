using namespace std;

struct Index {long long int index; double value; };

void selection_sort(Index lst[], long long int n) {
    for (long long int i = 0; i < n - 1; ++i) {
        long long int minI = i;
        for (long long int j = i + 1; j < n; ++j) {
            if (lst[j].value < lst[minI].value)
                minI = j; }
        Index nw = lst[i];
        lst[i] = lst[minI];
        lst[minI] = nw;
    }
}
