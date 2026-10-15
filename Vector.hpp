#ifndef Vector_HPP
#define Vector_HPP

#include<iostream>
#include<cstddef>
#include<utility>
#include<stdexcept>
using namespace std;
template<typename T>


class  Vector{
    private:
    T * data{nullptr};
    size_t size{0};
    size_t capacity{0};
    void reallocate(size_t new_capacity){
        T* new_data= new T[new_capacity];
        for(int i=0;i<size;i++)
            new_data[i]=std::move(data[i]);
        delete[] data;

        data=new_data;
        capacity=new_capacity;
    }
    public:
    Vector():size(0),data(nullptr),capacity(0){}
   
    ~Vector() {delete[] data;}
    
    Vector(const Vector& oth ):size(oth.size),capacity(oth.capacity){
     data= new T[capacity];
     for(int i=0;i<size;i++){
        data[i]=oth.data[i];
     }
    }
    Vector& operator =(const Vector& other){
        if(this!=other){
            delete[] data;

            size=other.size;
            capacity=other.capacity;
            data=new T[capacity];
            for(int i=0;i<size;i++){
               data[i]=other.data[i];
            }
        }
        return *this;
    }
    Vector(Vector&& other) noexcept 
        : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] data;

            data = other.data;
            size = other.size;
            capacity = other.capacity;

            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }
    T& operator[](size_t index){
        return data[index];
    }
    const T& operator[](size_t index)  const{ //const Vector օբյեկտների համար
        return data[index];
    }
   T& at(size_t index){
    if(index>=size)
    throw out_of_range("Vector index aut of range !");
    return data[index];
  }
  void push_back(T& value){
        if(capacity==size){
            size_t new_capacity=(capacity==0) ? 2 :capacity*2;
            reallocate(new_capacity);
        }
        data[size]=value;
        size++;
    }
    void push_back(T&& value){
        if(size==capacity){
        size_t new_capacity=(capacity==0) ? 2:capacity*2;
        reallocate(new_capacity);
        }
        data[size]=std::move(value);
        size++;
    }
    void pop_back(){
        if(size>0)
        size--;
    }

 size_t get_size() const noexcept{return size;}
 size_t get_capacity() const noexcept {return capacity;}
 bool empty() const noexcept {
    if(size==0)
    return true;
    return false;
}
};
 #endif