#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    ifstream file("210-final-1-FA25.txt");
    string start_airport;
    string end_airport;
    string flight;
    map<string, int> airports;
    // Milestone 1
    while(getline(file, flight)) {
        int start = 1;
        start_airport = "";
        end_airport = "";
        for(char c: flight) {
            if (c == ' ') {
                start = 0;
                continue;
            }
            if (start == 1) {
                start_airport += c;
            }
            else {
                end_airport += c;
            }
        }
        if (airports.find(start_airport) != airports.end()) {
            for (auto it = airports.begin(); it != airports.end(); it++) {
                if (it->first == start_airport) {
                    it->second += 1;
                    break;
                }
            }
        }
        else {
            airports.insert(make_pair(start_airport, 1));
        }
        if (airports.find(end_airport) != airports.end()) {
            for (auto it = airports.begin(); it != airports.end(); it++) {
                if (it->first == end_airport) {
                    it->second += 1;
                    break;
                }
            }
        }
        else {
            airports.insert(make_pair(end_airport, 1));
        }
    }
    cout << "List of airports and usage: " << endl;
    for(const auto& pair : airports) {
        cout << "  " << pair.first << "  " << pair.second << endl;
    }
}