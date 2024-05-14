#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    int n; // кол-во чисел в последовательности
    cout << "n = ";
    cin >> n;
    deque<int> sequence; // дек дл€ хранени€ целочисленных значений

    int x;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> x;
        sequence.push_back(x); // добавл€ет элемент в конец 
    }

    for (deque<int>::iterator iter = sequence.begin(); iter != sequence.end(); iter++) {
        cout << *iter << " "; // вывод последовательности
    }
    cout << endl;



    deque<int> replacedSequence(sequence); // —оздание копии исходной последовательности (полна€ независима€)

    // Ќахождение первого четного и последнего нечетного чисел
    auto firstEven = find_if(replacedSequence.begin(), replacedSequence.end(), [](int x) { return x % 2 == 0; });
    auto lastOdd = find_if(replacedSequence.rbegin(), replacedSequence.rend(), [](int x) { return x % 2 != 0; }).base();

    // «амена чисел в диапазоне от первого четного до последнего нечетного минимальным числом
    auto minNumber = *min_element(firstEven, lastOdd);
    for_each(firstEven, lastOdd, [minNumber](int& x) { x = minNumber; });

    deque<int> rotatedSequence(sequence); // —оздание копии исходной последовательности

    // Ќахождение максимального элемента
    auto maxElement = max_element(rotatedSequence.begin(), rotatedSequence.end());

    // ÷иклический сдвиг так, чтобы на первом месте сто€л максимальный элемент
    rotate(rotatedSequence.begin(), maxElement, rotatedSequence.end());

    deque<int> sortedUniqueSequence(sequence); // —оздание копии исходной последовательности

    // ”даление повтор€ющихс€ элементов и сортировка
    sort(sortedUniqueSequence.begin(), sortedUniqueSequence.end());
    sortedUniqueSequence.erase(unique(sortedUniqueSequence.begin(), sortedUniqueSequence.end()), sortedUniqueSequence.end());

    // ¬ывод результатов
    cout << "ѕоследовательность, где заменены все числа в диапазоне от первого четного до последнего нечетного минимальным числом: ";
    for (int x : replacedSequence) {
        cout << x << " ";
    }
    cout << endl;

    cout << "ѕоследовательность, где будет применен циклический сдвиг так, чтобы на первом месте сто€л максимальный элемент: ";
    for (int x : rotatedSequence) {
        cout << x << " ";
    }
    cout << endl;

    cout << "ќтсортированна€ последовательность, где удалены  повтор€ющиес€ элементы: ";
    for (int x : sortedUniqueSequence) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}


