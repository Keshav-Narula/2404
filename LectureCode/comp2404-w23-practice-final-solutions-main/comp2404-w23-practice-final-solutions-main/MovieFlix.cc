#include "MovieFlix.h"

MovieFlix::MovieFlix ( const string & subscriber ) : subscriber(subscriber), movies(Array<Movie*>) {
	

}

MovieFlix::MovieFlix ( const MovieFlix & movieFlix) {

	this->subscriber = movieFlix.subscriber;
	this->mf = movieFlix.mf;
	
	for (int i = 0; i < movieFlix.movies.size(); i++) {
		elements[i] = new Movie(*(movieFlix.movies[i]));
	}
}

MovieFlix::~MovieFlix() {
	
	for (int i = 0; i < movies.size(); i++) {
		delete elements[i];
	}
}


// make a new Movie and add it to the array
bool MovieFlix::addMovie ( const string & title , float price , const string & content ) {

	
	if (movies.isFull() == true) {
	
		return false;
	} else {
	
		Movie *movie = mf.makeMovie(title, price, content);
		movies += movie;
	}
	
	return true;
}

// play the Movie with the title given
bool MovieFlix::playMovie ( ostream & ost , const string & title ) const {

	for (int i = 0; i < movies.size(); i++) {
	
		if (movies[i] == title) {
			ost << movies[i];
			return true;
		}	
			
		
	}
	
	return false;
}

// remove the Movie with the title given
bool MovieFlix::removeMovie ( const string & title ) const {

	
	for (int i = 0; i < movies.size(); i++) {
	
		if (movies[i] == title) {
		
			movies -= movies[i];
			return true;
		}
	}
	
	return false;
}

// add all movies that match the
// Criteria object to the MovieList
void MovieFlix::getMovieList ( const Criteria & criteria, MovieList & movieList) const {
	
	for (int i = 0; i< movies.size(); i++) {
	
		if (criteria.matches(movies[i]) == true) {
			movieList.addBack(movies[i]);
		} 
	}	
		

}

// remove each Movie from ( the front of ) the MovieList
// and play it on the ostream
void MovieFlix::playMovieList ( ostream & ost , MovieList & movieList) {

	Movie *movie = movieList.removeFront();	
	
	while (movie != NULL) {
		ost << *movie;	
		Movie *movie = movieList.removeFront();
	}

}
