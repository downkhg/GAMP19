#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring& artist_, const std::wstring& title_) :
        artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring& date_,
        const std::wstring& location_,
        const std::wstring& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

using namespace std;

void SharedPtrMain()
{
    // Use make_shared function when possible.
    auto sp1 = make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");

    // Ok, but slightly less efficient. 
    // Note: Using new expression as constructor argument
    // creates no named variable for other code to access.
    shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));

    // When initialization must be separate from declaration, e.g. class members, 
    // initialize with nullptr to make your programming intent explicit.
    shared_ptr<Song> sp5(nullptr);
    //Equivalent to: shared_ptr<Song> sp5;
    //...
    sp5 = make_shared<Song>(L"Elton John", L"I'm Still Standing");

    //Initialize with copy constructor. Increments ref count.
    auto sp3(sp2);

    //Initialize via assignment. Increments ref count.
    auto sp4 = sp2;

    //Initialize with nullptr. sp7 is empty.
    shared_ptr<Song> sp7(nullptr);

    // Initialize with another shared_ptr. sp1 and sp2
    // swap pointers as well as ref counts.
    sp1.swap(sp2);

    vector<shared_ptr<Song>> v;

    v.push_back(make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"));
    v.push_back(make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"));
    v.push_back(make_shared<Song>(L"Thal�a", L"Entre El Mar y Una Estrella"));

    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](shared_ptr<Song> s)
    {
        return s->artist.compare(L"Bob Dylan") == 0;
    });

    for (const auto& s : v2)
    {
        wcout << s->artist << L":" << s->title << endl;
    }

    // Initialize two separate raw pointers.
// Note that they contain the same values.
    auto song1 = new Song(L"Village People", L"YMCA");
    auto song2 = new Song(L"Village People", L"YMCA");

    // Create two unrelated shared_ptrs.
    shared_ptr<Song> p1(song1);
    shared_ptr<Song> p2(song2);

    // Unrelated shared_ptrs are never equal.
    wcout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << endl;
    wcout << "p1 == p2 = " << std::boolalpha << (p1 == p2) << endl;

    // Related shared_ptr instances are always equal.
    shared_ptr<Song> p3(p2);
    wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;
}