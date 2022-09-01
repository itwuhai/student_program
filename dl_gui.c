#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "m_time.h"
#include "head.h"

char* xsyh_cc_zh;

void dl_gui(void)
{
    printf("\033c");
    printf("\n    *******************学生成绩与信息管理系统*******************\n");
    m_time();
    printf("\n----------------------------------------------------------------------\n");
    printf("*                         1.管理员用户登录                           *\n");
    printf("*--------------------------------------------------------------------*\n");
    printf("*                         2. 学生用户登录                            *\n");
    printf("*--------------------------------------------------------------------*\n"); 
    printf("\n退出系统（0）\n");

    int xuhao;
    while(1)
    {
        printf("\n请选择用户登录界面：");
        if(!scanf("%d",&xuhao))
        {
            //如果输失败，就清空缓存区
            while(getchar() != '\n');
            xuhao = -1;
        }
        switch(xuhao)
        {
            case 0:
            {
                //退出系统
                printf("\n                        感谢用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            break;
            case 1:
            {
                //管理员用户登录
                gly_cz();
                printf("\n          *********恭喜管理员登陆成功，欢迎您的使用！*********");
                fflush(stdout);
                sleep(2);
                gly_dl_gui();
            }
            break;
            case 2:
            {
                //学生用户登录
                xsyh_cc_zh = xs_zhmm_dlyz();
                xs_dl_gui();
            }
            break;
            default:
            {
                //输入错误
                printf("\n输入错误，请重新输入！\n");
            }
            break;
        }
    }
}