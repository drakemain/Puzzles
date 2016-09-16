#include <iostream>
#include <sstream>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <cassert>
#include <math.h>

template <class T>
class Vector {
private:
  std::size_t length_ = 0;
  std::size_t capacity_ = 8;
  T* dataStore_ = nullptr;
  const unsigned int GROWTH_FACTOR = 2;

public:
  Vector() : dataStore_(new T[this->capacity_]{0}) {}

  Vector(std::initializer_list<T> list) 
  : dataStore_(new T[this->capacity_]{0}) {
    for (const T &item : list) {
      this->push(item);
    }
  }

  ~Vector() {
    delete[] this->dataStore_;
  }


  void push(T val) {
    if (this->length_ >= capacity_) {
      this->reserve(this->capacity_ + 1);
    }

    this->dataStore_[this->length_] = val;
    ++this->length_;
  }

  T pop() {
    if (this->length_ == 0) {
      throw std::out_of_range("Attempted pop on empty Vector.");
    }

    return this->dataStore_[length_--];
  }

  void reserve(unsigned int requestedCapacity) {
    unsigned int newCapacity = pow(2, ceil(log2(requestedCapacity)));

    if (newCapacity <= this->capacity_) {
      return;
    }

    this->capacity_ = newCapacity;
    T *temp = this->dataStore_;
    this->dataStore_ = new T[this->capacity_];

    for (unsigned int i = 0; i < this->length_; ++i) {
      this->dataStore_[i] = temp[i];
    }

    delete[] temp;
  }

  void toOstream(std::ostream &stream) const {
    stream << "[";  

    for (unsigned int i = 0; i < this->length_; ++i) {
      stream << this->dataStore_[i];

      if (i < this->length_ - 1) {
        stream << ", ";
      }
    }

    stream << "]";
  }

  T& operator[](unsigned int index) {
    return this->dataStore_[index];
  }

  T& operator[](int index) {
    return this->dataStore_[index];
  }

  unsigned int length() const {
    return this->length_;
  }

  unsigned int capacity() const {
    return this->capacity_;
  }
};


template <typename T>
void test_expected_values(const Vector<T> &vector, const std::string &expectedString);
template <typename Function>
void test_throws_exception(Function func);

void test_normal_push() {
  Vector<int> push_vector{1, 2, 3};
  push_vector.push(4);
  test_expected_values(push_vector, "[1, 2, 3, 4]");
}

void test_empty_push() {
  Vector<int> push_vector_empty{};
  push_vector_empty.push(1);
  test_expected_values(push_vector_empty, "[1]");
}

void test_full_push_doubles_capacity() {
  Vector<int> push_vector_full{1, 2, 3, 4, 5, 6, 7, 8};
  assert(push_vector_full.capacity() == push_vector_full.length());

  unsigned int previousCapacity = push_vector_full.capacity();

  push_vector_full.push(9);

  assert(push_vector_full.capacity() == previousCapacity * 2);
  test_expected_values(push_vector_full, "[1, 2, 3, 4, 5, 6, 7, 8, 9]");
}

void test_normal_pop() {
  Vector<int> pop_vector{1};
  pop_vector.pop();
  test_expected_values(pop_vector, "[]");
}

void test_empty_pop_throws_exception() {
  Vector<int> empty_pop_vector{};
  test_throws_exception([&] { empty_pop_vector.pop(); });
}

void test_base_two_reserve() {
  Vector<int> reserve_vector{1, 2, 3};
  assert(reserve_vector.capacity() == 8); 

  reserve_vector.reserve(256);
  assert(reserve_vector.capacity() == 256);
  test_expected_values(reserve_vector, "[1, 2, 3]");
}

void test_non_base_two_reserve() {
  Vector<int> reserve_vector{1, 2, 3};
  assert(reserve_vector.capacity() == 8); 

  reserve_vector.reserve(257);
  assert(reserve_vector.capacity() == 512);
  test_expected_values(reserve_vector, "[1, 2, 3]");
}

void test_get_value() {
  Vector<int> index_retrieval_vector{1, 2, 3, 4, 5};
  
  assert(index_retrieval_vector[2] == 3);
}

void test_modify_value() {
  Vector<int> index_modify_vector{1, 2, 3, 4, 5};

  index_modify_vector[2] = 10;

  assert(index_modify_vector[2] == 10);
}

int main() {
  // test push
  test_normal_push();
  test_empty_push();
  test_full_push_doubles_capacity();

  // test pop
  test_normal_pop();
  test_empty_pop_throws_exception();

  // test reserve
  test_base_two_reserve();
  test_non_base_two_reserve();

  // test getting values at specific index
  test_get_value();
  test_modify_value();

  std::cout << std::endl << "All tests passed" << std::endl;
};

template <typename T>
void test_expected_values(const Vector<T> &vector, const std::string &expectedString) {
  std::ostringstream vectorValues;
  vector.toOstream(vectorValues);
  assert(vectorValues.str() == expectedString);
}

template <typename Function>
void test_throws_exception(Function func) {
  bool threw = false;

  try {
    func();
  } catch(...) {
    threw = true;
  }

  assert(threw);
}