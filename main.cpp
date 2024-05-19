#include <iostream>
using namespace std;

// ������� ��������� �������
struct queue
{
    int inf;
    queue* next;
};

// ������� ���������� �������� x � ����� �������
void push(queue*& h, queue*& t, int x)
{
    queue* r = new queue;
    r->inf = x;
    r->next = NULL;
    if (!h && !t)
    {
        h = t = r;
    }
    else
    {
        t->next = r;
        t = r;
    }
}

// ������� ������ ������� �� ������� � ���������� ��� ��������
int pop(queue*& h, queue*& t)
{
    int i = h->inf;
    queue* r = h;
    h = h->next;
    if (!h)
        t = NULL;
    delete r;
    return i;
}

// �������� �� ������� � ����� ������������ �������
int findMax(queue* h)
{
    int max = 0;
    queue* temp = h;
    while (temp)
    {
        if (temp->inf > max)
        {
            max = temp->inf;
        }
        temp = temp->next;
    }
    return max;
}

// �������� �� ������� � ����� ��������� ������ �������
int findLastCh(queue* h)
{
    int lastCh = 0;
    queue* temp = h;
    while (temp)
    {
        if (temp->inf % 2 == 0)
        {
            lastCh = temp->inf;
        }
        temp = temp->next;
    }
    return lastCh;
}

// �������� �� ������� � ����� ������� ������������� �������� �������� ��������� ������ �������
void result(queue*& h, queue*& t)
{
    int max = findMax(h);
    int lastCh = findLastCh(h);
    queue* newQueue = NULL;
    queue* newQueueEnd = NULL;

    while (h)
    {
        int x = pop(h, t);
        if (x == max)
        {
            push(newQueue, newQueueEnd, x);
            push(newQueue, newQueueEnd, lastCh);
        }
        else
        {
            push(newQueue, newQueueEnd, x);
        }
    }

    h = newQueue;
    t = newQueueEnd;
}

int main()
{
    queue* h = NULL; // �������� �������
    queue* t = NULL;

    int n, x;
    cout << "n=";
    cin >> n;
    cout << "Input element\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        push(h, t, x);
    }

    cout << "Old queue\n"; // ����� ������
    queue* temp = h;
    while (temp)
    {
        cout << temp->inf << " ";
        temp = temp->next;
    }

    result(h, t);

    cout << "\nNew queue\n";
    while (h)
    {
        cout << pop(h, t) << " ";
    }

    return 0;
}