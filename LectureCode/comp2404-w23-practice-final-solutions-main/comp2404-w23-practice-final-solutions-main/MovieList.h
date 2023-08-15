class MovieList {
	class Node {
		public :
			Movie * data ;
			Node * next ;
		};
		
	public :
		MovieList ();
		~ MovieList ();
		// add to the front of the MovieList
		void addFront ( Movie *);
		// add to the back of the MovieList
		void addBack ( Movie *);
		// remove and return the Movie at the front
		Movie * removeFront ();
		// remove and return the Movie at the back
		Movie * removeBack ();
	private :
		Node * head ;
		Node * tail ;
};
