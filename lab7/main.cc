/* Calvin Bui
SID 861064458 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <time.h>
#include <unordered_set>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;


void scramble(vector<string>&x)
{
    for (unsigned int i = 0; i < x.size()*2; i++)
    {
        swap(x[rand()%x.size()], x[rand()%x.size()]);
    }
}

int main(int argv, char* argc[])
{
    
    ifstream infile;
    
    srand(time(NULL));
    infile.open("words.txt");
    if (!infile.is_open())
    {
        cout << "input file error" << endl;
        exit(1);
    }
    string input;
    vector<string> wordsList;
    while (infile >> input)
    {
        wordsList.push_back(input);
    }
    infile.close();
    ofstream outfile;
    outfile.open("data.txt");

    int number = 5000;
    set<string>tree;
    unordered_set<string>hashTable;
    while (number <= 50000)
    {
        tree.clear();
        hashTable.clear();
        auto duration = 0, duration2 = 0, duration3 = 0, duration4 = 0;
        for (int i = 0; i < 10; i++)
        {
            scramble(wordsList);
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            for (int i = 0; i < number; i++)
            {
                tree.insert(wordsList.at(i));
            }
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            duration += std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
            cout << "tree insert time: " << duration/number << endl;
            
            high_resolution_clock::time_point ft1 = high_resolution_clock::now();
            for (int i = 0; i < number; i++)
            {
                tree.find(wordsList.at(i));
            }
            high_resolution_clock::time_point ft2 = high_resolution_clock::now();
            duration2 += std::chrono::duration_cast<std::chrono::microseconds>(ft2-ft1).count();
            cout << "tree find time: " << duration2 << endl;
        
            high_resolution_clock::time_point h1 = high_resolution_clock::now();
            for (int i = 0; i < number; i++)
            {
                hashTable.insert(wordsList.at(i));
            }
            high_resolution_clock::time_point h2 = high_resolution_clock::now();
            duration3 += std::chrono::duration_cast<std::chrono::microseconds>(h2-h1).count();
            cout << "hash table insert time: " << duration3 << endl;
            
            high_resolution_clock::time_point fh1 = high_resolution_clock::now();
            for (int i = 0; i < number; i++)
            {
                hashTable.find(wordsList.at(i));
            }
            high_resolution_clock::time_point fh2 = high_resolution_clock::now();
            duration4 += std::chrono::duration_cast<std::chrono::microseconds>(fh2-fh1).count();
            cout << "hash table find time: " << duration4 << endl;
        }
        outfile << number << ' ' << duration/10 << ' ' << duration3/10 << ' ' 
                << duration2/10 << ' ' << duration4/10 << endl;
        number += 5000;
    }  
    outfile.close();
    scramble(wordsList);
}