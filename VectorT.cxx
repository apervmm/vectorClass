#pragma once

#include<iostream>

using namespace std;

namespace CS52
{
	template<class T>

	class Vector
	{
	private:
		int iSize = 0;
		int iCapacity = 0;
		T *iData = nullptr;

	public:
		int size() const;

		Vector<T>();

		Vector<T>(const Vector & other);

		Vector<T>(int iSize, int initVal);

		T & at(int i) const throw(...);

		int capacity() const;

		~Vector<T>();

		void push_back(T element);

		void pop_back();

		void clear();

		T* data() const;

		bool empty() const;

		T & operator[] (int i);

		Vector<T> & operator=(const Vector<T> &);

		friend ostream & operator << (ostream &out, Vector<T> &v);
	};


	template<class T>
	Vector<T>::Vector()		//default constractor
	{}

	template<class T>
	Vector<T>::Vector(int iSize, int initVal)  //overloaded constructor
	{
		this->iCapacity = iSize;
		this->iSize = iSize;
		this->iData = new T[iSize];
		for (int i = 0; i < iSize; i++)
		{
			this->iData[i] = initVal;
		}
	}

	template<class T>
	Vector<T>::Vector(const Vector & other)		//coppy constractor
	{
		for (int i = 0; i < other.iSize; i++)
		{
			push_back(other.iData[i]);
		}
	}

	template<class T>
	void Vector<T>::push_back(T element)		//push_back()
	{
		if (iData == nullptr) {
			this->iCapacity = 3;
			this->iData = new T[this->iCapacity];
			this->iData[0] = element;
			this->iSize++;
		}
		else if (this->iSize + 1 < this->iCapacity)
		{
			this->iData[this->iSize++] = element;
		}
		else
		{
			T *newArr = new T[this->iCapacity + 1];
			for (int i = 0; i < this->iSize; i++)
			{
				newArr[i] = this->iData[i];
			}
			newArr[this->iSize++] = element;
			this->iCapacity++;
			delete[] this->iData;
			this->iData = newArr;
		}
	}

	template<class T>
	void Vector<T>::pop_back()   //pop_back()
	{
		this->iSize--;
		int *newArray = new T[this->iCapacity];
		for (int i = 0; i < this->iSize; i++)
		{
			newArray[i] = this->iData[i];
		}
		delete[] this->iData;
		this->iData = newArray;
	}


	template<class T>
	int Vector<T>::size() const // size()
	{
		return this->iSize;
	}

	template<class T>
	T & Vector<T>::at(int i) const throw(std::out_of_range)
	{
		if (i > (iSize - 1) || i < 0)
			throw std::out_of_range("out-of-bounds");

		return iData[i];
	}

	template<class T>
	int Vector<T>::capacity() const // capacity()
	{
		return this->iCapacity;
	}

	template<class T>
	Vector<T>::~Vector()		//destructor 
	{
		this->iSize = 0;
		delete[] this->iData;
		this->iCapacity = 0;
	}

	template<class T>
	void Vector<T>::clear() //clear()
	{
		this->iSize = 0;
		int *Arrclear = new T[this->iCapacity];
		for (int i = 0; i < this->iSize; i++)
		{
			Arrclear[i] = this->iData[i];
		}
		delete this->iData;
		this->iData = Arrclear;
	}

	template<class T>
	bool Vector<T>::empty() const //empty()
	{
		return iData == nullptr || iSize == 0;
	}

	template<class T>
	T * Vector<T>::data() const	//data()
	{
		return this->iData;
	}

	template<class T>
	ostream &operator<<(ostream & out, Vector<T> & v) //operator<<
	{
		for (int i = 0; i < v.iSize; i++)
		{
			out << v.iData[i] << " ";
		}

		return out;
	}

	template<class T>
	T & Vector<T>::operator[] (int i)   //operator[]
	{
		return this->iData[i];
	}

	template<class T>
	Vector<T> & Vector<T>::operator=(const Vector<T> & other)	//operator=
	{
		this->clear();
		for (int i = 0; i < other.iSize; i++)
		{
			push_back(other.iData[i]);
		}
		return *this;
	}
}