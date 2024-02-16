#include "../inc/Playlist.h"

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

// Triển khai hàm getName của lớp FileAbstract
string FileAbstract::getName() const {
    return name;
}

// Triển khai hàm getPath của lớp FileAbstract
string FileAbstract::getPath() const {
    return path;
}

// Triển khai hàm FileAbstract() của lớp FileAbstract
FileAbstract::FileAbstract() {}

// Triển khai hàm FileAbstract(const string&, const string&) của lớp FileAbstract
FileAbstract::FileAbstract(const string& n, const string& p) : name(n), path(p) {}
