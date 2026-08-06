#include <bits/stdc++.h>
using namespace std;

// ---------- Basic parsers ----------

class Solution {
public:
   
};

string readInput() {
    return string(
        istreambuf_iterator<char>(cin),
        istreambuf_iterator<char>()
    );
}

vector<long long> getNumbers(const string& s) {
    vector<long long> result;
    regex pattern(R"(-?\d+(\.\d+)?)");

    for (sregex_iterator it(s.begin(), s.end(), pattern), end;
         it != end; ++it) {
        result.push_back(stoll(it->str()));
    }

    return result;
}

vector<string> getStrings(const string& s) {
    vector<string> result;
    regex pattern(R"(["']([^"']*)["'])");

    for (sregex_iterator it(s.begin(), s.end(), pattern), end;
         it != end; ++it) {
        result.push_back((*it)[1]);
    }

    return result;
}

// ---------- Output helpers ----------

template <typename T>
void printValue(const T& value) {
    cout << value << '\n';
}

template <typename T>
void printValue(const vector<T>& values) {
    cout << '[';

    for (int i = 0; i < (int)values.size(); i++) {
        if (i) cout << ',';
        printValue(values[i]);
    }

    cout << "]\n";
}

void printValue(const string& value) {
    cout << '"' << value << '"';
}

void printValue(char value) {
    cout << '"' << value << '"';
}

void printValue(bool value) {
    cout << (value ? "true" : "false") << '\n';
}

// ---------- LeetCode node types ----------

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int value) : val(value), next(nullptr) {}
};

ListNode* makeList(const vector<long long>& values) {
    ListNode dummy(0);
    ListNode* current = &dummy;

    for (long long value : values) {
        current->next = new ListNode((int)value);
        current = current->next;
    }

    return dummy.next;
}

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value)
        : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* makeTree(const vector<long long>& values) {
    if (values.empty()) return nullptr;

    TreeNode* root = new TreeNode((int)values[0]);
    queue<TreeNode*> q;
    q.push(root);

    int index = 1;

    while (!q.empty() && index < (int)values.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (values[index] != LLONG_MIN) {
            current->left = new TreeNode((int)values[index]);
            q.push(current->left);
        }
        index++;

        if (index < (int)values.size() &&
            values[index] != LLONG_MIN) {
            current->right = new TreeNode((int)values[index]);
            q.push(current->right);
        }
        index++;
    }

    return root;
}

// ---------- Your LeetCode class goes above ----------


// ---------- Main driver ----------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input = readInput();

    vector<long long> numbers = getNumbers(input);
    vector<string> strings = getStrings(input);

    Solution sol;

    /*
    Select ONE driver below.
    Delete or comment out the others.
    */

    // 1. Several integer arguments
    // Example: n = 3, a = 2, b = 3, c = 5
    //
    // cout << sol.nthUglyNumber(
    //     (int)numbers[0],
    //     (int)numbers[1],
    //     (int)numbers[2],
    //     (int)numbers[3]
    // ) << '\n';


    // 2. One integer argument
    // Example: n = 10
    //
    // cout << sol.someFunction((int)numbers[0]) << '\n';


    // 3. One vector<int> argument
    // Example: nums = [1, 2, 3, 4]
    //
    // vector<int> nums;
    // for (long long x : numbers)
    //     nums.push_back((int)x);
    //
    // printValue(sol.someFunction(nums));


    // 4. One vector<string> argument
    // Example: strs = ["flower", "flow", "flight"]
    //
    // printValue(sol.someFunction(strings));


    // 5. Matrix of integers
    // Example: mat = [[0,0,0],[0,1,0],[0,0,0]]
    //
    // vector<vector<int>> mat = {
    //     {0, 0, 0},
    //     {0, 1, 0},
    //     {0, 0, 0}
    // };
    //
    // printValue(sol.someFunction(mat));


    // 6. Grid of strings/chars
    // Example: grid = [["1","1","0"],["1","0","0"]]
    //
    // vector<vector<char>> grid = {
    //     {'1', '1', '0'},
    //     {'1', '0', '0'}
    // };
    //
    // cout << sol.someFunction(grid) << '\n';


    // 7. Linked list
    // Example: head = [1,2,3,4]
    //
    // ListNode* head = makeList(numbers);
    // ListNode* answer = sol.someFunction(head);
    //
    // while (answer) {
    //     cout << answer->val << ' ';
    //     answer = answer->next;
    // }
    // cout << '\n';


    // 8. Binary tree
    // Example: root = [1,2,3,null,4]
    //
    // vector<long long> treeValues = {
    //     1, 2, 3, LLONG_MIN, 4
    // };
    //
    // TreeNode* root = makeTree(treeValues);
    // cout << sol.someFunction(root) << '\n';


    // 9. Boolean result
    // Example: s = "racecar"
    //
    // cout << boolalpha << sol.someFunction(strings[0]) << '\n';


    return 0;
}