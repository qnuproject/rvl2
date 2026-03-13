#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
	This program is a part of the QNU project.
	      QNU rvl version 2 (2026-03.2)
        Because of a big difference, the RVL was splitten into two versions: the tradicionalic and the new.

	      usage:

	      rvl [-m N]
	      - Repeats generation N times.
*/

const char *BIG[] = {
    "А","Б","В","Г","Д","Е","Ж","З",
    "И","Й","К","Л","М","Н","О","П",
    "Р","С","Т","У","Ф","Х","Ц","Ч",
    "Ш","Щ","Ъ","Ы","Ь","Э","Ю","Я", "Ǝ", "Є"
};

const char *SMA[] = {
    "а","б","в","г","д","е","ж","з",
    "и","й","к","л","м","н","о","п",
    "р","с","т","у","ф","х","ц","ч",
    "ш","щ","ъ","ы","ь","э","ю","я", "ǝ", "є"
};

void RVLY(const char *arr[], int count, int size) {
    for(int i = 0; i < count; i++) {
        int r = rand() % size;
        printf("%s", arr[r]);
    }
}

int main(int argc, char *argv[]) {
    int __MAX = -1;

    int SIZE_BIG = sizeof(BIG)/sizeof(BIG[0]);
    int SIZE_SMA = sizeof(SMA)/sizeof(SMA[0]);
    for(int i = 1; i < argc; i++) {
	    if(strcmp(argv[i], "-m") == 0 && i+1 < argc) {
		    __MAX = atoi(argv[i+1]);
		    if(__MAX <= 0) __MAX = -1;
		    i++;
	    }
    }
    srand(time(NULL));
    int __COUNT = 0;
    while(__MAX == -1 || __COUNT < __MAX) {
        RVLY(BIG, 3, SIZE_BIG);
        printf(" ");
        RVLY(SMA, 5, SIZE_SMA);
        printf(" ");
        RVLY(SMA, 10, SIZE_SMA);
        printf(".\n");
	__COUNT++;
    }
    return 0;
}
