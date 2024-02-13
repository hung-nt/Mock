// LocalMediaList.h
#ifndef LOCAL_MEDIA_LIST_H
#define LOCAL_MEDIA_LIST_H

#include <vector>
#include <algorithm>
#include "FileAbstract.h"

class LocalMediaList {
public:
    void addFile(const FileAbstract &file);
    void removeFile(const std::string &fileName);
    void displayAllFiles() const;
    const std::vector<FileAbstract *> getList() const;
    ~LocalMediaList();

private:
    std::vector<FileAbstract *> files;
};

#endif // LOCAL_MEDIA_LIST_H
