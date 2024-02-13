#ifndef LOCAL_MEDIA_LIST_H
#define LOCAL_MEDIA_LIST_H

#include <vector>
#include <algorithm>
#include <AppController.h>
#include "FileAbstract.h"

class LocalMediaList
{
public:
    // Thêm các phương thức cần thiết để quản lý danh sách các file đa phương tiện cục bộ
    void addFile(const FileAbstract &file);
    void removeFile(const std::string &fileName);
    void displayAllFiles() const;
    const std::vector<FileAbstract *> getList() const;
    ~LocalMediaList();

private:
    std::vector<FileAbstract *> files;
};

#endif // LOCAL_MEDIA_LIST_H
