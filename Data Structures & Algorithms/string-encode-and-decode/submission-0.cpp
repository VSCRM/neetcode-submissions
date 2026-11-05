class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (const string& s : strs)
            result += to_string(s.length()) + "#" + s;
        return result;

    }

    vector<string> decode(string s) {
        vector<string> result;
        size_t i = 0;

        while (i < s.length()) {
           int length = 0;

           while(s[i] != '#') {
                length = length * 10 + (s[i] - '0');
                i++;
           }
           i++;
           result.push_back(s.substr(i, length));
           i += length;
        }
        return result;
    }
};
