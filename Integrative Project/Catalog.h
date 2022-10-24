#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Video.h"
#include "Serie.h"
#include "Episode.h"
#include "Movies.h"

using namespace std;

class Catalog
{
private:
  string filename;
  string original;
  string delimeter;
  vector<Movies*> movies;
  vector<Serie*> series;

public:

  Catalog();
  Catalog(string _filename);
  string NEWCatalog(string _filename);


  vector<string> split(string original, string delimeter);
  vector<string> readFileToStringVector(string filename);
  int stringToInt(string s);
  float stringToFloat(string s);

  bool findSeries(string _name);
  vector<Serie*> getSerie();
  void showVideosWithRating(int _rating);
  void showVideosWithGenre(string _genre);
  void showEpisodeWithRating(string _name, int _rating);
  void showMoviesWithRating(int _rating);
  void RateAMovie(string _name, int _rating);
  void RateAEpisode(string _nameserie, string _nameep, int _rating);

};
