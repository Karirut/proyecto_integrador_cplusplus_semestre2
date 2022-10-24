#include "Serie.h"

//Constructor
Serie:: Serie(string _name, string title, int season, int length, int rating, string genre): Episode(title, season, length, rating)
{
  name = " ";
}

// Destructor
Serie:: ~Serie()
{

}

void Serie:: addEpisode(Episode *e){
  return episodes.push_back(e);
}


int Serie:: getTotalLength()
{
  vector<Episode*>:: iterator it;
  Episode* e = new Episode(title, season, length, rating);
  e -> setLength(0);
  for(it = episodes.begin(); it != episodes.end(); ++it)
  {
    e -> setLength((*e)+(*(*it)));
    
  }
  return e -> getLength();
}

int Serie:: getTotalRating()
{
  vector<Episode*>:: iterator it;
  Episode* e = new Episode(title, season, length, rating);
  e -> setRating(0);
  for(it = episodes.begin(); it != episodes.end(); ++it)
  {
    e -> setRating((*e)*(*(*it)));
    int r = (e -> getRating())/(stoi(e-> getRaters()));
    int i=0;
    while(i == 0)
    {
      if (r>5){
        r = r/100;
      }
      if(1<r && r>5)
      {
        i=1;
        return r;
      }
    }
  }
}

string Serie:: getName(){
  return name;
}

// To String
string Serie:: toString()
{
  string txt = "I'm a serie";
  txt += "Name: " + getName();
  txt += "Id: " + to_string(getId());
  txt += "Length: " + to_string(getTotalLength());
  txt += "Genre: " + getGenre();
  txt += "Rating: " + to_string(getTotalRating());
  txt += "Rators: " + getRaters();
  return txt;
}
