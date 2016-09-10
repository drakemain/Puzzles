#include <iostream>
#include <sstream>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <cassert>

template <class T>
class Vector {
private:
  unsigned int length = 0;
  unsigned int capacity = 8;
  T* dataStore = nullptr;

public:
  Vector() : dataStore(new T[this->capacity]{0}) {}

  Vector(std::initializer_list<T> list) 
  : dataStore(new T[this->capacity]{0}) {
    for (const T &item : list) {
      this->push(item);
    }
  }

  ~Vector() {
    delete[] this->dataStore;
  }


  void push(T val) {
    if (this->length >= capacity) {
      throw std::out_of_range("Vector capacity exceeded.");
    }

    this->dataStore[this->length] = val;
    ++this->length;
  }

  T pop() {
    if (this->length == 0) {
      throw std::out_of_range("Attempted pop on empty Vector.");
    }

    return this->dataStore[length--];
  }

  unsigned int len() const{
    return this->length;
  }

  unsigned int cap() const{
    return this->capacity;
  }

  void toOstream(std::ostream &stream) const {
    stream << "[";  

    for (unsigned int i = 0; i < this->length; i++) {
      stream << this->dataStore[i];

      if (i < this->length - 1) {
        stream << ", ";
      }
    }

    stream << "]";
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
  push_vector.push(1234);
  test_expected_values(push_vector, "[1, 2, 3, 4, 1234]");
}

void test_empty_push() {
  Vector<int> push_vector_empty{};
  push_vector_empty.push(1);
  test_expected_values(push_vector_empty, "[1]");
}

void test_full_push_throws_exception() {
  Vector<int> push_vector_full{1, 2, 3, 4, 5, 6, 7, 8};
  assert(push_vector_full.cap() == push_vector_full.len());

  test_throws_exception([&] {push_vector_full.push(9); });
}

void test_normal_pop() {
  Vector<int> pop_vector{1};
  pop_vector.pop();
  test_expected_values(pop_vector, "[]");
}

void test_empty_pop_throws_exception() {
  Vector<int> empty_pop_vector{};
  test_throws_exception([&] {empty_pop_vector.pop(); });
}

int main() {
  // test push
  test_normal_push();
  test_empty_push();
  test_full_push_throws_exception();

  // test pop
  test_normal_pop();
  test_empty_pop_throws_exception();

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