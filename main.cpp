// Подключаем необходимые библиотеки
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

// Структура для хранения узлов дерева
struct tree {
    int inf;        // Данные в узле
    tree* right;   // Указатель на правый узел
    tree* left;    // Указатель на левый узел
};

// Функция для создания нового узла дерева
tree* node(int x) {
    tree* n = new tree;    // Создаем новый узел
    n->inf = x;            // Устанавливаем данные в узел
    n->left = n->right = NULL;  // Инициализируем левого и правого потомков как NULL
    return n;               // Возвращаем созданный узел
}

// Функция для создания дерева
void create(tree*& tr, int n) {
    int x;
    if (n > 0) {
        cin >> x;
        tr = node(x);
        int nl = n / 2;
        int nr = n - nl - 1;
        create(tr->left, nl);
        create(tr->right, nr);
    }
}

// Функция для обхода дерева в прямом порядке
void preorder(tree* tr) {
    if (tr) {
        cout << tr->inf << " ";
        preorder(tr->left);
        preorder(tr->right);
    }
}

// Функция для вычисления высоты левого поддерева
int lefth(tree* tr) {
    int k = 0;
    tree* x = tr;
    while (x) {
        k++;
        x = x->left;
    }
    return k - 1;
}

// Функция для вычисления высоты правого поддерева
int righth(tree* tr) {
    int k = 0;
    tree* x = tr;
    while (x) {
        k++;
        x = x->right;
    }
    return k - 1;
}

// Функция для добавления узла в дерево
void add(tree*& tr, int x) {
    tree* n = node(x);
    tree* y = tr;
    if (lefth(tr) == righth(tr)) {
        do {
            y = y->left;
        } while (y->left);
        if (!y->left) y->left = n;
        else y->right = n;
    }
    else {
        do {
            y = y->right;
        } while (y->right);
        if (!y->left) y->left = n;
        else y->right = n;
    }
}

// Функция для поиска узла в дереве
void find(tree* tr, int x, tree*& res) {
    if (tr) {
        if (tr->inf == x) {
            res = tr;
        }
        else {
            find(tr->left, x, res);
            find(tr->right, x, res);
        }
    }
}

// Функция для удаления узла из дерева
void del_n(tree* tr, int val) {
    tree* y;
    find(tr, val, y);
    if (y) {
        if (lefth(tr) == 0) tr = NULL;
        else if (lefth(tr) != righth(tr)) {
            tree* x = tr->left;
            do {
                x = x->left;
            } while (x->left);
            y->inf = x->inf;
            del_n(tr, x->inf);
        }
        else {
            tree* x = tr->right;
            do {
                x = x->right;
            } while (x->right);
            y->inf = x->inf;
            del_n(tr, x->inf);
        }
    }
}

// Функция для подсчета количества листьев в дереве
int count_leaf(tree* tr) {
    int count = 0;
    if (tr) {
        if (!tr->left && !tr->right) {
            count++;
        }
        else {
            count += count_leaf(tr->left);
            count += count_leaf(tr->right);
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Введите количество узлов дерева: ";
    cin >> n;
    tree* root = NULL;
    create(root, n);
    cout << "Дерево в прямом порядке: ";
    preorder(root);
    cout << endl;
    cout << "Количество листьев: " << count_leaf(root) << endl;
    return 0;
}
