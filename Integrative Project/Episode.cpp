#include "Episode.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


// Constructor
Episode:: Episode(string _title, int _season, int _length, int _rating)
{
  title = ' ';
  rating = 0;
  raters = " ";
  length = 0;
}

//Destructor
Episode:: ~Episode()
{

}


// Getters

string Episode:: getTitle()
{
    return title;
}

int Episode:: getRating()
{
    return rating;
}

string Episode:: getRaters()
{
    return raters;
}

int Episode:: getLength()
{
    return length;
}

int Episode:: getSeason()
{
   return season; 
}

// Setters

void Episode:: setTitle(string _title)
{
    title = _title;
}

void Episode:: setRating(int _rating)
{
    rating = _rating;
}

void Episode:: setRaters(string _raters)
{
    raters = _raters;
}

void Episode:: setLength(int _length)
{
    length = _length;
}

void Episode:: setSeason(int _season)
{
    season = _season;
}


// To String
string Episode:: toString()
{
  string txt = "I'm a episode";
  txt+= "Title: " + getTitle();
  txt += "Length: " + to_string(getLength());
  txt += "Season: " + to_string(getSeason());
  txt += "Rating: " + to_string(getRating());
  txt += "Raters: " + getRaters();
  return txt; 
}
