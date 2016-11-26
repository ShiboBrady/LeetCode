class Solution {
    public:
        int lengthLongestPath(string input) {
            vector<string> vecLevel;
            int length = 0;
            size_t pos = 0, nextPos = 0;
            while(1) {
                nextPos = input.find('\n', pos);
                string subStr = input.substr(pos, nextPos - pos);

                int level = GetLevel(subStr);

                while (!vecLevel.empty() && vecLevel.size() - 1 >= level) {
                    vecLevel.pop_back();
                }

                vecLevel.push_back(subStr);

                if (IsFile(subStr)) {
                    length = max(GetPathLength(vecLevel), length);
                }

                if (string::npos == nextPos) {
                    break;
                }
                pos = nextPos + 1;
            }
            return length;
        }

        int GetPathLength(const vector<string>& vecPath) {
            int length = 0;
            for (auto& path: vecPath) {
                length += path.length();
                length++;//每层文件夹之间的‘/’
            }
            length--;
            return length;
        }

        bool IsFile(const string& str) {
            if (string::npos == str.find('.')) {
                return false;
            }
            return true;
        }

        int GetLevel(string& str) {
            int strLen = str.length();
            int levelNum = 0;
            for (auto& c: str) {
                if ('\t' == c) {
                    ++levelNum;
                }
            }
            str = str.substr(levelNum);
            return levelNum;
        }
};
