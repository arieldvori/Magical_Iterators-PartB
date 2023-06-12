#include "MagicalContainer.hpp"
#include <iostream>
using namespace std;
namespace ariel{
    // Ascending 

    MagicalContainer::AscendingIterator::AscendingIterator()
            :  _idx(0),_container(nullptr) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
            : _idx(other._idx), _container(other._container)  {}

    MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &other)
            :  _idx(0),_container(&other) {}
    
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other){
        if(_container != other._container){
            throw runtime_error("must point to the same container");
        }
        if(this != &other){
            _idx = other._idx;
            _container = other._container;   
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        if((_container == other._container) && (_idx == other._idx))
            return true;
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        if((_container == other._container) && (_idx > other._idx))
            return true;
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        if((_container == other._container) && (_idx < other._idx))
            return true;
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*(){
        return _container->mystical_elements[_idx];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        if(_idx == end()._idx)
            throw runtime_error("no more elemnts cant keep moving");
        _idx++;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
        AscendingIterator asc_iter(*_container);
        asc_iter._idx = _container->mystical_elements.size();
        return asc_iter;
    }

}