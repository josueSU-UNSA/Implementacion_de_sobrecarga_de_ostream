//dinamic .h
#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

#include "Point.h"
#include "Curso.h"
using namespace std;
template <typename T>
class DynamicArray
{
private:
    T *arr;
    int size;
    void resize(int newSize);
public:
    DynamicArray();
    DynamicArray(const T arr[], int size);
    DynamicArray(const DynamicArray &o);
    //implementacion de sobrecarga del metodo ostream para la clase DynamicArray
    friend ostream& operator<<(ostream&o,const DynamicArray &p){
        for (int i=0;i<p.getSize();i++){
            o<<p.arr[i]<<endl;
        }
        return o;
    }
    void push_back(T elem);
    void insert(T elem, int pos);
    void remove(int pos);
    void print();

    void clear();
    int getSize() const {
        return size;
    }

    ~DynamicArray();
};


template <typename T>
DynamicArray<T>::DynamicArray()
{
    size = 0;
    arr = new T[0];
}

template <typename T>
DynamicArray<T>::DynamicArray(const T arr[], int size)
{ 
    this->size = size;
    this->arr = new T[size];

    for(int i = 0; i < size; i++)
        this->arr[i] = arr[i];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &o)
{
    this->size = o.size;
    this->arr = new T[o.size];

    for(int i = 0; i < size; i++)
        this->arr[i] = o.arr[i];
}

template <typename T>
void DynamicArray<T>::resize(int newSize) {
    T *tmp = new T[newSize];
    int minSize = (newSize > size) ? size : newSize;
    for(int i = 0; i < minSize; i++)
        tmp[i] = arr[i];
    delete [] arr;
    size = newSize;
    arr = tmp;
}
template <typename T>
void DynamicArray<T>::push_back(T elem) {
    resize(size + 1);
    arr[size-1] = elem;
}

// Yamil
template <typename T>
void DynamicArray<T>::insert(T elem, int pos){
    resize(size+1);
    for(int j=size-1; j > pos;j--){
        arr[j]= arr[j-1];
    }
    arr[pos]=elem;
}

// Miguel
template <typename T>
void DynamicArray<T>::remove (int pos) {
    if( 0 <= pos and pos < size ){
        for(int i = pos; i <= size - 2; i++) {
            arr[i] = arr[i + 1];
        }
    }
    resize (size - 1);
}

template <typename T>
void DynamicArray<T>::clear() {
    resize(0);
}

// Yamil
template <typename T>
void DynamicArray<T>::print() {
    for(int i=0;i<this->size;i++){
		cout<< arr[i] << " ";
	}
	cout<<'\n';
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete []arr;
}

#endif