#include <iostream>
using namespace std;

struct list {//структура для узла списка
    int inf;
    list* next;
    list* prev;
};

void push(list*& h, list*& t, int x) {//добавленеие элемента в конец списка
    list* r = new list;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        r->prev = NULL;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void print(list*& h, list*& t) {
    list* p = h;
    while (p) {
        cout << p->inf << " ";
        p = p->next;
    }
}

void insert_begin(list*& t, list*& h, list* r, int y) { //вставляем после r
    list* p = new list;//выделяем память под новый элемент
    p->inf = y;//присваиваем значение у
    if (r == t) {//если r - последний элемент
        p->prev = NULL;//предыдущий указатель нового элемента 0
        p->next = r;//следующий указатель нового элемента указывает на r
        r->prev = p;//предыдущий указатель указывает на новый элемент
        t = p;//указатель конца списка перемещаем на новый элемент
        t->prev = NULL;//предыдущий указатель конца списка равен 0
    }
}

void del_curr(list*& h, list*& t, list* r) {//удаление текущего элемента
    if (r == h && r == t)
        h = t = NULL;
    else if (r == h) {//если r-первый элемент списка
        h = h->next;//перемещаем указатель на начало списка
        h->prev = NULL;//предыдущий указатель начала списка 0
    }
    else if (r == t) {//если r - последний элемент списка
        t = t->prev;//перемещаем указатель на конец списка
        t->next = NULL;//следующий указатель конца списка 0
    }
    else {
        r->next->prev = r->prev;//связь между соседними элементами
        r->prev->next = r->next;
    }
    delete r;
}
void result(list*& h, list*& t, int n) {
    bool flag = false;
    list* p = t;//указатель на конец списка
    for (int i = 0; i < n; i++) {
        int tmp = p->inf;//текущий элемент
        if (tmp % 2 == 0) { // Проверяем, четное ли число
            insert_begin(h, t, h, tmp);//если чет-вставляем в начало списка
            list* k = p->next;//запоминаем следующий элемент
            del_curr(h, t, p);//удаляем текущий
            p = k;//перемещаемся к следующему
        }
        if (p != nullptr) {
            p = p->prev;//переходим к предыдущему
        }
        else {
            break;
        }
    }
}

void del_list(list*& h) {//удаление списка
    list* cur = h;
    list* next;
    while (cur != NULL) {
        next = cur->next;
        delete cur;
        cur = next;
    }
    h = NULL;
}

int main() {
    setlocale(LC_ALL, "RU");
    int n, y;
    list* h = NULL;//начало
    list* t = NULL;//конец
    cout << "n = ";
    cin >> n;
    cout << "origin: ";
    for (int i = 0; i < n; i++) {//ввод списка
        cin >> y;
        push(h, t, y);
    }
    result(h, t, n);//выполнение 
    cout << "result: ";
    print(h, t);
    del_list(h);
    return 0;
}

