#include "../inc/Mp3File.h"

Mp3File::Mp3File() {}

Mp3File::Mp3File(const std::string& album) : album(album) {}

Mp3File::~Mp3File() {}

void Mp3File::setAlbum(const std::string& album) {
    this->album = album;
}

std::string Mp3File::getAlbum() const {
    return album;
}
