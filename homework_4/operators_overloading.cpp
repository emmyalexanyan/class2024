#include<iostream>
#include<vector>

template <typename T>
void Print(std::string message, std::vector<T> op) {
 std::cout << message << ": ";
 for (T i : op) {
  std::cout << i << " ";
 }
 std::cout << std::endl;
}

template <typename T>
std::vector<T> operator+ (const std::vector<T>& v1, const std::vector<T>& v2) {
 if (v1.size() != v2.size()) {
  std::cout << "Vectors must have same size" << std::endl;
 }
  std::vector<T> v;
  v.reserve(v1.size());

  for (size_t i = 0; i < v1.size(); ++i) {
   v.push_back(v1[i] + v2[i]);
  }
 return v;
}

template <typename T>
std::vector<int> operator- (const std::vector<T>& v1, const std::vector<T>& v2) {
 if (v1.size() != v2.size()) {
  std::cout << "Vectors must have same size" << std::endl;
 }
 std::vector<T> v;
 v.reserve(v1.size());
 for (size_t i = 0; i < v1.size(); ++i) {
  v.push_back(v1[i] - v2[i]);
 }
 return v;
}

template <typename T>
std::vector<T> operator* (const std::vector<T>& v1, const std::vector<T>& v2) {
 if (v1.size() != v2.size()) {
  std::cout << "Vectors must have same size" << std::endl;
 }
 std::vector<T> v;
 v.reserve(v1.size());
 for (size_t i = 0; i < v1.size(); ++i) {
  v.push_back(v1[i] * v2[i]);
 }
 return v;
}

template <typename T>
std::vector<T> operator/ (const std::vector<T>& v1, const std::vector<T>& v2) {
 if (v1.size() != v2.size()) {
  std::cout << "Vectors must have same size" << std::endl;
 }
 std::vector<T> v;
 v.reserve(v1.size());

 for (size_t i = 0; i < v1.size(); ++i) {
  if (v2[i] == 0) {
   std::cout << "Invalid argument" << std::endl;
  }
  v.push_back(v1[i] / v2[i]);
 }
 return v;
}

std::vector<int> operator% (const std::vector<int>& v1, const std::vector<int>& v2) {
 if (v1.size() != v2.size()) {
  std::cout << "Vectors must have same size" << std::endl;
 }
 std::vector<int> v;
 v.reserve(v1.size());
 for (size_t i = 0; i < v1.size(); ++i) {
  if (v2[i] == 0) {
   std::cout << "Invalid argument" << std::endl;
  }
    v.push_back(v1[i] % v2[i]);
    }
    return v;
}

template <typename T>
void operator++(std::vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        ++v[i];
    }
}

template <typename T>
std::vector<T> operator++(std::vector<T>& v, int a) {
    std::vector<T> tmp_v = v;
    for (size_t i = 0; i < v.size(); ++i) {
        v[i]++;
    }
    return tmp_v;
}

template <typename T>
void operator +=(std::vector<T>& v1, const std::vector<T>& v2) {
 if (v1.size() != v2.size()) {
  std::cout << "Vectors must have same size" << std::endl;
 }
 
 for (size_t i = 0; i < v1.size(); ++i) {
  v1[i] += v2[i];
 }
}
