class Solution {
public:
    bool isLetter(char ch)
    {
        if((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string reverseOnlyLetters(string s) {
        size_t begin = 0;
        size_t end = s.size() - 1;

        while(begin < end)
        {
            while(begin < end && !isLetter(s[begin]))
            {
                begin++;
            }
            while(begin < end && !isLetter(s[end]))
            {
                end--;
            }

            swap(s[begin], s[end]);
            begin++;
            end--;
        }

        return s;

    }
};
