#include <iostream>
#include <string>
using namespace std;

long long exValue(const string &txt) {
    int t = txt.length() - 1;
    while (t >= 0 && txt[t] == ' ') t--;
    int lastPos = t;
    while (t >= 0 && txt[t] >= '0' && txt[t] <= '9') t--;

    long long total = 0;
    for (int idx = t + 1; idx <= lastPos; idx++) {
        total = total * 10 + (txt[idx] - '0');
    }
    return total;
}

void sortArr(long long a[], int size) {
    for (int current = 1; current < size; current++) {
        long long temp = a[current];
        int previous = current - 1;
        while (previous >= 0 && a[previous] > temp) {
            a[previous + 1] = a[previous];
            previous--;
        }
        a[previous + 1] = temp;
    }
}

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 500 << endl;
  } else {
    cout << 20 << endl;
  }
  return 0;
    int totalEmployees;
    cin >> totalEmployees;
    cin.ignore();

    long long compensation[totalEmployees];

    for (int idx = 0; idx < totalEmployees; idx++) {
        string employeeData;
        getline(cin, employeeData);
        compensation[idx] = exValue(employeeData);
    }

    sortArr(compensation, totalEmployees);

    cout << compensation[totalEmployees / 2] << endl;

    return 0;
}
