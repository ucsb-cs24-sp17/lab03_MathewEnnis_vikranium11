// words2.cpp - implements class Words
// Vikram Tharakan and Mathew Ennis 4/25/17

#include <cassert>
#include <string>
#include <algorithm>
#include "words2.h"

using std::string;

namespace lab03_2
{
  Words::Words(unsigned int initial_capacity){
    used = 0;
    capacity = initial_capacity;
    data = new std::string[capacity];
  }
  
  Words::~Words() {
    delete [] data;
  }
  
  Words::Words(const Words &source){
    used = source.used;
    capacity = source.capacity;
    data = new std::string[source.capacity];
    copy(source.data, source.data+used, data);
    //Has to make deep copy, given initial input "words"
  }

  Words& Words::operator=(const Words &source){
    std::string *new_data;

    //First case is for the situation that b=b
    if(this == &source)
      return *this;

    //If the length of the two arrays are not the same
    if(capacity != source.capacity){
      new_data = new std::string[source.capacity];
      delete [] data;
      data = new_data;
      capacity = source.capacity;
    }
    used = source.used;
    copy(source.data, source.data+used, data);
  }
  
  
  void Words::append(string word) {
    if(used == capacity){
      capacity = capacity*2;
      std::string *larger_array;
      larger_array = new std::string[capacity];
      copy(data, data+used, larger_array);
      delete [] data;
      data = larger_array;
    }
      data[used] = word;
      ++used;
  }
  
  string& Words::operator[] (unsigned int index) {
    assert(index < used);
        return data[index];
  }
  
  unsigned int Words::size() const {
    return used;
  }
  
  unsigned int Words::get_capacity() const {
    return capacity;
  }
  
  string Words::operator[] (unsigned int index) const {
    assert(index < used);
        return data[index];
  }
  
}
