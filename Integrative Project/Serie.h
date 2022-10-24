#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Episode.h"
using namespace std;


class Serie : public Episode
{
public:
  string name;
  vector <Episode*> episodes;

  Serie(string _name, string title, int season, int length, int rating, string genre);
  ~Serie(); 
  int getTotalLength();
  int getTotalRating();
  string getName();
  string toString();
  void addEpisode(Episode *e);
};  