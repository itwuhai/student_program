#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "m_time.h"
#include "head.h"

void clear_hcq(void);
void tjxsyhxx(void);
void save_data(void);
void delete_xs_info(void);
void xg_xs_info(void);

void gly_gui(void)
{
    printf("\033c");
    printf("\n        *********************管理员操作界面*********************\n");
    m_time();
    printf("\n---------------------------------------------------------------------\n");
    printf("*      1.添加学生用户信息          |      2.删除学生用户信息        *\n");
    printf("*-------------------------------------------------------------------*\n");
    printf("*      3.修改学生用户信息          |      4.查询学生用户信息        *\n");
    printf("*-------------------------------------------------------------------*\n");
    printf("*      5.录入学生考试成绩          |      6.删除学生考试成绩        *\n");
    printf("*-------------------------------------------------------------------*\n");
    printf("*      7.修改学生考试成绩          |      8.查询学生成绩信息        *\n");
    printf("*-------------------------------------------------------------------*\n");

    int xuhao;
    while(1)
    {
        printf("请管理员选择对应的操作：");
        if(!scanf("%d",&xuhao))
        {
            while(getchar() != '\n');
            xuhao = -1;
        }
        switch(xuhao)
        {
            case 1:
            {
                //添加学生用户信息
                tjxsyhxx();
            }
            break;
            case 2:
            {
                //删除学生用户信息
                delete_xs_info();
            }
            break;
            case 3:
            {
                //修改学生用户信息
                xg_xs_info();
            }
            break;
            case 4:
            {
                //查询学生用户信息
                show(stu_list);
            }
            break;
            case 5:
            {
                //录入学生考试成绩
                lr_xs_grand();
            }
            break;
            case 6:
            {
                //删除学生考试成绩
                delete_stu_grand();
            }
            break;
            case 7:
            {
                //修改学生考试成绩
                xg_xs_grand();
            }
            break;
            case 8:
            {
                //查询学生考试成绩
                show_grand(stu_list);
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

//添加学生用户信息
void tjxsyhxx(void)
{
    student_info s_i;
    printf("\033c");
    printf("\n      ******************管理员添加学生用户信息界面******************\n");
    m_time();
    printf("\n                   请管理员按照以下提示添加学生用户信息！");
    printf("\n--------------------------------------------------------------------------\n");
    printf("                            班级：");
    scanf("%s",s_i.s_class);
    clear_hcq();
    printf("----------------------------------------------------------------------------\n");
    printf("                            学号：");
    scanf("%s",s_i.s_son);
    if(myfind(stu_list,s_i.s_son) != NULL)
    {
        printf("\n               您想添加的学生用户信息已添加，无须重复添加！\n");
        fflush(stdout);
        sleep(2);
        gly_gui();
    }
    clear_hcq();
    printf("----------------------------------------------------------------------------\n");
    printf("                            姓名：");
    scanf("%s",s_i.s_name);
    clear_hcq();
    printf("----------------------------------------------------------------------------\n");
    while(1)
    {
        printf("                            身份证号：");
        scanf("%s",s_i.s_idcard);
        clear_hcq();
        if(strlen(s_i.s_idcard) == 18)
        {
            printf("----------------------------------------------------------------------------\n");
            memcpy(s_i.s_pass,s_i.s_idcard+12,6);
            printf("                            密码：%s",s_i.s_pass);
            break;
        }
        printf("           %s身份证号输入错误，无法获取正确初始密码！请重新输入：\n",s_i.s_name);
    }
    s_i.s_is_cj = 0;
    s_i.student_g.student_g_is_lr = 0;
    printf("\n----------------------------------------------------------------------------\n");
    printf("                            手机号：");
    scanf("%s",s_i.s_number);
    clear_hcq();
    printf("----------------------------------------------------------------------------\n");
    strcpy(s_i.student_g.g_cno.chinese,"0");
    strcpy(s_i.student_g.g_cno.math,"0");
    strcpy(s_i.student_g.g_cno.english,"0");
    strcpy(s_i.student_g.g_time.chinese_time,"0");
    strcpy(s_i.student_g.g_time.math_time,"0");
    strcpy(s_i.student_g.g_time.english_time,"0");
    s_i.student_g.g_grade.chinese_grade = 0;
    s_i.student_g.g_grade.math_grade = 0;
    s_i.student_g.g_grade.english_grade = 0;
    push_back(stu_list,s_i);
    save_data();
    printf("\n                       添加学生用户信息成功！");
    fflush(stdout);
    sleep(2);
    gly_gui();
}


//用学号删除学生信息
void delete_xs_info(void)
{
    while(1)
    {
        show(stu_list);
        printf("\n\n退出系统（0）                  继续删除学生用户信息（1）                  返回上一级（-1）\n");
        char sno[20];
        printf("\n请管理员输入需要删除学生的学号：");
        scanf("%s",sno);
        if(my_remove(stu_list,sno))
        {
            printf("\n                             删除学生用户信息成功！\n");
            save_data();
            fflush(stdout);
            sleep(2);
            show(stu_list);
            printf("\n\n退出系统（0）                  继续删除学生用户信息（1）                  返回上一级（-1）\n");
        }
        else
        {
            printf("\n                         学生用户信息不存在，删除失败！\n");
        }
        int xuhao;
        while(1)
        {
            printf("\n请管理员选择对应的操作：");
            if(!scanf("%d",&xuhao))
            {
                while(getchar() != '\n');
                xuhao = -2;
            }
            if(xuhao == -1)
            {
                gly_gui();
            }
            if(xuhao == 0)
            {
                printf("\n                        感谢管理员用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            if(xuhao == 1)
            {
                break;
            }
            if((xuhao != -1) && (xuhao != 0) && (xuhao != 1))
            {
                printf("输入操作序号错误，请重新输入！\n");
            }
        }
    }
}

//修改学生用户信息
void xg_xs_info(void)
{
    while(1)
    {
        show(stu_list);
        printf("\n\n退出系统（0）                  继续修改学生用户信息（1）                  返回上一级（-1）\n");
        char sno[20];
        printf("\n请管理员输入需要修改的学生用户学号：");
        scanf("%s",sno);
        student_info* s_i = NULL;
        s_i = myfind(stu_list,sno);
        if(s_i != NULL)
        {
            printf("\n                   请管理员按照以下提示修改学生用户信息！");
            printf("\n--------------------------------------------------------------------------\n");
            printf("                            新班级：");
            scanf("%s",s_i->s_class);
            clear_hcq();
            printf("----------------------------------------------------------------------------\n");
            printf("                            新学号：");
            scanf("%s",s_i->s_son);
            clear_hcq();
            printf("----------------------------------------------------------------------------\n");
            printf("                            新姓名：");
            scanf("%s",s_i->s_name);
            clear_hcq();
            printf("----------------------------------------------------------------------------\n");
            while(1)
            {
                printf("                            新身份证号：");
                scanf("%s",s_i->s_idcard);
                clear_hcq();
                if(strlen(s_i->s_idcard) == 18)
                {
                    printf("----------------------------------------------------------------------------\n");
                    memcpy(s_i->s_pass,s_i->s_idcard+12,6);
                    printf("                            新密码：%s",s_i->s_pass);
                    break;
                }
                printf("           %s身份证号输入错误，无法获取正确初始密码！请重新输入：\n",s_i->s_name);
            }
            s_i->s_is_cj = 0;
            printf("\n----------------------------------------------------------------------------\n");
            printf("                            新手机号：");
            scanf("%s",s_i->s_number);
            clear_hcq();
            printf("----------------------------------------------------------------------------\n");
            printf("\n                             修改学生用户信息成功！\n");
            save_data();
            fflush(stdout);
            sleep(2);
        }
        else
        {
            printf("\n                         您想修改的学生用户信息不存在！\n");
            fflush(stdout);
            sleep(2);
        }
        show(stu_list);
        printf("\n\n退出系统（0）                  继续修改学生用户信息（1）                  返回上一级（-1）\n");
        int xuhao;
        while(1)
        {
            printf("\n请管理员选择对应的操作：");
            if(!scanf("%d",&xuhao))
            {
                while(getchar() != '\n');
                xuhao = -2;
            }
            if(xuhao == -1)
            {
                gly_gui();
            }
            if(xuhao == 0)
            {
                printf("\n                        感谢管理员用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            if(xuhao == 1)
            {
                break;
            }
            if((xuhao != -1) && (xuhao != 0) && (xuhao != 1))
            {
                printf("输入操作序号错误，请重新输入！\n");
            }
        }
    }
}

//录入学生考试成绩
void lr_xs_grand(void)
{
    printf("\033c");
    char sno[20];
    printf("\n      ******************管理员录入学生用户成绩界面******************\n");
    m_time();
    printf("\n--------------------------------------------------------------------------\n");
    printf("              请管理员输入需要录入成绩的学生用户的学号：");
    scanf("%s",sno);
    student_info* s_i;
    s_i = myfind(stu_list,sno);
    if(s_i == NULL)
    {
        printf("\n             您想录入的成绩的学生用户信息不存在，无法录入！\n");
    }
    if(s_i != NULL)
    {
        if(s_i->student_g.student_g_is_lr == 0)
        {
            printf("\n--------------------------------------------------------------------------\n");
            printf("\n               请管理员按照以下提示依次录入该学生用户的成绩!");
            printf("\n--------------------------------------------------------------------------\n");
            printf("                         课程名：");
            scanf("%s",s_i->student_g.g_cno.chinese);
            clear_hcq();
            printf("--------------------------------------------------------------------------\n");
            printf("                         考试时间（xxxx.xx.xx-xx:xx）：");
            scanf("%s",s_i->student_g.g_time.chinese_time);
            clear_hcq();
            printf("--------------------------------------------------------------------------\n");
            printf("                         成绩：");
            scanf("%f",&s_i->student_g.g_grade.chinese_grade);
            clear_hcq();
            printf("--------------------------------------------------------------------------\n");
            printf("                         课程名：");
            scanf("%s",s_i->student_g.g_cno.math);
            clear_hcq();
            printf("--------------------------------------------------------------------------\n");
            printf("                         考试时间（xxxx.xx.xx-xx:xx）：");
            scanf("%s",s_i->student_g.g_time.math_time);
            clear_hcq();
            printf("--------------------------------------------------------------------------\n");
            printf("                         成绩：");
            scanf("%f",&s_i->student_g.g_grade.math_grade);
            clear_hcq();
            printf("--------------------------------------------------------------------------\n");
            printf("                         课程名：");
            scanf("%s",s_i->student_g.g_cno.english);
            clear_hcq();
            printf("--------------------------------------------------------------------------\n");
            printf("                         考试时间（xxxx.xx.xx-xx:xx）：");
            scanf("%s",s_i->student_g.g_time.english_time);
            clear_hcq();
            printf("--------------------------------------------------------------------------\n");
            printf("                         成绩：");
            scanf("%f",&s_i->student_g.g_grade.english_grade);
            clear_hcq();
            printf("--------------------------------------------------------------------------\n");
            s_i->student_g.student_g_is_lr = 1;
            save_data();
            printf("\n                    录入学生用户成绩信息成功！");
        }
        else if(s_i->student_g.student_g_is_lr == 1)
        {
            printf("\n             您想录入的成绩的学生用户已录入成绩，无须重复录入！\n");
        }
    }
    fflush(stdout);
    sleep(2);
    gly_gui();
}

//删除学生考试成绩
void delete_stu_grand(void)
{
    while(1)
    {
        show_grand(stu_list);
        printf("\n\n退出系统（0）                  继续删除学生用户成绩（1）                  返回上一级（-1）\n");
        char sno[20];
        printf("\n请管理员输入需要删除成绩的学生的学号：");
        scanf("%s",sno);
        student_info* s_i_grand;
        s_i_grand = myfind(stu_list,sno);
        if(s_i_grand != NULL)
        {
            if(s_i_grand->student_g.student_g_is_lr == 1)
            {
                strcpy(s_i_grand->student_g.g_cno.chinese,"0");
                strcpy(s_i_grand->student_g.g_cno.math,"0");
                strcpy(s_i_grand->student_g.g_cno.english,"0");
                strcpy(s_i_grand->student_g.g_time.chinese_time,"0");
                strcpy(s_i_grand->student_g.g_time.math_time,"0");
                strcpy(s_i_grand->student_g.g_time.english_time,"0");
                s_i_grand->student_g.g_grade.chinese_grade = 0;
                s_i_grand->student_g.g_grade.math_grade = 0;
                s_i_grand->student_g.g_grade.english_grade = 0;
                s_i_grand->student_g.student_g_is_lr = 0;
                printf("\n                             删除学生用户信息成功！\n");
                save_data();
                fflush(stdout);
                sleep(2);
                show_grand(stu_list);
                printf("\n\n退出系统（0）                  继续删除学生用户成绩（1）                  返回上一级（-1）\n");
            }
            else if(s_i_grand->student_g.student_g_is_lr == 0)
            {
                printf("\n                         学生用户成绩未录入，无法删除！\n");
            }
        }
        else if(s_i_grand == NULL)
        {
            printf("\n                         学生用户信息不存在！\n");
        }
        int xuhao;
        while(1)
        {
            printf("\n请管理员选择对应的操作：");
            if(!scanf("%d",&xuhao))
            {
                while(getchar() != '\n');
                xuhao = -2;
            }
            if(xuhao == -1)
            {
                gly_gui();
            }
            else if(xuhao == 0)
            {
                printf("\n                        感谢管理员用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            else if(xuhao == 1)
            {
                break;
            }
            else if((xuhao != -1) && (xuhao != 0) && (xuhao != 1))
            {
                printf("输入操作序号错误，请重新输入！\n");
            }
        }
    }
}

//修改学生用户成绩
void xg_xs_grand(void)
{
    while(1)
    {
        show_grand(stu_list);
        printf("\n\n退出系统（0）                  继续修改学生用户成绩（1）                  返回上一级（-1）\n");
        char sno[20];
        printf("\n请管理员输入需要修改的成绩的学生用户学号：");
        scanf("%s",sno);
        student_info* s_i_grand;
        s_i_grand = myfind(stu_list,sno);
        if(s_i_grand != NULL)
        {
            if(s_i_grand->student_g.student_g_is_lr == 1)
            {
                printf("\n--------------------------------------------------------------------------\n");
                printf("\n               请管理员按照以下提示依次修改该学生用户的成绩!");
                printf("\n--------------------------------------------------------------------------\n");
                printf("                       新课程名：");
                scanf("%s",s_i_grand->student_g.g_cno.chinese);
                clear_hcq();
                printf("--------------------------------------------------------------------------\n");
                printf("                       新考试时间（xxxx.xx.xx-xx:xx）：");
                scanf("%s",s_i_grand->student_g.g_time.chinese_time);
                clear_hcq();
                printf("--------------------------------------------------------------------------\n");
                printf("                       新成绩：");
                scanf("%f",&s_i_grand->student_g.g_grade.chinese_grade);
                clear_hcq();
                printf("--------------------------------------------------------------------------\n");
                printf("                       新课程名：");
                scanf("%s",s_i_grand->student_g.g_cno.math);
                clear_hcq();
                printf("--------------------------------------------------------------------------\n");
                printf("                       新考试时间（xxxx.xx.xx-xx:xx）：");
                scanf("%s",s_i_grand->student_g.g_time.math_time);
                clear_hcq();
                printf("--------------------------------------------------------------------------\n");
                printf("                       新成绩：");
                scanf("%f",&s_i_grand->student_g.g_grade.math_grade);
                clear_hcq();
                printf("--------------------------------------------------------------------------\n");
                printf("                       新课程名：");
                scanf("%s",s_i_grand->student_g.g_cno.english);
                clear_hcq();
                printf("--------------------------------------------------------------------------\n");
                printf("                       新考试时间（xxxx.xx.xx-xx:xx）：");
                scanf("%s",s_i_grand->student_g.g_time.english_time);
                clear_hcq();
                printf("--------------------------------------------------------------------------\n");
                printf("                       新成绩：");
                scanf("%f",&s_i_grand->student_g.g_grade.english_grade);
                clear_hcq();
                printf("--------------------------------------------------------------------------\n");
                save_data();
                printf("\n                    修改学生用户成绩信息成功！");
                save_data();
                fflush(stdout);
                sleep(2);
                show_grand(stu_list);
                printf("\n\n退出系统（0）                  继续修改学生用户成绩（1）                  返回上一级（-1）\n");
            }
            else if(s_i_grand->student_g.student_g_is_lr == 0)
            {
                printf("\n                         学生用户成绩未录入，无法修改！\n");
            }
        }
        else if(s_i_grand == NULL)
        {
            printf("\n                         学生用户信息不存在！\n");
        }
        int xuhao;
        while(1)
        {
            printf("\n请管理员选择对应的操作：");
            if(!scanf("%d",&xuhao))
            {
                while(getchar() != '\n');
                xuhao = -2;
            }
            if(xuhao == -1)
            {
                gly_gui();
            }
            else if(xuhao == 0)
            {
                printf("\n                        感谢管理员用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            else if(xuhao == 1)
            {
                break;
            }
            else if((xuhao != -1) && (xuhao != 0) && (xuhao != 1))
            {
                printf("输入操作序号错误，请重新输入！\n");
            }
        }
    }
}

//清空缓存区
void clear_hcq(void)
{
    while(getchar() != '\n');
}

//创建空链表
node* creat(void)
{
    node* n = (node*)malloc(sizeof(node));
    n->next = NULL;
    return n;
}

//存储信息
void save_data(void)
{
    FILE *fp = fopen("stu_info","wb");
    if(fp == NULL)
    {
        perror("fopen fail");
    }

    //遍历链表所有节点
    node* l = stu_list->next;
    while(l != NULL)
    {
        fwrite(&(l->data),sizeof(student_info),1,fp);
        l = l->next;
    }
    fclose(fp);
}

//在链表尾部插入节点
void push_back(node* l,elem_type data)
{
    //创建一个节点
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    //找到链表的尾节点
    while(l->next != NULL)
        l = l->next;
    //在尾部插入新节点
    l->next = n;
}

//删除链表某个节点
int my_remove(node* l,char* sno)
{
    node* p = NULL;
    //找到待删除节点的前驱节点
    //节点存在，返回节点的前驱节点指针
    while(l->next != NULL && (strcmp(l->next->data.s_son,sno) != 0))
        l = l->next;
    //节点不存在返回0
    if(l->next == NULL) return 0;
    
    //连接断开的链表
    p = l->next;
    l->next = p->next;
    free(p);
    //删除成功返回1
    return 1;
}

//打印链表中所有学生信息节点数据
void show(node* l)
{
    l = l->next;
    printf("\033c");
    printf("\n      ******************学生用户信息界面******************\n");
    m_time();
    printf("\n  班级            学号      姓名              身份证号             密码       手机号");
    while(l != NULL)
    {
        printf("\n-----------------------------------------------------------------------------------------\n");
        printf("%-20s%-10s%-15s%-25s%-10s%-20s%d",l->data.s_class,l->data.s_son,l->data.s_name,l->data.s_idcard,l->data.s_pass,l->data.s_number,l->data.s_is_cj);
        l = l->next;
    }
}

//打印链表中所有学生成绩节点数据
void show_grand(node* l)
{
    l = l->next;
    printf("\033c");
    printf("\n      ******************学生用户成绩界面******************\n");
    m_time();
    printf("\n  班级    学号  姓名    课程名     考试时间      成绩   课程名     考试时间      成绩   课程名     考试时间      成绩");
    while(l != NULL)
    {
        if(l->data.student_g.student_g_is_lr == 1)
        {
            printf("\n----------------------------------------------------------------------------------------------------------------------\n");
            printf("%s  %s  %s    %s   %s  %.2f   %s  %s  %.2f   %s  %s  %.2f",l->data.s_class,l->data.s_son,l->data.s_name,l->data.student_g.g_cno.chinese,l->data.student_g.g_time.chinese_time,l->data.student_g.g_grade.chinese_grade,l->data.student_g.g_cno.math,l->data.student_g.g_time.math_time,l->data.student_g.g_grade.math_grade,l->data.student_g.g_cno.english,l->data.student_g.g_time.english_time,l->data.student_g.g_grade.english_grade);
            l = l->next;
        }
        else if(l->data.student_g.student_g_is_lr == 0)
        {
            l = l->next;
        }
    }
}