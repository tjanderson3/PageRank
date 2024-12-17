#include <sstream>
#include "AdjList.h"
using namespace std;

int main() {
    //used the basic skeleton
    int numLines, p;
    cin >> numLines;
    cin >> p;
    AdjacencyList T;
    string line;
    string from;
    string to;
    getline(cin, line); //Had an issue with input, used this to skip the first line
    for(int i = 0; i < numLines; i++)
    {
        getline(cin, line);
        istringstream input(line);
        input >> from;
        input >> to;
        T.newEdge(from, to); // adds edges for each line
    }
    T.pageRank(p);
    return 0;
}
