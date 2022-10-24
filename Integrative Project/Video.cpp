#include "Video.h"

// Constructor 
Video:: Video(){}

// Destructor
Video:: ~Video(){}


// Getters

int Video:: getId()
{
    return id;
}

string Video:: getName()
{
    return name;
}

int Video:: getLength()
{
    return length;
}

string Video:: getGenre()
{
    return genre;
}

int Video:: getRating()
{
  return rating;
}


// Setters

void Video:: setId(int _id)
{
    id = _id;
}

void Video::setName(string _name)
{
    name = _name;
}

void Video:: setLength(int _length)
{
    length = _length;
}

void Video:: setGenre(string _genre)
{
    genre = _genre;
}

void Video:: setRating(int _rating)
{
    rating = _rating;
}