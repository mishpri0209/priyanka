#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int fd1, fd2;		
	char buffer[256];
	ssize_t nbytes;

	chroot ("/root/chroot_example/jail");
	fd1 = open ("insidefile.txt", O_RDONLY);
	if (fd1 < 0) {
		fprintf (stderr, "Could not open insidefile.txt for reading\n");
	}
	else {
		fprintf (stderr, "Opened insidefile.txt\n");
		while ((nbytes = read (fd1, buffer, sizeof(buffer))) > 0) {
			write (1, buffer, nbytes);	
		}
		close (fd1);
	}

	fd2 = open ("../outsidefile.txt", O_RDONLY);
	if (fd2 < 0) {
		fprintf (stderr, "Could not open ../outsidefile.txt for reading\n");
	}
	else {
		fprintf (stderr, "Opened ../outsidefile.txt\n");
		while ((nbytes = read (fd2, buffer, sizeof(buffer))) > 0) {
			write (1, buffer, nbytes);	
		}
		close (fd2);
	}



	return 0;
}
