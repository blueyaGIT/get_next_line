<a href="https://github.com/blueyaGIT/get_next_line"><img src="https://github.com/blueyaGIT/blueyaGIT/blob/b34a5a4e10b9019609659eaa0541a4325db88ca5/covers/cover-get_next_line-bonus.png" alt="libft"></a>
###

`get_next_line` is a function that reads a file line by line. It is useful for processing files that need to be read incrementally rather than loading the entire content into memory. This function is implemented as part of the 42 School curriculum.

## Usage

To use `get_next_line`, clone the repository in the root of your project using one of the following commands:

#### SSH
```bash
git clone git@github.com:blueyaGIT/get_next_line.git
```
#### HTTPS
```bash
git clone https://github.com/blueyaGIT/get_next_line.git
```
#### GitHub CLI
```bash
gh repo clone blueyaGIT/get_next_line
```
This will create a directory called `get_next_line/`. Enter it with the command:

```bash
cd get_next_line
```

### Compiling

`get_next_line` is provided in `.c` and `.h` files, which you can include in your project. To compile a test program, you can use:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

The `BUFFER_SIZE` macro defines how many bytes `read()` retrieves at a time. You can change this value when compiling.

## Example Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Files

- `get_next_line.c` - Contains the `get_next_line()` function implementation.
- `get_next_line.h` - Header file with function prototypes and necessary includes.
- `get_next_line_utils.c` - Utility functions used by `get_next_line()`.
- `main.c` - Example program to test `get_next_line()`.

## Function Description

### `char *get_next_line(int fd);`
Reads a file descriptor `fd` line by line until the end of the file.

- Returns a `NULL` pointer if an error occurs or EOF is reached.
- Memory allocated for the returned string must be freed by the caller.

## Bonus

The `get_next_line_bonus.c` version supports multiple file descriptors, allowing you to read from different files at the same time.

To compile with bonus support, use:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

## Notes

- Ensure `BUFFER_SIZE` is greater than zero to avoid undefined behavior.
- Properly free allocated memory after usage to prevent leaks.
- `get_next_line()` handles any file descriptor, including stdin.

For more details, refer to the project documentation or the `42` subject PDF.

