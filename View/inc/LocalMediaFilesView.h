#ifndef LOCAL_MEDIA_FILES_VIEW_H
#define LOCAL_MEDIA_FILES_VIEW_H

#include <iostream>
#include "FileView.h"
#include "LocalMediaList.h"

enum LOCAL_MEDIA_FILES_OPTION {
    LIST_ALL_LOCAL_MEDIA_FILES = 1,
    MODIFY_FILE = 2,
    LOCAL_MEDIA_FILES_BACK = 0,
};

enum MODIFY_FILE_OPTION{
    SHOW_METADATA = 1,
    UPDATE_METADATA = 2,
    ADD_TO_PLAYLIST = 3,
    MODIFY_FILE_BACK = 0,
};

class LocalMediaFilesView : public FileView
{
public:
    LocalMediaFilesView();
    ~LocalMediaFilesView();

    void showMenu();
    void showModifyFileMenu();
    void displayAllFiles(const std::vector<FileAbstract*>& fileList);
    void showFile(const FileAbstract* file) override;
};

#endif // LOCAL_MEDIA_FILES_VIEW_H
