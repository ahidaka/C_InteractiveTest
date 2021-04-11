#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int Test();

int main()
{
    printf("Hello World!\n");

    (void) Test();

    return 0;
}

int GetWord(char* p, char* a1, char* a2, char* a3)
{
	bool end = FALSE;
	char* pt;
	char* args[3];
	int index = 0;

	args[0] = a1;
	args[1] = a2;
	args[2] = a3;

	while (!end && index < 3) {
		pt = args[index];
		while (TRUE) {
			if (p == NULL || *p == '\0' || *p == '\n') {
				end = TRUE;
				break;
			}
			else if (isspace(*p)) {
				p++;
			}
			else break;
		}

#pragma warning(disable:6011)
		* pt++ = *p++;
#pragma warning(default:6011)

		while (TRUE) {
			if (p == NULL || *p == '\0' || *p == '\n') {
				end = TRUE;
				break;
			}
			else if (!isspace(*p)) {
				*pt++ = *p++;
			}
			else break;
		}
		*pt = '\0';
		index++;
	}
	return index;
}

#define TESTBUFSIZ (64)

int Test() {
	char line[MAX_PATH];
	int count;
	char command[TESTBUFSIZ];
	char path[TESTBUFSIZ];
	char name[TESTBUFSIZ];

	while (TRUE) {

		memset(line, 0, MAX_PATH);

		printf("(start|stop|opt|quit) (path) (name)? ");

		(void)fgets(line, MAX_PATH, stdin);

		path[0] = name[0] = '\0';
		count = GetWord(line, command, path, name);

		if (count == 3) {

			if (!_strcmpi("START", command)) {

				printf("Get start\n");

				// Something to start...

			}
			else if (!_strcmpi("STOP", command)) {

				printf("Get stop\n");

				// Something to stop...

			}
			else if (!_strcmpi("OPT", command)) {

				printf("Get log\n");

				// Something to opt...

			}
		}
		else if (count == 1) {

			if (!_strcmpi("START", command)) {

				printf("Get start with 0,0=DEBUG\n");

			}
			else if (!_strcmpi("STOP", command)) {

				printf("Get stop with 0,0=DEBUG\n");

			}
			else if (!_strcmpi("OPT", command)) {

				printf("Get opt with 0,0=DEBUG\n");

			}
			else if (!_strcmpi("QUIT", command) || !_strcmpi("Q", command)) {

				printf("Get quit\n");
				return(0);
			}
		}

		else if (toupper(command[0]) == 'Q') {

			printf("Get quit\n");
			return(0);
		}
		printf("\nDEBUG: %s %s %s\n\n", command, path, name);
	}
	//while

	return 0;
}
