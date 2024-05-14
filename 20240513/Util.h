#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <locale.h>
#include <set>
#include <algorithm>
#include <Windows.h>
#include <iomanip>
#include <string>


#include "MusicInfo.h"


void lineSeparator();

class Util
{
public:
    
    /*struct Row
    {
        std::wstring title;
        std::wstring artist;
        std::wstring category;
        std::wstring releaseDate;
        std::wstring lyric;
    };*/

    //std::vector<Row> rows;
    //std::set<std::wstring> categoryList;

    void LoadMusicData(string filename, vector<MusicInfo>& musicinfos);
    /*void setCategoryList();

    void viewMusicList();
    void viewCategoryList();
    void viewPickedMusic(int);
    void viewMusicInfo(int);
    void viewMusicLyric(int);*/
};