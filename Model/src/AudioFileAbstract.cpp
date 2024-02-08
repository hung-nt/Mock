#include "LocalMediaList.h"
#include <iostream>

// Thêm các định nghĩa cho các phương thức mới trong LocalMediaList.h

void LocalMediaList::addFile(const FileAbstract& file) {
    fileList.push_back(file);
}

void LocalMediaList::removeFile(const std::string& fileName) {
    auto it = std::find_if(fileList.begin(), fileList.end(), [&](const FileAbstract& file) {
        return file.getName() == fileName;
    });
    if (it != fileList.end()) {
        fileList.erase(it);
        std::cout << "File '" << fileName << "' removed from local media list." << std::endl;
    } else {
        std::cout << "File '" << fileName << "' not found in local media list." << std::endl;
    }
}

void LocalMediaList::displayAllFiles() const {
    std::cout << "Local Media Files:" << std::endl;
    for (const auto& file : fileList) {
        std::cout << "- " << file.getName() << std::endl;
    }
}

const std::vector<FileAbstract>& LocalMediaList::getList() const {
    return fileList;
}
