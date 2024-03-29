#ifndef FILE_ABSTRACT_H
#define FILE_ABSTRACT_H
#include <iostream>
using namespace std;

class FileAbstract
{
private:
    string name;
    string path;

public:
    FileAbstract();
    FileAbstract(const string &n, const string &p);
    virtual ~FileAbstract() = default;

    void setName(const string &n);
    void setPath(const string &p);
    string getName() const;
    string getPath() const;

    bool operator==(const FileAbstract &other) const
    {
        return this->name == other.name;
    }
};

#endif // ! FILE_ABSTRACT_H