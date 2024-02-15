#ifndef FILE_VIEW_H
#define FILE_VIEW_H

#include <iostream>
#include "../../Model/inc/FileAbstract.h"

class FileView
{
public:
    FileView();
    virtual ~FileView();

    virtual void showFile(const FileAbstract* file) = 0;
};

#endif // ! FILE_VIEW_H
