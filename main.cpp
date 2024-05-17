#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для быстрой сортировки одного столбца (QuickSort)
void quickSortColumn(vector<int>& column, int left, int right) {
    // Реализация алгоритма QuickSort для сортировки одного столбца
    if (left < right) {
        int pivot = column[right]; // Выбираем опорный элемент из правого конца
        int i = left - 1;

        // Проход по столбцу, разделяя элементы по отношению к опорному элементу
        for (int j = left; j < right; j++) {
            if (column[j] <= pivot) {
                i++;
                swap(column[i], column[j]);
            }
        }

        swap(column[i + 1], column[right]); // Помещаем опорный элемент в правильную позицию
        int pivotIndex = i + 1;

        // Рекурсивный вызов для подмассивов слева и справа от опорного элемента
        quickSortColumn(column, left, pivotIndex - 1);
        quickSortColumn(column, pivotIndex + 1, right);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("array.txt");
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

    // Сортировка каждого столбца независимо от других
    for (int j = 0; j < n; j++) {
        vector<int> column(n);
        // Копирование столбца в отдельный вектор для сортировки
        for (int i = 0; i < n; i++) {
            column[i] = arr[i][j];
        }
        // Вызов функции сортировки для столбца
        quickSortColumn(column, 0, n - 1);
        // Обновление значений столбца в исходном двумерном векторе
        for (int i = 0; i < n; i++) {
            arr[i][j] = column[i];
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