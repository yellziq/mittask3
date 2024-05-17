#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// ������� ��� ������� ���������� ������ ������� (QuickSort)
void quickSortColumn(vector<int>& column, int left, int right) {
    // ���������� ��������� QuickSort ��� ���������� ������ �������
    if (left < right) {
        int pivot = column[right]; // �������� ������� ������� �� ������� �����
        int i = left - 1;

        // ������ �� �������, �������� �������� �� ��������� � �������� ��������
        for (int j = left; j < right; j++) {
            if (column[j] <= pivot) {
                i++;
                swap(column[i], column[j]);
            }
        }

        swap(column[i + 1], column[right]); // �������� ������� ������� � ���������� �������
        int pivotIndex = i + 1;

        // ����������� ����� ��� ����������� ����� � ������ �� �������� ��������
        quickSortColumn(column, left, pivotIndex - 1);
        quickSortColumn(column, pivotIndex + 1, right);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("array.txt");
    ofstream outputFile("sorted_array.txt");

    if (!inputFile.is_open()) {
        cerr << "������ �������� �������� ����� array.txt" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    // ������ ������� ������ �� ����� � ��������� ������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> arr[i][j];
        }
    }

    inputFile.close();

    // ���������� ������� ������� ���������� �� ������
    for (int j = 0; j < n; j++) {
        vector<int> column(n);
        // ����������� ������� � ��������� ������ ��� ����������
        for (int i = 0; i < n; i++) {
            column[i] = arr[i][j];
        }
        // ����� ������� ���������� ��� �������
        quickSortColumn(column, 0, n - 1);
        // ���������� �������� ������� � �������� ��������� �������
        for (int i = 0; i < n; i++) {
            arr[i][j] = column[i];
        }
    }

    // ������ ���������������� ������� � ����
    if (!outputFile.is_open()) {
        cerr << "������ �������� ��������� ����� sorted_array.txt" << endl;
        return 1;
    }

    outputFile << n << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outputFile << arr[i][j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();

    cout << "��������������� ������ ������� ������� � ���� sorted_array.txt" << endl;

    return 0;
}