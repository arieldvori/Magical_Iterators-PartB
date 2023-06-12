#pragma once

#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

namespace ariel{
    //classic isPrime func
    bool isPrime(int num);
    //func for simply compering two int pointers
    bool compFunc(int *first, int *second);
    class MagicalContainer{
    private:
        vector<int> mystical_elements;
        //vector to save the prime numbers in the mystical_elements
        vector<int*> p_prime;

    public:
        MagicalContainer();
        void addElement(int new_element);
        void removeElement(int past_element);
        int size();
        ~MagicalContainer();

        // Ascending Iterator class
        class AscendingIterator{
        private:
            size_t _idx;
            const MagicalContainer *_container;

        public:
            AscendingIterator();//default cons
            AscendingIterator(const AscendingIterator &other); //copy cons
            AscendingIterator(const MagicalContainer &other); //cons who gets the container
            ~AscendingIterator();//distractor
            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*();
            AscendingIterator& operator++();
            AscendingIterator begin();
            AscendingIterator end();
        };

        // SideCross Iterator class
        class SideCrossIterator {
        private:
            const MagicalContainer *_container;
            size_t _idx;

        public:
            SideCrossIterator();
            SideCrossIterator(const SideCrossIterator &other);
            SideCrossIterator(const MagicalContainer &other);
            ~SideCrossIterator();
            SideCrossIterator& operator=(const SideCrossIterator &other);

            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*();
            SideCrossIterator& operator++();
            SideCrossIterator begin();
            SideCrossIterator end();
        };

        // Prime Iterator class
        class PrimeIterator {
        private:
            const MagicalContainer *_container;
            size_t _idx;

        public:
            PrimeIterator();
            PrimeIterator(const PrimeIterator &other);
            PrimeIterator(const MagicalContainer &other);
            ~PrimeIterator();
            PrimeIterator& operator=(const PrimeIterator &other);

            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*();
            PrimeIterator& operator++();
            PrimeIterator begin();
            PrimeIterator end();
        };
    };
}