#pragma once

template <typename T>
class ListaLD
{
public:
	T* Content;
	int IloscElementow;

public:
	ListaLD();
	void push_back(T element);
	T pop_back();
	T operator[](int index);
	void clear();
};

