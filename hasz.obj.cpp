#include <cstdlib> 
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define hmax 97
#define smax 16

class node {
public:
	node *next;
	char str1[smax];
	char str2[smax];
	int monies;

	unsigned short int hashfunc() {
		unsigned short int h = 1;
		char *p, *q;
		int i = 0;
	
		p = str1;
		q = str2;
		while (*p && *q && i < 4) {
			h *= *p - 94;
			h *= *q - 94;
			h *= 17;
			h %= hmax;
			p++;
			q++;
			i++;
		}
		return h %= hmax;
	}
};

//unsigned short int hashfunc(char *str1, char *str2);

int main() {
	char input[smax * 3];
	char c;			// instr
//	char s1[smax];		// miro
//	char s2[smax];		// rycho
//	int n;			// lba z wejscia
	unsigned int h;		// hasz
	unsigned long int ctrp = 0;//
	unsigned long int ctrq = 0;//
	unsigned long int ctr = 0;//
	unsigned long int ctrl = 0;//
 
	node *tab[hmax] = {NULL};
	node obj;
	node *ptr;

	while (1) {
		obj.monies = 0;
		fgets(input, sizeof input, stdin); 
		sscanf(input, "%c %s %s %d", &c, obj.str1, obj.str2, &obj.monies);

		ctr++;//

		h = obj.hashfunc();
		ptr = tab[h];
	
		if (c == '+') {
			bool m = 0;
			unsigned long int i = 0;//

			ctrp++;//

			while (ptr && !m) {
				if (!strcmp(ptr->str1, obj.str1) && !strcmp(ptr->str2, obj.str2)) {
					ptr->monies += obj.monies;
					m = 1;
					break;
				}
				i++;//
				ptr = ptr->next;
			}
			if (!m) {
				node *ptr = new node;
	
				strcpy(ptr->str1, obj.str1);
				strcpy(ptr->str2, obj.str2);
				ptr->monies = obj.monies;
				if (tab[h])
					ptr->next = tab[h];
				else
					ptr->next = NULL;
				tab[h] = ptr;
				i++;	//
			}
//			printf("%d\n", ptr->monies);
			if (ctrl < i)	//
				ctrl = i;	//
		}

		if (c == '?') {

			ctrq++;//
			
			if (!ptr)
				printf("0\n");
			else {
				while (ptr) {
	//				if (!ptr->next) {
	//					monies = ptr->monies;
	//					break;
	//				}
					if (!strcmp(ptr->str1, obj.str1) && !strcmp(ptr->str2, obj.str2)) {
						printf("%d\n", ptr->monies);
						break;
					}
					ptr = ptr->next;
				}
			}
		}
	}
	return 0;
}

//unsigned short int hashfunc(char *str1, char *str2) {
//	unsigned short int h = 1;
//	char *p, *q;
//	int i = 0;
//
//	p = str1;
//	q = str2;
//	while (*p && *q && i < 4) {
//		h *= *p - 94;
//		h *= *q - 94;
//		h %= 661;
//		p++;
//		q++;
//		i++;
//	}
//	return h %= hmax;
//}

