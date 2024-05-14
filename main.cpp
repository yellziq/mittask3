#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <locale> // �������� ��������� ��� setlocale
using namespace std;



int main() {
    setlocale(LC_ALL, "russian");
    int n;//���-�� ����� � ������
    cout << "n = ";
    cin >> n;
    vector<int> vec;//������ ��� �������� ������������� �������� 

    int x;
    for (int i = 0; i < n; i++) {//���������� ������� 
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);//��������� ������� � ����� ������� 
    }

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {//��������� � ��������, �� ������� ��������� �������� : *iter.
        cout << *iter << " ";//����� �������
    }
    cout << endl;



    cout << "������ ����������� ����� �����:\n";
    int Min = *min_element(vec.begin(), vec.end());//������� ����������� ��
    replace(vec.begin(), vec.end(), Min, 0);//�������� ����� 

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {//������� 
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}


