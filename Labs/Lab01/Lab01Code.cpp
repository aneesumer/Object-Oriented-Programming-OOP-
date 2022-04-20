
  
// Anees Umer
// OOP Lab01

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Function Prototypes
bool fileRead(vector<int> &vec, const string &filename);
bool condMaxSearch (vector <int> &vec, int &maxi, int &ind);

int main()
{
    vector<int> vec;
    int maxi, ind;
    string fileName = "input.txt";
    if(fileRead(vec, fileName)) {
        cout << "File Reading is successful!!" << endl;
    }
    else {

        cout << "File cant be read!!" << endl;
    }

    if (condMaxSearch(vec, maxi, ind)) {
        cout << "The Highest valley is " << maxi << endl;
    }
    else {
        cout << "Cant find the Highest Valley!!" << endl;
    }
    return 0;
}

// Function for reading file
bool fileRead(vector<int> &vec, const string &filename) {
    fstream f(filename);

    if(f.fail()) {
        return false;
    }
    else {
        int e;
        vec.clear();
        while (f >> e) {
            vec.push_back(e);
        }

        return true;
    }

}

// Function for finding consitional maximum 
bool condMaxSearch (vector <int> &vec, int &maxi, int &ind) {
    bool l = false;
    for (int i = 1; i < vec.size() - 1; i++) {
        if (!l && vec.at(i) < vec.at(i-1) && vec.at(i) < vec.at(i+1)) {
            maxi = vec.at(i);
            ind = i;
            l = true;
        }
        else if(l && vec.at(i) < vec.at(i-1) && vec.at(i) < vec.at(i+1)) {
            if (maxi < vec.at(i)) {
                maxi = vec.at(i);
                ind = i;
                l = true;
            }
        }
    }

    return l;
}
