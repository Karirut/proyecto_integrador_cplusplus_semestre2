#pragma once
#include <iostream>
#include <string>
#include "Video.h"
using namespace std;


class Movies : public Video
{

    public:
        int rating;
        string rators;
        Movies();
        ~Movies();
        
        string toString();

        // Getters y Setters
        void setRating(int _rating);
        int getRating();
        void setRators(string _rators);
        string getRators();
        
};  


