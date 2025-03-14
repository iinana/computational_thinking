#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

vector<string> backtrack(unordered_map<string, vector<string>> nbrs, set<string> visited, vector<string>& path) {    
    for (string destination : nbrs[path.back()]) {
        if (visited.find(destination) == visited.end()) {
            path.push_back(destination);
            visited.insert(destination);
            path = backtrack(nbrs, visited, path);
            if (path.size() == nbrs.size()) return path;
        }
    }
    if (path.size() == nbrs.size()) return path;
    else return {};
}

vector<string> itinerary(vector<pair<string, string>> flights, string start) {
    unordered_map<string, vector<string>> nbrs;
    for (pair<string, string> f : flights) {
        if (nbrs.count(f.first) > 0) {
            nbrs[f.first].push_back(f.second);
        } else {
            nbrs[f.first] = {f.second};
        }
        if (nbrs.count(f.second) == 0) {
            nbrs[f.second] = {};
        }
    }

    vector<string> path = {start};
    return backtrack(nbrs, set<string>(), path);
}

int main() {
    // vector<pair<string, string>> flights = {
    //     {"SFO", "HKO"}, {"YYZ", "SFO"}, {"YUL", "YYZ"}, {"HKO", "ORD"}
    // };
    vector<pair<string, string>> flights = {{"SFO", "COM"}, {"COM", "YYZ"}};
    vector<string> res = itinerary(flights, "COM");
    for (string s : res) {
        cout << s << " ";
    }
}