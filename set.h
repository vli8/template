//Victor Li
//This is the header for the Set lab which will be included
//in the cpp file. This header file will have the signatures
//for the compiler to acknowledge.
//july 28th

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
template <class T>
class Set{
        friend istream& operator>>(istream &, Set<T> &);
        friend ostream& operator<<(ostream &, const Set<T> &);

                public:
                        Set(int = DEFAULT_SIZE);
                        Set(T[], int, char);
                        Set(const Set<T>&);
                        ~Set();
                        bool add(T);
                        Set<T> operator+(const Set<T> &);
                        Set<T> operator-(const Set<T> &);
                        Set<T> operator^(const Set<T> &);
                        bool operator==(const Set<T> &);
                        bool operator!=(const Set<T> &);
                        Set<T> Union(const Set<T> &);
                        Set<T> Intersection(const Set<T> &);
                        Set<T> Difference(const Set<T> &);
                        bool equality(const Set<T> &);
                        bool inequality(const Set<T> &);
                        bool element(T);//to check if the element is in array
                        void input();
                        int getpSize();
                        int getnumElements();
                        int getDELIM(); 
                        int numElements;//represent the # elements in s
                        int pSize; //Data members that will tell us size of arrays
                        static const int DELIM = -999;
                        T *set = new T [DEFAULT_SIZE];
    
                private:
                        char name;//names of the sets
                        static const int GROWSIZE = 10;
                        static const int DEFAULT_SIZE = 10;//represent the default value used to dynamically allocate memory
        };

