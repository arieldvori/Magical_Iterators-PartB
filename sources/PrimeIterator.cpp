#include "MagicalContainer.hpp"
#include <iostream>
using namespace std;
namespace ariel{
    // Prime

    bool isPrime(int num){
        // Corner case 
        if(num <= 1) 
            return false; 
        if (num == 2 || num == 3){
            return true;
        }
        // Check from 2 to n-1 
        for(int i = 2; i < num; i++) 
            if(num % i == 0) 
                return false; 

        return true; 
    }

    MagicalContainer::PrimeIterator::PrimeIterator()
            :_idx(0), _container(nullptr) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
            : _idx(other._idx), _container(other._container) {}

    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &other)
            : _idx(0), _container(&other) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other){
    if(_container != other._container){
        throw runtime_error("must point to the same container");
    }
    if(this != &other){
        _container = other._container;
        _idx = other._idx;
    }
    return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        if((_container == other._container) && (_idx == other._idx))
            return true;
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        if((_container == other._container) && (_idx > other._idx))
            return true;
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        if((_container == other._container) && (_idx < other._idx))
            return true;
        return false;
    }

    int MagicalContainer::PrimeIterator::operator*(){
        return *this->_container->p_prime[_idx];
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        if(_idx == end()._idx)
            throw runtime_error("no more elemnts cant keep moving");
        _idx++;
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
        PrimeIterator prime_iter(*_container);
        //cause it is the index of the last prime number 
        prime_iter._idx = _container->p_prime.size();
        return prime_iter;
    }

    bool compFunc(int *first, int *second){
        return *first < *second;
    }
}