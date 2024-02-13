// AppController.h
#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

#include <iostream>
#include <algorithm>
#include "LocalMediaList.h"
#include "Playlist.h"
#include "MainMenuView.h"
#include "LocalMediaFilesView.h"
#include "PlaylistView.h"

using namespace std;

class AppController {
private:
    LocalMediaList localFileList;
    vector<Playlist *> playlistVector;
    vector<FileAbstract> files;
    MainMenuView mainMenuView;
    LocalMediaFilesView localMediaFilesView;
    PlaylistView playlistView;

public:
    AppController();
    ~AppController();

    void run();
    int optionInput();

    void playWithLocalMediaFiles();
    void playWithYourPlayLists();

    void listAllLocalMediaFiles();
    void modifyFile();
    void showMetadata();
    void updateMetadata();
    void addToPlaylist();

    void createPlaylist();
    void deletePlaylist();
    void modifyPlaylist();
    void showPlaylist();
    void addFile();
    void deleteFile();
};

#endif // ! APP_CONTROLLER_H