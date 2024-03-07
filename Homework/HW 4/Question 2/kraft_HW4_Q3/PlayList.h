#pragma once
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

struct Song; // Forward declaration of Song structure

class PlayList
{
private:
    Song* head; // Pointer to the first song in the playlist
public:
    PlayList(); // Constructor
    void addSong(std::string title, std::string artist); // Add a song to the playlist
    void removeSong(std::string title); // Remove a song from the playlist
    void displayPlaylist() const; // Display the current playlist
};

#endif // PLAYLIST_H
