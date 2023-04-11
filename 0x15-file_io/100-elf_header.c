#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_elf_header - Prints the information contained in the ELF header.
 * @header: A pointer to the ELF header.
 */
void print_elf_header(Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");
    printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Unknown");
    printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "Unknown");
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_AIX: printf("UNIX - AIX\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_MODESTO: printf("Novell - Modesto\n"); break;
        case ELFOSABI_OPENBSD: printf("UNIX - OpenBSD\n"); break;
        case ELFOSABI_ARM: printf("ARM\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
        default: printf("Unknown\n"); break;
    }
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (header->e_type)
    {
        case ET_NONE: printf("NONE (None)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("Unknown\n"); break;
    }
    printf("  Entry point address:               %p\n", (void *)header->e_entry);
    printf("\n");
}

/**
 * main - displays information about an ELF file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd, nread;
	Elf64_Ehdr ehdr;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	nread = read(fd, &ehdr, sizeof(ehdr));
	if (nread == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fd);
		exit(98);
	}

	if (nread != sizeof(ehdr) || !is_elf(ehdr))
	{
		dprintf(STDERR_FILENO, "%s: Not an ELF file\n", argv[1]);
		close(fd);
		exit(98);
	}

	print_magic(ehdr);
	print_class(ehdr);
	print_data(ehdr);
	print_version(ehdr);
	print_os_abi(ehdr);
	print_abi_version(ehdr);
	print_type(ehdr);
	print_entry(ehdr);

	close(fd);
	return (0);
}
