#pragma once
#include <iostream>
#include <string>

using namespace std;


class Video
{
  
    public:
        int id;
        string name;
        int length;
        string genre;
        int rating;
        Video();
        ~Video();

        // Operators 
        int operator + (Video& v){
            return this -> getLength() + v.getLength();
        }
        int operator * (Video& v){
            return this -> getRating() * v.getRating();
        }

        // Getters y Setters
        int getId();
        void setId(int _id);
        string getName();
        void setName(string _name);
        int getLength();
        void setLength(int _length);
        string getGenre();
        void setGenre(string _genre);
        int getRating();
        void setRating(int _rating);


        // Abstract class
       virtual string toString() =0;



};  


