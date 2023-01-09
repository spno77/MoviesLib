#pragma once 

#include <iostream>
#include <string>
#include <iterator>
#include <list>

using namespace std;

class Movie
{
	string title;			// Movie's title
	int    year;			// Year of production	
	string directors;		// Directors
	string stars;			// Stars
	string genre;			// Movie genre
	string posterPath;		// Movies poster path

public:
	Movie(string title1,int year1,string directors1,string stars1,string genre1,string path);
	~Movie();

	string getTitle();
	void  setTitle(string title1);

	//Year
	int   getYear();
	void  setYear(int year1);

	//Directors
	string getDirectors();
	void   setDirectors(string directors1);

	//Stars
	string getStars();
	void   setStars(string stars1);

	//Genre
	string getGenre();
	void   setGenre(string genre1);

	//Poster
	string getPosterPath();
	void   setPosterPath(string path);
};

// creates a List with pointers to Movie objects
void createMovieList(list<Movie *> &movieList);

// Destroys all objects of the List and cleares it
void destroyList(list<Movie *> &movieList);

//get Movie from the list
Movie* searchList(list<Movie *> &movieList,string posterPath);