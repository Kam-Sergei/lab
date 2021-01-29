#include <iostream>
#include <stack>               // Заголовок стека
using namespace std;
char a,b; //a- символ в стеке b-ключ

void print(stack<char> st) {
	int p = st.size(); // Размер стека
	if (p == 0)
	{
		cout << "список пуст";
	}
	else {
		for (int i = 1; i <= p; i++) // Печать элементов стека
		{ 
			cout << st.top() << " ";
			st.pop();
		}
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Rus");
	stack<char> st;                // Создали пустой стек
	int n;                        // n- количество элементов стека
	cout << "Введите количество элементов стека : ";
	cin >> n;
	cout << "Введите элементы стека : ";
	for (int i = 1; i <= n; i++)
	{
		cin >> a; //ввод значения элемента
		st.push(a); // Добавление элементов в стек
	}
	cout << "Стек: ";
	print(st);                   // Печать стека

	stack<int> st2;   // Создали второй стек
	cout << "Введите ключ для удаления: ";
	cin >> b; //Ввод значения элемента для удаления
	int k = 0;//Количество элементов, которые будут удалины
	for (int i = 1; i <= n; i++) // Перенос всех элементов,
	{
		if (st.top() != b)
		{	
			st2.push(st.top());
		}        
		else
		{
			k = k + 1;
		}
		st.pop();
	}
	n = n - k;
		for (int i = 1; i <= n; i++) 
		{ 
			st.push(st2.top());  
			st2.pop();
		}
	cout << "Стек после удаления: ";
	print(st);                       // Печать стека

	k = 0; //Количество элементов для добавления
	cout << "Введите количество элементов для добавления: ";
	cin >> k;
	int s = 0; //Элемент, перед которым добавляют элементы
	cout << "Введите элемент, перед которым добавляют элементы: ";
	cin >> s;
	for (int i = 1; i <= n-s+1; i++) 
	{
		st2.push(st.top());
		st.pop();
	}
	cout << "Введите элементы: ";
	for (int i = 1; i <= k; i++) 
	{
		cin >> a;
		st.push(a);
	}
	for (int i = 1; i <= n - s + 1; i++)
	{
		st.push(st2.top());
		st2.pop();
	}
	print(st);

	return 0;
}