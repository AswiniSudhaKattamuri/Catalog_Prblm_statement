#include <bits/stdc++.h>
#include "json.hpp"  

using namespace std;
using json = nlohmann::json;


long long decodeValue(const string &value, int base) {
    long long result = 0;
    for (char ch : value) {
        int digit;
        if (isdigit(ch)) digit = ch - '0';
        else if (isalpha(ch)) digit = tolower(ch) - 'a' + 10;
        else throw runtime_error("Invalid digit in base representation");
        if (digit >= base) throw runtime_error("Digit out of range for base");
        result = result * base + digit;
    }
    return result;
}


vector<long double> gaussSolve(vector<vector<long double>> A, vector<long double> b) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        
        int pivot = i;
        for (int r = i; r < n; r++) {
            if (fabsl(A[r][i]) > fabsl(A[pivot][i])) pivot = r;
        }
        swap(A[i], A[pivot]);
        swap(b[i], b[pivot]);

        long double div = A[i][i];
        for (int c = 0; c < n; c++) A[i][c] /= div;
        b[i] /= div;

        for (int r = 0; r < n; r++) {
            if (r != i) {
                long double factor = A[r][i];
                for (int c = 0; c < n; c++) {
                    A[r][c] -= factor * A[i][c];
                }
                b[r] -= factor * b[i];
            }
        }
    }
    return b;
}

int main() {
   
    ifstream inFile("input.json");
    if (!inFile) {
        cerr << "Error: Could not open input.json\n";
        return 1;
    }

    json j;
    inFile >> j;

    int n = j["keys"]["n"];
    int k = j["keys"]["k"];
    int m = k - 1; 

  
    vector<pair<long long, long long>> points;
    for (auto &el : j.items()) {
        if (el.key() == "keys") continue;
        long long x = stoll(el.key());
        string baseStr = el.value()["base"];
        string valStr = el.value()["value"];
        long long y = decodeValue(valStr, stoi(baseStr));
        points.push_back({x, y});
    }

 
    sort(points.begin(), points.end());

  
    vector<pair<long long, long long>> sel(points.begin(), points.begin() + k);

    vector<vector<long double>> A(k, vector<long double>(k));
    vector<long double> b(k);
    for (int i = 0; i < k; i++) {
        long long xi = sel[i].first;
        long long yi = sel[i].second;
        for (int p = 0; p < k; p++) {
            A[i][p] = pow((long double)xi, m - p);
        }
        b[i] = yi;
    }

    // Solve for coefficients
    vector<long double> coeffs = gaussSolve(A, b);

    // Constant term is last coefficient
    cout << fixed << setprecision(0);
    cout << coeffs.back() << "\n";

    return 0;
}
