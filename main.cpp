// ���������� ����������� ����������
#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

// ��������� ��� �������� ����� ������
struct tree {
    int inf;        // ������ � ����
    tree* right;   // ��������� �� ������ ����
    tree* left;    // ��������� �� ����� ����
};

// ������� ��� �������� ������ ���� ������
tree* node(int x) {
    tree* n = new tree;    // ������� ����� ����
    n->inf = x;            // ������������� ������ � ����
    n->left = n->right = NULL;  // �������������� ������ � ������� �������� ��� NULL
    return n;               // ���������� ��������� ����
}

// ������� ��� �������� ������
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

// ������� ��� ������ ������ � ������ �������
void preorder(tree* tr) {
    if (tr) {
        cout << tr->inf << " ";
        preorder(tr->left);
        preorder(tr->right);
    }
}

// ������� ��� ���������� ������ ������ ���������
int lefth(tree* tr) {
    int k = 0;
    tree* x = tr;
    while (x) {
        k++;
        x = x->left;
    }
    return k - 1;
}

// ������� ��� ���������� ������ ������� ���������
int righth(tree* tr) {
    int k = 0;
    tree* x = tr;
    while (x) {
        k++;
        x = x->right;
    }
    return k - 1;
}

// ������� ��� ���������� ���� � ������
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

// ������� ��� ������ ���� � ������
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

// ������� ��� �������� ���� �� ������
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

// ������� ��� �������� ���������� ������� � ������
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
    cout << "������� ���������� ����� ������: ";
    cin >> n;
    tree* root = NULL;
    create(root, n);
    cout << "������ � ������ �������: ";
    preorder(root);
    cout << endl;
    cout << "���������� �������: " << count_leaf(root) << endl;
    return 0;
}
