class Solution {
public:
    vector<string> v;
    vector<string> Permutation(string str) {
        if (str == "") return v;
        sort(str.begin(), str.end());
        string str2 = "";
        dfs(str, str2);
        return v;
    }

    void  dfs(string str1, string str2)
    {
        if (str1 == "")
            v.push_back(str2);
        else 
        {
            int i = 0;
            while (i < str1.size())
            {
                str2 += str1[i];
                str1.erase(i, 1);
                dfs(str1, str2);
                str1.insert(str1.begin()+i, str2.back());
                str2.erase(str2.size()-1, 1);
                int j = i+1;
                while (str1[j] == str1[i] && j < str1.size())
                {
                    j++;
                }
                if (j < str1.size())
                    i = j;
                else
                    break;
            }
            
        }
    }
};;
