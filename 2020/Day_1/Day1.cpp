#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int solutionP1(vector<int> );
int solutionP2(vector<int> );

int main() {
     ifstream reportFile;
     vector<int> report;
     int temp, solution1 = 0, solution2 = 0;

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

     solution1 = solutionP1(report);
     if (solution1 != 0) {
          cout << "Puzzle 1 completed successfully with result: " << solution1 << endl;
     }
     else {
          cout << "Puzzle 1 did not complete successfully.\n";
     }
     
     solution2 = solutionP2(report);
     if (solution2 != 0) {
          cout << "Puzzle 2 completed successfully with result: " << solution2 << endl;
     }
     else {
          cout << "Puzzle 2 did not complete successfully.\n";
     }

     return 0;
}

int solutionP1(vector<int> report) {
     int temp;
     for (size_t i = 0; i < report.size() - 1; i++) {
          for (size_t j = i + 1; j < report.size(); j++) {
               temp = report[i] + report[j];
               switch (temp) {
               case 2020:
                    temp = report[i] * report[j];
                    cout << report[i] << " + " << report[j] << " = 2020\n";
                    cout << report[i] << " * " << report[j] << " = " << temp << endl;
                    return temp;
               default:
                    //cout << report[i] << " + " << report[j] << " != 2020\n";
                    break;
               }
          }
     }
     return 0;
}

int solutionP2(vector<int> report) {
     int temp;
     for (size_t i = 0; i < report.size() - 2; i++) {
          for (size_t j = i+1; j < report.size() - 1; j++) {
               for (size_t k = j + 1; k < report.size(); k++) {
                    temp = report[i] + report[j] + report[k];
                    switch (temp) {
                         case 2020:
                              temp = report[i] * report[j] * report[k];
                              cout << report[i] << " + " << report[j] << " + " << report[k] << " = 2020\n";
                              cout << report[i] << " * " << report[j] << " * " << report[k] << " = " << temp << endl;
                              return temp;
                         default:
                              //cout << report[i] << " + " << report[j] << " + " << report[k] << " != 2020\n";
                              break;
                    }
               }
          }
     }
     return 0;
}