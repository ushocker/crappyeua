
#include <iostream>
using namespace std;

struct EUC
{
	int i;
	int q;
	int r = -1;
	int x;
	int y;

};

void printHead();
void print(EUC*);

int main()
{
	EUC* val1 = new EUC;
	EUC* val2 = new EUC;
	EUC* valtemp = new EUC;

	const int X = 1;
	const int Y = 0;

	int M = 29;
	int N = 32;

	val1->i = -1;
	val1->q = -2;
	val1->r = M;
	val1->x = X;
	val1->y = Y;

	val2->i = 0;
	val2->q = -2;
	val2->r = N;
	val2->x = Y;
	val2->y = X;

	printHead();
	print(val1);
	print(val2);

	int i = 1;
	while (valtemp->r != 0)
	{
		valtemp->i = i++;
		valtemp->q = val1->r / val2->r;
		valtemp->r = val1->r % val2->r;
		valtemp->x = val1->x - (valtemp->q * val2->x);
		valtemp->y = val1->y - (valtemp->q * val2->y);
		print(valtemp);
		*val1 = *val2;
		*val2 = *valtemp;
	}


}

void printHead()
{
	cout << string(20, '-') << endl;
	cout << " I   Q   R   X   Y" << endl;
	cout << string(20, '-') << endl;
}

void print(EUC* s1)
{
	cout << " " << s1->i << "   ";
	if (s1->q == -2)
	{
		cout << " ";
	}
	else
	{
		cout << s1->q;
	}
	cout << "   " << s1->r << "   " << s1->x << "   " << s1->y << endl;
}
