#include <iostream>
using namespace std;
char a;


struct Stack {
    char data;
    Stack* prev;
};

Stack* make_stack(int n)
{
    if (n == 0) return NULL;
    Stack* top, * p; // top - ��������� �� ������� ������� �����
    top = NULL;     // ���� �� �� �� ��� �� ���������
    p = new Stack;    // ��������� ������ ��� 1 �������
    cin >> a;
    p->data = (char)(a);
    p->prev = NULL;   // ��� ��� �� ������, �� ����� ��������� ���
    top = p;        /* ����������, ��� �������� ������� ���� ������ */
    for (int i = 2; i <= n; i++) {
        Stack* h = new Stack; // ��������� ������ ��� ������ ��������
        cin >> a;
        h->data = (char)(a);
        h->prev = top; // ��������� �� ������ ������� 
        top = h;       /* ����������, ��� �������� ������� ���� ������ */
    }
    return top;
}

void print_stack(Stack* top)
{
    if (top == NULL)
    {
        cout << "���� ����" << endl;
    }
    else {
        Stack* p = top;   // p ��������� �� ������ �������
        while (p != NULL) // ���� ���������� �������� 
        {
            cout << p->data << " "; // ����� �����
            p = p->prev;  // ������� � ���������� ��������
        }
        cout << endl;
    }
}

char pop(Stack*& top) { // �����-�� ������� �������� � ��� ��������
    Stack* p = top;
    int k = 0;          // ���-�� ��������� � �����
    while (p != NULL) // ������� ���-�� ���������
    {
        k++;
        p = p->prev;
    }
    p = top;
    if (k == 1) /* ���� ������� ����, �� �������� ��������� � ���������� ��������� ������� */
    {
        char t = top->data;
        delete p;
        top = NULL;
        return t;
    }
    else // ���� ������ 1
    {
        Stack* t = p->prev; // ��������� �� ������ �������
        char u = p->data;    /* ���������� �������� ���������� �������� */
        top = t;          // � �� ������ ������ �������
        delete p;           // �������� ���������� ��������
        return u;           // ����������� ������� ��������
    }
}

Stack* push(Stack*& top, char val)
{
    // ������� ���������� �������� � ����
    Stack* p = new Stack; // ��������� ������ ��� ������ ��������
    p->data = val;        // ������������ ������ ��������
    p->prev = top;      /* ����� ������� ��������� �� ������ ������� */
    top = p;            // ����� ������� ���� ������ ��������� ����� */
    return top;
}

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "������� ���������� ���������: ";
    int n;
    cin >> n;
    cout << "������� �������� �����: ";
    Stack* st = make_stack(n); // �������� �����
    cout << "����: ";
    print_stack(st);           // ������ �����

    char b;
    int k;
    cout << "������� ���� ��� �������� : ";
    cin >> b;
    k = 0;
    Stack* st2 = make_stack(0);
    for (int i = 0; i < n; i++)
    {
        char t = pop(st);
        if (t != b)
        {
            push(st2, t);
        }
        else
        {
            k = k + 1;
        }
    }
    n = n - k;
    for (int i = 0; i < n; i++)
    {
        char t = pop(st2);
        push(st, t);
    }
    cout << "���� ����� �������� : ";
    print_stack(st);

    k = 0;                                                    //k- ���������� ��������� ��� ���������� 
    cout << "������� ���������� ��������� ��� ����������: ";
    cin >> k;
    int s = 0;                                                      //�������, ����� ������� ��������� ��������
    cout << "������� ����� ��������, ����� ������� ��������� ��������: ";
    cin >> s;
    for (int i = 0; i < n - s + 1; i++)
    {                    // ������� ���� ��������� ����� �� s-�������� ������������
        char t = pop(st);
        push(st2, t);
    }
    cout << "������� ��������: ";
    for (int i = 0; i < k; i++) {                          // ������ ��������� � ����
        cin >> a;                                                  // ���� �������� ��������
        push(st, a);                                               // ���������� ��������� � ����
    }
    for (int i = 0; i < n - s + 1; i++) {              // ������� ���� ��������� ������� ����� � ��������� ����
        char t = pop(st2);
        push(st, t);                                               // �������� �������� �� ������� ������� �����
    }
    print_stack(st);                                                    // ������ �����

    return 0;
}