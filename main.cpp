//// перед послдней гласной вставить знак 
#include<iostream>
#include <cstdlib>
using namespace std;

// Определение структуры для элементов стека
struct stack {
    char inf;
    stack* next;
};

// Функция для добавления элемента в стек
void push(stack*& h, char x) {
    stack* r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

// Функция для извлечения элемента из стека
char pop(stack*& h) {
    char i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}

// Функция для определения является ли символ гласной буквой
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Функция для обработки стека и добавления нового элемента перед последней гласной
stack* result(stack*& h) {
    stack* temp = NULL; // Временный стек для обработки элементов
    char new_el, x;
    bool vowelFound = false; // Флаг, указывающий на то, была ли найдена гласная

    cout << "Введите новую букву: ";
    cin >> new_el;
    cout << endl;

    while (h) {
        x = pop(h); // Извлекаем элемент из исходного стека
        push(temp, x); // Добавляем извлеченный элемент во временный стек

        // Если еще не была найдена гласная и текущий символ - гласная, добавляем новый элемент перед ней
        if (!vowelFound && isVowel(x)) {
            push(temp, '?');
            vowelFound = true; // Устанавливаем флаг гласной найденной
        }
    }

    return temp; // Возвращаем временный стек с обработанными элементами
}

int main() {
    stack* h = NULL; // Исходный стек
    int n;
    char x;

    cout << "Количество элементов в стеке n = ";
    cin >> n;
    cout << "Введите буквы для стека:" << endl;

    // Заполнение исходного стека введенными буквами
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(h, x);
    }
    cout << endl;

    // Получение обработанного стека с добавленной буквой перед последней гласной
    h = result(h);

    cout << "Результат: " << endl;
    // Вывод элементов обработанного стека
    while (h) {
        cout << pop(h) << " ";
    }
    cout << endl;

    return 0;
}
