//#include <iostream>
//#include <list>
//#include <algorithm>
//#include <functional>
//#include <iterator>
//#include <set>
//#include <fstream>
//#include <numeric>
//#include <vector>
//
//using namespace std;
////bool even(int x) {
//// return x % 2 == 0;
////}
//
//int main() {
//	setlocale(LC_ALL, "Ru");
//	set<int> two, rest; // для хранения только двухзнач / остальных цифр
//	int n = 3, x;
//	// считывание 10 чисел
//	for (int i = 0; i < n; ++i) {
//		cin >> x;
//
//		if (x > 9 && x < 100) { // если двухзнач
//			while (x > 0) {
//				two.insert(x % 10); // запоминаем каждую цифру
//				x /= 10;
//			}
//		}
//		else {
//			while (x > 0) {
//				rest.insert(x % 10);
//				x /= 10;
//			}
//		}
//	}
//	// вывод цифр только в двузнач
//	cout << "двузначные: ";
//	for (auto it = two.begin(); it != two.end(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	// вывод остальных цифр
//	cout << "Остальные : ";
//	for (auto it = rest.begin(); it != rest.end(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	// поиск и вывод цифр только в трехзнач
//	vector<int> v(two.size() + rest.size(), -1);
//	set_difference(two.begin(), two.end(), rest.begin(), rest.end(), v.begin());
//	v.erase(find(v.begin(), v.end(), -1), v.end());
//
//	cout << "Толко в двузначных: ";
//	for (auto it = v.begin(); it != v.end(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}