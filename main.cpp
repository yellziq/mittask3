#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <locale> // ƒобавлен заголовок дл€ setlocale
using namespace std;



int main() {
    setlocale(LC_ALL, "russian");
    int n;//кол-во чисел в строке
    cout << "n = ";
    cin >> n;
    vector<int> vec;//вектор дл€ хранени€ целочисленных значений 

    int x;
    for (int i = 0; i < n; i++) {//заполнение вектора 
        cout << "a[" << i << "] = ";
        cin >> x;
        vec.push_back(x);//добавл€ет элемент в конец вектора 
    }

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {//ќбращение к элементу, на который указывает итератор : *iter.
        cout << *iter << " ";//вывод вектора
    }
    cout << endl;



    cout << "«амена минимальных чисел нулем:\n";
    int Min = *min_element(vec.begin(), vec.end());//находим минимальный эл
    replace(vec.begin(), vec.end(), Min, 0);//замен€ем нулем 

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {//выводим 
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}


