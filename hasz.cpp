#include <cstdlib> 
#include <iostream>
#include <cstring>
using namespace std;

#define HMAX 97
#define SMAX 16

struct node {
	char str1[SMAX];
	char str2[SMAX];
	int  monies;
	node *next;
};

unsigned short int hashfunc(char *str1, char *str2);

int main() {
	char c;			// instr
	char str1[SMAX];	// miro
	char str2[SMAX];	// rycho
	int n;			// lba z wejscia
	unsigned int h;		// hasz
 
	node *tab[HMAX] = {NULL};
	node *ptr;

	while (cin >> c >> str1 >> str2) {

		h = hashfunc(str1, str2);
		ptr = tab[h];
	
		if (c == '+') {
			bool m = 0;

			cin >> n;
			while (ptr && !m) {
				if (!strcmp(ptr->str1, str1) && !strcmp(ptr->str2, str2)) {
					ptr->monies += n;
					m = 1;
					break;
				}
				ptr = ptr->next;
			}
			if (!m) {
				node *ptr = new node;
	
				strcpy(ptr->str1, str1);
				strcpy(ptr->str2, str2);
				ptr->monies = n;
				if (tab[h])
					ptr->next = tab[h];
				else
					ptr->next = NULL;
				tab[h] = ptr;
			}
		}

		if (c == '?') {
			bool m = 0;

			if (!ptr)
				cout << "0\n";
			else {
				while (ptr) {
					if (!strcmp(ptr->str1, str1) && !strcmp(ptr->str2, str2)) {
						cout << ptr->monies << "\n";
						m = 1;
						break;
					}
					ptr = ptr->next;
				}
				if (!m)
					cout << "0\n";
			}
		}
	}
}

unsigned short int hashfunc(char *str1, char *str2) {
	unsigned short int h = 1;
	char *p, *q;
	int i = 0;

	p = str1;
	q = str2;
	while (*p && *q && i < 5) {
		h *= *p - 94;
		h *= *q - 94;
		h *= 17;
		p++; 
		q++;
		i++;
	}
	return h %= HMAX;
}

