#pragma once 

#include <iostream>
#include <string>
#include <iterator>
#include <list>

using namespace std;

//Movie Class
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

	//Title getter/setter
	string getTitle();
	void  setTitle(string title1);

	//Year getter/setter
	int   getYear();
	void  setYear(int year1);

	//Directors getter/setter
	string getDirectors();
	void   setDirectors(string directors1);

	//Stars getter/setter
	string getStars();
	void   setStars(string stars1);

	//Genre getter/setter
	string getGenre();
	void   setGenre(string genre1);

	//Poster getter/setter
	string getPosterPath();
	void   setPosterPath(string path);
};

// creates a List with pointers to Movie objects
void createMovieList(list<Movie *> &movieList);

// Destroys all objects of the List and cleares it
void destroyList(list<Movie *> &movieList);

// Get Movie from the list by posterPath
Movie* searchListByPoster(list<Movie *> &movieList,string posterPath);

// Get Movie from the list by genre
Movie* searchListByGenre(list<Movie *> &movieList,string genre);

// Get movie from the list by year of production
Movie* searchListByYear(list<Movie *> &movieList,int year);
