#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для сортировки слиянием
void merge(vector<int>& row, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = row[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = row[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            row[k] = L[i];
            i++;
        }
        else {
            row[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        row[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        row[k] = R[j];
        j++;
        k++;
    }
}

// Функция для сортировки слиянием
void mergeSort(vector<int>& row, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(row, left, mid);
        mergeSort(row, mid + 1, right);
        merge(row, left, mid, right);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("input.txt");
    ofstream outputFile("sorted_array.txt");

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия входного файла array.txt" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    // Чтение входных данных из файла в двумерный вектор
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> arr[i][j];
        }
    }

    inputFile.close();

    for (int i = 3; i < n; i += 3) {
        // Сортировка каждой третьей строки по убыванию
        sort(arr[i].rbegin(), arr[i].rend());
    }

    for (int i = 0; i < n; i++) {
        if (i % 3 != 0) {
            // Сортировка остальных строк с использованием сортировки слиянием
            mergeSort(arr[i], 0, n - 1);
        }
    }

    // Запись отсортированного массива в файл
    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия выходного файла sorted_array.txt" << endl;
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

    cout << "Отсортированный массив успешно записан в файл sorted_array.txt" << endl;

    return 0;
}