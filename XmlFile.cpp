#include "XmlFile.h"

string XmlFile::loadFileName()
{
    return NAME_FILE;
}

bool XmlFile::isFileEmpty(fstream &XmlFile)
{
    XmlFile.seekg(0, ios::end);
    int position = XmlFile.tellg();
    if (position == 0)
    {
        return true;
    }
    else
        return false;
}
