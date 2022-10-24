#include "Catalog.h"
#include <iostream>

using namespace std;

int main() 
{ 
  Catalog* c = new Catalog();
  c -> NEWCatalog("Catalog.csv");

  int op;
  cout << "What do you want to see: \n 1) Videos (movies or series) with an especific rating \n 2) Videos (movies or series) with an especific genre \n 3) Episodes of an espesific series and a espesific rating \n 4) Movies with an espesific rating \n 5) Rate a video \n 6) Exit"<<endl;
  cin >> op;

  if(op == 1)
  {
    int rating;
    cout<<"With what rating?"<<endl;
    cin >> rating ;
    c -> showVideosWithRating(rating);
    

  }
  else if(op == 2)
  {
    string genre;
    cout<<"What genre?"<<endl;
    cin >> genre;
    c -> showVideosWithGenre(genre);
  }
  else if(op == 3)
  {
    string name;
    cout<<"What serie?"<<endl;
    cin >> name;
    
    int rating;
    cout<<"With what rating?"<<endl;
    cin >> rating ;
    
    c -> showEpisodeWithRating(name, rating);
  }
  else if(op == 4)
  {
    int rating;
    cout<<"With what rating?"<<endl;
    cin >> rating ;
  
    c -> showMoviesWithRating(rating);
  }
  else if(op == 5)
  {
    int ratesom;
    cout<<"Do you want to rate a movie (1) or a serie(2)"<<endl;
    cin >> ratesom;
    if(ratesom == 1)
    {
      string name;
      cout<<"What movie?"<<endl;
      cin >> name;
    
      int rating;
      cout<<"What rating?"<<endl;
      cin >> rating ;

      c -> RateAMovie(name,rating);
      
    }
    else if (ratesom == 2)
    {
      string nameserie;
      cout<<"What serie?"<<endl;
      cin >> nameserie;
      
      string nameep;
      cout<<"What episode?"<<endl;
      cin >> nameep;
      
      int rating;
      cout<<"What rating?"<<endl;
      cin >> rating ;

      c -> RateAEpisode(nameserie, nameep ,rating);
        
    }
    else
    {
      cout<<"Invalid option! :("<<endl;
    }
    
  }
  else if(op == 6)
  {
    cout<<"Have a nice day! See you later :)"<<endl;
  }
  else
  {
    cout << "Invalid Option! :("<<endl;
  }


  return 0; 
}