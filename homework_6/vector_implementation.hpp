

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class My_Vector{

private:  
    T *data_;
    size_t capacity_;
    size_t size_;
public:
    My_Vector(){
        size_= 0;
        capacity_ = 0;
    }

    My_Vector (size_t size); 
    ~My_Vector();


    size_t size_();
    void resize(size_t n, T value);
    size_t capacity();
    bool empty();
    void reserve(size_t n);
    void shrink_to_fit();

    T& operator[] (size_t index);
    const T& operator[] (size_t  index) const;
    T& at(size_t index);
    T& front();
    T& back();
    T* data();

    void push_back(T value);
    void pop_back();
    void insert(size_t position, T value);
    void erase(size_t position);
    void swap(size_t position1, size_t position2);
    void clear();

    class My_Iterator {
    private:
        T* my_iter;
    public:
        My_Iterator(T* p) { my_iter = p;}

        My_Iterator& operator++() { ++my_iter; return *this; }
        My_Iterator operator++(int){ My_Iterator temp = *this; ++my_iter; return temp; } 
        My_Iterator& operator--() { --my_iter; return *this; }
        T& operator*() { return *my_iter; }
        const T& operator*() const { return *my_iter; }
        bool operator==(const My_Iterator& other) const { return my_iter == other.my_iter; }
        bool operator!=(const My_Iterator& other) const { return !(*this == other); }
    };

     My_Iterator begin();
     My_Iterator end();

};




template <typename T>
size_t My_Vector<T>:: size_() {
    return size_;
}

template <typename T>
size_t My_Vector<T>:: capacity() {
    return capacity_;
}
template <typename T>
 My_Vector<T>::My_Vector (size_t size) {
    this->size_ = size;
    this->capacity_ = size;

    data_ = (T*) malloc(sizeof(T) * capacity_ > 0 ? capacity_ : 1);
    if(data_ == NULL) {
        std::cerr << "Bad allocation" << std::endl;
        return;
    }
 }

template <typename T>
My_Vector<T>:: ~My_Vector () {
    free(_data);
    data_ = NULL;
}

template <typename T>
void My_Vector<T>:: push_back(T value){
    if(size_ >= capacity_) {
        if(capacity_ == 0) capacity_ = 1;
        else capacity_ *= 2;

        T* temp = (T*)realloc(data_, sizeof(T)*capacity_);
        if (temp == NULL) {
            temp = (T*) malloc(sizeof(T) * capacity_);
            if(temp == NULL) {
                std::cerr << "Bad allocation" << std::endl;
                return;
            }
            for (size_t i = 0; i < size_; ++i) {
                temp[i] = data_[i];
            }
            free(data_);
        }
        data_ = temp;
        temp = NULL;
    }
    data_[size_] = value;
    ++size_;
}

template <typename T>
void My_Vector<T>:: pop_back(){
    if(size_ > 0) --size_;
}

template <typename T>
void My_Vector<T>:: insert(size_t position, T value){
    if(position > size_) return;
     if (size_ >= capacity_) {
         if(capacity_ == 0) capacity_ = 1;
         else capacity_ *= 2;

        T* temp = (T*)realloc(data_, sizeof(T) * capacity_);

        if (temp == NULL) {
            temp = (T*) malloc(sizeof(T) * capacity_);
            if(temp == NULL) {
                std::cerr << "Bad allocation" << std::endl;
                return;
            }

            for (size_t i = 0; i < position; ++i) {
                temp[i] = data_[i];
            }
            temp[position] = value;
            for (size_t i = position + 1; i < size_ + 1; ++i) {
                temp[i] = data_[i - 1];
            }

            free(data_);
            data_ = temp;
            temp = NULL;
            ++size_;
            
            return;
        }

        data_ = temp;
        temp = NULL;
    }
    
    for (size_t i = size_ - 1; i >= position; --i) {
        data_[i + 1] = data_[i];
    }
    data_[position] = value;

    ++size_;
    
}

template <typename T>
void My_Vector<T>:: erase(size_t position){
    if(position >= size_) return;
    for(size_t i = position; i < size_ - 1; ++i){
        data_[i] = data_[i+1];
    }
    --size_;
}

template <typename T>
void My_Vector<T>:: swap(size_t position1, size_t position2){
    T temp = data_[position1];
    data_[position1] = data_[position2];
    data_[position2] = temp;
}

template <typename T>
void My_Vector<T>:: clear(){
    size_ = 0;
}

template <typename T>
T& My_Vector<T>::operator[] (size_t index) {
    if(index < size_) {
        return data_[index];
    }
}

template <typename T>
const T& My_Vector<T>::operator[] (size_t index) const{
    if(index < size_) {
        return data_[index];
    }
}

template <typename T>
bool My_Vector<T>:: empty(){
    if(size_ == 0) return true;
    else return false;
}

template <typename T>
void My_Vector<T>:: reserve(size_t n){
    if (n > capacity_)
        capacity_ = n;

    T* temp = (T*)realloc(data_, sizeof(T) * capacity_);

     if (temp == NULL) {
            temp = (T*) malloc(sizeof(T) * capacity_);
            if(temp == NULL) {
                std::cerr << "Bad allocation" << std::endl;
                return;
            }
    for (size_t i = 0; i < position; ++i) {
                temp[i] = data_[i];
            }
    free(data_);
    }
   
    data_ = temp;
    temp = NULL;
}

template <typename T>
void My_Vector<T>:: shrink_to_fit(){
    if(capacity_ != size_){ 
     capacity_ = size_;
     T* temp = (T*)realloc(data_, sizeof(T) * capacity_);

     if (temp == NULL) {
            temp = (T*) malloc(sizeof(T) * capacity_);
            if(temp == NULL) {
                std::cerr << "Bad allocation" << std::endl;
                return;
            }
    for (size_t i = 0; i < position; ++i) {
                temp[i] = data_[i];
            }
    free(data_);
    }
   
    data_ = temp;
    temp = NULL;
    }
}

template <typename T>
T& My_Vector<T>::at (size_t index) {
    if(index < size_) {
        return data_[index];
    }
    else throw std::out_of_range("Bad allocation");
}

template <typename T>
T& My_Vector<T>::front (){
    return data_[0];
}

template <typename T>
T& My_Vector<T>::back(){
    return data_[size_-1];
}

template <typename  T>
T* My_Vector<T>:: data(){
    return data_;
}

template <typename T>
void My_Vector<T>::resize (size_t n, T value){
    if(n < size_){ 
        size_  =  n;
    }
    else {
        for(size_t i = 0; i  < n - size_; ++i){
            push_back(value);
        }
    }
}

template <typename T>
typename My_Vector<T>::My_Iterator My_Vector<T>::begin() {
        return My_Iterator(data_);
    }

template <typename T>
typename My_Vector<T>::My_Iterator My_Vector<T>::end() {
    return My_Iterator(data_ + size_);
}


#endif //VECTOR_HPP