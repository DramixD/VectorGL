#include<iostream>
#include"VectorGL.h"
#include"ForwardIteratorGL.h"
using namespace std;



int main() {
	cout << "Create empty vector\n";
	VectorGL<int> v;
	v.print();

	cout << "is the vector empty?\n";
	cout << v.empty() << endl;

	cout << "push_back 1,2\n";
	v.push_back(1);
	v.push_back(2);
	v.print();

	cout << "push_back 3\n";
	v.push_back(3);
	v.print();

	cout << "push_back 4...13\n";
	for (int i = 0; i < 10; ++i)
		v.push_back(i + 4);
	v.print();

	cout << "v[4] = " << v[4] << endl;

	cout << "v.erase(4)\n";
	v.erase(4);

	cout << "v[4] = " << v[4] << endl;

	v.print();

	cout << "v.reserve(10)\n";
	v.reserve(10);
	v.print();

	cout << "v.reserve(100)\n";
	v.reserve(100);
	v.print();
	
	cout << "push_back 0...9\n";
	for (int i = 0; i < 10; ++i)
		v.push_back(i);
	v.print();


	cout << "print by forward iterator\n";
	for (ForwardIteratorGL<int> it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;

	cout << "find v[i] = 5\n";
	cout << *(v.find(5))<<endl;

	cout << "v.clear()\n";
	v.clear();
	v.print();


}