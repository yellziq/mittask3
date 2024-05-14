#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    int n; // ���-�� ����� � ������������������
    cout << "n = ";
    cin >> n;
    deque<int> sequence; // ��� ��� �������� ������������� ��������

    int x;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> x;
        sequence.push_back(x); // ��������� ������� � ����� 
    }

    for (deque<int>::iterator iter = sequence.begin(); iter != sequence.end(); iter++) {
        cout << *iter << " "; // ����� ������������������
    }
    cout << endl;



    deque<int> replacedSequence(sequence); // �������� ����� �������� ������������������ (������ �����������)

    // ���������� ������� ������� � ���������� ��������� �����
    auto firstEven = find_if(replacedSequence.begin(), replacedSequence.end(), [](int x) { return x % 2 == 0; });
    auto lastOdd = find_if(replacedSequence.rbegin(), replacedSequence.rend(), [](int x) { return x % 2 != 0; }).base();

    // ������ ����� � ��������� �� ������� ������� �� ���������� ��������� ����������� ������
    auto minNumber = *min_element(firstEven, lastOdd);
    for_each(firstEven, lastOdd, [minNumber](int& x) { x = minNumber; });

    deque<int> rotatedSequence(sequence); // �������� ����� �������� ������������������

    // ���������� ������������� ��������
    auto maxElement = max_element(rotatedSequence.begin(), rotatedSequence.end());

    // ����������� ����� ���, ����� �� ������ ����� ����� ������������ �������
    rotate(rotatedSequence.begin(), maxElement, rotatedSequence.end());

    deque<int> sortedUniqueSequence(sequence); // �������� ����� �������� ������������������

    // �������� ������������� ��������� � ����������
    sort(sortedUniqueSequence.begin(), sortedUniqueSequence.end());
    sortedUniqueSequence.erase(unique(sortedUniqueSequence.begin(), sortedUniqueSequence.end()), sortedUniqueSequence.end());

    // ����� �����������
    cout << "������������������, ��� �������� ��� ����� � ��������� �� ������� ������� �� ���������� ��������� ����������� ������: ";
    for (int x : replacedSequence) {
        cout << x << " ";
    }
    cout << endl;

    cout << "������������������, ��� ����� �������� ����������� ����� ���, ����� �� ������ ����� ����� ������������ �������: ";
    for (int x : rotatedSequence) {
        cout << x << " ";
    }
    cout << endl;

    cout << "��������������� ������������������, ��� �������  ������������� ��������: ";
    for (int x : sortedUniqueSequence) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}


