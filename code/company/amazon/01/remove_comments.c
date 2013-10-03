#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
char* removeComment(char* s)
{
    size_t size = strlen(s);
    char *p, *end, c;          //p-动态移动的字符指针，end-指向文件末尾的字符指针，c-存储没一个p指向的字符
    char *sq_start, *dq_start; //sq_start-单引号开始位置（single），dq_start-双引号开始（double）
    char *lc_start, *bc_start; //lc_start-//的开始位置，bc_start-/*的开始位置
    size_t len;                //记录某符号结束和开始的位置之差（长度，偏移量）

    p = s;
    end = p + size;
    sq_start = dq_start = NULL;
    lc_start = bc_start = NULL;

    while ((*p) != '\0') /*当指针没有到达文件末尾 */
    {
        c = *p;     //用字符变量c存储指针指向的字符

        switch (c) //根据c的值做相应处理
        {
            case '\'': /*处理单引号*/
                {
                    if (dq_start || lc_start || bc_start) //当遇到过双引号、//或/*的时候，则不需要再判断'//'的情况了。
                    {
                        p++;
                        continue; //继续下一个，对while而言的
                    }
                    /*以下是没有遇到过双引号或//或/*的时候*/
                    if (sq_start == NULL) /*如果未遇到单引号*/
                    {
                        sq_start = p++; //start指向单引号的开始位置，p指向下一个
                    }
                    else /*如果遇到过单引号，sq_start指向单引号开始位置*/
                    {
                        len = (p++) -sq_start;
                        if (len == 2 && *(sq_start+1) == '\\') 
                        {
                            /*若遇到 “  '\''   ”这种情况则两个单引号并未匹配，遇到的“'”是“\' ”中的，而不是与sq_start所指向单引号匹配*/
                            continue;
                        }

                        sq_start = NULL; //否则将sq_start置位为NULL
                    }
                    /*以上是没有遇到过双引号或//或/*的时候*/
                    break;
                }

            case '\"': /*处理双引号*/
                {
                    if (sq_start || lc_start || bc_start) //当遇到过单引号、//或/*的时候，则不需要处理
                    {
                        p++;
                        continue;
                    }
                    /*以下是没有遇到过单引号或//或/*的时候*/
                    if (dq_start == NULL) /*如果没有遇到过双引号*/
                    {
                        dq_start = p++; //标记遇到了双引号
                    }
                    else if (*((p++) -1) =='\\') 
                    {
                        /*若遇到 “" ab\''cd"   ”这种情况则两个双引号并未匹配，遇到的“"”是“\"”中的，而不是与dq_start所指向双引号匹配*/
                        continue;
                    }
                    dq_start = NULL; //如果双引号中不是//，标记为NULL
                    /*以上是没有遇到过单引号或//或/*的时候*/
                }

            case '/': //斜杠，注意这个斜杠也可以是'//'，"//",//,/*/中的第二个斜杠，但会在下面第二行代码中被忽略掉
                {
                    if (sq_start || dq_start || lc_start || bc_start) //如果是单引号、双引号、斜杠、/*的后面
                    {
                        p++;
                        continue;
                    }
                    /*下面是遇到注释//或/*的时候*/
                    c = *(p + 1); //否则c取p指向字符的下一个字符
                    if (c == '/') //遇到了双斜杠
                    {
                        lc_start = p; //标记双斜杠的开始
                        p += 2; //p指向双斜杠后面的字符
                    }
                    else if (c == '*') //遇到了/*
                    {
                        bc_start = p; //标记/*的开始
                        p += 2; //p指向/*后面的字符
                    }
                    /*上面是遇到注释//或/*的时候*/
                    else
                    { 
                        p++; 
                    }
                }

            case '*': //星号，同斜杠，但少了如果遇到/*的情况，因为遇到这种情况后，要判断是不是遇到结束的地方*/了
                {
                    if (sq_start || dq_start || lc_start) //如果是单引号、双引号、斜杠、/*的后面
                    {
                        p++;
                        continue; 
                    }

                    if (*(p + 1) != '/') //如果星号后面紧跟的不是斜杠，那么忽略过。
                    {
                        p++;
                        continue;
                    }

                    p += 2; //否则p指向斜杠后面那个字符。注意下面的清空语句，p指向的那个字符并不会被清除。
                    memset(bc_start, ' ', p-bc_start); //清空/* …… */中间的内容包括注释符号本身。
                    bc_start = NULL;
                    break;
                }

            case '\n': /*换行符，主要处理遇到双斜杠时，需要清除双斜杠到\n的前面的字符*/
                {
                    if (lc_start == NULL) //如果还没有遇到双斜杠，那么忽略
                    {
                        p++;
                        continue; 
                    }

                    c = *(p - 1);
                    /*如果遇到过双斜杠，清空双斜杠本身和到\n前面的那个字符，p指向下一个字符，/r是回车符（光标退回到最前面），这里要判断
                      c == '\r'是因为在UNIX系统下文件结尾的换行只有\n，而windows系统下文件结尾的换行为\r\n   */
                    memset(lc_start, ' ', (c == '\r'? ((p++) -1) : p++) - lc_start); 
                    lc_start = NULL;
                    break;
                }

            default:
                p++;
                break;
        }
        /****************************************************
          如果遇到双斜杠，这个if语句存在的意义在于万一最后
          一行代码是带有双斜杠但没有给换行符\n的，也要清除掉。
         *****************************************************/
        if (lc_start) 
        {
            memset(lc_start, ' ', p - lc_start);
        }
    }

    return s;
}
/**********************************************
  main函数的开始
 ***********************************************/
int main (int argc, char *argv[])
{
    int fd, n;
    char buf[102400];

    if (argc != 2)
    {
        printf("command error: Input as ./command <file>\n");
    }

    fd = open(argv[1], O_RDONLY); /*只读打开*/
    if (fd == -1)
    {
        return -1;
    }

    n = read(fd, buf, sizeof(buf));
    if (n == -1 || n == 0)
    {
        close(fd);
        return -1;
    }
    printf("test\n");
    char *result = removeComment(buf);
    // *(buf + n) = '\0';
    // printf("%s", buf);
    *(result + n) = '\0';
    printf("%s", result);
    close(fd);

    return 0;
}
