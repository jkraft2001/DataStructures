// CS400LinkedListApplication(PlayList).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"PlayList.h"
#include <iostream>
#include <string>


struct Song {
	std::string title;
	std::string artist;
	Song* next;
};


class PlayList
{
private:
	Song* head;
public:
	PlayList();
	void addSong(std::string title, std::string artist);
	void removeSong(std::string title);
	void displayPlaylist() const;
};




int main()
{
    PlayList myPlaylist;

    myPlaylist.addSong("Song 1", "Artist 1");
    myPlaylist.addSong("Song 2", "Artist 2");
    myPlaylist.addSong("Song 3", "Artist 3");
    myPlaylist.addSong("Song 4", "Artist 4");

    myPlaylist.displayPlaylist();

    myPlaylist.removeSong("Song 2");

    myPlaylist.displayPlaylist();
}


