#include "Playlist.h"

void Playlist::addFile(const FileAbstract& file) {
    files.push_back(file);
}

void Playlist::viewPlaylist() {
    cout << "Playlist - " << name << endl;
    for (auto& media_file : files) {
        cout << media_file.getName() << " - " << media_file.getPath() << endl;
    }
    cout << endl;
}

string Playlist::getName() const {
    return name;
}

vector<FileAbstract> Playlist::getFiles() {
    return files;
}

void Playlist::deleteFile(const FileAbstract& file) {
    auto it = std::find(files.begin(), files.end(), file);

    if (it != files.end()) {
        files.erase(it);
        std::cout << "File '" << file.getName() << "' deleted from playlist '" << name << "'." << std::endl;
    } else {
        std::cout << "File '" << file.getName() << "' not found in playlist '" << name << "'." << std::endl;
    }
}