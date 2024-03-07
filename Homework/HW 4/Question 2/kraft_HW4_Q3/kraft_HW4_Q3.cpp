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

    // Constructor to initialize the song
    Song(std::string _title, std::string _artist) : title(_title), artist(_artist), next(nullptr) {}
};

PlayList::PlayList() : head(nullptr) {}

void PlayList::addSong(std::string title, std::string artist) {
    // Create a new song
    Song* newSong = new Song(title, artist);

    // If the playlist is empty, make the new song the head
    if (head == nullptr) {
        head = newSong;
        return;
    }

    // Otherwise, traverse to the end of the playlist and add the new song
    Song* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newSong;
}

void PlayList::removeSong(std::string title) {
    // If the playlist is empty, nothing to remove
    if (head == nullptr) {
        return;
    }

    // If the head song is to be removed
    if (head->title == title) {
        Song* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Otherwise, find the song to be removed
    Song* current = head;
    while (current->next != nullptr) {
        if (current->next->title == title) {
            Song* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

void PlayList::displayPlaylist() const {
    std::cout << "Current Playlist:" << std::endl;
    Song* current = head;
    while (current != nullptr) {
        std::cout << "Title: " << current->title << ", Artist: " << current->artist << std::endl;
        current = current->next;
    }
    std::cout << std::endl;
}





int main()
{
	PlayList myPlaylist;

	myPlaylist.addSong("Song 1", "Artist 1");
	myPlaylist.addSong("Song 2", "Artist 2");
	myPlaylist.addSong("Song 3", "Artist 3");
	myPlaylist.addSong("Song 4", "Artist 4");

	myPlaylist.displayPlaylist();

	myPlaylist.removeSong("Song 2");
    myPlaylist.removeSong("Song 1");

	myPlaylist.displayPlaylist();
}


