#include <iostream>
#include "../../Model/inc/LocalMediaList.h"
#include "../inc/AppController.h"
#include "FileAbstract.h"
using namespace std;

AppController::AppController()
{
}

AppController::~AppController()
{
}

void AppController::run()
{
    int option;
    do
    {
        mainMenuView.showMenu();
        option = optionInput();
        switch (option)
        {
        case PLAY_WITH_LOCAL_MEDIA_FILES:
        {
            playWithLocalMediaFiles();
            break;
        }
        case PLAY_WITH_YOUR_PLAYLISTS:
        {
            playWithYourPlayLists();
            break;
        }
        case EXIT:
        {
            cout << "Exit the program!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != EXIT);
}

int AppController::optionInput()
{
    int option;
    cin >> option;
    cin.ignore();
    return option;
}

void AppController::playWithLocalMediaFiles()
{
    int option;
    do
    {
        localMediaFilesView.showMenu();
        option = optionInput();
        switch (option)
        {
        case LIST_ALL_LOCAL_MEDIA_FILES:
        {
            listAllLocalMediaFiles();
            break;
        }
        case MODIFY_FILE:
        {
            modifyFile();
            break;
        }
        case LOCAL_MEDIA_FILES_BACK:
        {
            cout << "Exit to the Menu." << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != LOCAL_MEDIA_FILES_BACK);
}

void AppController::listAllLocalMediaFiles()
{
    localMediaFilesView.displayAllFiles(localFileList.getList());
}

void AppController::modifyFile()
{
    int option;
    do
    {
        localMediaFilesView.showModifyFileMenu();
        option = optionInput();
        switch (option)
        {
        case SHOW_METADATA:
        {
            showMetadata();
            break;
        }
        case UPDATE_METADATA:
        {
            updateMetadata();
            break;
        }
        case ADD_TO_PLAYLIST:
        {
            addToPlaylist();
            break;
        }
        case MODIFY_FILE_BACK:
        {
            cout << "Exit to the Menu." << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != MODIFY_FILE_BACK);
}

void AppController::showMetadata()
{
    if (localFileList.getList().empty())
    {
        cout << "No local media files available." << endl;
        return;
    }

    cout << "Available local media files:" << endl;
    for (const auto &file : localFileList.getList())
    {
        cout << "File: " << file->getName() << endl;
    }
}

void AppController::updateMetadata()
{
    showMetadata();

    size_t fileIndex;
    do
    {
        cout << "Enter the index of the file to update metadata (0 to cancel): ";
        fileIndex = static_cast<size_t>(optionInput());
        if (fileIndex == 0)
        {
            cout << "Cancelled." << endl;
            return;
        }
        if (fileIndex > localFileList.getList().size())
        {
            cout << "Invalid file index. Please enter a valid index!" << endl;
        }
    } while (fileIndex > localFileList.getList().size());

    // Tiếp tục xử lý với fileIndex ở kiểu size_t
    FileAbstract &selectedFile = *localFileList.getList()[fileIndex - 1];
    // string newName, newPath;
    // cout << "Enter the new name for the file: ";
    // getline(cin, newName);
    // cout << "Enter the new path for the file: ";
    // getline(cin, newPath);

    // selectedFile.setName(newName);
    // selectedFile.setPath(newPath);
}

void AppController::addToPlaylist()
{
    if (localFileList.getList().empty())
    {
        cout << "No local media files available." << endl;
        return;
    }

    if (playlistVector.empty())
    {
        cout << "No playlists available. Please create a playlist first." << endl;
        return;
    }

    cout << "Select a local media file to add to a playlist:" << endl;
    for (size_t i = 0; i < localFileList.getList().size(); ++i)
    {
        cout << i + 1 << ". " << localFileList.getList()[i]->getName() << endl;
    }

    size_t fileIndex;
    cout << "Enter the index of the file: ";
    cin >> fileIndex;
    cin.ignore();

    if (fileIndex == 0 || fileIndex > localFileList.getList().size())
    {
        cout << "Invalid file index. Please enter a valid index." << endl;
        return;
    }

    cout << "Select a playlist to add the file to:" << endl;
    showPlaylist();

    size_t playlistIndex;
    cout << "Enter the index of the playlist: ";
    cin >> playlistIndex;
    cin.ignore();

    if (playlistIndex == 0 || playlistIndex > playlistVector.size())
    {
        cout << "Invalid playlist index. Please enter a valid index." << endl;
        return;
    }

    playlistVector[playlistIndex - 1]->addFile(*localFileList.getList()[fileIndex - 1]);

    cout << "File '" << localFileList.getList()[fileIndex - 1]->getName() << "' added to playlist '" << playlistVector[playlistIndex - 1]->getName() << "'." << endl;
}

void AppController::playWithYourPlayLists()
{
    int option;
    do
    {
        playlistView.showMenu();
        option = optionInput();
        switch (option)
        {
        case CREATE_PLAYLIST:
        {
            createPlaylist();
            break;
        }
        case DELETE_PLAYLIST:
        {
            deletePlaylist();
            break;
        }
        case MODIFY_PLAYLIST:
        {
            modifyPlaylist();
            break;
        }
        case PLAYLIST_BACK:
        {
            cout << "Exit to the Menu." << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != PLAYLIST_BACK);
}

void AppController::createPlaylist()
{
    cout << "create a playlist." << endl;
    string new_name;
    cout << "Enter name of new playlist: ";
    cin.ignore();
    getline(cin, new_name);
    playlistVector.push_back(new Playlist(new_name));
    cout << "New playlist - " << new_name << " - Created" << endl;
}

void AppController::deletePlaylist()
{
    cout << "delete a playlist." << endl;
    string name;
    cout << "Enter name of the playlist to delete: ";
    cin.ignore();
    getline(cin, name);
    auto it = find_if(playlistVector.begin(), playlistVector.end(), [name](const Playlist *playlist)
                      { return playlist->getName() == name; });
    if (it != playlistVector.end())
    {
        playlistVector.erase(it);
        cout << "Playlist " << name << " has been deleted." << endl;
    }
    else
    {
        cout << "Playlist " << name << " does not exist." << endl;
    }
}

void AppController::modifyPlaylist()
{
    int option;
    do
    {
        playlistView.showModifyMenu();
        option = optionInput();
        switch (option)
        {
        case SHOW_PLAYLIST:
        {
            showPlaylist();
            break;
        }
        case ADD_FILE:
        {
            addFile();
            break;
        }
        case DELETE_FILE:
        {
            deleteFile();
            break;
        }
        case MODIFY_PLAYLIST_BACK:
        {
            cout << "Exit to the Menu." << endl;
            break;
        }
        default:
        {
            cout << "Invalid option. Please enter a valid option!" << endl;
            break;
        }
        }
    } while (option != MODIFY_PLAYLIST_BACK);
}

void AppController::showPlaylist()
{
    if (playlistVector.empty())
    {
        cout << "No playlists available." << endl;
        return;
    }

    cout << "Available playlists:" << endl;
    for (size_t i = 0; i < playlistVector.size(); ++i)
    {
        cout << i + 1 << ". " << playlistVector[i]->getName() << endl;
    }
}

void AppController::addFile()
{
    vector<FileAbstract>::size_type playlistIndex;
    if (playlistVector.empty())
    {
        cout << "No playlists available. Please create a playlist first." << endl;
        return;
    }

    cout << "Select a playlist to add the file to:" << endl;
    showPlaylist();

    //int playlistIndex;
    cout << "Enter the index of the playlist: ";
    cin >> playlistIndex;
    cin.ignore();

    if (playlistIndex <= 0 || playlistIndex > playlistVector.size())
    {
        cout << "Invalid playlist index. Please enter a valid index." << endl;
        return;
    }

    string fileName;
    cout << "Enter the name of the file to add: ";
    getline(cin, fileName);

    playlistVector[playlistIndex - 1]->addFile(FileAbstract(fileName, ""));

    cout << "File '" << fileName << "' added to playlist '" << playlistVector[playlistIndex - 1]->getName() << "'." << endl;
}

void AppController::deleteFile()
{
    vector<Playlist*>::size_type playlistIndex;
    if (playlistVector.empty())
    {
        cout << "No playlists available. Please create a playlist first." << endl;
        return;
    }

    cout << "Select a playlist to delete the file from:" << endl;
    showPlaylist();

    // int playlistIndex;
    cout << "Enter the index of the playlist: ";
    cin >> playlistIndex;

    if (playlistIndex <= 0 || playlistIndex > playlistVector.size())
    {
        cout << "Invalid playlist index. Please enter a valid index." << endl;
        return;
    }

    cout << "Available files in playlist '" << playlistVector[playlistIndex - 1]->getName() << "':" << endl;
    const vector<FileAbstract>& files = playlistVector[playlistIndex - 1]->getFiles();
    for (size_t i = 0; i < files.size(); ++i)
    {
        cout << i + 1 << ". " << files[i].getName() << endl;
    }

    int fileIndex;
    cout << "Enter the index of the file to delete: ";
    cin >> fileIndex;

    if (fileIndex <= 0 || fileIndex > files.size())
    {
        cout << "Invalid file index. Please enter a valid index." << endl;
        return;
    }

    cin.ignore(); // Clear the input buffer

    playlistVector[playlistIndex - 1]->deleteFile(files[fileIndex - 1]);

    cout << "File '" << files[fileIndex - 1].getName() << "' deleted from playlist '" << playlistVector[playlistIndex - 1]->getName() << "'." << endl;
}