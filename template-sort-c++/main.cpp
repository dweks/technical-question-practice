#include <iostream>
#include <iterator>
#include <string>

using std::cout;
using std::endl;
using std::begin;
using std::end;

template <typename T>
class Array {
  public:
    ~Array();
    Array();
    Array(T[], size_t);
    Array(const Array<T> &);

    size_t size();
    void print();
    T & operator [] (size_t);

  private:
    T* T_arr;
    size_t arr_size;
};

template <typename T>
class Sort {
  public:
    static Array<T> bubble(Array<T>);
    static Array<T> insertion(Array<T>);
};

int main() {

  try {
    /* Integers */
    /*
    int int_arr[10] = {4, 3, 8, 1, 0, 5, 2, 9, 6, 7};
    int size = sizeof(int_arr) / sizeof(int_arr[0]);
    Array<int> sorted_arr = Sort<int>::bubble(Array<int>(int_arr, size));
    */

    /* Strings */
    /*
    std::string str_arr[5] = {"viel", "chicken", "beef", "rodent", "pork"};
    int size = sizeof(str_arr) / sizeof(str_arr[0]);
    Array<std::string> sorted_arr = Sort<std::string>::bubble(Array<std::string>(str_arr, size));
    */

    /* Strings */
    char char_arr[7] = {'c', 'd', 'a', 'f', 'b', 'g', 'e'};
    int size = sizeof(char_arr) / sizeof(char_arr[0]);
    Array<char> sorted_arr = Sort<char>::bubble(Array<char>(char_arr, size));

    sorted_arr.print();
  }
  catch(size_t e) {
    cout << "Index out of bounds: " << e << endl;
  }
}

template <typename T>
Array<T>::Array(): T_arr(nullptr), arr_size(0) {}

template <typename T>
Array<T>::Array(T arr[], size_t size) {
  arr_size = size;
  T_arr = new T[arr_size];

  for(size_t i{0}; i < arr_size; ++i)
    T_arr[i] = arr[i];
}

template <typename T>
Array<T>::Array(const Array<T> & to_copy) {
  arr_size = to_copy.arr_size;
  T_arr = new T[arr_size];
  for(size_t i{0}; i < arr_size; ++i)
    T_arr[i] = to_copy.T_arr[i];
}

template <typename T>
size_t Array<T>::size() {
  return arr_size;
}

template <typename T>
Array<T>::~Array<T> () {
  delete [] T_arr;
}

template <typename T>
void Array<T>::print() {
  cout << endl;
  for(size_t i{0}; i < arr_size; ++i)
    cout << T_arr[i] << " ";
  cout << endl;
}

template <typename T>
T & Array<T>::operator [] (size_t index) {
  if(index > arr_size - 1)
    throw index;
  return T_arr[index];
}

// Sort functions

template <typename T>
Array<T> Sort<T>::bubble(Array<T> to_sort) {
  size_t size = to_sort.size();
  for(size_t i{1}; i < size - 1; ++i) {
    for(size_t j{0}; j < size - i; ++j) {
      if(to_sort[j] > to_sort[j + 1]) {
        T temp = to_sort[j];
        to_sort[j] = to_sort[j + 1];
        to_sort[j + 1] = temp;
      }
    }
  }
  return to_sort;
}
