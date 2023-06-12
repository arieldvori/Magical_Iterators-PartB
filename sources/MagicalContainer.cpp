#include "MagicalContainer.hpp"
#include <iostream>
using namespace std;
namespace ariel{

    MagicalContainer::MagicalContainer() {}

    void MagicalContainer::addElement(int new_element){
        //return an iterator pointing to the first element which has a value higher or equal than new_element
        auto iter = lower_bound(mystical_elements.begin(), mystical_elements.end(), new_element);
        mystical_elements.insert(iter, new_element);

        //if new_element is prime, insert a pointer of it to the p_prime vector
        if(isPrime(new_element)==true){
            int *prime_element = new int(new_element);
            auto it_prime = lower_bound(p_prime.begin(), p_prime.end(), prime_element,compFunc);
            p_prime.insert(it_prime, prime_element);
        }
    }

    //works for prime number too because it is vector of pointer to the original vector
    void MagicalContainer::removeElement(int past_element){
        //flag var
        int isIn = 0;
        for(auto it = mystical_elements.begin(); it != mystical_elements.end(); ++it){
            if(*it == past_element){
                mystical_elements.erase(it);
                isIn = 1;
                break;
            }
        }
        if(isIn == 0)
            throw runtime_error("cant delete unexist element");
    }

    int MagicalContainer::size(){
        return mystical_elements.size();
    }

    MagicalContainer::~MagicalContainer() {}
}