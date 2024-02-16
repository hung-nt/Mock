#include "../inc/Mp4File.h"

Mp4File::Mp4File() {}

Mp4File::Mp4File(const std::string &resolution) : resolution(resolution) {}

Mp4File::~Mp4File() {}

void Mp4File::setResolution(const std::string &resolution)
{
    this->resolution = resolution;
}

std::string Mp4File::getResolution() const
{
    return resolution;
}
