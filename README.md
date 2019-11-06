![ft_printf](https://raw.githubusercontent.com/romaniyazov/ft_printf/master/readme_assets/readme_title.png)

The goal of this project is to partially reimplement printf function from C standard library to use in [libft](https://github.com/romaniyazov/libft).

### Convertions implemented
 - `c`, `s`, `p` – char, string, pointer;
 - `d`, `i`, `o`, `u`, `x`, `X` – integer, octal, unsigned, hex with flags:
   - `h`, `hh`, `l`, `ll` - short, long modifiers;
 - `f` – floating point numbers with flags:
   - `l`, `L` – double, long double.

### Also supported
 - `#`, `0`, `-`, `+` and space flags;
 - Minimum width;
 - Precision.
 