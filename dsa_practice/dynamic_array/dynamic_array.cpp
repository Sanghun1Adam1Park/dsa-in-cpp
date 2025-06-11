//
//  dynamic_array.cpp
//  dsa_practice
//
//  Created by Sanghun Park on 07/06/2025.
//

#include "dynamic_array.hpp"
#include <stdexcept>

class DynamicArray {
private:
  size_t capacity;
  size_t size;
  int* memory;
    
public:
  DynamicArray(size_t capacity) :
  capacity(capacity), size(0), memory(new int[capacity]) {
    if (capacity == 0) {
      throw std::invalid_argument("Capacity must be at least 1");
    }
  }
  
  /**
   Copy constructor
   */
  DynamicArray(const DynamicArray& other) :
  capacity(other.capacity), size(other.size), memory(new int[other.capacity]) {
    for (size_t i = 0; i < size; ++i)
      memory[i] = other.memory[i];
  }
  
  // TODO: add move constructor
  
  /**
   Make sure to free the memory after deconstruction.
   */
  ~DynamicArray() {
    delete [] memory;
  }
  
  /**
   '&&' operator.
   */
  DynamicArray& operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] memory;                  // (1) free current memory (this->memory)
        capacity = other.capacity;
        size = other.size;
        memory = new int[capacity];       // (2) allocate new memory for this->memory
      for (size_t i = 0; i < size; ++i) { // (3) copy values
        memory[i] = other.memory[i];
      }
    }
    
    return *this; // (4) return address of this
  }

  // TODO: Add move operator
  
  int get(int i) {
    if (i < 0 || static_cast<size_t>(i) >= size) {
      throw std::out_of_range("Index out of range.");
    }
    return memory[i];
  }

  void set(int i, int n) {
    if (i < 0 || static_cast<size_t>(i) > size) {
      throw std::out_of_range("Index out of range.");
    }

    memory[i] = n;
  }

  void pushback(int n) {
    if (size == capacity) resize();
    
    memory[size] = n;
    size++;
  }

  int popback() {
    if (size == 0) throw std::underflow_error("Cannot pop from empty array");
    
    if (size > 0) size--;
    int elem = memory[size];
    return elem;
  }

  void resize() {
    capacity *= 2; // Double capcity
    int* new_array = new int[capacity]; // Allocase new doubled array
    for (size_t i = 0; i < size; ++i) { // Copy the element
      new_array[i] = memory[i];
    }
    delete [] memory;
    memory = new_array;
  }

  int getSize() {
    return static_cast<int>(size);
  }

  int getCapacity() {
    return static_cast<int>(capacity);
  }
};
