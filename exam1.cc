#include <iostream>
#include <string>
#include <vector>

#include <limits>

using namespace std;

const double EPSILON = 1e-6;

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::string::size_type start = 0; // 子串起始位置
    std::string::size_type end = str.find(delimiter); // 分隔符位置

    while (end != std::string::npos) {
        // 截取从 start 到 end 的子串（不包含分隔符）
        result.push_back(str.substr(start, end - start));
        start = end + 1; // 更新起始位置为分隔符后一位
        end = str.find(delimiter, start); // 从新起始位置继续查找
    }

    // 添加最后一个子串（分隔符后到字符串结尾）
    result.push_back(str.substr(start));
    return result;
}

// 2.36,3,6,7.1,6;1,30,8.6,2.5,21;0.3,69,5.3,6.6,7.8;1,13,2,17,5;340,67,300.6;<=,>=,<=
int main() {
  double epsilon = std::numeric_limits<double>::epsilon();
  cout << "epsilon: " << epsilon << endl;


  string input;
  // cin >> input;
  input = "2.36,3,6,7.1,6;1,30,8.6,2.5,21;0.3,69,5.3,6.6,7.8;1,13,2,17,5;340,67,300.6;<=,>=,<=";

  const vector<string>& vecResult = split(input, ';');
  if(vecResult.empty()) return 0;

  string strOpt;
  string strDest;
  string strVar;

  int i = vecResult.size() - 1;
  strOpt = vecResult[i--];
  strDest = vecResult[i--];
  strVar = vecResult[i--];

  int end = i;
  vector<string> vecFactor_Str;
  for(int j = 0; j <= end ; j++) {
    vecFactor_Str.push_back(vecResult[j]);
  }

  const vector<string>& vecOpt_Str  = split(strOpt, ',');
  const vector<string>& vecDest_Str = split(strDest, ',');
  const vector<string>& vecVar_Str  = split(strVar, ',');
  
  if(!(vecFactor_Str.size() == vecOpt_Str.size() 
     && vecFactor_Str.size() == vecDest_Str.size())
    ) return 0;
  
  vector<vector<double>> vecFactor;
  for(const auto& factors : vecFactor_Str) {
    vector<double> tmp;
    const auto& vecFacs = split(factors, ',');
    for(const auto& fac : vecFacs) {
      tmp.push_back(atof(fac.c_str()));
    }
    vecFactor.push_back(tmp);
  }

  vector<double> vecDest;
  vector<int>    vecVar;

  for(const auto& dest : vecDest_Str) {
    vecDest.push_back(atof(dest.c_str()));
  }

  for(const auto& var : vecVar_Str) {
    vecVar.push_back(atoi(var.c_str()));
  }

  bool bEqual = true;
  int maxDiff = 0;

  for(int i = 0; i < vecFactor.size(); ++i) {
    double sum = 0;
    for(int j = 0; j < vecFactor[i].size(); ++j) {
      sum += vecFactor[i][j] * vecVar[j];
    }

    double dest = vecDest[i];
    string opt  = vecOpt_Str[i];
    if(opt == "=") {
      if(!(std::abs(sum - dest) < EPSILON)) bEqual = false;
    } else if(opt == ">") {
      if(!(sum > dest)) bEqual = false;
    } else if(opt == ">=") {
      if(!(sum > dest
        || std::abs(sum - dest) < EPSILON)
      ) bEqual = false;
    } else if(opt == "<") {
      if(!(sum < dest)) bEqual = false;
    } else if(opt == "<=") {
      if(!(sum < dest
        || std::abs(sum - dest) < EPSILON)
      ) bEqual = false;
    }

    if(int(std::abs(sum - dest)) > maxDiff )
      maxDiff = int(std::abs(sum - dest));
  }

  string strEqual;
  if(bEqual)
    strEqual = "true";
  else
    strEqual = "false";

  cout << strEqual << " " << maxDiff << endl;
}
// 64 位输出请用 printf("%lld")