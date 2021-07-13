#include <unistd.h>
#include <stdio.h>

int wrap_dup(int x, char *xx, char *f, int l)
{
	int ret = dup(x);
	fprintf(stderr, "%s:%d dup: (%s=%d), return=%d\n", f, l, xx, x, ret);

	return (ret);
}

int wrap_dup2(int x, int y, char *xx, char *yy, char *f, int l)
{
	fprintf(stderr, "%s:%d dup2: (%s=%d, %s=%d)\r", f, l, xx, x, yy, y);
	return (dup2(x, y));
}

int wrap_close(int x, char *xx, char *f, int l)
{
	fprintf(stderr, "%s:%d close: (%s=%d)\n", f, l, xx, x);
	return (close(x));
}
