#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct Employee {
    string surname;
    string position;
    string birthDate;
    int experience;
    int salary;
};

void oddEvenSort(vector<Employee>& arr, string key) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (size_t i = 0; i < arr.size() - 1; i += 2) {
            if (arr[i].surname > arr[i + 1].surname ||
                (arr[i].surname == arr[i + 1].surname && arr[i].experience > arr[i + 1].experience) ||
                (arr[i].surname == arr[i + 1].surname && arr[i].experience == arr[i + 1].experience && arr[i].salary > arr[i + 1].salary)) {
                std::swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
        for (size_t i = 1; i < arr.size() - 1; i += 2) {
            if (arr[i].surname > arr[i + 1].surname ||
                (arr[i].surname == arr[i + 1].surname && arr[i].experience > arr[i + 1].experience) ||
                (arr[i].surname == arr[i + 1].surname && arr[i].experience == arr[i + 1].experience && arr[i].salary > arr[i + 1].salary)) {
                std::swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
    }
}

int main() {
    vector<Employee> employees;
    ifstream inputFile("данные_о_сотрудниках.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            stringstream ss(line);
            Employee emp;
            getline(ss, emp.surname, ',');
            getline(ss, emp.position, ',');
            getline(ss, emp.birthDate, ',');
            ss >> emp.experience;
            ss.ignore(1);  // Ignore the comma
            ss >> emp.salary;
            employees.push_back(emp);
        }
        inputFile.close();
    }
    else {
        cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }

    oddEvenSort(employees, "surname");

    ofstream outputFile("sorted_employees.txt");
    if (outputFile.is_open()) {
        for (const auto& emp : employees) {
            outputFile << emp.surname << ',' << emp.position << ',' << emp.birthDate << ',' << emp.experience << ',' << emp.salary << '\n';
        }
        outputFile.close();
    }
    else {
        cerr << "Error: Unable to open output file." << std::endl;
        return 1;
    }

    return 0;
}