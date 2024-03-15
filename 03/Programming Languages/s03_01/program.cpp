#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>

void new_id();
int command_palette();
void print_out();
void RFF();
void WTF();
void print_avr();
void pause();

struct info
{
    int group;
    std::string family;
    std::string examname;
    int res;
};

std::vector<info> studtable;
std::fstream working_file;

void printf_d(info a);

int main(){
    int y = 1;
    while(y){
        y = command_palette();
        switch (y)
        {

        case 1:
            new_id();
            break;

        case 2:
            print_out();
            break;

        case 3:
            print_avr();
            break;

        case 4:
            WTF();
            break;

        case 5:
            RFF();
            break;

        default:
            break;
        }
    }
    return 0;
}

int command_palette(){
    int var;
    printf("\nВариант взаимодействия:\n"
    "1\tСоздание новой записи\n"
    "2\tВыдача информации о студентах по фамилии или номеру группы\n"
    "3\tПодсчёт среднего балла по выбранному стденту или выбранной группе\n"
    "4\tЗапись информации в файл\n"
    "5\tЧтение информации из файла\n"
    "0\tВыход из программы\n");
    scanf("%d", &var);
    getchar();
    return var;
}

void new_id(){
    printf("\nСколько новых записей вы хотите создать?\n");
    int y;
    scanf("%i", &y);
    int a, b;
    char * c = new char[200], * d = new char[200];
    info B;
    printf("\nДля каждого студента введите: номер группы, фамилию, название экзамена, результат (2/3/4/5)\n");
    for(int i = 0; i < y; i++){
        scanf("%d%s%s%d", &a, c, d, &b);
        B.family = c;
        B.group = a;
        B.examname = d;
        B.res = b;
        studtable.push_back(B);
    }
}

bool exact(int a, int b)
{
    bool res = 0;
    while(b)
    {
        if(a == b)
        {
            res = 1;
            break;
        }
        b/=10;
    }
    return res;
}

bool exact(char* a, int size_a, std::string b)
{
    bool res = 1;
    int i;
    for(i=0;i<size_a && i<b.size(); i++)
    {
        if(a[i]!=b[i])
            res = 0;

    }
    if(i==b.size() && a[i]!=b[i])
        res = 0;
    return res;
}

int get_num(char * q, int size)
{
    int x=0;
    for(int i=0;i<size;i++)
    {
        x = x* 10 + q[i] - 48;
    }
    return x;
}

void print_out()
{
    if(!studtable.size())
    {
        printf("Сейчас в памяти нет данных, записывать нечего.\n");
        return;
    }
    printf("Введите номер группы или фамилию студента, или введите ");
    printf("точку для вывода всех значений:\n");
    char *inp, ch = ' ';
    int ssize = 0;
    inp = new char[1000];
    DO_IT_AGAIN:;
    ch = getchar();
    if(ch == '.')
        goto PRINT_ALL;
    while(ch != '\n')
    {
        inp[ssize++] = ch;
        ch = getchar();
    }
    if(ssize == 0) goto DO_IT_AGAIN;
    if(inp[0]>='0'&&inp[0]<='9')
    {
        int group_number = get_num(inp, ssize);
        for(auto i: studtable)
        {
            if(exact(group_number, i.group))
            {
                printf_d(i);
            }
        }
    }
    else
    {
        for(auto i: studtable)
        {
            if(exact(inp, ssize, i.family))
            {
                printf_d(i);
            }
        }
    }
    return;
    PRINT_ALL:;
    getchar();
    if(studtable.size()>100)
    {
        printf("Значений больше 100, будет выводиться по 25.\n");
        long long I = 0, R = studtable.size();
        while(I++<R)
        {
            if(!(I%25)&&I>0)
                pause();
            printf_d(studtable[I]);
        }
    }
    for(auto i: studtable)
        printf_d(i);
}

void print_avr()
{
    if(!studtable.size())
    {
        printf("Сейчас в памяти нет данных, записывать нечего.\n");
        return;
    }
    bool PRT = 0;
    printf("Введите номер группы или фамилию студента, или введите ");
    printf("точку для вывода среднего значения по всему объёму данных:\n");
    std::pair<int, int> avr = {0, 0};
    char *inp, ch = ' ';
    int ssize = 0;
    inp = new char[1000];
    DO_IT_AGAIN:;
    ch = getchar();
    if(ch == '.'){
        PRT = 1;
        goto PRINT_ALL;
    }
    while(ch != '\n')
    {
        inp[ssize++] = ch;
        ch = getchar();
    }
    if(ssize == 0) goto DO_IT_AGAIN;
    if(inp[0]>='0'&&inp[0]<='9')
    {
        int group_number = get_num(inp, ssize);
        for(auto i: studtable)
        {
            if(exact(group_number, i.group))
            {
                avr.first++;
                avr.second+=i.res;
            }
        }
    }
    else
    {
        for(auto i: studtable)
        {
            if(exact(inp, ssize, i.family))
            {
                avr.first++;
                avr.second+=i.res;
            }
        }
    }
    PRINT_ALL:;
    if(PRT)
    {
        getchar();
        avr.first = studtable.size();
        for(auto i: studtable)
            avr.second+=i.res;
    }
    printf("Среднее значение: %.6f\n", (float)avr.second / avr.first);
}

void RFF()
{
    std::fstream FL;
    char* FS = new char[200];
    REPEAT_AGAIN:;
    printf("Введите имя файла для чтения (с расширением):\n");
    scanf("%s", FS);
    getchar();
    FL.open(FS);
    if(!FL.is_open())
    {
        printf("Невозможно открыть файл!\nПопытаться открыть другой? y/n\n");
        char a;
        scanf("%c", &a); getchar();
        if(a=='y'||a=='Y') goto REPEAT_AGAIN;
        return;
    }
    if(studtable.size()>0)
    {
        printf("Перезаписать существующие данные, ");
        printf("сохранить их в отдельный файл, не открывать файл, ");
        printf("или добавить к существующим? y/s/n/a\n");
        char a;
        scanf("%c", &a);
        getchar();
        if(a>100)
            a-=115;
        if(a<0)
        {
            printf("Операция отменена.\n");
            return;
        }
        if(!a)
        {
            WTF();
            goto REPEAT_AGAIN;
        }
        if(a!=97)
            studtable.clear();
    }
    long long str, STR;
    FL>>str;
    STR=str;
    while(str--)
    {
        info i;
        FL>>i.group>>i.family>>i.examname>>i.res;
        studtable.push_back(i);
    }
    FL.close();
    printf("Импортировано %lld записей\n", STR);
}

void WTF()
{
    if(!studtable.size())
    {
        printf("Сейчас в памяти нет данных, записывать нечего.\n");
        return;
    }
    std::fstream FL;
    char* FS = new char[200];
    REPEAT_AGAIN:;
    printf("Введите имя сохраняемого файла (с расширением):\n");
    scanf("%s", FS);
    getchar();
    FL.open(FS, std::ios::in);
    if(FL.is_open())
    {
        if(!FL.eof())
        {
            printf("Похоже, файл не пустой. Перезаписать данные? y/n\n");
            char a;
            scanf("%c", &a); getchar();
            if(a=='n'||a=='N')
                goto FILE_IS_NOT_FREE;
        }
    }
    FL.close();
    FL.open(FS, std::ios::out | std::ios::trunc);
    if(!FL.is_open())
        printf("Невозможно открыть файл!\n");
    if(!FL.is_open())
    {
        FILE_IS_NOT_FREE:;
        printf("Попытаться открыть другой? y/n\n");
        char a;
        scanf("%c", &a); getchar();
        if(a=='y'||a=='Y') goto REPEAT_AGAIN;
        return;
    }
    FL<<studtable.size();
    FL<<std::endl;
    for(auto i:studtable)
    {
        FL<<i.group<<' '<<i.family<<' '<<i.examname<<' '<<i.res<<std::endl;
    }
    FL.close();
    printf("Экспортировано %ld записей\n", studtable.size());
}

void pause()
{
    char a = 'a';
    printf("Нажмите Enter для продолжения...");
    while(a != '\n')
        a = getchar();
}

void printf_d(info a)
{
    printf("%d %s %s %d\n", a.group, a.family.c_str(), a.examname.c_str(), a.res);
}