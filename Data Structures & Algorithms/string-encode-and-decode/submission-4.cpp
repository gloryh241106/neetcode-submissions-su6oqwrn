class Solution {
public:
    string encode(vector<string>& strs) {
        string res = "";
        for (const string &s : strs) 
            res += to_string(s.size()) + "#" + s;

        return res;
    }

    vector<string> decode(string s) {
        vector<string> mp;
        int i = 0;

        while (i < s.size()) {
            string str_size = "";
            while (s[i] != '#') 
                str_size += s[i++];

            int size = stoi(str_size);
            i++;

            mp.push_back(s.substr(i, size));
            i += size;
        }

        return mp;
    }
};
