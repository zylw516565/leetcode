#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

/*
4 4
2 1 0 3
0 1 2 1
0 3 0 0
0 0 0 0

*/

class Graph {
private:
  vector<list<int>> adjList_;
  int length_;
  int height_;

public:
  Graph(int length, int height) {
    length_ = length;
    height_ = height;
    adjList_.resize(length * height);
  }

  void addAllEdge() {
    for(int j = 0; j < height_; j++) {
      for (int i = 0; i < length_; i++) {
        if(i > 0) {
          addEdge(i - 1 + j * height_, i + j * height_);
        }
      }
    }

    for (int i = 0; i < length_; i++) {
      for(int j = 0; j < height_; j++) {
        if(j > 0) {
          addEdge((j - 1)*length_ + i, j*length_ + i);
        }
      }
    }
  }

  void addEdge(int i, int j) {
    adjList_[i].push_back(j);
    adjList_[j].push_back(i);
  }

  int bfs(const vector<vector<int>>& diningMap, int start, const int target) {
    int reach_count = 0;

    vector<bool> visited(adjList_.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
      auto current = q.front();
      q.pop();

      if(diningMap[current / height_][current % length_] == target) {
          reach_count++;
        }

      for(const auto& neighbor : adjList_[current]) {        
        if(diningMap[neighbor / height_][neighbor % length_]  == 1) {
          continue;
        }

        if(!visited[neighbor]) {
          visited[neighbor] = true;
          q.push(neighbor);
        }
      }
    }

    return reach_count;
  }


};


int main() {

  vector<vector<int>> diningMap;
  vector<int> start_list;

  int length, height;
  while (cin >> length >> height) { // 注意 while 处理多个 case
    for (int y = 0; y < height; y++) {
      vector<int> vecTemp;
      for (int x = 0; x < length; x++) {
          int val;
          scanf("%d", &val);
          vecTemp.push_back(val);
          if(val == 2) {
            start_list.push_back(x + y * length);
          }
      }
      diningMap.push_back(vecTemp);
    }

    Graph objGraph(length, height);
    objGraph.addAllEdge();

    vector<int> result_list;
    for (const auto &start : start_list) {
      result_list.push_back(objGraph.bfs(diningMap, start, 3));
    }
    
    cout << *std::min_element(result_list.begin(), result_list.end()) << endl;
  }

  return 0;
}