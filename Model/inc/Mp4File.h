#ifndef MP4_FILE_H
#define MP4_FILE_H

#include <iostream>
#include "FileAbstract.h"

class Mp4File : public FileAbstract
{
private:
    std::string resolution;

public:
    Mp4File();
    Mp4File(const std::string& resolution);
    ~Mp4File();

    void setResolution(const std::string& resolution);
    std::string getResolution() const;

};

#endif // ! MP4_FILE_H
