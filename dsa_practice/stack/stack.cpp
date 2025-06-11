//
//  stack.cpp
//  dsa_practice
//
//  Created by Sanghun Park on 11/06/2025.
//

#include "stack.hpp"

class MinStack {
  private:
    size_t capacity;
    int* stack;
    int* minstack;
    size_t size;
  
    void resize() {
      capacity *=2;
      int* new_stack = new int[capacity];
      int* new_min = new int[capacity];
      for (int i = 0; i < size; ++i) {
        new_stack[i] = stack[i];
        new_min[i] = minstack[i];
      }
      delete[] stack;
      delete[] minstack;
      stack = new_stack;
      minstack = new_min;
    }
  public:
    MinStack() :
    capacity(1), stack(new int[capacity]), minstack(new int[capacity]), size(0) {}
    
    MinStack(const MinStack& other) :
    capacity(other.capacity), stack(new int[capacity]), minstack(new int[capacity]), size(other.size) {
      for (int i = 0; i < size; ++i) {
        stack[i] = other.stack[i];
        minstack[i] = other.minstack[1];
      }
    }
      
   // TODO: add move constructor
  
    ~MinStack() {
        delete[] stack;
        delete[] minstack;
    }
  
    // TODO: Add copy operator
  
    // TODO: Add move operator
    
    void push(int val) {
      if (capacity == size) {
        resize();
      }
      
      stack[size] = val;
      int min = getMin();
      if (size == 0 || (val < min)) minstack[size] = val;
      else minstack[size] = min;
      size++;
    }
    
    void pop() { // Soft delete
      if (size > 0) --size;
    }
    
    int top() {
      return stack[size];
    }
    
    int getMin() {
      return minstack[size];
    }
};
