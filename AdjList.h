#ifndef PROJECT2_ADJLIST_H
#define PROJECT2_ADJLIST_H
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class AdjacencyList{
private:
    map<string, double> rankMap;
    map<string, int> outdegreeMap;
    map<string, vector<string>> adjList;
public:
    void newEdge(string fromPage, string toPage){
        rankMap[toPage] = 0; //We don't determine the outdegree in this, but we make sure these are added to rankMap
        rankMap[fromPage] = 0;
        adjList[toPage].push_back(fromPage);
        adjList[fromPage];
        if(outdegreeMap.find(fromPage) != outdegreeMap.end()){//checks whether this point is in outdegreeMap
            outdegreeMap[fromPage]++;
        }
        else{
            outdegreeMap[fromPage] = 1;
        }
    }
    void pageRank(int n){
        for(auto & i : rankMap){//creates rankMap
            i.second = (double) 1 / rankMap.size();
        }
        for(int j = 1; j < n; j++){
            map<string, double> tempMap;
            for(auto &k : adjList){//goes thru keys
                double total = 0;
                for(string l : k.second){
                    total += (double)(rankMap[l] / outdegreeMap[l]);
                }
                tempMap[k.first] = total;
            }
            rankMap=tempMap; //updates rankMap
        }
        cout << fixed;
        for(auto &m : rankMap){//goes thru rankMap and outputs result
            cout << m.first << " " << setprecision(2);
            cout << m.second << endl;
        }
    }
};



#endif //PROJECT2_ADJLIST_H
