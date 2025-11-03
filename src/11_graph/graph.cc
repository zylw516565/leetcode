#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

//*******V1 */
class Graph
{
private:
    int count_;  //顶点个数
    vector<list<int>> adjList_;

    //for dfs
    bool found_ = false;

public:
    Graph(const int count)
    :count_(count)
    {
        adjList_.resize(count_);
    }

    ~Graph() = default;

    void addEdge(const int i, const int j)
    {
        adjList_[i].push_back(j);
        adjList_[j].push_back(i);
    }

    void bfs(const int start, const int target)
    {
        if (start == target) return;

        vector<bool> vecVisited;
        vecVisited.resize(count_);
        vecVisited[start] = true;

        queue<int> queQueue;
        queQueue.push(start);

        vector<int> vecPrev;
        vecPrev.resize(count_);
        for (auto& elment : vecPrev) {
            elment = -1;
        }

        while (!queQueue.empty()) {
            int w = queQueue.front(); queQueue.pop();

            for (const auto& elment : adjList_[w]) {
                if (!vecVisited[elment]) {
                    vecPrev[elment] = w;

                    if (elment == target) {
                        print(vecPrev, start, target); cout << endl;
                        return;
                    }

                    vecVisited[elment] = true;
                    queQueue.push(elment);
                }
            }
        }
    }

    void dfs(const int start, const int target)
    {
        if (start == target) return;

        vector<bool> vecVisited;
        vecVisited.resize(count_);
        vecVisited[start] = true;

        vector<int> vecPrev;
        vecPrev.resize(count_);
        for (auto& elment : vecPrev) {
            elment = -1;
        }

        recurDFS(vecVisited, vecPrev, start, target);
        print(vecPrev, start, target); cout << endl;
    }

private:

    void recurDFS(vector<bool>& vecVisited, vector<int>& vecPrev, const int start, const int target)
    {
        if (found_) return;

        vecVisited[start] = true;
        if (start == target){
            found_ = true;
            return;
        }

        for (const auto& elment : adjList_[start]) {
            if (!vecVisited[elment]) {
                vecPrev[elment] = start;
                recurDFS(vecVisited, vecPrev, elment, target);
            }
        }
    }

    void print(const vector<int>& p_vecPrev, const int start, int target)
    {
        if (p_vecPrev[target] != -1 && start != target) {
            print(p_vecPrev, start, p_vecPrev[target]);
        }

        cout << target << " ";
    }
};


//*******V2 */

// class Graph
// {
// private:
//   int count_;  //顶点个数
//   vector<list<int>> adjList_;

//   //for dfs
//   bool found_ = false;

// public:
//   Graph(const int count)
//   :count_(count)
//   {
//     adjList_.resize(count_);
//   }

//   ~Graph() = default;

//   void addEdge(const int i, const int j)
//   {
//     if(i != j) {
//       adjList_[i].push_back(j);
//       adjList_[j].push_back(i);
//     }
//   }

//   void bfs(const int start, const int target)
//   {
//     if(start == target) return;

//     vector<bool> vecVisited(count_, false);
//     vecVisited[start] = true;

//     queue<int> vertexQueue;
//     vertexQueue.push(start);

//     vector<int> vecPrev(count_, -1);

//     while(!vertexQueue.empty()) {
//       int w = vertexQueue.front(); vertexQueue.pop();
//       for(const auto& vertex : adjList_[w]) {
//         if(!vecVisited[vertex]) {
//           vecPrev[vertex] = w;
          
//           if(vertex == target) {
//             print(vecPrev, start, target); cout << endl;
//             return;
//           }

//           vecVisited[vertex] = true;
//           vertexQueue.push(vertex);
//         }
//       }
//     }
//   }

//   void dfs(const int start, const int target)
//   {
//     if(start == target) return;

//     vector<bool> vecVisited(count_, false);
//     vecVisited[start] = true;

//     vector<int> vecPrev(count_, -1);

//     recurDFS(vecVisited, vecPrev, start, target);
//     print(vecPrev, start, target); cout << endl;
//   }

// private:

//   void recurDFS(vector<bool>& vecVisited, vector<int>& vecPrev, const int start, const int target)
//   {
//     if(found_) return;
    
//     vecVisited[start] = true;
//     if(start == target) {
//       found_ = true;
//       return;
//     }

//     for(const auto& vertex : adjList_[start]) {
//       if(!vecVisited[vertex]) {
//         vecPrev[vertex] = start;
//         recurDFS(vecVisited, vecPrev, vertex, target);
//       }
//     }
//   }

//   void print(const vector<int>& p_vecPrev, const int start, int target)
//   {
//     if (p_vecPrev[target] != -1 && start != target) {
//         print(p_vecPrev, start, p_vecPrev[target]);
//     }

//     cout << target << " ";
//   }
// };





int main()
{
  Graph objGraph(8);
	objGraph.addEdge(0, 1);
	objGraph.addEdge(0, 3);
	objGraph.addEdge(1, 2);
	objGraph.addEdge(1, 4);
	objGraph.addEdge(3, 4);
	objGraph.addEdge(2, 5);
	objGraph.addEdge(4, 5);
	objGraph.addEdge(4, 6);
	objGraph.addEdge(5, 7);
	objGraph.addEdge(6, 7);
	//广度优先
	objGraph.bfs(0, 6);

	Graph objGraphV2(9);
	objGraphV2.addEdge(1, 2);
	objGraphV2.addEdge(1, 4);
	objGraphV2.addEdge(2, 3);
	objGraphV2.addEdge(2, 5);
	objGraphV2.addEdge(3, 6);
	objGraphV2.addEdge(4, 5);
	objGraphV2.addEdge(5, 6);
	objGraphV2.addEdge(5, 7);
	objGraphV2.addEdge(6, 8);
	objGraphV2.addEdge(7, 8);
	//深度优先
	objGraphV2.dfs(1, 7);

  getchar();
}