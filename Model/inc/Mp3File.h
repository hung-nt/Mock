#ifndef MP3_FILE_H
#define MP3_FILE_H

#include <iostream>
#include "FileAbstract.h"

class Mp3File : public FileAbstract
{
private:
    std::string album;

public:
    Mp3File();
    Mp3File(const std::string& album);
    ~Mp3File();

    void setAlbum(const std::string& album);
    std::string getAlbum() const;

};

#endif // ! MP3_FILE_H
