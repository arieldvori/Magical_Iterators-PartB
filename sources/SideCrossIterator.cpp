#include "MagicalContainer.hpp"
#include <iostream>
using namespace std;
namespace ariel{

    // SideCross

    MagicalContainer::SideCrossIterator::SideCrossIterator()
            :_idx(0),_container(nullptr) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
            :_idx(other._idx),_container(other._container) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &other)
            :_idx(0) ,_container(&other) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other){
        if(_container != other._container){
            throw runtime_error("must point to the same container");
        }
        if(this != &other){
            _idx = other._idx;
            _container = other._container;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        if((_container == other._container) && (_idx == other._idx))
            return true;
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        if((_container == other._container) && (_idx > other._idx))
            return true;
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        if((_container == other._container) && (_idx < other._idx))
            return true;
        return false;
    }

    int MagicalContainer::SideCrossIterator::operator*(){
        return _container->mystical_elements[_idx];
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if(_idx == end()._idx)
            throw runtime_error("no more elemnts cant keep moving");
        if(_idx == (_container->mystical_elements.size() / 2)){
            _idx = _container->mystical_elements.size();
            return *this;
        }
        if(_idx < (_container->mystical_elements.size() / 2)){
            _idx = _container->mystical_elements.size() - _idx - 1;
            return *this;
        }
        else if(_idx > (_container->mystical_elements.size() / 2)){
            _idx = _container->mystical_elements.size() - _idx;
            return *this;
        }
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
        _idx = 0;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
        SideCrossIterator side_iter(*_container);
        side_iter._idx = (_container->mystical_elements.size());
        return side_iter;
    }
}
