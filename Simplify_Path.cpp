class Solution {
public:
	string simplifyPath(string path) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len = path.size();
		vector<string> vec;
		string folder;
		for( int i = 0; i < len; ++i )
		{
			if( s[i] == '/' ) 
			{
				if( folder != "" ) vec.push_back(folder);
				folder = "";
			}
			else if( s[i] == '.' )
			{
				if( s[i+1] )
			}
		}
	}
};

