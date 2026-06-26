//23100011076 ELANUR USSEN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[25];
    struct Node* next;
    struct Node* prev;
};

struct Stack {
    struct Node* top;
};

struct Stack* temp = NULL;


void push_fonk() {
    struct Node* eklenecek_site = (struct Node*)malloc(sizeof(struct Node));
    char site[25];
    printf("\nLUTFEN SITE ISMINI GIRINIZ: ");
    scanf("%s", site);
    strcpy(eklenecek_site->data, site);

    eklenecek_site->next = temp->top; //temp->top diye bahsettigim sey aslinda stackin top elemani demek
    eklenecek_site->prev = NULL;

    if (temp->top != NULL)
    {
        temp->top->prev = eklenecek_site;
    }

    temp->top = eklenecek_site;

    printf("-SITE BASARIYLA ACILDI...\n");
    printf("-SUANDA BULUNDUGUNUZ SITE - - >  %s\n", site);
}


void gerifonks() {
    if (temp->top == NULL || temp->top->next == NULL) {
        printf("-GERI GIDECEK BIR SITE YOK...\n");
        printf("-BULUNDUGUNUZ SITE - - >  %s\n", temp->top->data);
        return;
    }
    struct Node* TEMP2 = temp->top;
    if (TEMP2->next != NULL)
    {
        temp->top = TEMP2->next;
        printf("-BULUNDUGUNUZ SITE - - >  %s\n", temp->top->data);
    }
    else {
        printf("-SUANDA ILK SITEDESINIZ ZATEN GERI GIDECEK BIR SITE YOK...\n");
        printf("-BULUNDUGUNUZ SITE - - >  %s\n", temp->top->data);
    }
}

void ilerifonks() {
    if (temp->top == NULL) {
        printf("-HERHANGI BIR SITE BULUNAMADI...\n");
        printf("-BULUNDUGUNUZ SITE - - >  %s\n", temp->top->data);

        return;
    }

    struct Node* TEMP2 = temp->top;
    if (TEMP2->prev != NULL) {
        temp->top = TEMP2->prev;
        printf("-BULUNDUGUNUZ SITE - - >  %s\n", temp->top->data);
    }
    else
    {
        printf("-SUANDA EN SON SITEDESINIZ ZATEN ILERI GIDECEK BIR SITE YOK...\n");
        printf("-BULUNDUGUNUZ SITE - - >  %s\n", temp->top->data);
    }
}


void display() {
    if (temp->top == NULL) {
        printf("\n-LISTELENCEK HERHANGI BIR SITE YOK...\n");
        return;
    }

    struct Node* TEMP2 = temp->top;
    printf("\n--- -------- ---\n");
    while (TEMP2 != NULL) {
        printf("-%s\n", TEMP2->data);
        TEMP2 = TEMP2->next;
    }
    printf("-----------------------\n");
}

void menu() {
    int secim;
    while (1) {
        printf("\n------ TARAYICI ------\n");
        printf("1->>>> YENI SITEYE GIRIS\n");
        printf("2->>>> GERI\n");
        printf("3->>>> ILERI\n");
        printf("4->>>> TARAYICIYI KAPAT\n-----------------------\n");
        printf("-LUTFEN BIR SECIM YAPINIZ: ");
        scanf("%d", &secim);

        switch (secim) {
        case 1:
            push_fonk();
            break;
        case 2:
            gerifonks();
            break;
        case 3:
            ilerifonks();
            break;
        case 4:
            printf("TARAYICI KAPATILIYOR....\n");
            return;
        default:
            printf("GECERSIZ TUSLAMA LUTFEN TEKRAR DENEYINIZ!\n");
        }
    }
}

int main() {
    temp = (struct Stack*)malloc(sizeof(struct Stack));
    temp->top = NULL;
    menu();
    return 0;
}
//THE END
