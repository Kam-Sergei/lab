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
    Stack* top, * p; // top - указатель на верхний элемент стека
    top = NULL;     // Пока он ни на что не указывает
    p = new Stack;    // Выделение памяти под 1 элемент
    cin >> a;
    p->data = (a);
    p->prev = NULL;   // Так как он первый, то снизу элементов нет
    top = p;        /* Показываем, что введённый элемент стал первым */
    for (int i = 2; i <= n; i++) {
        Stack* h = new Stack; // Выделение памяти для нового элемента
        cin >> a;
        h->data = (char)(a);
        h->prev = top; // Указываем на нижний элемент 
        top = h;       /* Показываем, что введённый элемент стал первым */
    }
    return top;
}

void print_stack(Stack* top)
{
    if (top == NULL)
    {
        cout << "стек пуст" << endl;
    }
    else {
        Stack* p = top;   // p указывает на первый элемент
        while (p != NULL) // Пока существуют элементы 
        {
            cout << p->data << " "; // Вывод ключа
            p = p->prev;  // Переход к следующему элементу
        }
        cout << endl;
    }
}

char pop(Stack*& top) { // Возвр-ие первого элемента и его удаление
    Stack* p = top;
    int k = 0;          // Кол-во элементов в стеке
    while (p != NULL) // Считаем кол-во элементов
    {
        k++;
        p = p->prev;
    }
    p = top;
    if (k == 1) /* Если элемент один, то обнуляем указатели и возвращаем последний элемент */
    {
        char t = top->data;
        delete p;
        top = NULL;
        return t;
    }
    else // если больше 1
    {
        Stack* t = p->prev; // Указатель на второй элемент
        char u = p->data;    /* Сохранение значения последнего элемента */
        top = t;          // И он теперь первый элемент
        delete p;           // Удаление последнего элемента
        return u;           // Возвращение первого элемента
    }
}

Stack* push(Stack*& top, char val)
{
    // Функция добавления элемента в стек
    Stack* p = new Stack; // Выделение памяти для нового элемента
    p->data = val;        // Присваивание нового элемента
    p->prev = top;      /* Новый элемент указывает на нижний элемент */
    top = p;            // Новый элемент стаёт первым элементом стека */
    return top;
}

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введите количество элементов: ";
    int n;
    cin >> n;
    cout << "Введите элементы стека: ";
    Stack* st = make_stack(n); // Создание стека
    cout << "Стек: ";
    print_stack(st);           // Печать стека

    char b;
    int k;
    cout << "Введите ключ для удаления : ";
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
    cout << "Стек после удаления : ";
    print_stack(st);

    k = 0;                                                    //k- количество элементов для добавления 
    cout << "Введите количество элементов для добавления: ";
    cin >> k;
    int s = 0;                                                      //Элемент, перед которым добавляют элементы
    cout << "Введите номер элемента, перед которым добавляют элементы: ";
    cin >> s;
    for (int i = 0; i < n - s + 1; i++)
    {                    // Перенос всех элементов стека до s-элемента включительно
        char t = pop(st);
        push(st2, t);
    }
    cout << "Введите элементы: ";
    for (int i = 0; i < k; i++) {                          // Запись элементов в стек
        cin >> a;                                                  // Ввод значения элемента
        push(st, a);                                               // Добавление элементов в стек
    }
    for (int i = 0; i < n - s + 1; i++) {              // Перенос всех элементов второго стека в начальный стек
        char t = pop(st2);
        push(st, t);                                               // Удаление элемента из вершины второго стека
    }
    print_stack(st);                                                    // Печать стека

    return 0;
}
