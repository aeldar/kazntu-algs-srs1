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
  Vector(int buffer_size);
  Vector(int buffer_size, T elements);
  Vector(const Vector<T> & orig);
  ~Vector();
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
