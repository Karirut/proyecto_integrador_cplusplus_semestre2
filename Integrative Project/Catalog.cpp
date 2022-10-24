#include "Catalog.h"

Catalog::Catalog() {}

Catalog::Catalog(string _filename) { filename = _filename; }

vector<string> Catalog::split(string original, string delimeter) {
  vector<string> splitted;
  size_t pos = 0;
  string token;
  while ((pos = original.find(delimeter)) != string::npos) {
    token = original.substr(0, pos);
    splitted.push_back(token);
    original.erase(0, pos + delimeter.length());
  }
  splitted.push_back(original);
  return splitted;
}

vector<string> Catalog::readFileToStringVector(string filename) {
  vector<string> lines;
  fstream theFile;
  theFile.open(filename, ios::in);
  if (theFile.is_open()) {
    string line;
    while (getline(theFile, line)) {
      lines.push_back(line);
    }
  }
  theFile.close();
  return lines;
}

int Catalog::stringToInt(string s) {
  int n = 0;
  stringstream ssn;
  ssn << s;
  ssn >> n;
  return n;
}

float Catalog::stringToFloat(string s) {
  float n = 0;
  stringstream ssn;
  ssn << s;
  ssn >> n;
  return n;
}

string Catalog::NEWCatalog(string _filename) {
  vector<string> lines = readFileToStringVector(_filename);
  cout << "READ: " << to_string(lines.size()) << "LINES." << endl;

  vector<string>::iterator it;
  for (it = lines.begin(); it != lines.end(); ++it) {

    string line = (*it);
    vector<string> parts = split(line, ",");
    if (parts.size() == 10) {
      int id = stringToInt(parts[0]);
      string name = parts[1];
      int length = stringToInt(parts[2]);
      string genre = parts[3];
      float rating = stringToInt(parts[4]);
      int raters = stringToInt(parts[5]);
      string seriesOrMovies = parts[6];
      string episode = parts[7];
      string title = parts[8];
      int season = stringToInt(parts[9]);

      if (seriesOrMovies == "Movie") {
        Movies *m = new Movies();
        movies.push_back(m);
      }
      if (seriesOrMovies == "Series") {
        if (findSeries(name) == true) {
          Serie* s;
          //s = getSerie();
          Episode *e = new Episode(title, season, length, rating);
          s->addEpisode(e);
        } else {
          Serie *s = new Serie(name, title, season, length, rating, genre);
          series.push_back(s);
          Episode *e = new Episode(title, season, length, rating);
          s->addEpisode(e);
        }
      }

      for (int p = 0; p < 10; p++) {

        cout << parts[p] << "\t";
      }
      cout << endl;
    }
  }
}

void Catalog::showVideosWithRating(int _rating) {

  for (int i = 0; i < movies.size(); i++) {
    if (movies[i]->getRating() == _rating) {
      cout << movies[i]->toString() << endl;
    }
  }
  for (int j = 0; j < series.size(); j++) {
    if (series[j]->getTotalRating() == _rating) {
      cout << series[j]->toString() << endl;
    }
  }
}

void Catalog::showVideosWithGenre(string _genre) {
  
  for (int i = 0; i < movies.size(); i++) {
    if (movies[i]->getGenre() == _genre) {
      cout << movies[i]->toString() << endl;
    }
  }
  for (int j = 0; j < series.size(); j++) {
    if (series[j]->getGenre() == _genre)
    {
      cout << series[j]->toString() << endl;
    }
  }
}

void Catalog::showEpisodeWithRating(string _name, int _rating)
{
  for (int i = 0; i < series.size(); i++) 
  {
    if (series[i]->getName() == _name) 
    {
      if (series[i]->getTotalRating() == _rating)
      {
        cout << series[i]->toString() << endl;
      }
    }
    else
    {
      cout << "There isn't a serie with that name" << endl;
    }
  }
}
  
void Catalog::showMoviesWithRating(int _rating) 
{
  for (int i = 0; i < movies.size(); i++) 
  {
    if (movies[i]->getRating() == _rating) 
    {
      cout << movies[i]->toString() << endl;
    }
    else
    {
     cout << "There isn't a movie with that rating" << endl; 
    }
  }
}

void Catalog::RateAMovie(string _name, int _rating)
{
  vector<Movies *>::iterator it;
  for (it = movies.begin(); it != movies.end(); ++it) 
  {
    if ((*it)->getName() == _name) 
    {
      (*it)->setRating(_rating);
      cout << "You have rate a movie :)" << endl;
    } 
    else 
    {
      cout << "There isn't a movie with that name" << endl;
    }
  }
}
void Catalog::RateAEpisode(string _nameserie, string _nameep, int _rating) {
  vector<Serie *>::iterator it;
  for (it = series.begin(); it != series.end(); ++it) {
    if ((*it)->getName() == _nameserie) {
        (*it)->setRating(_rating);
        cout <<"You have rate a episode :)"<<endl;
      }
    else 
    {
      cout << "There isn't a serie with that name" << endl;
    }
  }
}

bool Catalog::findSeries(string _name) {
  bool x;
  vector<Serie *>::iterator it;
  for (it = series.begin(); it != series.end(); ++it) {
    if ((*it)->getName() == _name) {
      x = true;
    } else {
      x = false;
    }
  }
  return x;
}

vector <Serie*> Catalog::getSerie() { return series; }
