#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "m_time.h"
#include "head.h"
#include "md5.h"

name_pass n_p;

int is_first();
int gly_cz_check(const char* gl_name,const char* gl_pass);
void gly_revise_n_p(void);
void gly_cjxsyhzh(void);
int updata(node* l,char* sno);


void gly_dl_gui(void)
{
    printf("\033c");
    printf("\n          *******************管理员管理界面*******************\n");
    m_time();
    printf("\n------------------------------------------------------------------------\n");
    printf("*                          1.修改用户名和密码                          *\n");
    printf("*----------------------------------------------------------------------*\n");
    printf("*                          2.创建学生用户账号及密码                    *\n");
    printf("*----------------------------------------------------------------------*\n"); 
    printf("*                          3.管理员操作界面                            *\n");
    printf("*----------------------------------------------------------------------*\n"); 
    printf("\n退出系统（0）                                              返回上一级（-1）\n");

    int xuhao;
    while(1)
    {
        printf("\n请管理员选择对应的操作：");
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
                dl_gui();
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
                //修改用户名和密码
                gly_revise_n_p();
                gly_cz();
            }
            break;
            case 2:
            {
                //创建学生用户账号及密码
                gly_cjxsyhzh();
                save_data();
                fflush(stdout);
                sleep(2);
                gly_dl_gui();
            }
            break;
            case 3:
            {
                gly_gui();
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

void gly_cz(void)
{

    char gl_name[31], gl_pass[33],gl_pass_check[33];
    printf("\033c");
    printf("\n          *******************管理员登录界面*******************\n");
    m_time();
    printf("\n------------------------------------------------------------------------\n");
    printf("                            管理员用户名:");
    scanf("%s",gl_name);
    printf("*----------------------------------------------------------------------*\n");
    strcpy(gl_pass,getpass("                            管理员密码："));
    
    if(is_first())
    {
        if(strcmp(gl_name,"root") != 0 ||strcmp(gl_pass,"666666") != 0)
        {
            printf("\n管理员用户名或密码错误，登录失败!\n");
            exit(1);
        }

        //首次登陆成功
        printf("\033c");
        printf("\n     *******************管理员首次登录信息重置界面*******************\n");
        while(1)
        {
            printf("           为了保证您的账号安全，请重新设置管理员用户名和密码！          \n");
            m_time();
            printf("\n------------------------------------------------------------------------\n");
            printf("                          管理员新用户名:");
            scanf("%s",gl_name);
            printf("*----------------------------------------------------------------------*\n");
            strcpy(gl_pass,getpass("                          管理员新密码："));
            printf("*----------------------------------------------------------------------*\n");
            strcpy(gl_pass_check,getpass("                          再次输入管理员新密码："));
            if(strcmp(gl_pass,gl_pass_check) == 0) break;
            printf("\n                 两次输入的密码不一致，请重新输入!\n");
        }
        strcpy(n_p.gl_name,gl_name);
        md5_encode(gl_pass,strlen(gl_pass),n_p.gl_pass);

        FILE *fp =fopen("gly_data","wb");
        if(fp == NULL)
        {
            perror("open gly_data fail");
        }
        fwrite(&n_p,sizeof(n_p),1,fp);
        fclose(fp);
    }
    else
    {
        //重置信息后登录
        if(!gly_cz_check(gl_name,gl_pass))
        {
            printf("\n管理员用户名或密码输入错误，登录失败！\n");
            exit(1);
        }
    }
    printf("\n          *********恭喜管理员登陆成功，欢迎您的使用！*********");
    fflush(stdout);
    sleep(2);
    gly_dl_gui();
}

//第一次登录验证
int is_first()
{
    FILE *fp = fopen("gly_data","rb");
    if(fp == NULL) return 1;
    fclose(fp);
    return 0;
}

//更改新密码后登录验证
int gly_cz_check(const char* gl_name,const char* gl_pass)
{
    FILE *fp = NULL;
    name_pass gly_np;
    char gly_pass_md5[33];
    int check_success = 0;

    fp = fopen("gly_data","rb");
    if(fp == NULL) return 0;

    md5_encode(gl_pass,strlen(gl_pass),gly_pass_md5);

    while(fread(&gly_np,sizeof(gly_np),1,fp) == 1)
    {
        if(strcmp(gl_name,gly_np.gl_name) == 0 && strcmp(gly_pass_md5,gly_np.gl_pass) == 0)
        {
            n_p = gly_np;
            check_success = 1;
            break;
        }
    }
    fclose(fp);
    return check_success;
}


//管理员修改用户名及密码界面
void gly_revise_n_p(void)
{
    char gl_name[31], gl_pass[33],gl_pass_check[33];
    printf("\033c");
    printf("\n     *******************管理员修改用户名和密码界面*******************\n");
        while(1)
        {
            m_time();
            printf("\n------------------------------------------------------------------------\n");
            printf("                          管理员新用户名:");
            scanf("%s",gl_name);
            printf("*----------------------------------------------------------------------*\n");
            strcpy(gl_pass,getpass("                          管理员新密码："));
            printf("*----------------------------------------------------------------------*\n");
            strcpy(gl_pass_check,getpass("                          再次输入管理员新密码："));
            if(strcmp(gl_pass,gl_pass_check) == 0) break;
            printf("\n                 两次输入的密码不一致，请重新输入!\n");
        }
        strcpy(n_p.gl_name,gl_name);
        md5_encode(gl_pass,strlen(gl_pass),n_p.gl_pass);

        FILE *fp =fopen("gly_data","wb");
        if(fp == NULL)
        {
            perror("open gly_data fail");
        }
        fwrite(&n_p,sizeof(n_p),1,fp);
        fclose(fp);
}

//管理员创建学生用户账号
void gly_cjxsyhzh(void)
{
    FILE* fp = NULL;
    fp = fopen("stu_info","rb");
    if(fp == NULL)
    {
        printf("               目前暂未有学生用户信息录入！无法创建。");
        return;
    }
    fclose(fp);
    student_info* s_i = NULL;
    char xsyh_zh[20];
    printf("\033c");
    printf("\n     *******************创建学生用户账号及密码界面*******************\n");
    m_time();
    printf("\n输入需要创建的学生用户账号（账号为学号），并核对其初始密码（自动生成初始密码为身份证后六位）！");
    printf("\n------------------------------------------------------------------------\n");
    printf("                          学生用户账号:");
    scanf("%s",xsyh_zh);
    s_i = myfind(stu_list,xsyh_zh);
    if(s_i != NULL)
    {
        if(s_i->s_is_cj == 1)
        {
            printf("\n               此学生用户账号及密码已创建！");
            return;
        }   
        printf("*----------------------------------------------------------------------*\n");
        printf("                          学生用户密码：%s",s_i->s_pass);
        s_i->s_is_cj = 1;
        printf("\n*----------------------------------------------------------------------*\n");
        printf("                      创建学生用户账号及密码成功！");
        return;
    }
    printf("\n                     此学生用户的信息暂未录入！");
    return;
}

//按学号查找信息
student_info* myfind(node* l,char* sno)
{
    //遍历链表所有节点
    l = l->next;
    while(l != NULL)
    {
        if(strcmp(l->data.s_son,sno) == 0) return &(l->data);
        l = l->next;
    }
    return NULL;
}


