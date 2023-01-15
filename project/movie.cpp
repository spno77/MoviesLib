#include "movie.h"
#include "config.h"

// Movie constructor
Movie::Movie(string title1,int year1,string directors1,string stars1,string genre1,string poster)
:title(title1),year(year1),directors(directors1),stars(stars1),genre(genre1),posterPath(poster)
{}

// Movie destructor
Movie::~Movie(){}

// Title getter/setter
string  Movie::getTitle() { return title; }
void    Movie::setTitle(string title1) { title = title1; }

// Year getter/setter
int     Movie::getYear() { return year; }
void    Movie::setYear(int year1) { year = year1; }

// Directors getter/setter
string  Movie::getDirectors() { return directors; }
void    Movie::setDirectors(string director1) { directors = director1; }

// Stars getter/setter
string  Movie::getStars() { return stars; }
void    Movie::setStars(string stars1) { stars = stars1; }

// Genre getter/setter
string  Movie::getGenre() { return genre; }
void    Movie::setGenre(string genre1) { genre = genre1; }

// PosterPath getter/setter
string  Movie::getPosterPath() { return posterPath; }
void    Movie::setPosterPath(string path) { posterPath = path; }

// Populates the list with Movie objects
void createMovieList(list<Movie *> &movieList)
{	
	string asset = string(ASSET_PATH);

	Movie *movie = new Movie("Fight Club",1999,"David Fincher","Brad Pitt,Edward Norton","thriller",asset+"fightclub.png");
    movieList.push_back(movie);

    movie = new Movie("Joker",2019,"Todd Philips","Joaquin Phoenix,Robert De Niro","thriller",asset+"joker.png");
    movieList.push_back(movie);

    movie = new Movie("It",2017,"Andy Muschietti","Bill Skarsgard,Finn Wolfhard","horror",asset+"it.png");
	movieList.push_back(movie);

	movie = new Movie("Athena",2022,"Romain Gavras","Dali Banssalah,Sami Slimate","drama",asset+"athena.png");
	movieList.push_back(movie);

	movie = new Movie("Antman",2015,"Peyton Reed","Paul Rudd,Michael Douglas","action",asset+"antman.png");
	movieList.push_back(movie);
}

// Destroys all objects of the List and cleares it
void destroyList(list<Movie *> &movieList)
{
	for (auto movie : movieList)
	{
		delete movie;
	}
	//clear the list
	movieList.clear();
}

// Search for a movie in the list by the posterPath
Movie* searchListByPoster(list<Movie *> &movieList,string posterPath)
{
	for (auto movie: movieList)
	{
		if (movie->getPosterPath() == posterPath)
		{
			return movie;
		}
	}
	return nullptr;
}

// Get Movie from the list by genre
Movie* searchListByGenre(list<Movie *> &movieList,string genre)
{
	for (auto movie: movieList)
	{
		if (movie->getGenre() == genre)
		{
			return movie;
		}
	}
	return nullptr;
}

// Get movie from the list by year of production
Movie* searchListByYear(list<Movie *> &movieList,int year)
{
	for (auto movie: movieList)
	{
		if (movie->getYear() == year)
		{
			return movie;
		}
	}
	return nullptr;
}
