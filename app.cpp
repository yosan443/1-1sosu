#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 素数判定関数
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    // 奇数のみを確認し、sqrt(n)まで確認
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// エラトステネスの篩を使用して素数をカウント
int countPrimesUpTo(int limit) {
    if (limit < 2) return 0;

    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    // エラトステネスの篩の実装
    for (int i = 2; i * i <= limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 素数の個数をカウント
    int count = 0;
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) count++;
    }

    return count;
}

int main() {
    while (true) {
        cout << "Select:\n";
        cout << "0:素数判定\n";
        cout << "1:1〜1000までの素数の個数を計算\n";

        int choice;
        cin >> choice;

        if (choice == 0) {
            int num;
            cout << "数値を入力: ";
            cin >> num;

            if (isPrime(num)) {
                cout << num << "は素数である\n";
            } else {
                cout << num << "は素数でない\n";
            }
        }
        else if (choice == 1) {
            int count = countPrimesUpTo(1000);
            cout << "1〜1000までの素数の個数:" << count << "\n";
        }
        else {
            cout << "ERROR\n";
        }

        cout << "\n";
    }

    return 0;
}