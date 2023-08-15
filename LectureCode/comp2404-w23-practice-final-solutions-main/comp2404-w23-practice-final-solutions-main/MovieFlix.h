#include "Movie.h"

class MovieFlix {
	public :
		MovieFlix ( const string & subscriber );
		MovieFlix ( const MovieFlix &);
		~ MovieFlix ();
		// make a new Movie and add it to the array
		bool addMovie ( const string & title , float price ,
		const string & content );
		// play the Movie with the title given
		bool playMovie ( ostream & ost , const string & title ) const ;
		// remove the Movie with the title given
		bool removeMovie ( const string & title ) const ;
		// add all movies that match the
		// Criteria object to the MovieList
		void getMovieList ( const Criteria & , MovieList &) const ;
		// remove each Movie from ( the front of ) the MovieList
		// and play it on the ostream
		void playMovieList ( ostream & ost , MovieList &);
	private :
		// the name of the MovieFlix subscriber
		string subscriber ;
		MovieFactory mf ;
		// Collection class which stores the Movies
		// ( see Array class definition above )
		Array < Movie * > movies ;
};
