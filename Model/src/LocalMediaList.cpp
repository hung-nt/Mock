// LocalMediaList.cpp
#include "../inc/LocalMediaList.h"
#include "FileAbstract.h"
#include <algorithm>
#include <iostream>

void LocalMediaList::addFile(const FileAbstract& file) {
    files.push_back(new FileAbstract(file)); // Thêm file mới vào danh sách
}

void LocalMediaList::removeFile(const std::string& fileName) {
    auto it = std::find_if(files.begin(), files.end(), [&](FileAbstract* file) { // Sửa lambda thành nhận con trỏ
        return file->getName() == fileName; // Sử dụng phép toán như trước với con trỏ
    });
    if (it != files.end()) {
        delete *it;
        files.erase(it);
        std::cout << "File '" << fileName << "' removed from local media list." << std::endl;
    } else {
        std::cout << "File '" << fileName << "' not found in local media list." << std::endl;
    }
}

void LocalMediaList::displayAllFiles() const {
    std::cout << "Local Media Files:" << std::endl;
    for (const auto& file : files) {
        std::cout << "- " << file->getName() << std::endl;
    }
}

const std::vector<FileAbstract*> LocalMediaList::getList() const {
    return files;
}

LocalMediaList::~LocalMediaList() {
    for (auto file : files) {
        delete file;
    }
}
