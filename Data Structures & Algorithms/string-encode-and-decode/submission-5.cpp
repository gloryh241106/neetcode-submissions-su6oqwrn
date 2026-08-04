class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (const string &s : strs)
            encoded_string += (to_string(s.size()) + "#" + s);

        return encoded_string; 
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;

        while (i < s.size()) {
            string size = "";
            while (s[i] != '#')
                size += s[i++];

            i++;

            int j = stoi(size);
            strs.push_back(s.substr(i, j));
            i += j;
        }

        return strs;
    }
};
