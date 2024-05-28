#include <iostream>
#include <stack>
#include <string>
using namespace std;

void compute(std::stack<int>& st1, std::stack<char>& st2)
{
    auto b = st1.top();
    st1.pop();
    auto a = st1.top();
    st1.pop();
    auto op = st2.top();
    st2.pop();

    switch (op) {
    case '+': a = a + b;
        break;
    case '-': a = a - b;
        break;
    case '*': a = a * b;
        break;
    case '/': a = a / b;
        break;
    default:
        break;
    }

    st1.push(a);
}

bool priority(char m, char n){ //比较运算符优先级
    if(m == '(') //括号优先级最高
        return false;
    else if((m == '+' || m == '-') && (n == '*' || n == '/')) //加减法小于乘除法
        return false;
    return true;
}

int main() {
    std::string str;
    std::getline(cin, str);

    std::stack<int> st1;
    std::stack<char> st2;
    st2.push('('); //整个运算式添加括号
    str += ')';

    bool flag = false; //数字标志
    for (int i = 0; i < str.size(); ++i) {
        if(str[i] == '(') { //左括号
            st2.push('(');
        } else if (str[i] == ')') { //右括号
            while (st2.top() != '(') {
                compute(st1, st2);            
            }
            st2.pop();
        } else if (flag) { //运算符
              while(priority(st2.top(), str[i])){ //比较运算优先级
                  compute(st1, st2); //可以直接计算
              }
              st2.push(str[i]); //需要将现阶段加入栈中等待运算
              flag = false;
        } else { //数字
            int j = i;
            if(str[i] == '-' || str[i] == '+') i++;
            while (isdigit(str[i])) {
                ++i;
            }

            auto tmp = str.substr(j, i - j);
            st1.push(stoi(tmp));
            i--;
            flag = true;
        }
    }

    cout << st1.top() << endl; //输出
}