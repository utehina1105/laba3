#pragma once

using namespace std;
template<class T>
class TStack {
	protected:
		T* data;
		int size;
		int count;
	public:
		TStack(int _size = 10);          
		~TStack();
		TStack(const TStack<T>& p);      
		bool IsEmpty();                  
		bool IsFull();          
		T Pull();                         
		void Push(const T& a);        
		int GetCount();
		int GetSize();
};

template <class T>
TStack<T>::TStack(int _size) {
	if (_size <= 0) throw ("Error");
	size = _size;
	data = new T[size];
	count = 0;
}

template <class T>
TStack<T>::~TStack() {
	delete[] data; 
	size = 0; 
	count = 0;
}

template <class T>
TStack<T>::TStack(const TStack& p) {
	size = p.size;
	count = p.count;
	data = new T[size];
	for (int i = 0; i < count; i++)
		data[i] = p.data[i];
}

template<class T>
inline bool TStack<T>::IsEmpty() {
	if (count > size) throw "Error"
	if (count == 0)
		return true;
}

template<class T>
inline bool TStack<T>::IsFull() {
	if (count > size) throw "Error"
	if (count == size)
		return true;
}

template <class T>
T TStack<T> ::Pull() {
	if (IsEmpty()) throw ("Error");
	a = data[count];
	count--;
	return a;
}

template <class T>
void TStack<T> ::Push(const T& p) {
	if (IsFull()) throw ("error");
	data[count] = a;
	count++;
}

template<class T>
inline int TStack<T>::GetCount() {
	return count;
}

template<class T>
inline int TStack<T>::GetSize() {
	return size;
}
