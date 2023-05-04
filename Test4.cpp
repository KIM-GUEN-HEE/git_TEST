#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int year;
    int month;
    int day;
    int amount;
    char description[50];
} Entry;

Entry entries[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("더 이상 기록을 추가할 수 없습니다.\n");
        return;
    }

    printf("날짜(YYYY MM DD): ");
    scanf("%d %d %d", &entries[entryCount].year, &entries[entryCount].month, &entries[entryCount].day);
    printf("금액: ");
    scanf("%d", &entries[entryCount].amount);
    printf("설명: ");
    scanf("%s", entries[entryCount].description);

    entryCount++;
}

void showEntries() {
    printf("기록\t\t\t\t금액\t설명\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < entryCount; i++) {
        printf("%d.%02d.%02d\t\t%d\t%s\n", entries[i].year, entries[i].month, entries[i].day, entries[i].amount, entries[i].description);
    }

    printf("---------------------------------------------------\n");
}

void clearEntries() {
    entryCount = 0;
    printf("모든 기록이 삭제되었습니다.\n");
}

int main() {
    while (1) {
        printf("1. Add record\n");
        printf("2. Show record\n");
        printf("3. Remote all record\n");
        printf("4. Finish\n");

        int menu;
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                addEntry();
                break;
            case 2:
                showEntries();
                break;
            case 3:
                clearEntries();
                break;
            case 4:
                return 0;
            default:
                printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}
