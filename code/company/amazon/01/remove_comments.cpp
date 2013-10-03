#include <sstream>
#include <iostream>
#include <string>
#include <cstdio>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;

string removeComment(string s) {
    istringstream stream(s);
    string line;
    string::iterator sq_start_iter; // single quote
    string::iterator dq_start_iter; // double quote
    string::iterator dsc_start_iter; // double slash(//) comments
    string::iterator ssc_start_iter; // single slash(/*) comments
    sq_start_iter = dq_start_iter = dsc_start_iter = ssc_start_iter = NULL;
    string result;
    while (getline(stream, line))
    {
        // cout << line << endl;
        string::iterator iter = line.begin();
        while (iter != line.end())
        {
            switch(*iter)
            {
                // 双引号情况
                case '\"':
                    // 之前不存在单个未匹配的双引号, 单引号, 或者块注释符
                    if (dq_start_iter == NULL && sq_start_iter == NULL && ssc_start_iter == NULL)
                    {
                        dq_start_iter = iter; // 标记新的双引号开始

                        // 在本行查找与该双引号匹配的另一个双引号
                        while (*iter != '\"' && iter != line.end())
                            ++iter;

                        // 在本行匹配到另一个双引号
                        if (*iter != line.end())
                        {
                            dq_start_iter = NULL;
                            continue;
                        }
                    }
                    // 之前有未匹配的双引号
                    else if (dq_start_iter != NULL)
                    {
                        dq_start_iter = NULL;
                        continue;
                    }
                    ++iter;     
                    break;

                case '\'':
                    iter += 2;
                    break;

                case '/':
                    // 注释连接情况
                    if (dsc_start_iter != NULL)
                    {
                        ++iter;
                        continue;
                    }
                    else if (*(iter + 1) == '/')
                    {
                        dsc_start_iter = iter;
                        // 结尾不是注释连接符'\'
                        if (*(line.end() - 1) != '\\')
                            line.erase(dsc_start_iter, line.end());
                        else
                        {
                            while (getline(stream, line))
                            {
                                if (*(line.end() - 1) != '\\')
                            }
                            continue;
                        }
                    }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    freopen("remove_comments.in", "r", stdin);
    string line;
    while (getline(cin, line))
    {
        removeComment(line);
    }
    fclose(stdin);
    return 0;
}