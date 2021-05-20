#pragma once

using namespace std;

template<typename T>
class Vector {
private:
  T * elements;
  int current_size;
  int buffer_size;
public:
  Vector();
  Vector(int);
  Vector(int, T);
  Vector(const Vector<T> &);
  ~Vector();

  void push_back(T);
  void pop_back();
  int size() const;

  T & operator[](int) const;
};

template<typename T>
Vector<T>::Vector() {
  elements = nullptr;
  current_size = 0;
  buffer_size = 0;
}

template<typename T>
Vector<T>::Vector(int buffer_size) {
  this->buffer_size = buffer_size;
  this->current_size = 0;
  this->elements = new T[this->buffer_size];
}

template<typename T>
Vector<T>::Vector(int buffer_size, T element) {
  this->buffer_size = buffer_size;
  this->current_size = buffer_size;
  this->elements = new T[this->buffer_size];

  for (int i = 0; i < this->current_size; i++) {
    this->elements[i] = element;
  }
}

template<typename T>
Vector<T>::Vector(const Vector<T> & orig) {
  this->buffer_size = orig.buffer_size;
  this->current_size = orig.current_size;
  this->elements = new T[this->buffer_size];

  for (int i = 0; i < this->current_size; i++) {
    this->elements[i] = orig.elements[i];
  }
}

template<typename T>
Vector<T>::~Vector() {
  delete[] elements;
}

template<typename T>
void Vector<T>::push_back(T el) {
  if (buffer_size == 0 && current_size == 0) {
    buffer_size = 4;
    elements = new T[buffer_size];
  } else if (current_size == buffer_size) {
    buffer_size *= 2;
    T* tmp = new T[buffer_size];
    for (int i =0; i < current_size; i++) {
      tmp[i] = elements[i];
    }
    delete[] elements;
    elements = tmp;
  }
  
  elements[current_size++] = el;
}

template<typename T>
void Vector<T>::pop_back() {
  current_size--;
}

template<typename T>
T & Vector<T>::operator[](int index) const {
  return elements[index];
}

template<typename T>
int Vector<T>::size() const {
  return current_size;
}
