#include<iostream>
#include<string>

#include "VectorT.cxx"

using namespace std;
using namespace CS52;


template <class T>
void info(Vector <T>& v)
{
	cout << " Size is: " << v.size() << "\n";
	cout << " Capacity is: " << v.capacity() << "\n";
	cout << " Contents : ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
}


template<class T>
void print(T t)
{
	cout << t << endl;
}


int main()
{
	// testing double , bool , std :: string , and CS52 :: Vector <int > instantiations
	Vector<double> dVector(5, -1.0);
	cout << "\n CS52::Vector <double> dVector (5 , -1); \n";
	info(dVector);
	// example exception handling in try / catch block
	try
	{
		// throw and exception
		dVector.at(-1);
	}
	catch (const exception & e)
	{
		cout << "\n Exception index: -1 \n" << e.what() << "\n";
	}


	Vector<bool> booVector(5, true);
	cout << "\n CS52::Vector <bool> booVector (5 , true ); \n";
	info(booVector);


	cout << "\n Testing std::string as an element: \n";
	Vector<string> strVector;
	strVector.push_back(" this is great ");
	strVector.push_back(" I love my CS52::Vector ");
	strVector.push_back(string(" Amazing "));

	for (int i = 0; i < strVector.size(); i++)
	{
		cout << strVector[i] << "\n";
	}


	cout << "\n Testing a 2D vector(matrix) \n";
	Vector<Vector<int>> vecOfIntVecs;
	int cols = 3;
	int rows = 5;
	for (int i = 0; i < rows; i++)
	{
		Vector<int> v(cols, i);
		vecOfIntVecs.push_back(v);	}

	for (int i = 0; i < vecOfIntVecs.size(); i++)
	{
		Vector<int> v = vecOfIntVecs[i];

		for (int j = 0; j < v.size(); j++)
		{
			cout << " " << v[j];
		}
		cout << "\n";
	}	cout << "\n CS52::Vector<int> iVector(3,8) \n";	Vector<int> iVector(3, 8);	info(iVector);

	char q;
	cin >> q;

	return 0;
}