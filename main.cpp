//// ����� �������� ������� �������� ���� 
#include<iostream>
#include <cstdlib>
using namespace std;

// ����������� ��������� ��� ��������� �����
struct stack {
    char inf;
    stack* next;
};

// ������� ��� ���������� �������� � ����
void push(stack*& h, char x) {
    stack* r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

// ������� ��� ���������� �������� �� �����
char pop(stack*& h) {
    char i = h->inf;
    stack* r = h;
    h = h->next;
    delete r;
    return i;
}

// ������� ��� ����������� �������� �� ������ ������� ������
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// ������� ��� ��������� ����� � ���������� ������ �������� ����� ��������� �������
stack* result(stack*& h) {
    stack* temp = NULL; // ��������� ���� ��� ��������� ���������
    char new_el, x;
    bool vowelFound = false; // ����, ����������� �� ��, ���� �� ������� �������

    cout << "������� ����� �����: ";
    cin >> new_el;
    cout << endl;

    while (h) {
        x = pop(h); // ��������� ������� �� ��������� �����
        push(temp, x); // ��������� ����������� ������� �� ��������� ����

        // ���� ��� �� ���� ������� ������� � ������� ������ - �������, ��������� ����� ������� ����� ���
        if (!vowelFound && isVowel(x)) {
            push(temp, '?');
            vowelFound = true; // ������������� ���� ������� ���������
        }
    }

    return temp; // ���������� ��������� ���� � ������������� ����������
}

int main() {
    stack* h = NULL; // �������� ����
    int n;
    char x;

    cout << "���������� ��������� � ����� n = ";
    cin >> n;
    cout << "������� ����� ��� �����:" << endl;

    // ���������� ��������� ����� ���������� �������
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(h, x);
    }
    cout << endl;

    // ��������� ������������� ����� � ����������� ������ ����� ��������� �������
    h = result(h);

    cout << "���������: " << endl;
    // ����� ��������� ������������� �����
    while (h) {
        cout << pop(h) << " ";
    }
    cout << endl;

    return 0;
}
