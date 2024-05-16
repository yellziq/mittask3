#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Employee {//������� ���������� � �������
    string �������;
    string ���������;
    string ����_��������;
    int ����_������;
    int ��������;
};

void quicksort(vector<Employee>& arr, int L, int R) {//�������� ������� ����������. ������� �������- �������� ����������
    int i = L;
    int j = R;
    int pivot = arr[(L + R) / 2].��������; // �������� ������� �������

    while (i <= j) {
        while (arr[i].�������� < pivot) {
            i++;
        }
        while (arr[j].�������� > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (L < j) {
        quicksort(arr, L, j); // ��������� ����� ���������
    }
    if (i < R) {
        quicksort(arr, i, R); // ��������� ������ ���������
    }
}

int main() {
    ifstream input_file("������_�_�����������.txt");//��������� ����� ����� � ������
    ofstream output_file("���������������_������.txt");

    vector<Employee> employees;//���������� ����������� � ������ ���������
    string line;

    while (getline(input_file, line)) {
        istringstream iss(line);
        Employee employee;
        getline(iss, employee.�������, ',');
        getline(iss, employee.���������, ',');
        getline(iss, employee.����_��������, ',');
        iss >> employee.����_������;
        iss.ignore(); // ���������� �������
        iss >> employee.��������;
        employees.push_back(employee);
    }

    quicksort(employees, 0, employees.size() - 1);//����� �������

    for (const Employee& employee : employees) {
        output_file << employee.������� << ", " << employee.��������� << ", " << employee.����_�������� << ", " << employee.����_������ << ", " << employee.�������� << "\n";
    }

    input_file.close();
    output_file.close();

    return 0;
}