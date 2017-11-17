//Victor Li
//This is the source code file in which contains the header file Set. 
//Writing the methods and constructors provided in the header file Set.
//July 28th


#include "set.h"

        template <class T>
        Set<T>::Set(int size ){//Default constructor)
                pSize = numElements = 0;
                set = NULL;

                if ( size > pSize) {
                        set = new T[size];//initializing template so that it can take any datatype
                        pSize = size;

                        // loop to initialize each element
                        for(int i = 0; i <pSize; i++)
                                set[i];
                }

        }

        //Custom Constructor to define all data members
        template <class T>
        Set<T>::Set(T a[],  int num,  char letter) : Set(num) {
                name = letter;

                // loop to initialize set from a
                for (int i=0; i < num; i++){
                        set[i] = a[i];
                }
        }

        //Accessor
        template <class T>
        int Set<T>:: getpSize(){
                return(pSize);
        }

        //Copy Constructor
        template <class T>
        Set<T>::Set(const Set<T> &a) : Set( a.numElements ) {

                *this = a;
        }
        //Destructor
        template <class T>
        Set<T>::~Set(){
                if ( set )
                        delete [] set;
        }

        //Template e is to take into all datatypes when the array is added more elements
        template <class T>
        bool Set<T>::add( T e ) {

                bool status = false;

                if ( e != DELIM ) {

                        // Check if elements is filled with actual size
                        if ( numElements == pSize ) {
                                // Need to allocate more memory, we set it equal to 10 as a guess
                                int newSize = pSize + GROWSIZE;
                                T *nptr = new T [newSize];

                                if ( !nptr ) {
                                        cout << "Error: Memory allocation failed, exiting program." << endl;
                                        pSize = 0;
                                        exit(1);
                                }

                        if ( set ) {
                        // copy over all the elements of the current array to the newly created array
                                for ( int i = 0; i < numElements; i++ )
                                        nptr[i] = set[i];

                                delete [] set;
                                set = NULL;
                        }

                        // Assign the array pointer to the newly created array
                                set = nptr;
                        }

                //  increment the numElements
                set[ numElements++ ] = e;

                status = true;
                }

        return( status );
        }


        template <class T>
        bool Set<T>::element(T a){
                int i;
                bool status = true;
                if(a != set[i]){
                        status = false;
                }
                return(status);
        }

        //input method to ask the user to name the array
        template < class T>
        void Set<T>::input(){
                char letter;
                T num;

                cout << "Please enter the name of the set (one letter): " ;
                cin >> letter;
                cout << "How many elements in your set of numbers: ";
                cin >> num;
        }


        //operator overload for union
        template <class T>
        Set<T> Set<T>::operator+(const Set<T> &b) {

                return( this->Union(b) );
        }

        template <class T>
        Set<T> Set<T>::Union(const Set<T> &a) {
                Set<T> C = *this; //new Set<T>(*this);

                for (int i = 0; i<a.numElements; i++){
                        C.add(a.set[i]);
                }

                return(C);
        }

        //operator overload for intersection
        template <class T>
        Set<T> Set<T>::operator^(const Set<T> &a){

                return(this->Intersection(a));

        }

        template <class T>
        Set<T> Set<T>::Intersection(const Set<T> &a){

                Set C=*this;
                for(int i = 0; i<a.numElements; i++){
                        C.element(a.set[i]);
                }
                return(C);
        }

        //operator overload for difference
        template <class T>
        Set<T> Set<T>:: operator-(const Set<T> &a){

                return(this->Difference(a));

        }

        template <class T>
        Set<T> Set<T>::Difference(const Set<T> &a){
                Set C= *this;
                for (int i = 0; i < a.numElements; i++){
                        !C.element(a.set[i]);
                }
                return(C);
        }
        //operator overload for difference
        template <class T>
        Set<T> Set<T>:: operator-(const Set<T> &a){

                return(this->Difference(a));

        }

        template <class T>
        Set<T> Set<T>::Difference(const Set<T> &a){
                Set C= *this;
                for (int i = 0; i < a.numElements; i++){
                        !C.element(a.set[i]);
                }
                return(C);
        }

        //operator overload for equality
        template <class T>
        bool Set<T>::operator == (const Set<T>& a){

                return(this-> equality(a));

        }

        template <class T>
        bool Set<T>::equality(const Set<T>& a){
                bool status = true;

                if ( numElements == a.numElements ) {
                        for ( int i = 0; i < numElements; i++ )
                                if ( set[ i ] != a.set[ i ] ){
                                        status = false;
                                        break;
                                }
                } else
                        status = false;

                return( status );
        }

        //operator overload for inequality
        template <class T>
        bool Set<T>::operator != (const Set<T>& a){

                return(this-> inequality(a));

        }

        template <class T>
        bool Set<T>::inequality(const Set<T>& a){
                bool status = false;

        if ( numElements == a.numElements ) {
                for ( int i = 0; i < numElements; i++ )
                        if ( set[ i ] != a.set[ i ] ){
                                status = true;
                                break;
                        }
        } else
                status = true;

                return( status );
        }


        template <class T>
        istream &operator>>( istream &input, Set<T> &a ) {

                int ival;
                //a.input() possible option to call the method in the operator overload on an object
                cout << "Enter elements to store in the array: " << Set<T>::DELIM << " to stop : ";
                do {
                        input >> ival;
                } while ( a.add( ival ) );



                return input;

        }

        template <class T>
        ostream &operator<<( ostream &output, const Set<T> &a) {
                int i;

                output << "Array size: " << a.pSize << "  number of elements in the array: " << a.numElements << endl;

                // output private array with a simple row/column format
                for ( i = 0; i < a.numElements; i++ ) {

                        output << right << setw(10) << *(a.set+i);


                if ( (i + 1) % 4 == 0 )
                        output << endl;
                } // end for

                if ( i % 4 != 0 ) // end last line of output
                        output << endl;

                return output; // enables cout << x << y
        }

main(){
        int o[3] = {1,2,3};
        Set<int> a(5), b(5), c(o,3,'a');

        a.input();
        cin >> a;
        cout << a << endl;

        b.input();
        cin >> b;
        cout << b;

        cout << c;

        a+b;


}

