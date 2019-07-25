#ifndef VECTOR_HEADER_HR
#define VECTOR_HEADER_HR
#include <cstdlib>
template <class T>
class Vector{
	private:
	unsigned int vSize;
	T * data;

	public:
	Vector();
	Vector(int size);
	Vector(const Vector<T> & v);
	T & operator[](std::size_t index);
	void clear();
	~Vector();
	void insert(int,T);
	T* read(int);
	bool remove(int);
	unsigned int size(){return vSize;}

};
template<class T>
Vector<T>::Vector(){
	vSize = 0;
	data = new T[vSize];
}

template<class T>
Vector<T>::Vector(int size){
	vSize = size;
	data = new T[vSize];
}

template<class T>
Vector<T>::Vector(const Vector<T> & v){
	vSize = v.vSize;
	data = new T[vSize];
	for(unsigned int i = 0; i < vSize; i++){
		data[i] = v.data[i];
	}
}
template<class T>
T & Vector<T>::operator[](std::size_t index){
	return data[index % vSize];
}
template<class T>
void Vector<T>::clear(){
	delete[] data;
	vSize = 0;
	data = new T[vSize];
}
template<class T>
Vector<T>::~Vector(){
	delete[] data;
	data = NULL;
}

template<class T>
void Vector<T>::insert(int index, T p){
	if((unsigned int)index > vSize){
		unsigned int oldSize = vSize;
		vSize = index + 1;
		T * newData = new T[vSize];
		for(unsigned int i = 0; i < oldSize; i++){
			newData[i] = data[i];
		}
		for(unsigned int i = oldSize; i < vSize-1; i++){
			newData[i] = NULL;
		}
		newData[vSize-1] = p;
		delete[] data;
		data = newData;
	}else{
		vSize++;
		T * newData = new T[vSize];
		for(unsigned int i = 0, j = 0; i < vSize; i++){
			if(i == (unsigned int)index){
				newData[i] = p;
			}
			else{
				newData[i] = data[j];
				j++;
			}
		}
		delete[] data;
		data = newData;
	}
}
template <class T>
T* Vector<T>::read(int index){
	if((unsigned int)index >= vSize || index < 0){
		return NULL;
	}
	else{
		return data[index];
	}
}

template<class T>
bool Vector<T>::remove(int index){
	if(index < 0 || (unsigned int)index >= vSize){return false;}
	T * newData = new T[vSize - 1];
	for(unsigned int i = 0, j = 0; i < vSize; i++){
		if(i == (unsigned int)index){
			continue;
		}else{
			newData[j] = data[i];
			j++;
		}
	}
	vSize--;
	delete[] data;
	data = newData;
	return true;
}

#endif
