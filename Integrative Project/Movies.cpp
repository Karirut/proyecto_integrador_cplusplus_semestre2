#include "Movies.h"

// Constructor
Movies:: Movies()
{
  rating = 0;
  rators = " ";
}

//Destructor
Movies:: ~Movies()
{

}

// Getters
int Movies:: getRating()
{
    return rating;
}

string Movies:: getRators()
{
    return rators;
}

// Setters
void Movies:: setRating(int _rating)
{
    rating = _rating;
}

void Movies:: setRators(string _rators)
{
    rators = _rators;
}

// To String

string Movies:: toString()
{
  string txt = "I'm movie";
  txt += "Name: " + getName();
  txt += "Id: " + to_string(getId());
  txt += "Length: " + to_string(getLength());
  txt += "Genre: " + getGenre();
  txt += "Rating: " + to_string(getRating());
  txt += "Rators: " + getRators();

  return txt; 

}