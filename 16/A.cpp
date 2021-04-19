#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;

// структура декартового дерева
struct Treap
{
	ll key;
	ll prior;
	Treap* left = nullptr;
	Treap* right = nullptr;
};

// 
void Split(Treap* t, ll k, Treap*& l, Treap*& r)
{
	// если дерево пустое
	if (t == nullptr)
	{
		l = nullptr;
		r = nullptr;
		return;
	}
	// если у текущего узла меньше приоритет, то 
	// разделить по правому поддереву
	if (t->key < k)
	{
		Split(t->right, k, t->right, r);
		l = t;
	}
	// разделить по левому поддереву
	else
	{
		Split(t->left, k, l, t->left);
		r = t;
	}
}

void Insert(Treap*& l, Treap*& r) {
	// если дерево пустое
	if (l == nullptr) 
		l = r;
	// если приоритет у правого дерева больше чем у корня
	else if (r->prior > l->prior) 
	{
		// разделить на два дерева, то есть в правое вставить левое
		Split(l, r->key, r->left, r->right);
		l = r;
	}
	// если приоритет меньше, то вставить в левый
	// или правый узел
	else 
	{
		if (r->key < l->key)
			Insert(l->left, r);
		else
			Insert(l->right, r);
	}
}

void Do(Treap* t)
{
	if (t == nullptr)
		//так как узел пуст, вывести null
		cout << "null" << '\n';
	else
	{
		// вывод значения узла
		cout << t->key <<" " << t->prior << '\n';
		// рекурсивно обойти остальные узлы
		Do(t->left);
		Do(t->right);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int n;
	cin >> n;
	ll k, p;
	Treap* t = nullptr;
	for (int i = 0; i < n; i++)
	{
		Treap* nw = new Treap;
		cin >> nw->key >> nw->prior;
		// вставка узла в дерево
		Insert(t, nw);
	}
	// обход дерева
	Do(t);
	

}