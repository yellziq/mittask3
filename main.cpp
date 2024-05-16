#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
struct Employee {
    string surname;
    string position;
    string birthDate;
    int experience;
    int salary;
};

void merge(vector<Employee>& arr, vector<Employee>& left, vector<Employee>& right, string key1, string key2) {
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i].salary < right[j].salary || (left[i].salary == right[j].salary && left[i].birthDate < right[j].birthDate)) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }
    while (i < left.size()) {
        arr[k++] = left[i++];
    }
    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}

void mergeSort(vector<Employee>& arr, string key1, string key2) {
    if (arr.size() <= 1) {
        return;
    }
    size_t mid = arr.size() / 2;
    vector<Employee> left(arr.begin(), arr.begin() + mid);
    vector<Employee> right(arr.begin() + mid, arr.end());
    mergeSort(left, key1, key2);
    mergeSort(right, key1, key2);
    merge(arr, left, right, key1, key2);
}

int main() {
    vector<Employee> employees;
    ifstream inputFile("employees.txt");
    if (inputFile.is_open()) {
        std::string line;
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

    mergeSort(employees, "salary", "birthDate");

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