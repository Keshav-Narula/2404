#include <iostream>
#include <string>
using namespace std;
#include "Song.h"

Song::Song(int i, string t, string a)
{
  
  id     = i;
  title  = t;
  artist = a;
  cout<<"-- Song default ctor:  "<< id <<endl;
}

//we are not plagiarizing, we are "inspired by"
//Copy constructor, this is what the default copy constructor does, otherwise it just defaults to what the erfular constuctor does 
//Still need to initialize all the variables
Song::Song(Song& oldSong)
{
  id     = oldSong.id;
  title  = oldSong.title;
  artist = oldSong.artist;
  cout<<"-- Song COPY ctor:  "<< id <<": "<<title <<endl;
}

//Destructor
Song::~Song()
{
  cout<<"-- Song dtor:  "<< id <<endl;
}

void Song::print()
{
  cout<<"\""<< title <<"\" by "<<artist<<endl;
}