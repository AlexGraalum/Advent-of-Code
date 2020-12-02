#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool validateP1(int, int, char, string);
bool validateP2(int, int, char, string);

int main() {
     ifstream reportFile;
     int countP1 = 0, countP2 = 0;
     string temp;

     reportFile.open("Passwords.txt");
     if (reportFile.is_open()) {
          while (getline(reportFile, temp)) {
               int lo = stoi(temp.substr(0, temp.find("-")));
               int hi = stoi(temp.substr(temp.find("-") + 1, temp.find(" ")));
               char x = temp.at(temp.find(" ") + 1);
               string pass = temp.substr(temp.find(":") + 2, temp.length());

               if (validateP1(lo, hi, x, pass))
                    countP1++;
               if (validateP2(lo - 1, hi - 1, x, pass))
                    countP2++;
          }
     }
     else {
          cout << "ERROR: File not found. Aborting!\n\n";
          return -1;
     }
     reportFile.close();

     cout << "Puzzle 1 - Valid password count: " << countP1 << endl;
     cout << "Puzzle 2 - Valid password count: " << countP2 << endl;
     return 0;
}

bool validateP1(int lo, int hi, char x, string pass) {
     int y = count(pass.begin(), pass.end(), x);

     if (y >= lo && y <= hi) {
          return 1;
     }
     return 0;
}

bool validateP2(int lo, int hi, char x, string pass) {
     if ((pass.at(lo) == x) && (pass.at(hi) != x)) {
          return 1;
     }else if ((pass.at(lo) != x) && (pass.at(hi) == x)) {
          return 1;
     }
     return 0;
}