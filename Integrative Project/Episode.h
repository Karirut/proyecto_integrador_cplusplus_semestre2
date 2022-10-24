#pragma once
#include <iostream>
#include <string>
#include "Video.h"
using namespace std;


class Episode: public Video
{
public:
  string title;
  int rating;
  string raters;
  int length;
  int season;

  Episode(string _title, int _season, int _length, int _rating);
  ~Episode();
                
  string toString();

  // Getters y setters 
  void setTitle(string _title);
  string getTitle();
  void setRating(int _rating);
  int getRating();
  void setRaters(string _raters);
  string getRaters();
  void setLength(int _length);
  int getLength();
  int getSeason();
  void setSeason(int _season);
};  