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
//	set<int> two, rest; // ��� �������� ������ �������� / ��������� ����
//	int n = 3, x;
//	// ���������� 10 �����
//	for (int i = 0; i < n; ++i) {
//		cin >> x;
//
//		if (x > 9 && x < 100) { // ���� ��������
//			while (x > 0) {
//				two.insert(x % 10); // ���������� ������ �����
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
//	// ����� ���� ������ � �������
//	cout << "����������: ";
//	for (auto it = two.begin(); it != two.end(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	// ����� ��������� ����
//	cout << "��������� : ";
//	for (auto it = rest.begin(); it != rest.end(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	// ����� � ����� ���� ������ � ��������
//	vector<int> v(two.size() + rest.size(), -1);
//	set_difference(two.begin(), two.end(), rest.begin(), rest.end(), v.begin());
//	v.erase(find(v.begin(), v.end(), -1), v.end());
//
//	cout << "����� � ����������: ";
//	for (auto it = v.begin(); it != v.end(); ++it)
//		cout << *it << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}