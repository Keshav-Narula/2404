# define MAX_ARR 200
# include < iostream >
# include < string >
using namespace std ;
class Movie {
	friend ostream & operator < <( ostream & , const Movie &);
	public :
		Movie ( const string & title , float price );
		bool operator ==( const string & t ) const { return title = t ;}
	protected :
		virtual void play ( ostream & ost ) const = 0;
		string title ;
		float price ;

};

// high definition
class HDMovie : public Movie {
	public :
		HDMovie ( const string & title , float price , const string & hd );
	protected :
		virtual void play ( ostream & ost );
		string hdContent ;
};

// standard definition
class SDMovie : public Movie {
	public :
		SDMovie ( const string & title , float price , const string & sd );
	protected :
		virtual void play ( ostream & ost );
		string sdContent ;
};

