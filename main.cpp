//#include <iostream>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <iterator>
//#include <string>
//using namespace std;
//
//string str_tolower(string s)
////Функция преобразует строку s в нижний регистр
//{
//    for (int i = 0; i < s.length(); i++)
//        s[i] = tolower(s[i]);
//    return s;
//}
//
//set <string> set_word(string s)
////Функция извлекает множество из предложения s
//{
//    set <string> set_s;
//    if (s.empty()) {
//        return set_s;
//    }
//    if (s[s.length() - 1] != ' ')
//        s += " ";
//    while (s != "") {
//        set_s.insert(str_tolower(s.substr(0, s.find(' '))));//добавл значения
//        s.erase(0, s.find(' ') + 1);
//    }
//    return set_s;
//}
//
//int main() {
//    setlocale(LC_ALL, "RU");
//    string s, pr;
//    cout << "Введите текст\n";
//    getline(cin, s);
//    set <string> res, pov, voskl, vopr, s0;
//    //Будем составлять множеста pov, voskl, vopr из извлеченных
//    //повествовательных, восклицательных и вопросительных предложений соответственно
//    while (s != "") {
//        int pos = s.find_first_of(".!?");
//        pr = s.substr(0, pos);
//        s0 = set_word(pr);
//        if (s[pos] == '.') pov.insert(s0.begin(), s0.end());
//        if (s[pos] == '!') voskl.insert(s0.begin(), s0.end());
//        if (s[pos] == '?') vopr.insert(s0.begin(), s0.end());
//        s.erase(0, pos + 1);
//    }
//    // Находим объединение voskl и vopr
//    set <string> set_vopr_voskl;
//    set_vopr_voskl.insert(voskl.begin(), voskl.end());
//    set_vopr_voskl.insert(vopr.begin(), vopr.end());
//    // Находим разность pov и объединенного множеста
//    set_difference(pov.begin(), pov.end(), set_vopr_voskl.begin(), set_vopr_voskl.end(), inserter(res, res.begin()));
//    for (set <string> ::iterator i = res.begin(); i != res.end(); i++)
//        cout << *i << " ";
//    return 0;
//}