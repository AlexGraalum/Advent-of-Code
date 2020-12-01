#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void solution(int, int);

int main() {
     ifstream reportFile;
     vector<int> report;
     int temp;

     reportFile.open("Expense_Report.txt");
     if (reportFile.is_open()) {
          while (reportFile >> temp) {
               report.push_back(temp);
          }
     }
     else {
          cout << "ERROR: File not found. Aborting!\n\n";
          return -1;
     }
     reportFile.close();
     for (size_t i = 0; i < report.size()-1; i++) {
          for (size_t j = 1; j < report.size(); j++) {
               temp = report[i] + report[j];
               switch (temp) {
                    case 2020:
                         solution(report[i], report[j]);
                         return 0;
                    default:
                         cout << report[i] << " + " << report[j] << " != 2020\n";
                         break;
               }
          }
     }

     return 0;
}

void solution(int x, int y) {
     int product = x * y;
     cout << x << " + " << y << " = 2020\n";
     cout << x << " * " << y << " = " << product << endl;
}