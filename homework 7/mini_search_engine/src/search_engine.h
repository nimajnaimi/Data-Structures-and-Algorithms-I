#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <map>

//#define PRINT

using namespace std;

class MyMiniSearchEngine {
private:
    // default solution. OK to change but change index() accordingly if you do
    map<string, vector<vector<int>>> indexes;

    // cleanUpData returns a copy of the texts vector with all non alphabetic removed,
    // and all characters turned to lower cases
    unique_ptr<vector<string>> cleanUpData(const vector<string> &texts) {

        unique_ptr<vector<string>> data = make_unique<vector<string>>(texts);

        for (int i = 0; i < data->size(); ++i) {

            // remove none alphabet
            string *s = &(*data)[i];
            s->erase(remove_if(s->begin(), s->end(), [](char c) { return !isalpha(c) && !isspace(c); }), s->end());

            // convert to lower case
            for_each(s->begin(), s->end(), [](char &c) {
                c = ::tolower(c);
            });
        }

        return data;
    }

    // split the given string by white spaces
    // for example "hello world  Seattle" ==> ["hello", "world", "Seattle"]
    unique_ptr<vector<string>> splitByWhiteSpaces(const string &str) {
        vector<string> words;
        istringstream iss(str);
        for (std::string s; iss >> s;) {
            words.push_back(s);
#ifdef PRINT
            printf("'%s'\n", s.c_str());
#endif
        }
        return make_unique<vector<string>>(words);
    }

    // index generates the indexes based on the provided document texts
    // OK to change/rewrite based on design of the index
    void index(const vector<string> &texts) {

        // clean up data
        unique_ptr<vector<string>> pData = cleanUpData(texts);

        // each item of the vector is a document
        int numOfDoc = (*pData).size();
        for (int i = 0; i < numOfDoc; ++i) {

            string doc = (*pData)[i];

            // split the document by white spaces
            unique_ptr<vector<string>> words = splitByWhiteSpaces(doc);

            // homework: generate index for search
        }
#ifdef PRINT
        printIndex();
#endif
    }

public:
    MyMiniSearchEngine() = delete;

    void printIndex() {
        for (auto it = indexes.begin(); it != indexes.end(); it++) {
            printf("[%s]:{", it->first.c_str());
            auto fileVector = it->second;
            for (int i = 0; i < fileVector.size(); i++) {
                printf("[");
                for (int j = 0; j < fileVector[i].size(); j++) {
                    if (j != 0) {
                        printf(",");
                    }
                    printf("%d", fileVector[i][j]);
                }
                printf("]");
            }
            printf("}\n");
        }
    }

    explicit MyMiniSearchEngine(const vector<string> &texts) {
        reload(texts);
    }

    void reload(const vector<string> &texts) {
        indexes.clear();
        index(texts);
    }

    // search(key) return all the document id where the given string appears
    // document is labelled as the integer index of the search engine constructor.
    // search key can have one or two words in all English alphabetic characters.
    // return pointer to an empty vector if search() finds no match in all files
    vector<int> search(const string &searchKey) {
        // homework
        return vector<int>(-1);   // place holder
    }
};

