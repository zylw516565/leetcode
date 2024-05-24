#include <iostream>
using namespace std;

int main() {
    int n; int end;
    while (cin >> n);

    int count = 0;
    for (int j = 1; j <= n; ++j) {
        int sum = 0;
        for (int i = 1; i <= j/2; ++i) {
            if(j%i == 0) {
                sum += i;
            }
        }

        if(sum == j) {
          count++;
          printf("%lld\n", sum);
        }
    }

    printf("%lld\n", count);
}
// 64 位输出请用 printf("%lld")