//when temp is empty and c is #, cant pop
class Solution_0 {
public:
    bool backspaceCompare(string s, string t) {
        return newstring(s) == newstring(t);
    }

    string newstring (string str)
    {
        string temp = "";
        for(auto c:str)
        {
            if(c=='#' && !temp.empty())
            {
                temp.pop_back();
            }
            else
            {
                temp.push_back(c);
            }
        }
        return temp;
    }
};