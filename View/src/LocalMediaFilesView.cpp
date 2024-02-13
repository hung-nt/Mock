#include "LocalMediaFilesView.h"

LocalMediaFilesView::LocalMediaFilesView() {}

LocalMediaFilesView::~LocalMediaFilesView() {}

void LocalMediaFilesView::showMenu()
{
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "PLAY WITH LOCAL MEDIA FILES MENU: " << std::endl;
    std::cout << LIST_ALL_LOCAL_MEDIA_FILES << ". List all local media files." << std::endl;
    std::cout << MODIFY_FILE << ". Modify file." << std::endl;
    std::cout << LOCAL_MEDIA_FILES_BACK << ". Back." << std::endl;
}

void LocalMediaFilesView::showModifyFileMenu(){
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "MODIFY FILE OPTION: " << std::endl;
    std::cout << SHOW_METADATA << ". Show metadata." << std::endl;
    std::cout << UPDATE_METADATA << ". Update metadata." << std::endl;
    std::cout << ADD_TO_PLAYLIST << ". Add to playlist." << std::endl;
    std::cout << MODIFY_FILE_BACK << ". Back." << std::endl;
}

void LocalMediaFilesView::displayAllFiles(const std::vector<FileAbstract*>& fileList)
{
    std::cout << "Local Media Files:" << std::endl;
    for (const auto &file : fileList) {
        std::cout << "- " << file->getName() << std::endl;
    }
}


void LocalMediaFilesView::showFile(const FileAbstract* file) {
    std::cout << "Showing file: " << file->getName() << std::endl;
    // Thực hiện các thao tác khác cần thiết để hiển thị thông tin của file
}
