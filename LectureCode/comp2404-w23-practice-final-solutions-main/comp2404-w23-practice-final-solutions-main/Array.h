# ifndef ARRAY_H
# define ARRAY_H
# include < iostream >
# include < string >
# define MAX_ARRAY 256
using namespace std ;
template < class T >
class Array {
	public :
		Array ();
		~ Array ();
		// add T to the back of the array if there is room
		Array <T >& operator +=( const T &);
		// remove T if it exists
		Array <T >& operator -=( const T &);
		// return element at index , or call exit (1) on bad index
		T & operator []( int index );
		const T & operator []( int index ) const ;
		// inline functions
		int size () const { return numElements ; }
		bool isFull () const { return numElements >= MAX_ARRAY ;}
	private :
		int numElements ;
		T * elements ;
};


template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	numElements = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
Array<T>& Array<T>::operator+=(const T& t){

	//Check if array has space to add elements to the array
	if (numElements >= MAX_ARRAY) {
		return *this;
	}
	
	//If there is space, add element t to the array
	elements[numElements++] = t;
	return *this;
}


template <class T>
Array<T>& Array<T>::operator-=(const T& t){

	//Traverse the array and find the element to remove
	int index = 0;
	
	while (index < numElements) {
		
		if (t == elements[index]) {
			--numElements;
			break;
		
		}
		
		++index;
	}
	
	//Once the element is removed, shift the elements in the array so elements are still contingious
	while (index < numElements) {
		elements[index] = elements[index + 1];
		++index;
	}
	
	return *this;
}


template <class T>
const T& Array<T>::operator[](int index) const{
	
	if (index < 0 || index >= MAX_ARRAY) {
	
		cerr << "Array index is out of bounds" << endl;
		exit(1);
	}
		
	return elements[index];
}

T& Array<T>::operator[](int index){

	if (index < 0 || index >= MAX_ARRAY) {
	
		cerr << "Array index is out of bounds" << endl;
		exit(1);
	}
		
	return elements[index];	
}
