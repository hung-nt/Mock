#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "FileAbstract.h"
using namespace std;


class Playlist {
private:
    string name;
    vector<FileAbstract> files;
public:
    Playlist(const string& n) : name(n) {}
    ~Playlist() = default;

    void addFile(const FileAbstract& file);

    void viewPlaylist();

    string getName() const;

    vector<FileAbstract> getFiles();
    void deleteFile(const FileAbstract& file);
};


#endif // ! PLAYLIST_H