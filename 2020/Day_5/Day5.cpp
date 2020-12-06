#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
const int rows = 128;
const int cols = 8;

struct Pass {
     int row, column, ID;
     Pass(int x, int y, int z) {
          row = x;
          column = y;
          ID = z;
     }
};

std::ostream& operator<<(ostream&, const Pass&);

bool compareID(const Pass &, const Pass &);
int myID(vector<Pass> );

int main() {
     ifstream passPorts;
     string str;
     vector<Pass> Passes;

     passPorts.open("Passes.txt");
     if (passPorts.is_open()) {
          while (getline(passPorts, str)) {
               int x = 0, y = rows-1, a, b;
               for (size_t i = 0; i < str.length() - 3; i++) {
                    if (str[i] == 'F') {
                         y = (y+x)/2;
                    }
                    else {
                         x += (y-x)/2 + 1;
                    }
               }
               a = x;
               x = 0; y = cols - 1;
               for (size_t i = str.length() - 3; i < str.length(); i++) {
                    if (str[i] == 'L') {
                         y = (y + x) / 2;
                    }
                    else {
                         x += (y - x) / 2 + 1;
                    }
               }
               b = (a * 8) + x;

               Passes.push_back(Pass(a, x, b));
          }
     }
     else {
          cout << "ERROR: File not found. Aborting!\n\n";
          return -1;
     }

     sort(Passes.begin(), Passes.end(), compareID);

     for (auto x : Passes) {
          cout << x;
     }

     cout << "Highest seat ID: " << max_element(Passes.begin(), Passes.end(), [](const Pass& a, const Pass& b) {return a.ID < b.ID; })->ID << endl;
     cout << "Your seat ID is: " << myID(Passes) <<endl;
     return 0;
}

std::ostream& operator<<(ostream& os, const Pass& pass) {
     os << "Boarding Pass ID: " << pass.ID << " ## Row: " << pass.row << " -- Column: " << pass.column << endl;
     return os;
}

bool compareID(const Pass &a, const Pass &b) {
     return a.ID < b.ID;
}

int myID(vector<Pass> passes) {
     for (size_t i = 0; i < passes.size() - 1; i++) {
          if (passes[i + 1].ID - 1 != passes[i].ID) {
               return passes[i].ID + 1;
          }
     }

     return 0;
}