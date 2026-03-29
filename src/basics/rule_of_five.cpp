/*
Goal: understand shallow copy vs deep copy and the Rule of 5.
Key takeaways:
- Owning raw pointers need custom copy/move behavior.
- Copy duplicates resources; move transfers ownership.
- After a move, the source must stay valid but empty/safe.
Notes: see notes/rule_of_five.md for the mental model.
*/
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

class ShallowArray {
public:
  static constexpr std::size_t kSize = 5;

  ShallowArray() {
    data_ = new int[kSize];
    for (std::size_t i = 0; i < kSize; i++) {
      data_[i] = static_cast<int>(i);
    }
  }

  ~ShallowArray() { delete[] data_; }

  void Set(std::size_t index, int value) { data_[index] = value; }
  void Print(const char *label) const {
    std::cout << label << ": ";
    for (std::size_t i = 0; i < kSize; i++) {
      std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
  }

private:
  // Default copying only copies this address value, not the pointed array.
  int *data_;
};

class DeepArray {
public:
  static constexpr std::size_t kSize = 5;

  DeepArray() : data_(new int[kSize]) {
    std::cout << "default constructor" << std::endl;
    for (std::size_t i = 0; i < kSize; i++) {
      data_[i] = static_cast<int>(i * i);
    }
  }

  ~DeepArray() {
    delete[] data_;
    std::cout << "destructor" << std::endl;
  }

  DeepArray(const DeepArray &other) : data_(new int[kSize]) {
    std::cout << "copy constructor" << std::endl;
    // Deep copy: allocate our own storage, then copy the values.
    std::copy(other.data_, other.data_ + kSize, data_);
  }

  DeepArray &operator=(const DeepArray &other) {
    std::cout << "copy assignment" << std::endl;
    if (this == &other) {
      return *this;
    }

    // Copy assignment replaces already-owned memory safely.
    int *new_data = new int[kSize];
    std::copy(other.data_, other.data_ + kSize, new_data);
    delete[] data_;
    data_ = new_data;
    return *this;
  }

  DeepArray(DeepArray &&other) noexcept : data_(other.data_) {
    std::cout << "move constructor" << std::endl;
    // Move steals the pointer instead of duplicating the array.
    other.data_ = nullptr;
  }

  DeepArray &operator=(DeepArray &&other) noexcept {
    std::cout << "move assignment" << std::endl;
    if (this == &other) {
      return *this;
    }

    // Move assignment frees current storage, then steals from the source.
    delete[] data_;
    data_ = other.data_;
    other.data_ = nullptr;
    return *this;
  }

  void Set(std::size_t index, int value) { data_[index] = value; }

  void Print(const char *label) const {
    std::cout << label << ": ";
    if (data_ == nullptr) {
      std::cout << "<moved-from>" << std::endl;
      return;
    }

    for (std::size_t i = 0; i < kSize; i++) {
      std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
  }

private:
  int *data_;
};

int main() {
  // Uncomment this block to see shallow-copy aliasing and double-free risk.
  /*
  ShallowArray shallow_a;
  ShallowArray shallow_b = shallow_a; // both objects now store the same address
  shallow_b.Set(0, 99);
  shallow_a.Print("shallow_a");
  shallow_b.Print("shallow_b");
  */

  DeepArray original;
  original.Set(0, 100);
  original.Print("original");

  DeepArray copied = original; // copy constructor: creates a new object from original
  copied.Set(1, 200);
  original.Print("original after copy");
  copied.Print("copied");

  DeepArray assigned;
  assigned = original; // copy assignment: replaces contents of an existing object
  assigned.Set(2, 300);
  original.Print("original after assignment");
  assigned.Print("assigned");

  std::vector<DeepArray> arrays;
  arrays.reserve(2);

  DeepArray temp;
  arrays.push_back(std::move(temp)); // move constructor into vector storage
  temp.Print("temp after move");

  arrays.push_back(DeepArray{}); // temporary can also move

  return 0;
}
