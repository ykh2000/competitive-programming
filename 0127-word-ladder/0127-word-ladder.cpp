/***
 * Use - 
 * 1. unodered_set<char> when order doesnot matter - 
 * - uses HashSet
 * - O(1) lookups + memory overhead is minimum
 * - O(1) - 1 Hash + 1 Bucket check
 * There is a Hashfunction - So very minimal comparison
 * 
 * 
 * 2. set<char> - when order matters 
 * - Uses TreeSet
 * - 5X Slower
 * - O(log(n)) -  TreeSet is a Self Balancing (BST)
 * Number of Level - Log(N), base 2
 * 
 */





#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end()); // Dictionary in a set
    /**
     * find function returns - 
     * 1. If Found - Returns the iterator (pointer) to the elment
     * 2. If not found - returns the end() of the list
     */
    if(st.find(endWord) == st.end()) return 0;

    //BFS Queue - [{word1,steps_taken}, {word2,steps_taken}, {word3,steps_taken}]
    queue<pair<string,int>>q;
    q.push({beginWord,1});

    //Visited Set to avoid cycles
    unordered_set<string> vis;
    vis.insert(beginWord);
    

    /**
     * Algorithm : Main
     */
    
     while(!q.empty()){
        string u = q.front().first; //currWord
        int d = q.front().second;
        q.pop(); // Pop the first word
        if(u == endWord) return d;
        /**
         * This is kind of a Brute force 
         * for finding the valid neighbours of the current word in the Queue that is
         * present in the wordList.
         * 
         *  -  There are 3 Characters and 26 letters so about -
         * 78 Combinations 
         * like for "HIT" - It will check for 
         * 1. "AIT", "BIT", "CIT","DIT"....."ZIT"
         * 2. "HAT", "HBT", "HCT"...... "HZT"
         * 3. "HIA","HIB","HIC"....."HIZ"
         *  and will check for each  element in each row if it exist in the WordList (that will be the next neighbour)
         **/

        for (int i = 0; i < u.size(); i++) { // Runs 3 times - 0,1,2
            char org = u[i];
            //Try all 26 Projects
            for(char c = 'a' ; c<='z';c++){ // Runs 26 times 
                if(c == org) continue; // IF we hit the Original Word like for "HIT", we continue
                u[i] = c;

                //Valid unvisited word in the dictionary
                /*
                    Again Find function - same as above 
                 */
                if(st.find(u)!=st.end() && vis.find(u) == vis.end()){
                    vis.insert(u);
                    q.push({u,d+1});
                }
            }
            u[i] = org;

        }

     }
     return 0;

    }
};