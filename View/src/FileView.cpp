#include "FileView.h"
#include "Mp3File.h"
#include "Mp4File.h"

FileView::FileView() {}
FileView::~FileView() {}

void FileView::showFile(const FileAbstract* file) {
    std::cout << "This is a generic file." << std::endl;
}

class Mp3FileView : public FileView {
public:
    Mp3FileView() {}
    ~Mp3FileView() {}

    void showFile(const FileAbstract* file) override {
        const Mp3File* mp3File = dynamic_cast<const Mp3File*>(file);
        if (mp3File) {
            std::cout << "This is an MP3 file." << std::endl;
        } else {
            std::cout << "This is not an MP3 file." << std::endl;
        }
    }
};

class Mp4FileView : public FileView {
public:
    Mp4FileView() {}
    ~Mp4FileView() {}

    void showFile(const FileAbstract* file) override {
        const Mp4File* mp4File = dynamic_cast<const Mp4File*>(file);
        if (mp4File) {
            std::cout << "This is an MP4 file." << std::endl;
        } else {
            std::cout << "This is not an MP4 file." << std::endl;
        }
    }
};
