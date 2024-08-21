#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <fstream>
using namespace std;

int chooseFlask(int requirements_count, vector<int>& requirements, int flaskTypes, int markings_rows, vector<vector<int>>& markings) {
    unordered_map<int, vector<int>> flask_markings;

    for (const auto& marking : markings) {
        int flask_type = marking[0];
        int marking_value = marking[1];
        flask_markings[flask_type].push_back(marking_value);
    }

    int min_waste = INT_MAX;
    int best_flask = -1;

    for (int flask_type = 0; flask_type < flaskTypes; ++flask_type) {
        if (flask_markings.find(flask_type) == flask_markings.end()) continue;

        int waste = 0;
        bool valid = true;

        sort(flask_markings[flask_type].begin(), flask_markings[flask_type].end());

        for (int req : requirements) {
            auto it = lower_bound(flask_markings[flask_type].begin(), flask_markings[flask_type].end(), req);

            if (it == flask_markings[flask_type].end()) {
                valid = false;
                break;
            } else {
                waste += (*it - req);
            }
        }

        if (valid && waste < min_waste) {
            min_waste = waste;
            best_flask = flask_type;
        }
    }

    return best_flask;
}

int main() {
    ifstream infile(getenv("INPUT_PATH"));
    ofstream outfile(getenv("OUTPUT_PATH"));

    int requirements_count;
    infile >> requirements_count;

    vector<int> requirements(requirements_count);
    for (int& req : requirements) {
        infile >> req;
    }

    int flaskTypes;
    infile >> flaskTypes;

    int markings_rows;
    infile >> markings_rows;

    vector<vector<int>> markings(markings_rows, vector<int>(2));
    for (auto& marking : markings) {
        infile >> marking[0] >> marking[1];
    }

    int result = chooseFlask(requirements_count, requirements, flaskTypes, markings_rows, markings);
    outfile << result << endl;

    return 0;
}
