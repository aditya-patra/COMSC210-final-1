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
    while(getline(file, flight)) {
        int start = 1;
        start_airport = "";
        end_airport = "";
        for(char c: flight) {
            if (c == ' ') {
                start = 0;
            }
            if (start == 1) {
                start_airport += c;
            }
            else {
                end_airport += c;
            }
        }
        cout << end_airport << endl;
    }
}