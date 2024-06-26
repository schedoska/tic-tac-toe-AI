#include "ListaLD.h"
#include <SFML/Graphics.hpp>
#include "MiniMaxAI.h"

template <typename T>
ListaLD<T>::ListaLD()
{
	IloscElementow = 0;
	Content = nullptr;
}

template <typename T>
void ListaLD<T>::push_back(T element)
{
	IloscElementow++;
	T* temp_Content = new T[IloscElementow];
	for (int q = 0; q < IloscElementow - 1; q++)
	{
		temp_Content[q] = Content[q];
	}
	temp_Content[IloscElementow - 1] = element;
	delete[] Content;
	Content = temp_Content;
}

template<typename T>
T ListaLD<T>::pop_back()
{
	IloscElementow--;
	T* temp_Content = new T[IloscElementow];
	for (int q = 0; q < IloscElementow; q++)
	{
		temp_Content[q] = Content[q];
	}
	T ostatni_elemnt = Content[IloscElementow];
	delete[] Content;
	Content = temp_Content;
	return ostatni_elemnt;
}

template<typename T>
T ListaLD<T>::operator[](int index)
{
	return Content[index];
}

template<typename T>
void ListaLD<T>::clear()
{
	delete[] Content;
	Content = nullptr;
	IloscElementow = 0;
}

template class ListaLD<int>;
template class ListaLD<sf::Sprite>;
template class ListaLD<Ruch>;