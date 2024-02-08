#include "LocalMediaList.h"
#include <iostream>

void AppController::addFile() {
    // Thay đổi kiểu dữ liệu của playlistIndex sang size_t
    size_t playlistIndex;
    cout << "Enter playlist index: ";
    cin >> playlistIndex;
    if (playlistIndex <= 0 || playlistIndex > playlistVector.size()) {
        cout << "Invalid playlist index." << endl;
        return;
    }

    // Thay đổi kiểu dữ liệu của fileIndex sang size_t
    size_t fileIndex;
    cout << "Enter file index: ";
    cin >> fileIndex;
    if (fileIndex <= 0 || fileIndex > files.size()) {
        cout << "Invalid file index." << endl;
        return;
    }
}

void LocalMediaList::removeFile(const std::string& fileName) {
    auto it = std::find_if(files.begin(), files.end(), [&](FileAbstract* file) { // Chỉnh sửa đối số của lambda
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

const std::vector<FileAbstract *> LocalMediaList::getList() const {
    return files;
}

LocalMediaList::~LocalMediaList() {
    // Giải phóng bộ nhớ của các đối tượng FileAbstract được lưu trữ trong fileList
    for (auto file : files) {
        delete file;
    }
}
