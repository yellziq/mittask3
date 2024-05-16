#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Employee {//создаем структоуру с данными
    string фамилия;
    string должность;
    string дата_рождения;
    int стаж_работы;
    int зарплата;
};

void quicksort(vector<Employee>& arr, int L, int R) {//алгоритм быстрой сортировки. опорный элемент- зарплата сотрудника
    int i = L;
    int j = R;
    int pivot = arr[(L + R) / 2].зарплата; // Выбираем опорный элемент

    while (i <= j) {
        while (arr[i].зарплата < pivot) {
            i++;
        }
        while (arr[j].зарплата > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (L < j) {
        quicksort(arr, L, j); // Сортируем левый подмассив
    }
    if (i < R) {
        quicksort(arr, i, R); // Сортируем правый подмассив
    }
}

int main() {
    ifstream input_file("данные_о_сотрудниках.txt");//открываем файлы ввода и вывода
    ofstream output_file("отсортированные_данные.txt");

    vector<Employee> employees;//информация добавляется в вектор структуры
    string line;

    while (getline(input_file, line)) {
        istringstream iss(line);
        Employee employee;
        getline(iss, employee.фамилия, ',');
        getline(iss, employee.должность, ',');
        getline(iss, employee.дата_рождения, ',');
        iss >> employee.стаж_работы;
        iss.ignore(); // Пропускаем запятую
        iss >> employee.зарплата;
        employees.push_back(employee);
    }

    quicksort(employees, 0, employees.size() - 1);//вызов функции

    for (const Employee& employee : employees) {
        output_file << employee.фамилия << ", " << employee.должность << ", " << employee.дата_рождения << ", " << employee.стаж_работы << ", " << employee.зарплата << "\n";
    }

    input_file.close();
    output_file.close();

    return 0;
}