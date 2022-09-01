#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "head.h"
#include "m_time.h"

void mohu_info(node* l,char* info,int xuhao);
int daying(node* l,int cnt);
void mohu_grand(node* l,char* info,const int xuhao);
int daying_grand(node* l,int cnt);
//模糊查询学生信息界面
void mo_find_xs_info(void)
{
    int xuhao;
    char g_j_z[20];
    while(1)
    {
        printf("\033c");
        printf("\n        *******************管理员查询学生用户信息界面*******************\n");
        m_time();
        printf("\n域名：    班级（1）      学号（2）      姓名（3）      身份证号码（4）      手机号（5）\n");
        printf("\n                   请管理员选择需要查询的关键字所在的域名：");
        if(!scanf("%d",&xuhao)) 
        {
            while(getchar() != '\n');
            xuhao = 0;
        }
        if(xuhao != 1 && xuhao != 2 && xuhao != 3 && xuhao != 4 && xuhao != 5)
        {
            printf("\n                  您输入的关键字所在的域名错误，请重新输入！\n");
            fflush(stdout);
            sleep(2);
            mo_find_xs_info();
        }
        printf("\n                   请管理员输入此域名中的关键字：");
        scanf("%s",g_j_z);
        printf("\n          *******************查询结果如下所示*******************\n");
        m_time();
        printf("\n  班级            学号      姓名              身份证号             密码       手机号");
        printf("\n-----------------------------------------------------------------------------------------\n");
        mohu_info(stu_list,g_j_z,xuhao);
        printf("\n\n退出系统（0）                    继续查询学生用户信息（1）                     返回上一级（-1）\n");
        int caozuo;
        printf("\n请管理员选择对应的操作：");
        if(!scanf("%d",&caozuo))
        {
            while(getchar() != '\n')
            caozuo  = -2;
        }
        while(caozuo != 0 && caozuo != 1 && caozuo != -1)
        {
            printf("输入操作序号错误，请重新输入！\n");
            printf("\n请管理员选择对应的操作：");
            if(!scanf("%d",&caozuo))
            {
                while(getchar() != '\n')
                caozuo  = -2;
            }
            if(caozuo == -1||caozuo == 0||caozuo == 1)
                break;
        }
        switch(caozuo)
        {
            case -1:
            {
                //返回上一级
                gly_gui();
            }
            break;
            case 0:
            {
                //退出系统
                printf("\n                     感谢管理员用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            break;
            case 1:
            {
                //继续
                continue;
            }
            break;
        }
    }
}

void mohu_info(node* l,char* info,const int xuhao)
{
    int cnt ;
    cnt = 0;
    l = l->next;
    while(l != NULL)
    {
        if((xuhao == 1) && (strstr(l->data.s_class,info) != NULL))
            cnt = daying(l,cnt);
        else if((xuhao == 2) && (strstr(l->data.s_son,info) != NULL))
            cnt = daying(l,cnt);
        else if((xuhao == 3) && (strstr(l->data.s_name,info) != NULL))
            cnt = daying(l,cnt);
        else if((xuhao == 4) && (strstr(l->data.s_idcard,info) != NULL))
            cnt = daying(l,cnt);
        else if((xuhao == 5) && (strstr(l->data.s_number,info) != NULL)) 
            cnt = daying(l,cnt);
        l = l->next;
    }
    if(cnt == 0)
        printf("\n                抱歉，未能查询到与关键词相关的学生信息！\n");
    if(cnt != 0 )
        printf("\n               为您查询到与关键词相关的 %d 位学生用户信息!\n",cnt);
}

int daying(node* l,int cnt)
{
    printf("%-20s%-10s%-15s%-25s%-10s%-20s\n",l->data.s_class,l->data.s_son,l->data.s_name,l->data.s_idcard,l->data.s_pass,l->data.s_number);
    printf("-----------------------------------------------------------------------------------------\n");
    cnt++;
    return cnt;
}


//模糊查询学生信息界面
void mo_find_xs_grand(void)
{
    int xuhao;
    char g_j_z[20];
    while(1)
    {
        printf("\033c");
        printf("\n        *******************管理员查询学生用户成绩界面*******************\n");
        m_time();
        printf("\n域名：          班级（1）            学号（2）            姓名（3）            成绩（4）\n");
        printf("\n                   请管理员选择需要查询的关键字所在的域名：");
        if(!scanf("%d",&xuhao)) 
        {
            while(getchar() != '\n');
            xuhao = 0;
        }
        if(xuhao != 1 && xuhao != 2 && xuhao != 3 && xuhao != 4)
        {
            printf("\n                  您输入的关键字所在的域名错误，请重新输入！\n");
            fflush(stdout);
            sleep(2);
            mo_find_xs_grand();
        }
        printf("\n                   请管理员输入此域名中的关键字：");
        scanf("%s",g_j_z);
        printf("\n          *******************查询结果如下所示*******************\n");
        m_time();
        printf("\n  班级    学号  姓名    课程名     考试时间      成绩   课程名     考试时间      成绩   课程名     考试时间      成绩");
        printf("\n----------------------------------------------------------------------------------------------------------------------\n");
        mohu_grand(stu_list,g_j_z,xuhao);
        printf("\n\n退出系统（0）                          继续查询学生用户成绩（1）                       返回上一级（-1）\n");
        int caozuo;
        printf("\n请管理员选择对应的操作：");
        if(!scanf("%d",&caozuo))
        {
            while(getchar() != '\n')
            caozuo  = -2;
        }
        while(caozuo != 0 && caozuo != 1 && caozuo != -1)
        {
            printf("输入操作序号错误，请重新输入！\n");
            printf("\n请管理员选择对应的操作：");
            if(!scanf("%d",&caozuo))
            {
                while(getchar() != '\n')
                caozuo  = -2;
            }
            if(caozuo == -1||caozuo == 0||caozuo == 1)
                break;
        }
        switch(caozuo)
        {
            case -1:
            {
                //返回上一级
                gly_gui();
            }
            break;
            case 0:
            {
                //退出系统
                printf("\n                     感谢管理员用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            break;
            case 1:
            {
                //继续
                continue;
            }
            break;
        }
    }
}

void mohu_grand(node* l,char* info,const int xuhao)
{
    int cnt ;
    cnt = 0;
    l = l->next;
    while(l != NULL)
    {
        if(l->data.student_g.student_g_is_lr == 1)
        {
            if((xuhao == 1) && (strstr(l->data.s_class,info) != NULL))
                cnt = daying_grand(l,cnt);
            else if((xuhao == 2) && (strstr(l->data.s_son,info) != NULL))
                cnt = daying_grand(l,cnt);
            else if((xuhao == 3) && (strstr(l->data.s_name,info) != NULL))
                cnt = daying_grand(l,cnt);
            else if((xuhao == 4) && ((l->data.student_g.g_grade.chinese_grade==atof(info))||(l->data.student_g.g_grade.math_grade==atof(info))||(l->data.student_g.g_grade.english_grade==atof(info))))
                cnt = daying_grand(l,cnt);
            l = l->next;
        }
        else if(l->data.student_g.student_g_is_lr == 0)
        {
            l = l->next;
        }
    }
    if(cnt == 0)
        printf("\n                抱歉，未能查询到与关键词相关的学生信息！\n");
    if(cnt != 0 )
        printf("\n               为您查询到与关键词相关的 %d 位学生用户信息!\n",cnt);
}

int daying_grand(node* l,int cnt)
{
    printf("%s  %s  %s    %s   %s  %.2f   %s  %s  %.2f   %s  %s  %.2f",l->data.s_class,l->data.s_son,l->data.s_name,l->data.student_g.g_cno.chinese,l->data.student_g.g_time.chinese_time,l->data.student_g.g_grade.chinese_grade,l->data.student_g.g_cno.math,l->data.student_g.g_time.math_time,l->data.student_g.g_grade.math_grade,l->data.student_g.g_cno.english,l->data.student_g.g_time.english_time,l->data.student_g.g_grade.english_grade);
    printf("\n----------------------------------------------------------------------------------------------------------------------\n");
    cnt++;
    return cnt;
}