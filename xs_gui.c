#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "head.h"
#include "m_time.h"

void find_xs_info(void);
void find_xs_grand(void);

void xs_gui(void)
{
    printf("\033c");
    printf("\n        *******************学生用户管理界面********************\n");
    m_time();
    printf("\n------------------------------------------------------------------------\n");
    printf("*                           1.查询个人信息                             *\n");
    printf("*----------------------------------------------------------------------*\n"); 
    printf("*                           2.查询个人成绩                             *\n");
    printf("*----------------------------------------------------------------------*\n"); 
    printf("\n退出系统（0）                                           返回上一级（-1）\n");

    int xuhao;
    while(1)
    {
        printf("请学生用户选择对应的操作：");
        if(!scanf("%d",&xuhao))
        {
            while(getchar() != '\n');
            xuhao = -2;
        }
        switch(xuhao)
        {
            case -1:
            {
                //返回上一级
                xs_dl_gui();
            }
            break;
            case 0:
            {
                //退出系统
                printf("\n                     感谢学生用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            break;
            case 1:
            {
                //查询个人信息
                find_xs_info();
            }
            break;
            case 2:
            {
                //查询个人成绩
                find_xs_grand();
            }
            break;
            default:
            {
                printf("输入操作序号错误，请重新输入！\n");
            }
            break;
        }
    }
}


//查询个人信息
void find_xs_info(void)
{
    student_info* s_i = NULL;
    s_i = myfind(stu_list,xsyh_cc_zh);
    printf("\033c");
    printf("\n      ******************学生用户信息界面******************\n");
    m_time();
    printf("\n  班级            学号      姓名              身份证号             密码       手机号");
    printf("\n-----------------------------------------------------------------------------------------\n");
    printf("%-20s%-10s%-15s%-25s%-10s%-20s\n",s_i->s_class,s_i->s_son,s_i->s_name,s_i->s_idcard,s_i->s_pass,s_i->s_number);

    printf("\n退出系统（0）                                                              返回上一级（-1）\n");
    int xuhao;
    while(1)
    {
        printf("\n请学生用户选择对应的操作：");
        if(!scanf("%d",&xuhao))
        {
            while(getchar() != '\n');
            xuhao = -2;
        }
        switch(xuhao)
        {
            case 0:
            {
                printf("\n                        感谢学生用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            break;
            case -1:
            {
                xs_gui();
            }
            break;
            default:
            {
                printf("输入操作序号错误，请重新输入！\n");
            }
            break;
        }
    }

}


//查询个人成绩
void find_xs_grand(void)
{
    student_info* s_i = NULL;
    s_i = myfind(stu_list,xsyh_cc_zh);
    printf("\033c");
    printf("\n      ******************学生用户成绩界面******************\n");
    m_time();
    printf("\n  班级    学号  姓名    课程名     考试时间      成绩   课程名     考试时间      成绩   课程名     考试时间      成绩");
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
    if(s_i->student_g.student_g_is_lr == 0)
    {
        printf("                                      抱歉，管理员暂未录入您的成绩信息，无法查询！\n");
    }
    else
        printf("%s  %s  %s    %s   %s  %.2f   %s  %s  %.2f   %s  %s  %.2f\n", s_i->s_class, s_i->s_son, s_i->s_name, s_i->student_g.g_cno.chinese, s_i->student_g.g_time.chinese_time, s_i->student_g.g_grade.chinese_grade, s_i->student_g.g_cno.math, s_i->student_g.g_time.math_time, s_i->student_g.g_grade.math_grade, s_i->student_g.g_cno.english, s_i->student_g.g_time.english_time, s_i->student_g.g_grade.english_grade);
    printf("\n退出系统（0）                                                                                          返回上一级（-1）\n");
    int xuhao;
    while(1)
    {
        printf("\n请学生用户选择对应的操作：");
        if(!scanf("%d",&xuhao))
        {
            while(getchar() != '\n');
            xuhao = -2;
        }
        switch(xuhao)
        {
            case 0:
            {
                printf("\n                        感谢学生用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            break;
            case -1:
            {
                xs_gui();
            }
            break;
            default:
            {
                printf("输入操作序号错误，请重新输入！\n");
            }
            break;
        }
    }
}
