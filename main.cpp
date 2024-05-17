#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// ������� ��� ���������� ���-�����
void oddEvenSort(vector<int>& row, int n) {
    bool isSorted = false; // ���� ��� ������������ ���������� ����������
    while (!isSorted) {
        isSorted = true;
        for (int i = 1; i <= n - 2; i += 2) {
            if (row[i] > row[i + 1]) {
                swap(row[i], row[i + 1]);
                isSorted = false;
            }
        }
        for (int i = 0; i <= n - 2; i += 2) {
            if (row[i] > row[i + 1]) {
                swap(row[i], row[i + 1]);
                isSorted = false;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("input.txt");
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

    for (int k = 0; k < n; ++k) {
        vector<int> diagonal;
        for (int i = 0; i < n - k; ++i) {
            diagonal.push_back(arr[i][i + k]);
        }
        oddEvenSort(diagonal, diagonal.size()); // ���������� ��������� � ������� ���������� ���-�����
        for (int i = 0; i < n - k; ++i) {
            arr[i][i + k] = diagonal[i];
        }
    }

    for (int k = 1; k < n; ++k) {
        vector<int> diagonal;
        for (int i = 0; i < n - k; ++i) {
            diagonal.push_back(arr[i + k][i]);
        }
        oddEvenSort(diagonal, diagonal.size()); // ���������� ��������� � ������� ���������� ���-�����
        for (int i = 0; i < n - k; ++i) {
            arr[i + k][i] = diagonal[i];
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