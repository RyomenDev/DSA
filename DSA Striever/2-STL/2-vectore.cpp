
#include <iostream>
#include <vector>
using namespace std;

void explain_vetors()
{

    vector<int> v1;
    v1.push_back(1);
    v1.emplace_back(2);
    v1.emplace_back(3);
    v1.emplace_back(4);
    // {1,2,3,4}

    cout << v1[0] << endl; // 1
    vector<int>::iterator it = v1.begin();
    it++;
    cout << *(it) << endl;     // 2
    cout << v1.back() << endl; // 2

    //

    //

    //

    {
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *(it) << " ";
        }
        cout << endl;
        for (auto it = v1.begin(); it != v1.end(); it++)
        {
            cout << *(it) << " ";
        }
        cout << endl;
        for (auto it : v1)
        {
            cout << (it) << " ";
        }
        cout << endl;
    }

    //

    //

    {
        auto x1 = v1.begin();  // iterator pointing to first element
        cout << *(x1) << endl; // 1

        {
            auto x2 = v1.end(); // after last element -theoretical
            x2--;
            cout << *(x2) << endl; // 4

            auto x3 = v1.rbegin(); // moves last to first element
            cout << *(x3) << endl; // 4
        }

        auto x4 = v1.rend(); // before first element -theoretical - reverse
        x4--;                // 1
        x4--;                // 2
        cout << *(x4) << endl;

        auto x5 = v1.cbegin(); // constant iterator = 1
        // x5++;2
        cout << *(x5) << endl; // 1

        auto x6 = v1.cend();
        x6--;
        cout << *(x6) << endl; // 4

        auto x7 = v1.crbegin(); // constant reverse iteratorpointing last element - moves last to first
        // x7++;3
        cout << *(x7) << endl; // 4

        auto x8 = v1.crend();  // constant reverse iterator pointing theoretical element precceding first element
        x8--;                  // reverse
        cout << *(x8) << endl; // 1
    }

    cout << v1.back() << endl; // 3

    {
        cout << v1.size() << endl;     // number of elements in vector
        cout << v1.max_size() << endl; // max number of elements vector can hold
        cout << v1.capacity() << endl; // 4 -  current storage allocted

        // v1.resize(8);               // resie the container
        // cout << v1.size() << endl;  // 8
        cout << v1.empty() << endl; // 0 - if empty     1-else
    }

    //

    //

    //

    cout << "Element access" << endl;

    {
        // y1=v1.reference
        cout << v1.at(2) << endl;   // 3
        cout << v1.front() << endl; // 1
        cout << v1.back() << endl;  // 3
        cout << v1.data() << endl;  // direct pointer to memory array used internally by te vector to store its owned elements
        cout << *v1.data() << endl; // 1
    }

    //

    //

    //

    cout << "modifiers" << endl;

    {

        {
            vector<int> va;
            va.assign(5, 1); //(size,value)
            for (auto i = 0; i < va.size(); i++)
            {
                cout << va.at(i) << " "; // 1 1 1 1 1
            }
            cout << endl;
            int a[] = {9, 8, 7, 6, 5, 4};
            va.assign(a, a + 4); //(arr,arr+size) arr which is to be assigned  size-num of elements t be assigned from beginning
            for (auto i = 0; i < va.size(); i++)
            {
                cout << va.at(i) << " "; // 9 8 7 6
            }
            cout << endl;
        }

        {
            v1.push_back(8);
            for (auto i = 0; i < v1.size(); i++)
            {
                cout << v1.at(i) << " "; // 1 2 3 4 8
            }
            cout << endl;
        }
        {
            v1.pop_back();
            for (auto i = 0; i < v1.size(); i++)
            {
                cout << v1.at(i) << " "; // 1 2 3 4
            }
            cout << endl;
        }

        {
            v1.insert(v1.begin() + 3, 9); //(position,val)
            for (auto i = 0; i < v1.size(); i++)
            {
                cout << v1.at(i) << " "; // 1 2 3 9 4
            }
            cout << endl;
        }

        {
            v1.insert(v1.begin() + 3, 2, 7); //(position,size,val)
            for (auto i = 0; i < v1.size(); i++)
            {
                cout << v1.at(i) << " "; // 1 2 3 7 7 9 4
            }
            cout << endl;
        }

        // {
        // to remove all the elements of the vector container
        // v1.clear();
        // cout << v1.empty() << endl; // 1
        // }
        {
            vector<int> vs1{9, 8, 7};
            vector<int> vs2{1, 2, 3};
            vs1.swap(vs2);
            for (auto it : vs1)
            {
                cout << (it) << " "; // 1 2 3
            }
            cout << endl;
            for (auto it : vs2)
            {
                cout << (it) << " "; // 9 8 7
            }
            cout << endl;
        }
        {
            {it = v1.begin();
        v1.erase(it); // remove elements one by one
        for (auto it : v1)
        {
            cout << (it) << " "; // 2 3 7 7 9 4
        }
        cout << endl;

        {
            auto it1 = v1.begin();
            auto it2 = it1 + 5;
            it1 = it1 + 2;
            v1.erase(it1, it2); // remove elements within range
            for (auto it : v1)
            {
                cout << (it) << " "; // 2 3 4
            }
            cout << endl;
        }
    }
}
{
    {
        v1.emplace(v1.begin() + 1, 9); //(const_iterator_position,element)
        for (auto it : v1)
        {
            cout << (it) << " "; // 2 9 3 4
        }
        cout << endl;
    }
    {
        v1.emplace_back(7); // added at end of vector
        for (auto it : v1)
        {
            cout << (it) << " "; // 2 9 3 4 7
        }
        cout << endl;
    }
}
}

//

//
 

vector<pair<int, int>> v2;
v2.push_back({1, 2});
v2.emplace_back(1, 2);
v2.emplace_back(3, 4);

vector<int> v3(5, 100);
vector<int> v4(5);

vector<int> v5(5, 20);
vector<int> v6(v4);
}

int main()
{
    explain_vetors();

    return 0;
}