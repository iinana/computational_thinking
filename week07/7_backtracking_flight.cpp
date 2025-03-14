// itinerary.cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

void dfs(const string& airport,
         unordered_map<string, multiset<string>>& flight_map,
         vector<string>& path);

vector<string> itinerary(vector<pair<string, string>>& flights, string& start) {
    unordered_map<string, multiset<string>> flight_map;
    for (auto& flight : flights) {
        if (flight_map.find(flight.first) == flight_map.end()) {
            flight_map[flight.first] = {flight.second};
        } else {
            flight_map[flight.first].insert(flight.second);
        }
        if (flight_map.find(flight.second) == flight_map.end())
            flight_map[flight.second] = {};
    }

    vector<string> path = {};
    dfs(start, flight_map, path);
    if (path.size() == flight_map.size()) return path;
    else return {};
}

void dfs(const string& airport,
         unordered_map<string, multiset<string>>& flight_map,
         vector<string>& path) {
    for (string p : path) {
        if (p.compare(airport) == 0) return;
    }

    path.push_back(airport);
    for (string s : flight_map[airport]) {
        dfs(s, flight_map, path);
    }
}

int main() {
    vector<pair<string, string>> flights = {
        {"SFO", "HKO"},
        {"YYZ", "SFO"},
        {"YUL", "YYZ"},
        {"HKO", "ORD"}
    };
    string start = "YUL";
    vector<string> result = itinerary(flights, start);
    if (!result.empty()) {
        for (const auto& airport : result) {
            cout << airport << " ";
        }
        cout << endl;  // Expected Output: YUL YYZ SFO HKO ORD
    } else {
        cout << "None" << endl;
    }

    flights = {
        {"SFO", "COM"},
        {"COM", "YYZ"}
    };
    start = "COM";
    result = itinerary(flights, start);
    if (!result.empty()) {
        for (const auto& airport : result) {
            cout << airport << " ";
        }
        cout << endl;  // Expected Output: None
    } else {
        cout << "None" << endl;
    }

    return 0;
}

