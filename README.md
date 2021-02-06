# 42-ft_printf
Rewrite the famous printf() function from Standard I/O header.

### Flags

| Flag  | Description														 |
|-------|--------------------------------------------------------------------|
| **-** | Align replaced text to the left when enough width is given         |
| **0** | Add '0' as a padding character in numeric conversions              |

### Conversions

| Conversion | Description					|
|------------|------------------------------|
| **c**		 | int converted to ASCII char	|
| **s**		 | NULL - terminated string		|
| **p**		 | Pointer memory address		|
| **d**		 | int in decimal base			|
| **i**		 | int in decimal base			|
| **x**		 | int in hex base (lowercase)	|
| **X**		 | int in hex base (uppercase)	|
| **%**		 | '%' char literal				|

### Width

| Width | Description					|
|------------|------------------------------|
| **(number)**| Minimum number of characters to be printed.	|
| **\***| The width is specified as an additional integer value argument preceding the argument that has to be formatted.	|


### Precisions

| Precision | Description					|
|------------|------------------------------|
| **.number**| For d, i, o, u, x, X: precision specifies the minimum number of digits to be written.	|
| **.string**| For s: this is the maximum number of characters to be printed.	|
