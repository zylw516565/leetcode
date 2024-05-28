#include <iostream>
#include <string>
using namespace std;

int main() {
    std::string str;
    std::getline(cin, str);

    int charCount = 0, digitCount = 0, spaceCount = 0, otherCount = 0;
    for (auto&& item : str) {
        if(item >= 'A' && item <= 'Z'
           || item >= 'a' && item <= 'z')
        {
            charCount++;
        } else if (item == ' ') {
            spaceCount++;
        } else if (item >= '0' && item <= '9') {
            digitCount++;
        } else {
            otherCount++;
        }
    }

    cout << charCount << endl;
    cout << spaceCount << endl;
    cout << digitCount << endl;
    cout << otherCount << endl;
}
// 64 位输出请用 printf("%lld")