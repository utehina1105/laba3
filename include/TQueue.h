#pragma once

using namespace std;
template<class T>
class TQueue {
	protected:
		T* data;
		int size;
		int start, end;
	public:
		TQueue(int _size = 10);
		~TQueue() {};
		TQueue(const TQueue<T>& p);
		bool IsEmpty();
		bool IsFull();
		int getCount();
		int getStart();
		int getEnd();
		int getSize();
		T Pull(); 
		void Push(const T& a);

};
template<class T>
inline TQueue<T>::TQueue(int _size) {
	if (_size < 0) throw ("Error");
	size = _size;
	start = 0;
	end = 0;
	data = new T[size];
}

template <class T>
TQueue<T>::~TQueue() {
	delete[] data; 
	size = 0; 
	start = 0; 
	end = 0;
}

template<class T>
inline TQueue<T>::TQueue(const TQueue<T>& p) {
	size = p.size;
	start = p.start;
	end = p.end;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = p.data[i];
}
template<class T>
inline bool TQueue<T>::IsEmpty() {
	if (end == start)
		return true;
}
template<class T>
inline bool TQueue<T>::IsFull() {
	if (end == size)
		return true;
}
template<class T>
inline int TQueue<T>::getCount() {
	return (end - start);
}
template<class T>
inline int TQueue<T>::getStart() {
	return start;
}
template<class T>
inline int TQueue<T>::getEnd() {
	return end;
}
template<class T>
inline int TQueue<T>::getSize() {
	return size;
}
template<class T>
inline T TQueue<T>::Pull() {
	if ((start < size) && (start > 0)) {
		a = date[start];
		start++;
		return a;
	}
	else throw "Error";
}
template<class T>
inline void TQueue<T>::Push(const T& a) {
	if (size < end) throw "Error"
	data[end] = a;
	end++;
}
