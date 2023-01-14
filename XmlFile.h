#ifndef XMLFILE_H
#define XMLFILE_H
#include <iostream>
#include <fstream>
using namespace std;

class XmlFile
{
    const string NAME_FILE;

public:
    XmlFile(string nameFile):NAME_FILE(nameFile){}

    string loadFileName();
    bool isFileEmpty(fstream &XmlFile);
};

#endif
