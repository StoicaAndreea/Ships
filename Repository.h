#pragma once
#include"Vapor.h"
#include<iterator>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T>class RepositoryTemplate {
protected:
	list<T> elem;
public:
	RepositoryTemplate<T>() {}
	virtual int addElem(T&);
	virtual int deleteElem(T&);
	int findElem(T&);
	int getSize();
	virtual void updateElem(T s, T& nou);
	list<T> getAll();
	T getItemFromPos(int);
	virtual T getItemFromPoint(int,int);
	void clearElem();
	~RepositoryTemplate();
};





template<class T>
int RepositoryTemplate<T>::addElem(T& e)
{
	//typename list<T>::iterator it;
	//it = find(elem.begin(), elem.end(), e);
	//if (it == elem.end())
	//{
	elem.push_back(e);
	return 0;
	//}
	//return -1;
}

template<class T>
int RepositoryTemplate<T>::deleteElem(T& e)
{
	typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it != elem.end())
	{
		elem.erase(it);
		return 0;
	}
	return -1;
}

template<class T>
int RepositoryTemplate<T>::findElem(T& e)
{
	typename list<T>::iterator it;
	int i = 0;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if (*it == e)
		{
			return i;
		}
		i++;
	}
	return -1;
}

template<class T>
int RepositoryTemplate<T>::getSize()
{
	return elem.size();
	return 0;
}

template<class T>
void RepositoryTemplate<T>::updateElem(T vechi, T& nou)
{
	replace(elem.begin(), elem.end(), vechi, nou);

}

template<class T>
list<T> RepositoryTemplate<T>::getAll()
{
	return elem;
	return list<T>();
}

template<class T>
T RepositoryTemplate<T>::getItemFromPos(int i) {
	typename list<T>::iterator it;
	int k = 0;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if (k == i)
			return *it;
		k++;

	}
}
template<class T>
T RepositoryTemplate<T>::getItemFromPoint(int x, int y) {
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if ((*it).getX()==x && (*it).getY()==y)
			return *it;

	}
}
template<class T> void RepositoryTemplate<T>::clearElem() {
	elem.clear();
}
template <class T> RepositoryTemplate<T>::~RepositoryTemplate()
{
}
