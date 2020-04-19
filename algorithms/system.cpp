#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AVAILABLE 0
#define UNAVAILABLE 1
#define MAXNAME 30
#define CLEAR "cls"

// ͼ��ṹ �������֣���ţ����������״̬����һ���� 
typedef struct book{
    char *name;
    int id;
    int count;
    int status;
    struct book *next;
}Book;

void welcome();
void error(char *);           // [�쳣����]
char land();                  // [��ҳ����Ŀ]
int usrstudent();             // [ѧ�����]���� 0��ʾ������ҳ 1��ʾ����ִ�б�����
int usrmanager();             // [����Ա���]���� 0��ʾ������ҳ 1��ʾ����ִ�б�����
int viewbook();               // [�鿴ͼ��]���ش�ӡ��ͼ�����     ʧ�ܷ���-1
int addbook();                // [ע��ͼ��]���ͼ��ɹ� ����ͼ��id  ʧ�ܷ���-1
int modbook();                // [�޸�ͼ��]�޸�ͼ����Ϣ   �ɹ��󷵻�id  ʧ�� -1
int delbook();                // [ע��ͼ��]ɾ���ɹ� ���ر�ɾ��ͼ���id ʧ�ܷ���-1
void printbook(Book *);       // [��ӡͼ��]
Book *lookup(char *, int);    // [����ͼ��]
int borrowbook();             // [����ͼ��]
int returnbook();             // [�黹ͼ��]

Book *head = NULL;
int nbook = 0;
int main(){
    
    welcome();
    return 0;
}
// ��ʼ���� 
void welcome(){
    printf("*************************��ӭʹ��ͼ�����ϵͳ*************************\n");
    while(1){
        printf("-------------------------------------\n");
        printf("��������Ŀǰ���ִ����ز�����\n");
        printf("\n[1] ����Ա���\n\n[2] ѧ�����\n\n[0] �˳�\n\n");
        switch(land()){
            case '1':
                while(1){
                    if(usrmanager()){
                        continue;
                    }else{
                        break;
                    }
                 }
                break;
            case '2':
                while(1){
                    if(usrstudent()){
                        continue;
                    }else{
                        break;
                    }
                }
                break;
            case '0':
                exit(0);
            default:
                error("�ɼ���Ŀ����ʧ��");
        }
    }
}
// �ж���������ֱ���Ƿ���ȷ 
char land(){
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("[��������� 1 / 2 / 0 ѡ����Ŀ]");
    }
    return '\0';
}
void error(char *s){
    fprintf(stderr, "%s\n", s);
}
char dostudent(){
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i )
            ;
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '3' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("[��������� 1 / 2 / 3/ 0 ѡ����Ŀ]");
    }
}
int usrstudent(){
    printf("-------------------------------------\n");
    printf("��������Ŀǰ���ִ����ز�����\n\n");
    printf("[1] ����ͼ��\n[2] �黹ͼ��\n[3] �鿴�ݴ�ͼ��\n");
    printf("[0] ������ҳ\n");
    switch(dostudent()){
        case '1':
            borrowbook();
            break;
        case '2':
            returnbook();
            break;
        case '3':
            viewbook();
            break;
        case '0':
            return 0;
        default:
            error("�ɼ���Ŀ����ʧ��");
            break;
    }
    return 1;
}
int borrowbook(){
    system(CLEAR);
    char sname[MAXNAME];
    printf("����ͼ��:\n");
        scanf("%s", sname);
        getchar();
        Book *bp;
        char *namep = NULL;
        if((bp = lookup(namep = strdup(sname), 0)) == NULL){
            printf("ͼ�� %s ������\n", namep);
            fflush(stdin);
            return -1;
        }else{
            printbook(bp);
            if(! bp->status){
                printf("����ͼ�飺 Y N\n");
            }else{
                printf("ͼ�������\n");
                return 0;
            }
            while(1){
                char c = '\0';
                scanf("%c", &c);
                getchar();
                if(!(c == 'Y' || c == 'y' || c == 'N' || c == 'n')){
                    fflush(stdin);
                    error("ָ����Ч");
                    continue;
                }
                if(c == 'Y' || c == 'y'){
                    --bp->count > -1 ? printf("�ɹ�\n") : printf("ʧ��\n");
                    if(! bp->count){
                        bp->status = UNAVAILABLE;
                    }
                    return bp->id;
                }else{
                    return 0;
                }
            }
        }  
    return -1;
}
int returnbook(){
    system(CLEAR);
    char sname[MAXNAME];
    printf("�黹ͼ�飺\n");
    scanf("%s", sname);
    getchar();
    Book *bp;
    char *namep;
    if((bp = lookup(namep = strdup(sname), 0)) == NULL){
        fflush(stdin);
        printf("��ͼ�鲢���ǹ���ͼ��\n");
        return -1;
    }else{
        printbook(bp);
        printf("�黹ͼ�飺 Y N\n");
        while(1){
            char c = '\0';
            scanf("%c", &c);
            getchar();
            if(!(c == 'Y' || c == 'y' || c == 'N' || c == 'n')){
                fflush(stdin);
                error("ָ����Ч");
            }else if(c == 'Y' || c == 'y'){
                bp->count++ ? : (bp->status = AVAILABLE);
                printf("�ɹ�\n");
                return bp->id;
            }else{
                return 0;
            }
        }
    }

    return -1;
}

// ���������������Ƿ���ȷ 
char domanager(){

    char c, flag;
    int i;
    
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if(flag == '1' || flag == '2' || flag == '3' || flag == '4' || flag == '0'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        error("[��������� 1 / 2 / 3/ 4 / 0 ѡ����Ŀ]");
            
    }
    
    return '\0';
}

// ����Ա����
// ����  �鿴�Ѵ�ͼ�� ע����ͼ�� �޸�����ͼ����Ϣ ע���ִ�ͼ��
int usrmanager(){
    printf("-------------------------------------\n");
    printf("��������Ŀǰ���ִ����ز�����\n\n");
    printf("[1] �鿴�Ѵ�ͼ��\n[2] ע����ͼ��\n[3] �޸�����ͼ����Ϣ\n[4] ע���ִ�ͼ��\n");
    printf("[0] ������ҳ\n");
    switch(domanager()){
        case '1':
            viewbook();
            break;
        case '2':
            addbook();
            break;
        case '3':
            modbook();
            break;
        case '4':
            delbook();
            break;
        case '0':
            return 0;
        default:
            error("�ɼ���Ŀ����ʧ��");
            break;
    }
    return 1;

}

//  �鿴�Ѵ�ͼ��
int viewbook(){
    system(CLEAR);      ///////////////////////////////////////////
    Book *bp;
    for(bp =head; bp != NULL; bp = bp->next){
        printbook(bp);
    }
    if(nbook){
        return nbook;
    }else{
        printf("ͼ��ݻ�û��ͼ��Ŷ\n");
        return 0;
    }
    return -1;
}
void printbook(Book *bp){
    printf("ͼ���ţ�%d\n", bp->id);
    printf("ͼ������%s\n", bp->name);
    printf("ͼ�������%d\n", bp->count);
    printf("ͼ��״̬��%s\n", bp->status ? "���ɽ�" : "�ɽ�");
}
int addbook(){
    system(CLEAR);      ///////////////////////////////////////////
    char sname[MAXNAME];
    int id, count;
    char *namep;

    while(1){
        id = 0;
        count = 0;
        namep = NULL;
        printf("������ͼ������\n");
        scanf("%s", sname);
        getchar();
        printf("������С��1000��ͼ���ţ�\n");
        scanf("%d", &id);
        getchar();
        if(!(id > 0 && id < 1000)){
            error("�����Ų�����Ҫ��");
            fflush(stdin);
            continue;
        }
        printf("������С��50��ͼ��������\n");
        scanf("%d", &count);
        getchar();
        if(!(count > 0 && count < 50)){
            error("������Ŀ������Ҫ��");
            fflush(stdin);
            continue;
        }
        Book *bp;        
        if((bp = lookup(namep = strdup(sname), id)) == NULL){
            bp = (Book *)malloc(sizeof (Book));
            if(bp == NULL || (bp->name = namep) == NULL){
                error("ע��ͼ��ʧ��");
                fflush(stdin);
                continue;
            }
            bp->id = id;
            bp->count = count;
            bp->status = AVAILABLE;
            ++nbook;
            
            bp->next = head;
            head = bp;
            printf("ͼ�� %s ע��ɹ�\n", sname);
            return id;
        }else{
            fflush(stdin);
            error("ͼ���������Ѿ���ռ��");
        }
    }

    return -1;
}
Book *lookup(char *s, int id){
    Book *bp;
    for(bp = head; bp != NULL; bp = bp->next){
        if(id == bp->id || strcmp(s, bp->name) == 0){
            return bp;
        }
    }
    return NULL;
}
int modbook(){  // �޸ĳ�id֮�����Ϣ  ��ΪҪ�޸�id ֱ��ɾ����������ӻ����
    system(CLEAR);      ///////////////////////////////////////////
    Book *bp = NULL;
    while(1){
        int id = 0;
        printf("������Ҫ�޸���Ϣ��ͼ���ţ�\n");
        scanf("%d", &id);
        getchar();
        if(!(id > 0 && id < 1000)){
            fflush(stdin);
            error("ͼ���Ų�����Ҫ��");
            continue;
        }
        if((bp = lookup("", id)) != NULL){
            printf("����ΪҪ�޸ĵ�ͼ���������Ϣ��\n");
            printbook(bp);
            printf("[1] �޸�ͼ����\n[2] �޸�ͼ������\n[3] �޸�ͼ��״̬\n[0] �����޸�\n");
            while(1){
                int i;
                scanf("%d", &i);
                getchar();
                if(!(i == 1 || i == 2 || i == 3 || i == 0)){
                    fflush(stdin);
                    error("������Ŀǰ���ѡ�������Ŀ");
                    continue;
                }
                switch(i){
                    case 1:
                        while(1){
                            char newname[MAXNAME], *namep;
                            printf("ͼ������\n");
                            scanf("%s", newname);
                            getchar();
                            if((lookup(namep = strdup(newname), 0)) != NULL){
                                fflush(stdin);
                                error("ͼ�����Ѵ���");
                                continue;
                            }
                            if((bp->name = namep) != NULL){
                                printf("�޸ĳɹ�\n");
                                return id;
                            }
                        }
                        break;
                    case 2:
                        while(1){
                            int bnum;
                            printf("����ͼ��������\n");
                            scanf("%d", &bnum);
                            getchar();
                            if(!(bnum > 0 || bnum < 1000)){
                                fflush(stdin);
                                error("��Ŀ������Ҫ��");
                                continue;
                            }
                            bp->count = bnum;
                            printf("�޸ĳɹ�\n");
                            return id;
                        }
                        break;
                    case 3:
                        while(1){
                            char c;
                            int status;
                            status = bp->status;
                            status == AVAILABLE ? printf("�޸�״̬Ϊ[���ɽ�]�� Y N\n") : printf("�޸�״̬Ϊ[�ɽ�]�� Y N\n");
                            scanf("%c", &c);
                            getchar();
                            if(!( c == 'Y' || c == 'y' || c == 'N' || c == 'n')){
                                fflush(stdin);
                                error("ָ����Ч");
                                continue;
                            }
                            if(c == 'Y' || c == 'y'){
                                 status == AVAILABLE ? bp->status = UNAVAILABLE : (bp->status = AVAILABLE);
                                 printf("�޸ĳɹ�\n");
                                 return id;
                            }else{
                                printf("�����޸�\n");
                                return 0;
                            }
                        }
                        break;
                    case 0:
                        return 0;
                    default:
                        error("��ȡ����ʧ��");
                        break;   
                }
            }
        }else{
            printf("û�д�ͼ��\n");
            return 0;
        }
    }
    return -1;
}
int delbook(){
    system(CLEAR);      ///////////////////////////////////////////
    Book *bp, *fbp;
    
    int id = 0;
    printf("������Ҫע����ͼ���ţ�\n");
    scanf("%d", &id);
    getchar();
    if(!(id > 0 && id < 1000)){
        fflush(stdin);
        error("ͼ���Ų�����Ҫ��");
        return -1;
    }
    for(fbp = bp = head; bp != NULL; fbp = bp, bp = bp->next){
        if(bp->id == id){
            printbook(bp);
            break;
        }
    }
    if(bp != NULL){
        while(1){
            printf("ȷ��Ҫע����ͼ�飺Y  N\n");
            char YN;
            scanf("%c", &YN);
            getchar();
            if(!((YN == 'Y' || YN == 'y') || (YN == 'N' || YN == 'n'))){
                fflush(stdin);
                error("ָ����Ч\n");
                continue;
            }
            if(YN == 'Y' || YN == 'y'){
                bp == head ? head = bp->next : (fbp->next = bp->next);
                free(bp->name);                                         //2018-05-26�޸ģ�����ͷ�name����ڴ�//bp�ڴ��ֻ��ָ��name��ָ��
                free(bp);
                bp = NULL;
                printf("ͼ��ע���ɹ�\n");
                break;
            }else{
                printf("����ע��\n");
                return 0;
            }
        }  
        return id;
    }else{
        printf("Ҫע����ͼ���Ų�����\n");
        return -1;
    }
    return -1;
}
